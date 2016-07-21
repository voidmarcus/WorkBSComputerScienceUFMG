# include <stdio.h>

int main(){

int cidades=0, i=0, j=0, k=0, l=0, x=0, y=0, teste=1;


    scanf("%d", &cidades);

    int matriz[cidades+1][cidades+1];

    for (i=0; i<=cidades; i++){
        for (j=0; j<=cidades; j++){
            matriz[i][j]=0;
        }
    }

    for (i=1; i<=cidades; i++){
        scanf("%d %d",&x , &y);
        matriz[x][y]=1;
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

    int contador=0;

    for (i=1; i<=cidades; i++){
        for (j=1; j<=cidades; j++){
            if (matriz[i][j]==0){
                contador++;
            }
        }
    }


    if (contador>0){
        printf("N");
    }else
    printf("S");

return 0;
}
