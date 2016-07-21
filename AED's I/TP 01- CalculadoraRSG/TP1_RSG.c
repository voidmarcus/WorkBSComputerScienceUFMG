#include <stdio.h>
main()
{
    int D=0,i;
    float rsg;
    scanf("%d",&D);
    int notas[D];
    for (i=0;i<D;i++)
    {
        scanf ("%d", &notas[i]);
        if (notas[i]>=0 && notas[i]<=39)
            notas[i]=0;else;
        if (notas[i]>39 && notas[i]<=59)
            notas[i]=1;else;
        if (notas[i]>59 && notas[i]<=69)
            notas[i]=2;else;
        if (notas[i]>69 && notas[i]<=79)
            notas[i]=3;else;
        if (notas[i]>79 && notas[i]<=89)
            notas[i]=4;else;
        if (notas[i]>89 && notas[i]<=100)
            notas[i]=5;
    }
    for (i=0;i<D;i++)
    {
        rsg+=notas[i]*4;       //creditos padronizados em 4. (???)
    }
    rsg=rsg/(4*D);
    printf("%1.2f",rsg);
}
