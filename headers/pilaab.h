#include "./arbolbinario.h"
typedef AB ITEM_AB; 
const AB indefinido = NULL;
typedef struct ELEMENTO_AB {
    ITEM_AB dato; //arbol
    struct ELEMENTO_AB* siguiente; 
}ELEMENTO_AB;
typedef struct {
    struct ELEMENTO_AB *cabecera;
	int altura;
} PILA_AB;

void PILAVACIA_AB(PILA_AB *P);
PILA_AB PUSH_AB(PILA_AB P, ITEM_AB I);
PILA_AB POP_AB(PILA_AB P);
ITEM_AB TOP_AB(PILA_AB P);


PILA_AB POP_AB(PILA_AB P){
    ELEMENTO_AB *AUX;
    
    AUX = P.cabecera;
    P.cabecera = P.cabecera->siguiente;
    P.altura--;
    free(AUX);
    return P;
}


PILA_AB PUSH_AB(PILA_AB P, ITEM_AB I){
    ELEMENTO_AB * nuevo = (ELEMENTO_AB *) malloc(sizeof(ELEMENTO_AB));
    nuevo->dato = I;
    nuevo->siguiente = P.cabecera;
    P.cabecera = nuevo;
    P.altura++;
    return P;
}

ITEM_AB TOP_AB(PILA_AB P){
    return P.cabecera->dato;
}

void PILAVACIA_AB(PILA_AB *P){
    //P = NULL;
    P->altura = 0;
    P->cabecera = NULL;
}
