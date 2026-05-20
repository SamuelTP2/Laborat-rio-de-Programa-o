#include <stdio.h>

#define MAX 5

struct Filme {
  char nome[50];
  int nota;
};

struct Filme filmes[MAX];
int total = 0;

void cadastrarFilme() {

  if (total < MAX) {

    printf("Nome do filme: ");
    scanf(" %[^\n]", filmes[total].nome);

    while (1) {
      printf("Nota do filme (0 a 10): ");
      scanf("%d", &filmes[total].nota);

      if (filmes[total].nota >= 0 && filmes[total].nota <= 10) {
        break;
      } else {
        printf("Nota invalida!\n");
      }
    }

    total++;
    printf("Filme cadastrado!\n");

  } else {
    printf("Limite de filmes atingido!\n");
  }
}

void listarFilmes() {

  int i;
  int soma = 0;

  if (total == 0) {
    printf("Nenhum filme cadastrado.\n");
  } else {

    printf("\n--- LISTA DE FILMES ---\n");

    for (i = 0; i < total; i++) {

      printf("%d. %s - Nota: %d\n", i + 1, filmes[i].nome, filmes[i].nota);

      soma += filmes[i].nota;
    }

    printf("Media das notas: %.2f\n", (float)soma / total);
  }
}

int main() {

  int opcao;

  while (1) {

    printf("\n===== CATALOGO DE FILMES =====\n");
    printf("1 - Cadastrar filme\n");
    printf("2 - Listar filmes\n");
    printf("3 - Sair\n");
    printf("Escolha: ");
    scanf("%d", &opcao);

    switch (opcao) {

    case 1:
      cadastrarFilme();
      break;

    case 2:
      listarFilmes();
      break;

    case 3:
      printf("Programa encerrado.\n");
      return 0;

    default:
      printf("Opcao invalida!\n");
    }
  }

  return 0;
}