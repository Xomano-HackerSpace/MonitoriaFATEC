#include<stdio.h>
#include<stdlib.h>

//O que � um vetor e uma matriz?

//Um vetor � um array de mesmo tipo, unidimensional de tamanho pr� especificado.

//Uma matriz � um � um array de mesmo tipo, multidimensional ([].[] -> Bidimensional; [].[].[] -> Tridimensional; etc...) de tamanho e dimens�o pr� especificado.
//N�o � errado dizer que uma matriz � um vetor de vetores, porque..

//Qual a diferen�a entre um vetor e uma matriz?
    //Na representa��o l�gica do seu programa, a estrutura.
    //Na mem�ria... NENHUMA!

/* Quando criamos uma matriz (Matriz[qtd_linhas]x[qtd_colunas] = tamanho total do vetor) o computador ir� representar esse vetor gigante como sendo uma matriz (para fins l�gicos).
    Por�m quando tentamos acessar uma posi��o espec�fica de uma matriz, o computador ir� calcular a posi��o desejada dentro do vetor (ex. Consulta = Matriz[2][5] ==== Posi��o 10 do vetor).
*/


int main6(void){
    char matriz[2][4] = {1,2,3,4,5,6,7,8};

    char vetor[8] = {1,2,3,4,5,6,7,8};
    printf(vetor);
    printf(matriz);

    return 0;
}


