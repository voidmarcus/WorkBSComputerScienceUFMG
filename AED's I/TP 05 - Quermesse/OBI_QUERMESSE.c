# include <stdio.h>

main(){
int n, i, j=0, aux;
do
{
    scanf("%d", &n); int v[n];
    if (n==0)
        break;
    printf ("Teste %d\n",++j);
    for (i=1; i<=n; i++)
    {
        scanf("%d", &v[i]);
        if (v[i]==i)
            aux=i;
    }
    printf ("%d\n", aux);
}while (n!=0);
}
