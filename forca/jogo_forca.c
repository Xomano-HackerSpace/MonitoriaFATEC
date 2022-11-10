
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int letraJaChutada(char letra);

char palavra[20];
char chutes[20];
int erros = 0;

int palavraContemLetra(char letra)
{

  for (int j = 0; j < strlen(palavra); j++)
  {
    if (letra == palavra[j])
    {
      return 1;
    }
  }

  return 0;
}

int countErros()
{
  int erros = 0;

  for (int i = 0; i < erros; i++)
  {

    if (!palavraContemLetra(chutes[i]))
    {
      erros++;
    }
  }

  return erros;
}

int enforcou()
{
  return countErros() >= 5;
}

int ganhou()
{
  for (int i = 0; i < strlen(palavra); i++)
  {
    if (!letraJaChutada(palavra[i]))
    {
      return 0;
    }
  }

  return 1;
}

void abertura()
{
  printf("/****************/\n");
  printf("/ Jogo de Forca */\n");
  printf("/****************/\n\n");
}

void chutar()
{
  char chute;
  printf("Qual letra? ");
  scanf(" %c", &chute);

  if (palavraContemLetra(chute))
  {
    printf("Você acertou: a palavra tem a letra %c\n\n", chute);
  }
  else
  {
    printf("\nVocê errou: a palavra NÃO tem a letra %c\n\n", chute);
  }

  chutes[erros] = chute;
  erros++;
}

int letraJaChutada(char letra)
{
  int achou = 0;
  for (int j = 0; j < erros; j++)
  {
    if (chutes[j] == letra)
    {
      achou = 1;
      break;
    }
  }

  return achou;
}

void desenhaforca()
{

  int erros = countErros();

  printf("  _______       \n");
  printf(" |/      |      \n");
  printf(" |      %c%c%c  \n", (erros >= 1 ? '(' : ' '), (erros >= 1 ? '_' : ' '), (erros >= 1 ? ')' : ' '));
  printf(" |      %c%c%c  \n", (erros >= 3 ? '\\' : ' '), (erros >= 2 ? '|' : ' '), (erros >= 3 ? '/' : ' '));
  printf(" |       %c     \n", (erros >= 2 ? '|' : ' '));
  printf(" |      %c %c   \n", (erros >= 4 ? '/' : ' '), (erros >= 4 ? '\\' : ' '));
  printf(" |              \n");
  printf("_|___           \n");
  printf("\n\n");

  for (int i = 0; i < strlen(palavra); i++)
  {

    if (letraJaChutada(palavra[i]))
    {
      printf("%c ", palavra[i]);
    }
    else
    {
      printf("_ ");
    }
  }
  printf("\n");
}

void escolhepalavra()
{

  char palavras[10][20] = {
      "Palavra0",
      "Palavra1",
      "Palavra2",
      "Palavra3",
      "Palavra4",
      "Palavra5",
      "Palavra6",
      "Palavra7",
      "Palavra8",
      "Palavra9"};

  int randomico = rand() % 10;

  for (int i = 0; i < strlen(palavras[randomico]); i++)
  {

    palavra[i] = palavras[randomico][i];
  }
}

int main()
{

  abertura();
  escolhepalavra();

  do
  {
    desenhaforca();
    chutar();

  } while (!ganhou() && !enforcou());

  if (ganhou())
  {
    printf("\nParabéns, você ganhou!\n\n");
    printf("(▔▀ ‿ ▀ )ლ ▂▂⌇\n");
  }
  else
  {
    printf("\nPuxa, você foi enforcado!\n");
    printf("A palavra era **%s**\n\n", palavra);

    printf("(▄█▀ █▬█ █ ▀█▀\n");
  }

  return 0;
}
