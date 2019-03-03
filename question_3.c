#include <stdio.h>

int main (void){
	
	int notas[10],i,contador = 0;
	double media = 0;

	
	for ( i = 0; i < 10; i++){ 
	
	scanf("%d",&notas[i]);
	media+= notas[i];
	}

	media /= 10;

	for (i = 0; i < 10; i++) if (notas[i] > media) contador++;

	
	printf("%.1lf\n", media);
	printf("%d\n",contador); 

	return 0;
}
