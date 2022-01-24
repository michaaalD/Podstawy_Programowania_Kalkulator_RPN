#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *tab; //wsk na adres dynamicznej listy
    int top;  
    int rozmiar;
} Stos;

Stos* inicjuj(int rozmiar){
    Stos *wsk = (Stos*)malloc(sizeof(Stos));
    if(wsk == NULL){
        printf("Stos niezainicjowany\n");
        exit(1);
    }
    wsk->tab= (int*) malloc(sizeof(int) * rozmiar);
    if(wsk->tab == NULL){
        printf("Nie mona zainicjalizowac stosu\n");
        exit(1);
    }
    wsk->top = -1; //top indeks -1, w miare zwiekszania stosu, indeks zwieksza sie, wiec 1 element ma indeks 0
    wsk->rozmiar = rozmiar;

    return wsk;

}
void push(Stos *wsk, int x){
    if(wsk->top == wsk->rozmiar -1){ //zebyn nie przepelnic stosu
    int* temp =(int*)malloc(sizeof(int)*(*wsk).rozmiar *2); //lokowanie pamieci
    if(temp == NULL){
        printf("Nie udalo sie zaalokowac pamieci\n");
    }
    for(int i=0; i<wsk->rozmiar -1; i++){ //skopiowanie tablicy tab do tymczasowej tablicy temp
        temp[i]=wsk->tab[i];
    }
    free(wsk->tab);   // zwolnienie pamieci na tab
    wsk->tab=temp;    //temp ma adres nowo zalokowanej tablicy
    wsk->rozmiar *=2;
    }
    wsk->tab[++wsk->top] = x; //zwiekszenie indeksu topu i umieszczenie tam x
}
int pop(Stos *wsk){
    if(wsk->top == -1){ //sprawdzenie czy top = -1, wtedy stos jest pusty
        printf("Stos jest pusty\n");
        return 1;
    }
    else
        return wsk->tab[wsk->top--];
}

int empty_stack(Stos *wsk){ 
    if(wsk->top == -1){ //sprawdzenie czy top = -1, wtedy stos jest pusty
        printf("Stos jest pusty\n");
        return 1;
    }
    else
        printf("Elementy stosu:\n");
        for(int i=0; i< wsk->rozmiar ; i++){ 
            if(wsk->top != -1){
            printf(" %d\n",wsk->tab[wsk->top]);
            wsk->top--;
            }
        }
}

int print_top(Stos* wsk){
    if(wsk->top == -1){ //sprawdzenie czy top = -1, wtedy stos jest pusty
        return 1;
    }
    else
        printf("Top stosu: %d\n",wsk->tab[wsk->top]);       
}

int main(){
    

    Stos *stack = inicjuj(5);

    push(stack,3);
    push(stack, 7);
    
    printf("%d",pop(stack) + pop(stack));
    

    return 0;
}
