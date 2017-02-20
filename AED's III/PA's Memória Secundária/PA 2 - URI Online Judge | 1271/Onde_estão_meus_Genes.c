#include <stdio.h>

int main() {
	int n = 0, r = 0, q = 0, linha_q;
	int teste = 1;
	int i = 0,j = 0;

	while (1) {
		scanf("%d", &n);
		if (n == 0){
			break;
		}

		scanf("%d", &r);
		int inversao_1[r];
		int inversao_2[r];

		for (i = 0; i < r; i++)
			scanf("%d %d", &inversao_1[i], &inversao_2[i]);

		scanf("%d", &q);

		printf("Genome %d\n", teste);
		teste++;

		for (i = 0; i < q; i++) {
			scanf("%d", &linha_q);

			for (j = 0; j < r; j++)
				if (linha_q <= inversao_2[j] && linha_q >= inversao_1[j] ) {
					linha_q = inversao_1[j] + inversao_2[j] - linha_q;
					//printf("%d = %d + %d - %d, \n", linha_q, inversao_1[j],
					//		inversao_1[j], linha_q);
				}
			printf("%d\n", linha_q);
		}
	}

	return 0;
}
