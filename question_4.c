#include <stdio.h>

int main (void){
	int i,n, vetor[100],novo[100];
	
	scanf("%d", &n);
	
	for (i = 0; i < n; i++){

	scanf("%d", &vetor[i]);	
	}
		
	for (i = 0; i < n; i++){

		if (i == 0){
			novo[0] = (vetor[0] + vetor[1]) / 2;
			}
		
		else if(i + 1 == n){
			novo[i] = (vetor[i] + vetor[i-1]) / 2;
			}

		else{
			novo[i] = (vetor[i] + vetor[i-1] + vetor[i+1]) / 3;
			}
		}
		
	for (i = 0; i < n; i++) printf("%d ", novo[i]);
	
	printf("\n");
	return 0;
}
