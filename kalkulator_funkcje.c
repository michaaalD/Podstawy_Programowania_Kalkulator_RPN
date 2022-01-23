#include <stdio.h>

#include "lab06_funkcje.h"

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
