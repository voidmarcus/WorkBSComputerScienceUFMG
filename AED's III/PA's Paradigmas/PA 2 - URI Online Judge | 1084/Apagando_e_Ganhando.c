/*
 ============================================================================
 Name        : Apagando e Ganhando
 Author      : Marcus Vinicius de Oliveira
 Copyright   : AEDs 3
 Description : PA Apagando e Ganhando
 ============================================================================
 */

#include <stdio.h>

#define MAX 110000

int main() {

	char stack[MAX], num;
	int top, del, n, d, i;

	while (scanf("%d%d", &n, &d) && (n + d)) {

		del = 0;

		for (i = 0, top = -1; i < n; i++) {
			scanf(" %c", &num);

			while (top > -1 && del < d && num > stack[top]) {

				top--;

				del++;
			}
			if (top + 1 < n - d)
				stack[++top] = num;
		}

		stack[++top] = '\0';

		printf("%s\n", stack);
	}
	return 0;
}