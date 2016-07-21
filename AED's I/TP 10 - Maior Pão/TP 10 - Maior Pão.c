#include <stdio.h>
#include <stdlib.h>

int main(void) {
int i=0,sanduiches=0, pessoas=0, tamanho_total=0, tamanho_max=0, aux=0;

scanf ("%d", &pessoas);
scanf ("%d", &sanduiches);

int tamanho_sanduiches[sanduiches];

for (i=0; i<sanduiches; i++)
{
    scanf ("%d", &tamanho_sanduiches[i]);
    tamanho_total+=tamanho_sanduiches[i];
}

for(tamanho_max = tamanho_total/pessoas;tamanho_max!=0;tamanho_max--)
{
    for (i=0; i<sanduiches ;i++)
    {
        aux+=(tamanho_sanduiches[i]/tamanho_max);
    }

    if (aux==pessoas)
    {
        printf("%d", tamanho_max);
        break;
    }
    aux=0;
}

return EXIT_SUCCESS;
}
