#include <ctype.h>

void isnumeric ( char password[20] ){
	int num = 0, i=0;
		
	while( password[i] != '\0' ){
		i++;
		
		if (isdigit(password[i])){
		num++;
		}
		}
			
	if (num < 2 || i < 6){
	printf("NÃO\n");
	}
	
	else{
	printf("SIM\n");
}
}
