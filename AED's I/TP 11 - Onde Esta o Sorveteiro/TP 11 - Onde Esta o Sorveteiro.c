#include <stdio.h>
#include <stdlib.h>

int main(void) {
int tamanho_praia=0, n_sorveteiros=0,i=0,j=0,k=0,ini=0,fim=0, estado=0, contador=0;


do
{
	scanf("%d %d", &tamanho_praia, &n_sorveteiros);
	if (tamanho_praia==0 && n_sorveteiros==0)
	    break;
	tamanho_praia++;

	int praia[tamanho_praia];

	for (i=0; i<tamanho_praia; i++)
	{
		praia[i]=0;
	}

	for (i=0; i<n_sorveteiros; i++)
	{
		scanf ("%d %d", &ini, &fim);
		for (k=ini; k<fim; k++)
		{
			praia[k]=1;
		}
	}

	printf ("Teste %d\n",++j);

	for (i=0; i<tamanho_praia;i++)
	{
		if (praia[i]!=estado)
			{
			if (estado==0)
				{
				ini=i;
				}
			if (estado==1)
				{
				fim=i;
				}
			contador++;
			estado=praia[i];

			if (contador%2==0)
				{
				printf ("%d %d\n", ini, fim);
				}
			}
	}
	printf ("\n");

}while (tamanho_praia!=0 && n_sorveteiros!=0);
	return EXIT_SUCCESS;
}
