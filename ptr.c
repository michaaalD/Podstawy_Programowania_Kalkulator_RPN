
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
 

typedef struct  el_stosu_t{               //zadeklarowanie struktury
    int wartosc;                          //zmianna int wartosc 
    struct el_stosu_t* next;              // wskaznik na nastepny element struktury
} el_stosu_t;
 
el_stosu_t new_el_stosu_t(int wartosc){
    el_stosu_t el = {wartosc, NULL};        //zainicjowanie stosu
    return el;
}
 
void push(el_stosu_t **head, int wartosc){
    el_stosu_t* new_element = (el_stosu_t*)malloc(sizeof(el_stosu_t)); //zaalokowanie pamieci dla stosu 
 
    new_element->wartosc = wartosc;   //przypisanie wartosci
    new_element->next = *head;        //przypisanie head stosu jako nastepny element na stosie
 
    *head = new_element;
}
 

int pop(el_stosu_t **head)
{
    if(*head != NULL){
        int wartosc;
        el_stosu_t *old_head = *head; //aktualny element na szczycie stosu, jako old_head
 
        *head = (*head)->next;        //head jako nastepny element
        wartosc = old_head->wartosc;  //przypisanie zmiennej wartosci wartosci starego head
 
        free(old_head);               //zwolnienie pamieci gdzie byl wskaznik na zdjety element
        return wartosc;                //zwrocenie elementu jaki zdjelismy
    }
    else{
        printf("Nie mozna zdjac elementu z pustego stosu\n");
        return 1;
    }
}

void empty(el_stosu_t **head)
{
    
    while(*head != NULL)            //sprawdzamy czy glowa nie wskazuje na 'nic'
    {
        *head = (*head)->next;      //head zmienia sie na kazdy kolejny element stosu
    }
    head = NULL;                    //head wskazuje na 'nic'
    
    printf("Stos Pusty\n");
}

int print(el_stosu_t **head){
  if(*head != NULL){                  //sprawdzamy czy stos nie jest pusty
      el_stosu_t *display_top;        //wskanik na nastepny Element
      display_top = *head;            
      int x=display_top->wartosc;     //przypisanie zmiennej x wartosci ze struktury
      printf("Szczyt stosu: %d\n",x); //wypisanie tej wartosci
      return x;                       
   
  }
  else{
      printf("Stos pusty\n");
      return 1;
    }
  }


int print_FULL(el_stosu_t ** head){

    el_stosu_t *display_all;    //wskaznik na kolejny element struktury
    display_all = *head;         //wskaznik pokauje na head
    
    if(display_all!= NULL)        //sprawdzamy czy wskaznik nie pokazuje na 'nic'
    {
        printf("Elementy Stosu:\n");
        do                                  //wypisanie elementow stosu, wyswietli conajmniej jeden element stosu,
        {   
            int x = display_all->wartosc;
            printf("%d\n",x);
            display_all = display_all->next;
        }
        while (display_all!= NULL);
        return 0;
    }
    else
    {
        printf("Stos pusty\n");
        return 1;
    }
}



int copy_top(el_stosu_t ** head){
   
  if(*head != NULL){                        //sprawdzamy czy wskaznik nie pokazuje na 'nic'
    el_stosu_t *copy_top; 
    copy_top=*head;
     int kopia;                             
      kopia = copy_top->wartosc;            //przypisujemy zmiennej kopia wartosc head
      printf("Skopiowano top stosu:\n");
      return kopia;                         //zwracamy kopie
      
    
    }
    else{
      printf("Stos pusty\n");
      return 0;
    }
  }



int main()
{ 
  el_stosu_t* stos = NULL;      //zainicjowanie stosu

  char oper =' ';             //zmienna operatora
  float arg;                  //zmienna aktualnego argumentu
  int n=0;                    //liczba argumentow
  
  printf("-------------------------------------------------------------------------------\n");
  printf("Kalkulator RPN\n");
  printf("-------------------------------------------------------------------------------\n");
  printf(" t(print top), p(pop), c(wyczysc stos), f(print stos), r(odwroc stos), d(duplikat topu), q(koniec)\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("Instrukcja podawania argumentów: \n");
  printf("-------------------------------------------------------------------------------\n");
  printf("1 liczba\n2 liczba\n");
  printf("znak operacji:\n");
  printf("'+', '-', '/', '*', '^', '%', 't', 'p', 'c','f', 'r', 'd', 'q'\n");
  printf("-------------------------------------------------------------------------------\n");

  while(oper != 'q'){
    
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
           oper = ' ';                          //po kazdej operacji wyzerowanie operatora
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
            oper=' ';
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
            oper=' ';
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
            oper=' ';
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
                  push(&stos,c);
                  n--;
                }
                else{
                  printf("Nie mozna obliczyc reszt z dzielenia przez 0\n");
                }
            }
            else{
                printf("ERROR(%)Stos pusty\n");
            }
            oper=' ';
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
            oper=' ';
            break;
        }
        case 'c':
          {
            empty(&stos);                       
            free(stos);                         //zwolnienie pamieci dla stosu
            stos=NULL;                          //przywrocenie aby stos znow skazywal  na "nic"
            
            n=0;
            oper=' ';                                
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
            oper=' ';
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
            oper=' ';
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
            oper=' ';
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
            oper=' ';
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
          oper=' ';
          break;
        }
        case 's':
        {
          if(n>0){
                float a= pop(&stos);
                if(a>0){                        //sprawdzamy czy liczba pierwiastkowana wieksza od zera
                  float b = sqrt(a);
                  printf("Wynik: %.2f\n",b);
                  push(&stos,b);
                }
                else{
                  printf("Nie mozna obliczyc pierwiastka z liczby ujemnej\n");
                  push(&stos,a);
                }
            }
            else{
                printf("ERROR(s) - Stos pusty\n");
            }
            oper=' ';
            break;
        }
        default:
          {
            if(oper != ' ' && oper!='q' && sizeof(oper)==sizeof(char))
            printf("ERROR - Nieprawidłowy znak\n");
            oper=' ';
            break;
          }
          
        }
      
}


printf("Koniec Programu\n");
  

  
return 0;
}

/*Sprawozdanie
Michal Dos
Temat: Kalkulator RPN
Data: 19.01.2021r.

TESTY:
Testy programu zaczalem od implementacji prostych operacji arytmetycznych do switcha.
Program poprwanie wykonwyal podstawowe arytmetyczne np. 
1)  5 5 * = 25
2)  6 2 / = 3
3)  7 8 + = 15
4)  74 65 - = 9

Program podobnie jak w przypadku kalkulatora dc zmienia znak liczby po wpisaniu - np.
1)  5 - = -5
2) -3 - = 3

Program nie pozwala na wykonanie operacji gdy jest tylko jeden argument, po wykonaniu takiej operacji, operator zostaje wyzerowany np. :
1)  5 * = ERROR(*) Stos


Dodatkowo dodalem do programu opcje liczenia potegi liczby, reszty z dzielenia, pierwiastkowanie. 

Nastepnie zajalem sie deklaracja asercji poszczegolnych dzialan 
1)  Program nie pozwala dzielic przez 0 np.:
1 0 / = ERROR mianownik mniejszy od zera

2)  Program nie pozwala liczyc reszty z dzeielenia przez 0:
 8 0 % = ERROR nie  mozna liczyc reszty z dzielenia przez 0

3) Program nie pozwala liczyc pierwiastkow z liczby ujemnej:
-5 s = Nie mozna liczyc pierwiastka z liczby ujemnej

Wnioski :
Program wydaje sie popwawnie wykonywac operacje jako kalkulator RPN.

*/
