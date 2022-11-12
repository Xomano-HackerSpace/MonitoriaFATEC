#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int jachutou(char letra);

char palavrasecreta[20];
char chutes[26];
int chutesdados = 0;

int letraexiste(char letra)
{

  for (int j = 0; j < strlen(palavrasecreta); j++)
  {
    if (letra == palavrasecreta[j])
    {
      return 1;
    }
  }

  return 0;
}

int chuteserrados()
{
  int erros = 0;

  for (int i = 0; i < chutesdados; i++)
  {

    if (!letraexiste(chutes[i]))
    {
      erros++;
    }
  }

  return erros;
}

int enforcou()
{
  return chuteserrados() >= 5;
}

int ganhou()
{
  for (int i = 0; i < strlen(palavrasecreta); i++)
  {
    if (!jachutou(palavrasecreta[i]))
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

void chuta()
{
  char chute;
  printf("Qual letra? ");
  scanf(" %c", &chute);

  if (letraexiste(chute))
  {
    printf("Você acertou: a palavra tem a letra %c\n\n", chute);
  }
  else
  {
    printf("\nVocê errou: a palavra NÃO tem a letra %c\n\n", chute);
  }

  chutes[chutesdados] = chute;
  chutesdados++;
}

int jachutou(char letra)
{
  int achou = 0;
  for (int j = 0; j < chutesdados; j++)
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

  int erros = chuteserrados();

  printf("  _______       \n");
  printf(" |/      |      \n");
  printf(" |      %c%c%c  \n", (erros >= 1 ? '(' : ' '), (erros >= 1 ? '_' : ' '), (erros >= 1 ? ')' : ' '));
  printf(" |      %c%c%c  \n", (erros >= 3 ? '\\' : ' '), (erros >= 2 ? '|' : ' '), (erros >= 3 ? '/' : ' '));
  printf(" |       %c     \n", (erros >= 2 ? '|' : ' '));
  printf(" |      %c %c   \n", (erros >= 4 ? '/' : ' '), (erros >= 4 ? '\\' : ' '));
  printf(" |              \n");
  printf("_|___           \n");
  printf("\n\n");

  for (int i = 0; i < strlen(palavrasecreta); i++)
  {

    if (jachutou(palavrasecreta[i]))
    {
      printf("%c ", palavrasecreta[i]);
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

    palavrasecreta[i] = palavras[randomico][i];
  }
}

int main()
{

  abertura();
  escolhepalavra();

  do
  {

    desenhaforca();
    chuta();

  } while (!ganhou() && !enforcou());

  if (ganhou())
  {
    printf("\nParabéns, você ganhou!\n\n");

    printf("(▔▀ ‿ ▀ )ლ ▂▂⌇\n");
  }
  else
  {
    printf("\nPuxa, você foi enforcado!\n");
    printf("A palavra era **%s**\n\n", palavrasecreta);

    printf("(▄█▀ █▬█ █ ▀█▀\n");
  }

  return 0;
}