#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BRAK_ZNAKU 0
 
 
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
    printf("Stos Pusty\n");
}

int print_FULL(el_stosu **head){
  if(*head != NULL){
    int wartosc;
   el_stosu* temp_element = (el_stosu*)malloc(sizeof(el_stosu)); //zaalokowanie pamieci dla stosu temp
   temp_element->wartosc = wartosc;
   temp_element->next = *head;
   
   el_stosu* stos_temp = NULL;

   push(&stos_temp,pop(&stos));
   
  }
  else{
    printf("Stos pusty\n");
    return 1;
  }
  
}

int print(el_stosu ** head){
  if(*head != NULL){
    int wartosc;
    el_stosu *akt_head = *head;
    wartosc = akt_head->wartosc;
    printf("Sczyt stosu %d\n",wartosc);
    return wartosc;
  }
  else{
    printf("Stos pusty\n");
    return 1;
  }
}

int main()
{ 
  el_stosu* stos = NULL;

  char oper =' ';             //zmienna operatora
  int arg;                    //zmienna aktualnego argumentu
  int n=0;                    //liczba argumentow


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
  if(n>1 && oper != ' '){
    switch(oper){
      case '+':
      {
        int a= pop(&stos);
        int b = pop(&stos);
        float c = b+a;
        printf("Wynik: %.2f\n",c);
        push(&stos,c);
        break;
        break;
      }
      case '-':
      {
        int a= pop(&stos);
        int b = pop(&stos);
        float c = b-a;
        printf("Wynik: %.2f\n",c);
        push(&stos,c);
        break;
        }
      case '/':
      {
        int a= pop(&stos);
        int b = pop(&stos);
        float c = (float)b/(float)a;
        printf("Wynik: %.2f\n",c);
        push(&stos,c);
        break;
      }
      case '*':
      {
        int a= pop(&stos);
        int b = pop(&stos);
        float c = (float)b*(float)a;
        printf("Wynik: %.2f\n", c);
        push(&stos,c);
        break;
      }
      case 'c':
      {
        empty(&stos);
        break;
      }
      case 'p':
      {
        print(&stos);
        break;
      }
      case 'f':
      {
        print_FULL(&stos);
        break;
      }
      default:
        {
          if(oper!='q')
          printf("Invalid\n");
          break;
        }
      n--;
      oper=' ';
    }
  }

    

    }
  printf("Koniec Programu\n");
  

  
  return 0;
}


//oper = getc(st
