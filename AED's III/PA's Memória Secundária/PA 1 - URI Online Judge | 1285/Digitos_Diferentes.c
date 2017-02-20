/*
 ============================================================================
 Name        : dígitosDiferentes.c
 Author      : Marcus Vinicius de Oliveira
 Version     :1.4
 Copyright   : AEDs 3 - PA 2.1
 Description : URI Online Judge | 1285 -PA 2.1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numValido(int x) {
	int d = 0;
	int valor[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	if (x == 0) {
		return 0;
	}

	if (x > 5000) {
		return 0;
	}

	while (x != 0) {
		d = x % 10;
		x = x / 10;

		valor[d] = valor[d] + 1;

		//printf("%d R 10=%d\n", x, d);
		if (valor[d] > 1) {
			return 0;
		}
	}

	return 1;
}

int main(void) {

	int i = 0;
	int n = 0;
	int m = 0;
	int r = 0;

	while (r = 0, scanf("%d %d", &n, &m) != EOF) {
		for (i = n; i <= m; i++) {
			if (numValido(i) != 0) {
				//printf("%d\n", i);
				r++;
			}
		}

		printf("%d\n", r);
	}

}
