# include <stdio.h>

int main(void)
{
    int quantidade_dados=0, soma=0, contador=0, i=0, j=0;
    scanf ("%d", &quantidade_dados);
    int valores[quantidade_dados];
    
    for (i=0; i<quantidade_dados; i++)
    {
        scanf("%d", &valores [i]);
    }
    
    for (i=0; i<quantidade_dados; i++)
    {   
        soma = valores[i];
        if (soma%8==0)
            {
                 contador++;            
            }
        for (j=i+1; j<quantidade_dados; j++)
        {
            soma += valores[j];
            if (soma%8==0)
            {
                 contador++;            
            }
        }
        soma=0;
    }
    printf("%d", contador);
    
    //system("pause");
}
