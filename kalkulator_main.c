#include <stdio.h>

#include "lab06_funkcje.h"



int main()
{ 
  el_stosu_t* stos = NULL;      //zainicjowanie stosu

  char oper =' ';             //zmienna operatora
  float arg;                  //zmienna aktualnego argumentu
  int n=0;                    //liczba argumentow
  
  printf("-------------------------------------------------------------------------------\n");
  printf("Kalkulator RPN\n");
  printf("-------------------------------------------------------------------------------\n");
  
  printf("-------------------------------------------------------------------------------\n");
  printf("Instrukcja podawania argumentów: \n");
  printf("-------------------------------------------------------------------------------\n");
  printf("1 liczba\n2 liczba\n");
  printf("znak operacji:\n");
  printf("'+', '-', '/', '*', '^', '%', 't', 'p', 'c','f', 'r', 'd', 's', 'q'\n");
  printf("-------------------------------------------------------------------------------\n");

  while(oper != 'q'){
    oper=' ';                                 //wyzerowanie operatora
    if(scanf("%f",&arg)){                     //pobranie argumentow liczbowych
        printf("Wczytano liczbe: %.2f\n",arg);
        push(&stos,arg);                      //umieszczenie na stosie
        n++;                                  //zwiekszenie licznika ilosci argumentow
      }
    else{ 
        oper = getc(stdin);                   //pobranie operatora
        printf("Wczytano znak: >%c<\n",oper);
      }

    switch(oper){
        case '+':
          {
            if(n>1){
                float a= pop(&stos);
                float b = pop(&stos);
                float c = b+a;                 //pomocnicza c do operacji arytmetycznych
                printf("Wynik: %.2f\n",c);
                push(&stos,c);
                n--;                           //po kazdej operacji arytmetycznej licznik elementow -1
                                              
            }
            else{
                printf("ERROR(+)Stos pusty\n");
            }
           break;
          }
        case '-':
          { 
            if(n>1){                            //jak 2 argumenty to wykonujemy odejmowanie
                float a= pop(&stos);
                float b = pop(&stos);
                float c = b-a;
                printf("Wynik: %.2f\n",c);
                push(&stos,c);
                n--;
                
                 
            }
            else if(n==1){                      //jak 1 argument, zmieniamy znak
              float a = pop(&stos);
              float c = (-a);
              printf("Wynik: %.2f\n",c);
              push(&stos,c);
              n--;
              
            }
            else{
                printf("ERROR(-) Stos pusty\n");
            }
            break;
            }
        case '/':
          {
            if(n>1){
                float a= pop(&stos);
                float b = pop(&stos);
                if(a!=0){                           //sprawdzenie czy mianownik nie jest zerem
                  float c = b/a;
                  printf("Wynik: %.2f\n",c);
                  push(&stos,c);
                  n--;
                }
                else{
                  printf("ERROR - Mianownik mniejszy or zera\n");
                }
              }
            else{
                printf("ERROR(/)Stos pusty\n");
              }
            break;
          }
        case '*':
          {
            if(n>1){
                float a= pop(&stos);
                float b = pop(&stos);
                float c = b*a;
                printf("Wynik: %.2f\n", c);
                push(&stos,c);
                n--;  
            }
            else{
                printf("ERROR(*)Stos pusty\n");
	    }
            break;
          }
        case '%':
          {
            if(n>1){
                float a= pop(&stos);         
                float b = pop(&stos);
                if(a!=0){
                  int c = (int)b % (int)a;            //modulo musi miec liczby stalopozycyjne, wiec zmieniam typ zmiennej z float na int, liczby beda mialy anulowana czesc po przecinku, jezeli ja maja, a nastepnie zostanie zwrocona reszta z dzielenia tych liczb
                  printf("Wynik: %d\n", c);
                  push(&stos,(float)c);
                  n--;
                }
                else{
                  printf("Nie mozna obliczyc reszt z dzielenia przez 0\n");
                }
            }
            else{
                printf("ERROR(%)Stos pusty\n");
            }
            break;
          }
        case '^':
        {
            if(n>1){
                float a= pop(&stos);
                float b = pop(&stos);
                float c = pow(b,a);
                printf("Wynik: %.2f\n", c);
                push(&stos,c);
                n--;   
            }
            else{
                printf("ERROR(^)Stos pusty\n");
            }
            break;
        }
        case 'c':
          {
            empty(&stos);                       
            free(stos);                         //zwolnienie pamieci dla stosu
            stos=NULL;                          //przywrocenie aby stos znow skazywal  na "nic"
            
            n=0;                              
            break;
          }
        case 't':
          {
            if(n>0){
                print(&stos);                    
            
            }
            else{
                printf("ERROR(t) - Stos pusty\n");
            }
            break;
          }
        case 'f':
          {
            if(n>0){
                print_FULL(&stos);
                
            }
            else{
                printf("ERROR(f) - Stos pusty\n");
            }
            break;
          }
        case 'p':
          {
            if(n>0){
                pop(&stos);
                
            }
            else{
                printf("ERROR(p) - Stos pusty\n");
            }
            //oper=' ';
            break;
          }
        case 'd':
        {
            if(n>0){
                
              push(&stos,copy_top(&stos));              //skopiowanie topu
              if(n==1)n++;                              //kiedy jest jeden element na stosie, a chcemy go skopiowac
            }
            else{
                printf("ERROR(p) - Stos pusty\n");
            }
            break;
        }
        case 'r':
        {
            if(n>1){
            el_stosu_t* stos_temp1 = NULL;              //pomocnicze stosy do zmaiany kolejnosci elementow
            el_stosu_t* stos_temp2 = NULL;
            
            push(&stos_temp1,pop(&stos));             //push elementow ze stosu glownego na stos temp1 
            push(&stos_temp1,pop(&stos));
            free(stos);                               //zwolnienie pamieci stosu glownego

            push(&stos_temp2,pop(&stos_temp1));       //push ze stosu temp1 na stos temp2
            push(&stos_temp2,pop(&stos_temp1));
            free(stos_temp1);                         //zwolnienie pamieci stosu temp1

            push(&stos,pop(&stos_temp2));             //push elementow ze stosu temp2 na stos glowny
            push(&stos,pop(&stos_temp2));
            free(stos_temp2);                         ////zwolnienie pamieci stosu temp2

            printf("Odwrocono stos\n");
            
            }
            else{
                printf("ERROR(r) - Stos pusty\n");
            }
          break;
        }
        case 's':
        {
          if(n>0){
	    float a= pop(&stos);
                if(a>0){                        //sprawdzamy czy liczba pierwiastkowana wieksza od zera
                  float b = sqrt(a);
                  printf("Wynik: %f\n",b);
                  push(&stos,b);
                }
		  else if(a < 0){
                  printf("Nie mozna obliczyc pierwiastka z liczby ujemnej\n");
                  push(&stos,a);
                }
		  else if(sizeof(a)!=sizeof(int)){
		      printf("Nie mozna obliczyc pierwiastka z liczby niewymiernej\n");
		    }
            }
            else{
                printf("ERROR(s) - Stos pusty\n");
            }
            break;
        }
    case 'h':{
      printf("t(print top), p(pop), c(wyczysc stos), f(print stos), r(odwroc stos), d(duplikat topu), q(koniec), s(pierwiastek liczby calkowitej)");
}
        default:
          {
            if(oper != ' ' && oper!='q' && sizeof(oper)==sizeof(char))
            printf("ERROR - Nieprawidłowy znak\n");
            break;
          }
          
        }
      
}


printf("Koniec Programu\n");
  

  
return 0;
}
