#include<stdio.h>
#include<stdlib.h>

//O que é um vetor e uma matriz?

//Um vetor é um array de mesmo tipo, unidimensional de tamanho pré especificado.

//Uma matriz é um é um array de mesmo tipo, multidimensional ([].[] -> Bidimensional; [].[].[] -> Tridimensional; etc...) de tamanho e dimensão pré especificado.
//Não é errado dizer que uma matriz é um vetor de vetores, porque..

//Qual a diferença entre um vetor e uma matriz?
    //Na representação lógica do seu programa, a estrutura.
    //Na memória... NENHUMA!

/* Quando criamos uma matriz (Matriz[qtd_linhas]x[qtd_colunas] = tamanho total do vetor) o computador irá representar esse vetor gigante como sendo uma matriz (para fins lógicos).
    Porém quando tentamos acessar uma posição específica de uma matriz, o computador irá calcular a posição desejada dentro do vetor (ex. Consulta = Matriz[2][5] ==== Posição 10 do vetor).
*/


int main(void){
    char matriz[20][20];
    matriz[10][0] = 'a';

    return 0;
}


