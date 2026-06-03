#include "cadastros.h"
#include <stdio.h>

int main() {

  int opcao;

  do {

    printf("\n===== SISTEMA DE CADASTROS ESCOLARES =====\n");
    printf("1 - Cadastrar aluno\n");
    printf("2 - Listar alunos\n");
    printf("3 - Cadastrar professor\n");
    printf("4 - Listar professores\n");
    printf("5 - Cadastrar funcionário\n");
    printf("6 - Listar funcionários\n");
    printf("0 - Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    switch (opcao) {

    case 1:
      cadastro_alunos();
      break;

    case 2:
      listar_alunos();
      break;

    case 3:
      cadastro_professores();
      break;

    case 4:
      listar_professores();
      break;

    case 5:
      cadastro_funcionarios();
      break;

    case 6:
      listar_funcionarios();
      break;

    case 0:
      printf("\nEncerrando sistema...\n");
      break;

    default:
      printf("\nOpção inválida!\n");
      break;
    }

  } while (opcao != 0);

  return 0;
}