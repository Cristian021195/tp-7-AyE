#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INDEF -9999;

typedef char itemAB;
typedef struct nodoAB { // nodo - abrol singular, etc.
    itemAB raiz;
    struct nodoAB *izq;
    struct nodoAB *der;
}nodoAB;
typedef struct nodoAB * AB; // arbol

AB ABVACIO();
int ESABVACIO();
AB ARMARAB(AB A, itemAB c ,AB B);
AB IZQUIERDO(AB A);
AB DERECHO(AB A);
char RAIZ(AB A);
int PERTENECE(AB A, itemAB c);
void PREORDEN(AB A);
void ENORDEN(AB A);
void POSORDEN(AB A);


int PERTENECE(AB A, itemAB c){
    // PERTENECE(ARMARAB(izq,x,der),y) ≡ x=y OR PERTENECE(izq,y) OR PERTENECE(der,y)    
    if(A != NULL){
        if(A->raiz == c){
            return 0;
        }else{
            PERTENECE(A->izq,c);
            PERTENECE(A->der,c);
        }
    }else{
        return 1;
    }
}
char RAIZ(AB A){
    if(A == NULL){
        printf("No hay mas\n");
        return '1';
    }
    return A->raiz;
}
AB IZQUIERDO(AB A){
    return A->izq;
}
AB DERECHO(AB A){
    return A->der;
}


AB ARMARAB(AB A, itemAB c ,AB B){//(ELEMENTO *) malloc(sizeof(ELEMENTO));
    AB N = (AB) malloc(sizeof(AB));
    N->izq = A;
    N->der = B;
    N->raiz = c;
    return N;
}
int ESABVACIO(AB ABIN){
    return ABIN == NULL;
}
AB ABVACIO(){
    AB AUX = NULL;
    //AUX->der = NULL;
    //AUX->izq = NULL;
    //AUX->raiz = ' ';
    return AUX;
}


void PREORDEN(AB A){
    if(A != NULL){
        printf("%c, ", A->raiz);
        PREORDEN(A->izq);
        PREORDEN(A->der);
    }
}
void ENORDEN(AB A){
    if(A != NULL){
        PREORDEN(A->izq);
        printf("%c, ", A->raiz);
        PREORDEN(A->der);
    }
}
void POSORDEN(AB A){
    if(A != NULL){
        PREORDEN(A->izq);        
        PREORDEN(A->der);
        printf("%c, ", A->raiz);
    }
}