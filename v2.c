#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
 
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
    el_stosu *old_head = *head;
    while(*head != NULL)
    {
        *head = (*head)->next;
    }
    printf("Stos Pusty\n");
}

int main()
{ 
  el_stosu* stos = NULL;
  char oper=' ';
  int arg;
  int n;

  while(oper != 'q'){
    if(scanf("%d",&arg)){
      printf("Wczytano liczbe: %d\n",arg);
      push(&stos,arg);
      n++;
    }
    else{
      oper = getc(stdin);
      printf("Wczytano znak: >%c<\n",oper);
    }
    if(n>=2)
    {
    switch(oper){
      case '+':{
        int a = pop(&stos);
        int b = pop(&stos);
        printf("Wynik: %d",a+b);
        push(&stos,a+b);
        break;
      }
      default:
        {
          printf("Invalid\n");
          break;
        }
      n=1;
    }
    }
  }
    return 0;
}
