#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<string.h>
#include <locale.h>
#include <windows.h>
/*fonte https://www.clubedohardware.com.br/forums/topic/1290480-campo-minado-em-c/*/

char campominado[20][20];
int cont,linha,coluna,i,j,k,flag,minas=100,jogada,acertos=0,cont=0; //Declaramos todas as variáveis que iremos usar... 100 bombas = totalmatriz * 25%

void gotoxy(int x,int y)//Função para forçar uma posição para impressão de texto
{
    COORD c; //Variavel de coordenada, lib windows https://learn.microsoft.com/pt-br/windows/console/coord-str
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);//transporta o prompt para a posição da coord do cmd.
}

int main(){
    setlocale(LC_ALL,""); //Método para evitar setar o locale de acordo com o locale do ambiente.
    srand(time(NULL)); //função que previne o rand de repetir a seed retirando as informações de hora do sistema de criação randomica.
    for(i=0;i<20;i++)
        for(j=0;j<20;j++)
            campominado[i][j]=0;

    do {
        int l = rand()%20;
        int c = rand()%20;
        if(campominado[l][c] != 'B'){
            campominado[l][c] = 'B'; //Função que atribui as bombas as posições da matriz, aleatóriamente.
            cont+=1;
        }
    } while (cont!=100);


    system("cls");
    printf("Colunas\n             0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19\n");
    printf("Linha 0 ->     |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   \n");
    printf("            ---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---\n");
    printf("Linha 1 ->     |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   \n");
    printf("            ---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---\n");
    printf("Linha 2 ->     |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   \n");
    printf("            ---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---\n");
    printf("Linha 3 ->     |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   \n");
    printf("            ---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---\n");
    printf("Linha 4 ->     |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   \n");
    printf("            ---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---\n");
    printf("Linha 5 ->     |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   \n");
    printf("            ---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---\n");
    printf("Linha 6 ->     |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   \n");
    printf("            ---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---\n");
    printf("Linha 7 ->     |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   \n");
    printf("            ---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---\n");
    printf("Linha 8 ->     |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   \n");
    printf("            ---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---\n");
    printf("Linha 9 ->     |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   \n");
    printf("            ---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---\n");
    printf("Linha 10->     |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   \n");
    printf("            ---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---\n");
    printf("Linha 11->     |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   \n");
    printf("            ---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---\n");
    printf("Linha 12->     |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   \n");
    printf("            ---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---\n");
    printf("Linha 13->     |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   \n");
    printf("            ---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---\n");
    printf("Linha 14->     |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   \n");
    printf("            ---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---\n");
    printf("Linha 15->     |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   \n");
    printf("            ---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---\n");
    printf("Linha 16->     |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   \n");
    printf("            ---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---\n");
    printf("Linha 17->     |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   \n");
    printf("            ---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---\n");
    printf("Linha 18->     |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   \n");
    printf("            ---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---\n");
    printf("Linha 19->     |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   \n");



    for(jogada=1;jogada<300;jogada++){ //Como são 100 bombas, o usuario precisa acertar 300 jogadas para ganhar...
        do{
            gotoxy(5,44);
            printf("                                            \n");
            printf("                                              ");
            gotoxy(5,44);
            printf("Informa a linha que voce quer jogar: ");
            scanf("%d",&linha);
            printf("     Informe a coluna que voce quer jogar: ");
            scanf("%d",&coluna);
        }while((linha<0||linha>19) || (coluna<0||coluna>19));
        if(campominado[linha][coluna]=='B'){/* condição se marcar o espaço que está a mina, o jogo acaba */
            printf("\n\nVoce pisou na mina!");
            printf("\n\nSeu total de acertos foi: %d", acertos);
            printf("\n\n       GAME OVER!");
            flag=1;
            imprimebomba();
            break;
        }
         else{
         campominado[linha][coluna]='X';/* condição se marcar um espaço sem mina, vai aparecer o X no tabuleiro */
         acertos+=1;
        }
        imprimematriz();
    }
    gotoxy(0,44);
    if(flag==0)printf("    Parabéns,  Você Venceu . . . !\n");
    getch();
    return 0;
}

void imprimematriz(){

    for(i=0;i<20;i++){                /* quantidade de linhas */
            k=13;                        /* primeira posição */
            for(j=0;j<20;j++){            /* quantidade de colunas */
                if(campominado[i][j] !='B')/* verifica se nessa posição não eh mina */
                {
                    gotoxy(k,i*2+2);      /* coloca o cursor nessa posição */
                    printf("%c",campominado[i][j]);/* imprime o que está nessa posição */
                }
                k+=4;                     /* vai para a proxima posição no desenho na tela */
            }
        }
}

void imprimebomba(){

    for(i=0;i<20;i++){                /* quantidade de linhas */
            k=13;                        /* primeira posição */
            for(j=0;j<20;j++){            /* quantidade de colunas */
                gotoxy(k,i*2+2);      /* coloca o cursor nessa posição */
                printf("%c",campominado[i][j]);/* imprime o que está nessa posição */
                k+=4;                     /* vai para a proxima posição no desenho na tela */
            }
        }
}
