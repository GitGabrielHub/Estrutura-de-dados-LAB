typedef struct nolista
{
	int dado;
	struct  nolista *prox;
	
	
}no;

typedef no* TListaEnc;

void criarLista (TListaEnc* lista);

int listaVazia (TListaEnc lista);

int tamanhoLista (TListaEnc lista);

int inserirElemento(TListaEnc* lista, int dado, int posicao);

void imprimir (TListaEnc lista);

int removerPosicao (TListaEnc* lista, int posicao, int *eleminado);

TListaEnc clonar (TListaEnc lista);
