
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
 

typedef struct  el_stosu{
    int wartosc;
    struct el_stosu* next;
} el_stosu;
 
el_stosu new_el_stosu(int wartosc){
    el_stosu el = {wartosc, NULL};
    return el;
}
 
void push(el_stosu **head, int wartosc){
    el_stosu* new_element = (el_stosu*)malloc(sizeof(el_stosu)); //zaalokowanie pamieci dla stosu 
 
    new_element->wartosc = wartosc;
    new_element->next = *head;
 
    *head = new_element;
}
 

int pop(el_stosu **head)
{
    if(*head != NULL){
        int wartosc;
        el_stosu *old_head = *head; //aktualny element na szczycie stosu, jako old_head
 
        *head = (*head)->next;
        wartosc = old_head->wartosc;
 
        free(old_head); //zwolnienie pamieci gdzie byl wskaznik na zdjety element
        return wartosc;
    }
    else{
        printf("Nie mozna zdjac elementu z pustego stosu\n");
        return 1;
    }
}

void empty(el_stosu **head)
{
    
    while(*head != NULL)
    {
        *head = (*head)->next;
    }
    head = NULL;
    
    printf("Stos Pusty\n");
}

int print(el_stosu **head){
  if(*head != NULL){
    el_stosu *display_top;
    display_top = *head;
    int x=display_top->wartosc;
    printf("Szczyt stosu: %d\n",x);
    return x;
   
  }
  else{
    printf("Stos pusty\n");
    return 1;
  }
  }


int print_FULL(el_stosu ** head){

    el_stosu *display_all;
    display_all = *head;
    
    if(display_all!= NULL)
    {
        printf("Elementy Stosu:\n");
        do
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


/*
void copy_top(el_stosu ** head){
   
  if(*head != NULL){
      el_stosu *display_top;
      display_top = *head;
      int *temp= malloc(sizeof(int));
      temp = display_top->wartosc;
      printf("Szczyt stosu: %d\n",x);
      return 0;
    
    }
    else{
      printf("Stos pusty\n");
      return 1;
    }
  }
*/


int main()
{ 
  el_stosu* stos = NULL;      //zainicjowanie stosu

  char oper =' ';             //zmienna operatora
  float arg;                  //zmienna aktualnego argumentu
  int n=0;                    //liczba argumentow
  
  printf("-------------------------------------------------------------------------------\n");
  printf("Kalkulator RPN\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("Instrukcja podawania argumentów: \n");
  printf("-------------------------------------------------------------------------------\n");
  printf("1 liczba\n");
  printf("2 liczba\n");
  printf("znak operacji:\n");
  printf("  +(jako '-+'), -(jako '-'), '/', '*', '^'(potegowanie),\n");
  printf(" t(print top), p(pop), c(wyczysc stos), f(print stos), r(odwroc stos), d(duplikat topu), q(koniec)\n");
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
                                      //po kazdej operacji wyzerowanie operatora
            }
            else{
                printf("Stos pusty\n");
            }
          break;
          }
        case '-':
          { 
            if(n>1){
                float a= pop(&stos);
                float b = pop(&stos);
                float c = b-a;
                printf("Wynik: %.2f\n",c);
                push(&stos,c);
                n--;
                 ;
            }
            else{
                printf("Stos pusty\n");
            }
            break;
            }
        case '/':
          {
            if(n>1){
                float a= pop(&stos);
                float b = pop(&stos);
                float c = b/a;
                printf("Wynik: %.2f\n",c);
                push(&stos,c);
                n--;
                 
            }
            else{
                printf("Stos pusty\n");
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
                printf("Stos pusty\n");
            }
            break;
          }
        case '%':
          {
            if(n>1){
                float a= pop(&stos);
                float b = pop(&stos);
                int c = (int)b % (int)a;            //modulo musi miec liczby stalopozycyjne, wiec zmieniam typ zmiennej z float na int, liczby beda mialy anulowana czesc po przecinku, jezeli ja maja, a nastepnie zostanie zwrocona reszta z dzielenia tych liczb
                printf("Wynik: %d\n", c);
                push(&stos,c);
                n--;
                
            }
            else{
                printf("Stos pusty\n");
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
                printf("Stos pusty\n");
            }
            break;
        }
        case 'c':
          {
            empty(&stos);                       
            free(stos);                         //zwolnienie pamieci dla stosu
            stos=NULL;                          //przywrocenie aby stos znow wskazywal na "nic"
            printf("Stos pusty\n");
            n=0;                                //n=0 bo zdjelismy wszystie argumenty
            
            break;
          }
        case 't':
          {
            if(n>0){
                print(&stos);                     
            
            }
            else{
                printf("Stos pusty\n");
            }
            break;
          }
        case 'f':
          {
            if(n>0){
                print_FULL(&stos);
                
            }
            else{
                printf("Stos pusty\n");
            }
            break;
          }
        case 'p':
          {
            if(n>0){
                pop(&stos);
                
            }
            else{
                printf("Stos pusty\n");
            }
            break;
          }
        case 'r':
        {
            if(n>1){
            el_stosu* stos_temp1 = NULL;              //pomocnicze stosy do zmaiany kolejnosci elementow
            el_stosu* stos_temp2 = NULL;
            
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
                printf("Stos pusty\n");
            }
          break;
        }
        default:
          {
            if(oper!='q' && oper != n)
            printf("Nieprawidłowy znak\n");
            n--;
            
            break;
          }
          oper=' ';
        }
      
}


printf("Koniec Programu\n");
  

  
return 0;
}

