#define ACK 1
#define DATA 0
typedef struct packet
{
	int identificador_dado;
	char tipo_pacote;
	int endereco_origem;
	int endereco_destino;
	char* carga_util;
	int tamanho;
	
}Tpacket;

Tpacket* createDataPacket (int ident_pac, int end_ori, int end_dest, int quant);
Tpacket* createACKPacket (int ident_pac, int end_ori, int end_dest);
Tpacket* clonePacket (Tpacket* pacote);
void writeData (Tpacket *pacote, char* array, int tamanho);
void printPacketInformation(Tpacket *pacote);
void deletePacket (Tpacket *pacote);

