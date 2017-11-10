//=================== TP2 - Análise Numárica ===================================

//=================== Informações do aluno =====================================
// Nome: Marcus Vinicius de Oliveira
// Matricula: 2014144804
// Turma: tn1
// email: marcusvoliveira@dcc.ufmg.br
//==============================================================================
//==================== Observações =============================================
// O trabalho foi executado conforme os requisitos. Resalto que conforme orienta
// ção, não foram considerados os diretorios completo dos arquivos para realizar
// as operações, somente o seus nomes.
//==============================================================================
//==================== Instucoes de Uso=========================================
// O codigo foi construido e testado dentro da propia IDE do scilab.
// Basta executar o codigo e os resultados devem ser impresos no arquivo de sai
// da 'solucoes.sai', dentro da mesma pasta do arquivo '.sce'
//==============================================================================

// Função de Decomposição LU por eliminação de Gaus com pivotação parcial
// matriz -> Matriz que deseja decompor
// ordemMatriz -> Ordem da 'matriz' 

function [matriz, determinante, pivot] = decomposicao_lu (matriz,ordemMatriz)
    pivot = 1:n
    determinante = 1
    for j = 1:n-1
        [maxMatriz, p]=max(abs(matriz(j:ordemMatriz,j))) 
        p = p + j - 1
        if p ~= j 
            for linhas = 1:n
                t = matriz(j, linhas) 
                matriz(j, linhas) = matriz(p, linhas) 
                matriz(p, linhas) = t
            end
            m = pivot(j)
            pivot(j) = pivot(p)
            pivot(p) = m
            determinante = -determinante
        end
        determinante = determinante * matriz (j,j)
        if abs(matriz(j, j)) ~= 0
            r = 1 / matriz (j, j)
            for i = j + 1:n
                mult = matriz (i, j) * r
                matriz(i,j) = mult
                for col = j+1:n
                    matriz(i, col) = matriz(i, col) - mult * matriz(j, col)
                end
            end
        end
    end
    determinante = determinante * matriz(n,n)
endfunction

// Função de substituições sucessivas
// n -> Ordem da matriz triangular obtida a partir da deconposição LU
// matrizCoeficiente -> Matriz triangular obtida a partir da deconposição LU
// pivot -> Linhas pivot
function [y] = sub_sucessivas(n, matrizCoeficiente, termosIndependentes, pivot)
    y = zeros(n, 1)
    y(1) = termosIndependentes(pivot(1))
    for i = 2:n
        soma = 0
        for j = 1:i-1
            soma = soma + sum(matrizCoeficiente(i, j) * y(j))
        end
        y(i) = termosIndependentes(pivot(i)) - soma
    end
endfunction

// Função de substituições retroativas
// n Ordem da matrizCoeficiente
// matrizCoeficiente -> matriz triangular superior obtida da deconposição LU
// termosIndependentes -> obtidos a partir de sub_sucessivas
function [x] = sub_retroativas (n, matrizCoeficiente, termosIndependentes)
    x = zeros(n, 1)
    x(n) = termosIndependentes(n) / matrizCoeficiente(n, n)
    for i = n-1:-1:1
        soma = 0
        for j = i+1:n
            soma = soma + sum(matrizCoeficiente(i, j) * x(j))
        end
        x(i) = (termosIndependentes(i) - soma) / matrizCoeficiente(i, i)
    end
endfunction

// Abre arquivos de entrada e saida
entrada = file('open','sistemas.dat', 'old')
saida = mopen('solucoes.sai', 'w')

// Lê n da matriz e logo em seguida a matriz
n = read(entrada,1,1)
matriz = read(entrada, n,n)

// Calcula matrizLU e pivotLU
[matrizLU, determinanteLU, pivotLU] = decomposicao_lu (matriz,n)

// Lê a quantidade de vetores e para cada vetor, aplica sub_sucessivas e sub_re
// troativas. Logo em seguida, grava o resultado no arquivo de saida.
for vetores = 1:read(entrada,1,1)
    vetor = read(entrada, 1, n)
    y = sub_sucessivas(n, matrizLU, vetor, pivotLU)
    x = sub_retroativas(n, matrizLU, y)
    
    for j = 1:length(x)
        mfprintf(saida, '%8.2f ', x(j))
    end
    mfprintf(saida, '\n')  
end

// Fecha o aruivo de saida.
mclose(saida)


//==============================================================================
//=========================Bibliografia=========================================
// Bibliografia
// Algoritmos Numericos, Frederico Campos, 2001 - Paginas: 41(substituição suces
// siva),44(substituição retroativa), 62(decomposição LU)
// Apostila Introdução ao Matlab - Frederico Campos, 2013 - Paginas 94-99
//==============================================================================
