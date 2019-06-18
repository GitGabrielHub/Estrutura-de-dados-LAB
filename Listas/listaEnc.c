#include <stdio.h>
#include <stdlib.h>
#include "listaEnc.h"

void criarLista(TListaEnc* lista){ *lista = NULL;}

int listaVazia (TListaEnc lista) {return lista == NULL;}

int tamanhoLista (TListaEnc lista){
	int contador = 0;

	if (listaVazia(lista)) return 0;

	int i;
	while (lista != NULL) {
		contador ++;
		lista = lista -> prox;
	}
	return contador;
}

int inserirElemento (TListaEnc* lista, int dado, int posicao){
	TListaEnc novo = NULL;
	
	if (listaVazia(*lista)){
		if(posicao != 1) return 0;
		if (((novo = (no*) malloc (sizeof(no)))) == NULL) return 0;
		
		novo -> dado = dado;
		novo -> prox = NULL;
		*lista = novo;

		return 1;
	}

	if (posicao == 1){
		if (((novo = (no*) malloc (sizeof(no)))) == NULL) return 0;
		novo -> dado = dado;
		novo -> prox = *lista;
		*lista = novo;

		return 1;
	}

	int contador = 1;
	TListaEnc aux = NULL;
	aux = *lista; 

	while ((contador < posicao - 1) && (aux != NULL)){
		aux = aux -> prox;
		contador++;

	}

	if (aux == NULL )return 0;

	if (((novo = (no*) malloc (sizeof(no)))) == NULL) return 0;

	novo -> dado = dado;
	novo -> prox = aux -> prox;
	aux -> prox = novo;

	return 1;
}

void imprimir (TListaEnc lista){
	while (lista != NULL){
		printf("Elemento: %d\n", lista -> dado);
		lista = lista -> prox;
	}
}

int removerPosicao (TListaEnc* lista, int posicao, int *eleminado){
	TListaEnc aux = NULL, anterior = NULL;

	if (listaVazia(*lista)) return 0;

	aux = *lista;

	int i;
	for (i = 0; i < posicao - 1; i++){
		anterior = aux;
		aux = aux -> prox;
	}

	if (aux == NULL) return 0;

	*eleminado = aux -> dado;

	if (posicao == 1) *lista = aux -> prox;
	else anterior -> prox = aux -> prox;

	free(aux);
	return 1;
}

TListaEnc clonar (TListaEnc lista){
	TListaEnc aux = NULL;
	if (listaVazia(lista)) return 0;

	while (lista != NULL){
		aux = (no*) malloc (sizeof(no));
		aux -> dado = lista -> dado;
		
		lista = lista -> prox;

		aux -> prox = lista -> prox;
		aux = aux -> prox;

	}
	printf("AUx\n");
	imprimir(aux);
	return aux;
	
	
}