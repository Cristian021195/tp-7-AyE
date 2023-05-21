#include <stdio.h>
#include <stdlib.h>
#include "./headers/arbolbinario.h"

int main(){
    AB A = ABVACIO();   A = ARMARAB(NULL, 'A', NULL);
    AB B = ABVACIO();   B = ARMARAB(NULL, 'B', NULL);
    AB C = ABVACIO();   C = ARMARAB(NULL, 'C', NULL);
    AB RES = ABVACIO();   RES = ARMARAB(A, 'R', B);

    //printf("Esvacio? %d", ESABVACIO(A));
    //printf("arbol izq->raiz? %c\n", IZQUIERDO(RES)->raiz);
    //printf("arbol der->raiz? %c\n", DERECHO(RES)->raiz);
    //printf("raiz? %c\n", RAIZ(RES));

    //printf("raiz? %c\n", RAIZ(RES->izq->izq));
    //printf("Pertenece R? %d", PERTENECE(RES, 'B'));

    printf("\nPREORDEN: < ");PREORDEN(RES);printf(">");
    printf("\nENORDEN: < ");ENORDEN(RES);printf(">");
    printf("\nPOSORDEN: < ");POSORDEN(RES);printf(">");


    return 0;
}