#include <stdio.h>
#include <stdlib.h>
#include "pacote.h"

Tpacket* createDataPacket (int ident_pac, int end_ori, int end_dest, int quant){

	Tpacket *p;
	p = (Tpacket*)malloc(sizeof(Tpacket));

	p -> tipo_pacote = DATA;
	p -> identificador_dado = ident_pac;
	p -> endereco_origem = end_ori;
	p -> endereco_destino = end_dest;
	p -> tamanho = quant;

	return p;
}

Tpacket* createACKPacket (int ident_pac, int end_ori, int end_dest){
	Tpacket *p;
	p = (Tpacket*)malloc(sizeof(Tpacket));

	p -> tipo_pacote = ACK;
	p -> identificador_dado = ident_pac;
	p -> endereco_origem = end_ori;
	p -> endereco_destino = end_dest;
	p -> tamanho = 0;
	p -> carga_util = NULL;

	return p;
}

Tpacket* clonePacket (Tpacket* pacote){
	Tpacket *clone;
	clone = (Tpacket*)malloc(sizeof(Tpacket));

	clone -> identificador_dado = 1;
	clone -> tipo_pacote = pacote -> tipo_pacote;
	clone -> endereco_origem = pacote -> endereco_origem;
	clone -> endereco_destino = pacote -> endereco_destino;
	clone -> tamanho = pacote -> tamanho;
	clone -> carga_util = (char*)malloc(pacote ->tamanho * sizeof(char));
	
	int i;
	for ( i = 0; i < pacote -> tamanho; i++){
		clone -> carga_util[i] = pacote -> carga_util[i];
	}

	 return clone;
}

void writeData (Tpacket *pacote, char* array, int tamanho){
		pacote -> carga_util = (char*)malloc(pacote->tamanho*sizeof(char));
		int i;
		for ( i = 0; i < pacote -> tamanho; i++){
			
			if (i > tamanho - 1){
				
				pacote -> carga_util[i-1] = '0';
			}
			else{
				//printf("%c\n", *array);
				pacote -> carga_util[i] = *array;
				array++;
			}
		}

	}

void printPacketInformation(Tpacket *pacote){
	if (pacote -> tipo_pacote == 0){
		printf("Packet type: DATA\n");
		printf("ID: %d\n", pacote -> identificador_dado);
		printf("Source Addres: %d\n", pacote -> endereco_origem);
		printf("Destination Addres: %d\n", pacote -> endereco_destino);
		printf("Payload Size: %d\n", pacote -> tamanho);
		printf("Payload: ");

		int i;
		for ( i = 0; i < pacote -> tamanho; i++ ) printf("%c ", pacote -> carga_util[i]);

		printf("\n");
	}

	else{
		printf("Packet type: ACK\n");
		printf("ID: %d\n", pacote -> identificador_dado);
		printf("Source Addres: %d\n", pacote -> endereco_origem);
		printf("Destination Addres: %d\n", pacote -> endereco_destino);
	}

}

void deletePacket (Tpacket *pacote){

	free(pacote -> carga_util);
	free(pacote);
}