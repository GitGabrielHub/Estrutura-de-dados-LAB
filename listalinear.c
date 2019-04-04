#include <stdio.h>
#include <stdlib.h>
#include "listalinear.h"

lista * criaLista(int n) {
    lista *nova = (lista*)malloc(sizeof(lista));
    nova->val = (int*)malloc(n*sizeof(int));
    nova->max = n;
    nova->ue = 0;
    return nova;
}

int hasElement (const lista* l, int v){

	int i;
	for (i = 0; i < l -> ue; i++){
		if (l -> val[i] == v) return i+1;
	}
	return -1;
}

int insertPosition (lista* l, int v, int pos){

	if ( pos > l -> ue + 1) return -1;

	if ( l -> ue == l -> max){
		int* aux = (int*)realloc(l -> val, 2*l->max*sizeof(int));
		if (aux == NULL) return -1;

		l -> val = aux;
		l -> max*=2;

	}

	int i;
	for (i = l -> ue; i > pos-1; i--){
		l -> val[i] = l -> val[i-1];
	}

	l -> val[pos-1] = v;
	l -> ue++;
	return 0;

}

int removeElement (lista *l, int v){
	int i;
	for (i = 0; i < l -> ue; i++){
		if (l -> val[i] == v) return remove_pos(l,i);
	}

	return -1;

}

int insere(lista * l, int v) {
    if(l->ue == l->max) {
       int *aux = (int*)realloc(l->val, 2*l->max*sizeof(int));
        if (aux == NULL) {
            return -1;
        }
        else {
            //printf("Realocou...\n");
            l->val = aux;
            l->max *= 2; 
        }
    }
    l->val[l->ue] = v;
    l->ue++;
    return 0;
}

int remove_pos(lista *l, int i) {
    if(i >= l->ue || i < 0) return -1;
    else {
        int k;
        for(k = i+1; k < l->ue; k++) {
            l->val[k-1] = l->val[k];
        }
        l->ue--;
        return 0;
    }
}

int get(const lista *l, int i) {
    if(i >= 0 && i < l->ue)
    	return l->val[i];
}

int size(const lista *l) {
    return l->ue;
}

void printLista(const lista *l) {
    printf("[");
    int i;
    for(i = 0; i < l->ue; i++) {
        if(i < l->ue-1){
            printf("%d,",l->val[i]);
        }
        else {
            printf("%d]",l->val[i]);
        }
    }
    printf("\n");
}

void libera(lista *l) {
    free(l->val);
    free(l);
}
