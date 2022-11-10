#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<string.h>
#include <locale.h>
#include <windows.h>
/*fonte https://www.clubedohardware.com.br/forums/topic/1290480-campo-minado-em-c/*/

void gotoxy(int x,int y)//Função para forçar uma posição para impressão de texto
{
    COORD c; //Variavel de coordenada, lib windows https://learn.microsoft.com/pt-br/windows/console/coord-str
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);//transporta o prompt para a posição da coord.
}
int main(){
    setlocale(LC_ALL,""); //Método para evitar setar o locale de acordo com o locale do ambiente.
    srand(time(NULL)); //função que previne o rand de repetir a seed.
    char campominado[5][5],cminado[5][5];
    int linha,coluna,i,j,k,flag=50,minas,nivel,jogada;
    printf("\n\n---------------------BEM VINDO AO CAMPO MINADO 2.0---------------------");/*//Criação do menu*/
    printf("\n\nEscolha um nível de dificuldade:\n\n(1) - fácil \n(2) - difícil \n(3) - Impossível: \n\n     -%c ",16);
    do{
        scanf("%d",&nivel);
    }while(nivel <1 || nivel > 3);
    for(i=0;i<5;i++)/*//criação do tabuleiro que aparece na tela*/
        for(j=0;j<5;j++)
            campominado[i][j]=0;

    if(nivel==1){
        printf("\n\nNeste nivel ha 5 minas no tabuleiro,boa sorte!     tecle ");
        minas=5;
    }
    else{
        if(nivel==2){
            printf("\n\nNeste nivel ha 12 minas no tabuleiro,boa sorte!     tecle ");
            minas = 12;
        }
        else{
            printf("\n\nNeste nivel ha 24 minas no tabuleiro,boa sorte!     tecle ");
            minas = 24;
        }
    }

    for(linha=0;linha<minas;linha++)
        campominado[rand()%5][rand()%5] = '*'; /*https://www.tutorialspoint.com/c_standard_library/c_function_rand.htm*/


    system("cls");
    printf("\n\n                  Colunas\n             0   1   2   3   4\n");
    printf("Linha 0 ->     |   |   |   |   \n");
    printf("            ---+---+---+---+---\n");
    printf("Linha 1 ->     |   |   |   |   \n");
    printf("            ---+---+---+---+---\n");
    printf("Linha 2 ->     |   |   |   |   \n");
    printf("            ---+---+---+---+---\n");
    printf("Linha 3 ->     |   |   |   |   \n");
    printf("            ---+---+---+---+---\n");
    printf("Linha 4 ->     |   |   |   |   \n");
    for(jogada=1;jogada<4;jogada++){/* laço para controlar o nº de jogadas */
        do{
            gotoxy(5,15);
            printf("                                            \n");
            printf("                                              ");
            gotoxy(5,15);
            printf("Informa a linha que voce quer jogar: ");
            scanf("%d",&linha);
            printf("     Informe a coluna que voce quer jogar: ");
            scanf("%d",&coluna);
        }while((linha<0||linha>4) || (coluna<0||coluna>4));
        if(campominado[linha][coluna]=='*'){/* condição se marcar o espaço que está a mina, o jogo acaba */
            printf("\n\nVoce pisou na mina, buuummmm!");
            printf("\n\n       GAME OVER");
            flag=1;
            break;
        }
         else{
         campominado[linha][coluna]='X';/* condição se marcar um espaço sem mina, vai aparecer o X no tabuleiro */
        }
        for(i=0;i<5;i++){                /* quantidade de linhas */
            k=13;                        /* primeira posição */
            for(j=0;j<5;j++){            /* quantidade de colunas */
                if(campominado[i][j] !='*')/* verifica se nessa posição não eh mina */
                {
                    gotoxy(k,i*2+4);      /* coloca o cursor nessa posição */
                    printf("%c",campominado[i][j]);/* imprime o que está nessa posição */
                }
                k+=4;                     /* vai para a proxima posição no desenho na tela */
            }
        }
    }
    gotoxy(0,22);
    if(flag==0)printf("    Parabéns,  Você Venceu . . . !\n");
    printf("\n          Finalizar . . . !\n\n");
    getch();
    return 0;
}
