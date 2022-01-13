#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define BUFF_LEN 33
 
#define PRINT 1
#define NO_PRINT 0
 
typedef struct  stack_el
{
    int value;
    struct stack_el* next;
} stack_el;
 
stack_el new_stack_el(int value)
{
    stack_el el = {value, NULL};
    return el;
}
 
void push(stack_el **ptr, int value)
{
    stack_el* new_element = (stack_el*)malloc(sizeof(stack_el));
 
    new_element->value = value;
    new_element->next = *ptr;
 
    *ptr = new_element;
}
 
/*Funkcja pop nie zwraca tym razem wartości,
ale przyjmuje dodatkowy parametr pozwalający sterować tym,
czy zdjęta wartość ma być wypisana na wyjściu*/
void pop(stack_el **ptr, int print)
{
    if (*ptr == NULL)
    {
        /*Obsługa błędu w przypadku próby zdjęcia
          elementu z pustego stosu*/
        if (print == PRINT)
        { 
            printf("error\n");
        }
    }
    else
    {
        int value;
        stack_el *old_ptr = *ptr;
 
        *ptr = (*ptr)->next;
        value = old_ptr->value;
 
        free(old_ptr);
 
        if (print == PRINT)
        {
            printf("%d\n", value);
        }
    }
}
 
int main_test()
{
    stack_el* stack = NULL;
    char buffer[BUFF_LEN];
    while (fgets(buffer, BUFF_LEN, stdin) != NULL)
    {
        if (strcmp(buffer, "pop\n") == 0)
        {
            pop(&stack, PRINT);
        }
        else
        {
            /*Omijamy napis push i konwertujemy resztę
              linii do zmiennej typu int*/
            int value = atoi(&buffer[5]);
 
            push(&stack, value);
        }
    }
 
    /*Czyścimy stos*/
    while (stack!=NULL)
    {
        pop(&stack, NO_PRINT);
    }
 
    return 0;
}
