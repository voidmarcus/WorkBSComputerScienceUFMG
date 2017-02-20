
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n = 0;

	int i =0;

	printf("Teste\n");
	//while (scanf("%d", n) != EOF){
		scanf("%d", n);
		printf("Teste\n");
		int loop[n];
		int pico = 0;

		printf("Teste\n");

		for (i = 0; i < n; ++i) {
			scanf("%d", loop[i]);
		}

		if ((loop[n - 1] > loop[0] && loop[1] > loop[0]) || (loop[n - 1] < loop[0] && loop[1] < loop[0])){
			pico++;
		}

		if ((loop[n-2] > loop[n-1] && loop[0]>loop[n-1]) || (loop[n-2] < loop[n-1] && loop[0]<loop[n-1])){
			pico++;
		}

		for (int i = 1; i < n -1; ++i) {
			if ((loop [i-1]>loop[i] && loop[i+1]>loop[i]) || (loop[i-1] < loop[i] && loop[i+1] < loop[i])){
				pico++;
			}
		}

		printf("%d\n", pico);

	//}
	return EXIT_SUCCESS;
}
