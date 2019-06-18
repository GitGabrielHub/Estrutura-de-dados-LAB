#include <stdio.h>
#include <stdlib.h>
#include "listaEnc.h"

int main (void){

	int dado = 0;

	TListaEnc lista;
	TListaEnc clone;

	criarLista(&lista);

	if (listaVazia(lista)) printf("Vazia!\n");

	inserirElemento (&lista,10,1);
	inserirElemento (&lista,30,2);
	inserirElemento (&lista,20,2);
	inserirElemento (&lista,100,1);
	inserirElemento (&lista,300,2);
	
	inserirElemento (&lista,200,2);
	// (&lista,3,&dado);
	
	printf("Número eleminado: %d\n", dado);
	//removerPosicao (&lista,1,&dado);

	inserirElemento (&lista,0,2);
	inserirElemento (&lista,1,2);
	inserirElemento (&lista,2,2);
	inserirElemento (&lista,3,2);

	clone = clonar(lista);

	printf("Número eleminado: %d\n", dado);
	printf("Quantidade de elementos clone: %d\n", tamanhoLista(clone));
	printf("Quantidade de elementos original: %d\n", tamanhoLista(lista));

	printf("Lista original:\n");
	imprimir(lista);

	printf("Lista clone:\n");
	imprimir(clone);
	
	return 0;
}