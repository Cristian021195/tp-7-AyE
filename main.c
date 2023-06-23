#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./headers/pilaab.h"

AB ARBOL_DE_EXPRESION(char ep[], int n);

int main(){
    char ep[8] = {'a','b','c','+','*','d','/','='};
    /*PILA P; PILAVACIA(&P); // [fnd - top]
    P = PUSH(P,'a'); P = PUSH(P,'b'); P = PUSH(P,'c'); P = PUSH(P,'+');
    P = PUSH(P,'*'); P = PUSH(P,'d'); P = PUSH(P,'/'); P = PUSH(P,'=');*/
    AB B = ABVACIO();   B = ARMARAB(NULL, 'B', NULL);
    AB C = ABVACIO();   C = ARMARAB(NULL, 'C', NULL);
    AB D = ABVACIO();   D = ARMARAB(NULL, 'D', NULL);
    AB E = ABVACIO();   E = ARMARAB(NULL, 'E', NULL);
    AB A = ABVACIO();   A = ARMARAB(E, 'A', D);
    AB R = ABVACIO();   R = ARMARAB(A, 'R', B);
    AB RES = ABVACIO(); PILA_AB PAUX; PILAVACIA_AB(&PAUX);

    //printf("Esvacio? %d", ESABVACIO(A));
    //printf("arbol izq->raiz? %c\n", IZQUIERDO(RES)->raiz);
    //printf("arbol der->raiz? %c\n", DERECHO(RES)->raiz);
    //printf("raiz? %c\n", RAIZ(RES));

    //printf("raiz? %c\n", RAIZ(RES->izq->izq));
    //printf("Pertenece R? %d", PERTENECE(RES, 'B'));

    /*printf("\nPREORDEN: < ");PREORDEN(R);printf(">");
    printf("\nENORDEN: < ");ENORDEN(R);printf(">");
    printf("\nPOSORDEN: < ");POSORDEN(R);printf(">");*/

    RES = ARBOL_DE_EXPRESION(ep, 8);
    printf("\nPOSORDEN: < ");POSORDEN(RES);printf(">");
    //printf("\n(%c)\n", RES->raiz);
    //printf("\n(%c)\n", RES->izq->izq->raiz);
    //printf("\n(%c)\n", RES->izq->der->der->raiz);
    //printf("%c", RES->raiz);

    /*PAUX = PUSH_AB(PAUX, ARMARAB(ABVACIO(),'a',ABVACIO()));
    printf("%c", TOP_AB(PAUX)->raiz);*/
    
    return 0;
}

AB ARBOL_DE_EXPRESION(char ep[], int n){
    PILA_AB PAUX; PILAVACIA_AB(&PAUX);
    AB ACT = ABVACIO(); AB ANT = ABVACIO(); // falta codigo para armar el arbol que devuelve la fn    

    for(int i = 0; i < 8; i++){
        if(ep[i] == '+' || ep[i] == '-'){
            ACT = TOP_AB(PAUX);
            PAUX = POP_AB(PAUX);
            ANT = TOP_AB(PAUX);
            PAUX = POP_AB(PAUX);

            PAUX = PUSH_AB( PAUX, ARMARAB( ANT, ep[i], ACT ) );
        }else if(ep[i] == '*' || ep[i] == '/'){
            ACT = TOP_AB(PAUX);
            PAUX = POP_AB(PAUX);
            ANT = TOP_AB(PAUX);
            PAUX = POP_AB(PAUX);

            PAUX = PUSH_AB( PAUX, ARMARAB( ANT, ep[i], ACT ) );
        }
        else if(ep[i] == '='){
            break;
        }else{
            PAUX = PUSH_AB(PAUX, ARMARAB(ABVACIO(), ep[i] ,ABVACIO()));
        }
    }
    printf("\naltura: %d \n", PAUX.altura);
    return TOP_AB(PAUX);
}