#include "./arbolbinario.h"
typedef AB ITEM; 
const AB indefinido = NULL;
typedef struct ELEMENTO {
    ITEM dato; //arbol
    struct ELEMENTO* siguiente; 
}ELEMENTO;
typedef struct {
    struct ELEMENTO *cabecera;
	int altura;
} PILA;

void PILAVACIA(PILA *P);
PILA PUSH(PILA P, ITEM I);
PILA POP(PILA P);


PILA POP(PILA P){
    ELEMENTO *AUX;
    
    AUX = P.cabecera;
    P.cabecera = P.cabecera->siguiente;
    free(AUX);
    return P;
}


PILA PUSH(PILA P, ITEM I){
    ELEMENTO * nuevo = (ELEMENTO *) malloc(sizeof(ELEMENTO));
    nuevo->dato = I;
    nuevo->siguiente = P.cabecera;
    P.cabecera = nuevo;
    P.altura++;
    return P;
}

void PILAVACIA(PILA *P){
    P = NULL;
}
