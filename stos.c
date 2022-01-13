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
    el_stosu* new_element = (el_stosu*)malloc(sizeof(el_stosu));
 
    new_element->wartosc = wartosc;
    new_element->next = *head;
 
    *head = new_element;
}
 

int pop(el_stosu **head)
{
    if(*head != NULL){
        int wartosc;
        el_stosu *old_head = *head;
 
        *head = (*head)->next;
        wartosc = old_head->wartosc;
 
        free(old_head);
        return wartosc;
    }
    else{
        printf("Nie mozna zdjac elementu z pustego stosu\n");
    }
}

int empty(el_stosu **head)
{
    el_stosu *old_head = *head;
    while(*head != NULL)
    {
        *head = (*head)->next;
    }
}

int peep(el_stosu **head){
    if(*head != NULL){
        
        int wartosc;
        el_stosu *akt_head = *head;
 
        wartosc = akt_head->wartosc;
 
        
        return wartosc;
        
    }
    else{
        printf("Stos pusty\n");
    }
}
 
int main()
{
    el_stosu* stos = NULL;

    push(&stos,1);
    push(&stos,2);
    push(&stos,3);
    push(&stos,5);
    pop(&stos);
    push(&stos,4);
    //empty(&stos);
    //int a = pop(&stos);
    //int b = pop(&stos);

    peep(&stos);
    return 0;
}
