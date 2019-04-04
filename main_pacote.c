#include <stdio.h>
#include <stdlib.h>
#include "pacote.h"
int main (void){

	int ident_dado = 1;
	int end_o = 50;
	int end_d = 80;
	int tamanho = 10;
	char lista[11] = {'1','2','3','4','5','6','7','8','9','\n'};
	Tpacket *pacote, *clone, *ack;

	pacote = createDataPacket (ident_dado,end_o,end_d,tamanho);
	ack = createACKPacket (ident_dado, end_o, end_d);
	
	writeData (pacote, lista,tamanho);
    clone = clonePacket(pacote);
	printPacketInformation(pacote);
	printf("\n");
	printPacketInformation(clone); // printando CLONE
	printf("\n");
	printPacketInformation(ack);

	deletePacket(pacote);
	deletePacket(ack);
	deletePacket(clone);
	return 0;
}
