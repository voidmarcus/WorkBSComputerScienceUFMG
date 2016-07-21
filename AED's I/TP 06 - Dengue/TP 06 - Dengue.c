# include <stdio.h>

int main(){

int cidades=0, i=0, j=0, k=0, l=0, x=0, y=0, teste=1;


while (scanf("%d", &cidades)&&cidades) {

    int matriz[cidades+1][cidades+1];

    for (i=0; i<=cidades; i++){
        for (j=0; j<=cidades; j++){
            matriz[i][j]=0;
        }
    }

    for (i=1; i<cidades; i++){
        scanf("%d %d",&x , &y);
        matriz[x][y]=1;
        matriz[y][x]=1;
    }


    int distancia=1;

    for (l=1; l<=cidades; l++)
    {
        for (i=1; i<=cidades; i++){
            for (j=1; j<=cidades; j++){
                if (matriz[i][j]==distancia){
                    for (k=1; k<=cidades; k++){
                        if (matriz[j][k]==1 && matriz[i][k]==0){
                            matriz[i][k]=(distancia+1);
                        }
                    }
                }
            }
        }
    distancia++;
    }

    int soma=0, cidade_posto=0, soma_antiga=999;

    for (i=1; i<=cidades; i++){
        for (j=1; j<=cidades; j++){
            soma+=matriz[i][j];
        }
        if (i==1){
            soma_antiga=soma;
            cidade_posto=i;
        }
        if (soma<soma_antiga){
            cidade_posto=i;
            soma_antiga=soma;
        }
        soma=0;
    }

    printf("Teste %d\n%d\n\n", teste++, cidade_posto);
}
return 0;
}
