/*
 ============================================================================
 Name        : ArrayHash.c
 Author      : Marcus Vinicius de Oliveira
 Version     : 1.0
 Copyright   : AEDs 3 - PA 1.3(Extra)
 Description : URI Online Judge | 1257
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int i;
	int n;
	int l;
	int valor=0;

	scanf("%d", & n);
	scanf("%d", &l);

	char string [l][50];

	printf("%Teste");

	for(i=0; i<l; i++){
		scanf("%s", string[1]);
		printf("i=%d\n", i);
		printf("%s\n", string[1]);
	}

	while(string[l]){
		printf("%s\n", string[1]);
	}

	printf("%d", valor);

	return EXIT_SUCCESS;
}
