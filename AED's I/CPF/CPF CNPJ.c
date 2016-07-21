#include <stdio.h>

int verificar_cpf (int cpf)
{
        int d9=cpf%10,          d6=cpf/1000%10,     d3=cpf/1000000%10,      //Declara e define cada digito do CPF
            d8=cpf/10%10,       d5=cpf/10000%10,    d2=cpf/10000000%10,
            d7=cpf/100%10,      d4=cpf/100000%10,   d1=cpf/100000000;

        int auxd,auxu,dv,uv;

        auxd=d9*2+d8*3+d7*4+d6*5+d5*6+d4*7+d3*8+d2*9+d1*10;                     //soma dos produtos dos nove digitos utilizando peso dois para unidade, peso 3 para dezena, peso 4 para centena e assim sucessivamente

        if (auxd%11>1)                                                          //A dezena do número verificador é 0 caso o resto da divisão por 11 da soma dos produtos seja 0 ou 1; caso contrario a dezena corresponde  a subtrair de 11 o resto da divisão por 11 da soma dos produtos
            dv=11-(auxd%11);
        else
            dv=0;

        auxu=dv*2+d9*3+d8*4+d7*5+d6*6+d5*7+d4*8+d3*9+d2*10+d1*11;               //Soma dos produtos dos dez digitos, onde o digito menos significativo passa a ser a dezena dos digitos verificadores, utilizando os seguintes pesos: 2, 3, 4, 5, 6, 7, 8, 9, 10, 11

        if (auxu%11>1)                                                          //A unidade do número verificador é 0 caso o resto da divisão da soma dos produtos seja 0 ou 1; caso contrário a unidade corresponde a 11 menos o resto da divisão por 11 da soma dos produtos
            uv=11-(auxu%11);
        else
            uv=0;

        printf("O CPF com digito verificador, 'e: %d-%d%d\n",cpf, dv,uv);
}


main()
{
    int cpf, i;
    char cont;

    do
    {
        do                                                                       //Verifica se o usuario digitou 9 digitos.
        {
            printf("Digite os nove primeiros numeros do CPF:");
            scanf ("%d", &cpf);
            int aux=cpf;
            for (i=0; aux!=0; i++)
            {
            aux=aux/10;
            }

            if (i!=9)
                printf("Voce digitou errado, tente novamente.\n");
        }while (i!=9);

    fflush(stdin);

    verificar_cpf(cpf);                                                             //Verifica se usuario desejar continuar
    printf("Deseja verificar outro CPF? (Digite S ou s para continuar)");
    cont= getchar();

    }while (cont=='s'| cont=='S');


    system ("pause");
}
