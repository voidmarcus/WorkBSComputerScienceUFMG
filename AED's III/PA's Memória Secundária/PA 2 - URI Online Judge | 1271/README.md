<span>URI Online Judge | 1271</span>
Onde estão meus Genes
=====================

Por Vinícius 
Fortuna ![](https://urionlinejudge.r.worldssl.net/gallery/images/flags/br.gif) Brasil

**Timelimit: 3**

Uma maneira que os cientistas tem para tentar medir como uma espécie 
evoluiu para outra é investigando como o genoma do ancestral se 
modificou para se transformar nesta outra espécie. Espécies intimamente 
relacionadas têm vários genes em comum e verifica-se que uma boa maneira 
de compará-las é através da comparação de como os genes comuns mudaram 
de lugar.

Uma das mutações mais comuns que alteram a ordem dos genes de genomas é 
a inversão. Se modelarmos um genoma como uma sequência de N genes sendo 
cada gene um número inteiro de 1 a N,então uma inversão é uma mutação 
que altera o genoma revertendo a ordem de um bloco de genes 
consecutivos. A inversão pode ser descrita por dois índices (i, j), (1 ≤ 
i ≤ j ≤ N), indicando que ela inverte a ordem dos genes dentro de 
índices de i até j.

Assim, quando isto é aplicado para um genoma \[g1,. . . , gi-1, gi , 
gi+1,. . . , gj-1, gj , gj+1,. . . , gN\], obtém-se o genoma \[g1,. . . 
, gi-1, gj , gj-1,. . . , gi+1, gi , gj+1,. . . , gN\]. Como um exemplo, 
a inversão de (3, 6), aplicado à genoma \[1, 2, 3, 4, 5, 6, 7\] dá \[1, 
2, 6, 5, 4, 3, 7\]. Se depois que a inversão (1, 3) é aplicada, obtém-se 
o genoma \[6, 2, 1, 5, 4, 3, 7\].

Um cientista que está estudando a evolução de uma espécie deseja tentar 
uma série de inversões no genoma desta espécie. Em seguida, ele quer 
consultar a posição final de vários genes. Será que você aceita o 
desafio de ajudá-lo?

Entrada
-------

A entrada contém vários casos de teste. A primeira linha de um caso de 
teste contém um inteiro **N** indicando o número de genes no genoma (1 ≤ 
**N** ≤ 50000). Você pode supor que o ordem inicial dos genes é a 
sequência de números inteiros de 1 a **N** em ordem crescente. A segunda 
linha de um caso de teste contém um inteiro **R** (0 ≤ **R** ≤ 1000) que 
indica o número de inversões a serem aplicadas ao genoma. Então, **R** 
linhas seguem, cada uma contendo dois inteiros **i**, **j** (1 ≤ **i** ≤ 
**j** ≤ **N**), separados por um único espaço, o qual indicam os dois 
índices que definem a inversão correspondente. Após a descrição das 
inversões há uma linha contendo um inteiro **Q** (0 ≤ **Q** ≤ 100), que 
indica o número de consultas para os genes, seguido de **Q** linhas, 
onde cada linha contém um inteiro representando um gene cuja posição 
final você deve determinar.
O final da entrada é indicada por **N** = 0.

Saída
-----

Para cada caso de teste da entrada seu programa deve produzir **Q** + 1 
linhas de saída. A primeira linha deve conter a string "**Genome**", 
seguido do número do caso de teste. As seguintes **Q** linhas devem 
conter um número inteiro, cada um representando as respostas das 
consultas.



<table>
<thead>
<tr>
<td>
Exemplo de Entrada

</td>
<td>
Exemplo de Saída

</td>
</tr>
</thead>
<tbody>
<tr>
<td class="division">
9
1
3 6
4
1
3
5
1
5
2
1 2
1 5
2
5
2
0

</td>
<td>
Genome 1
1
6
4
1
Genome 2
1
5

</td>
</tr>
</tbody>
</table>

ACM/ICPC South America Contest 2005


