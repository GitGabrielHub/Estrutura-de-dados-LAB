#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int contar_numeros (char *lista){
    int quant = 0,i;

    for( i = 0; lista[i] != '\0'; i++){
        if ( isdigit(lista[i]) && (lista[i+1] == '\0' || lista[i+1] == ' ')) quant++;

        else if( lista[i] !=' ' && lista[i] != '\0' && !isdigit(lista[i])) return 0;

    }

    return quant;

}

int* lista_numero (char* lista, int* quantidade){

	if ((*quantidade = contar_numeros(lista)) == 0) return NULL;
    int* l = (int*) malloc(*quantidade * sizeof(int));
    int aux,cont=0,pos=0;
    char palavra[15];

    int i;
    for ( i = 0; lista[i] != '\0'; i++){
        if (isdigit(lista[i])){
            palavra[cont] = lista[i];
            cont++;
            if ( lista[i+1] == ' ' || lista[i+1] == '\0'){
                palavra[cont] = '\0';
                l[pos] = atoi(palavra);
                cont = 0;
                pos++;
            }
        }
       

    }
    return l;
}

int main(void){

    char list[100];
    int quant ;
    scanf("%[^\n]s", list);
    int *end_list = lista_numero(list,&quant);

    if (end_list == NULL){
        printf("String inválida\n");
        return 1;
    }

    printf("Quantidade de numeros = %d\n", quant);

    int i;
    printf("Lista final: ");
    for (i = 0; i < quant; i++) printf("%d ", end_list[i]);
    printf("\n");

    return 0;
}
