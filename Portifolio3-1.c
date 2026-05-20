/* 3 - Controle de Biblioteca

Exercício de Linguagem C
Escolher 2 opções da lista abaixo e criar 2 programas em Linguagem C.
Cada programa deve ter:
1. struct
2. if/else
3. while
4. for
5. switch
6. Funções
7. Menu de opções
8. Cadastro de dados
9. Listagem dos dados cadastrados
10. Algum cálculo ou validação

3. Controle de Biblioteca
Criar um programa para cadastrar livros.
Pode ser pedido:
1. Título do livro
2. Autor do livro
3. Ano de publicação
4. Quantidade disponível
5. Verificar se o livro está disponível
6. Listar livros cadastrados
7. Buscar livros publicados após determinado ano
Regra:
Quantidade maior que 0: disponível
Quantidade igual a 0: indisponível*/

#include <stdio.h>

#define limite 100

struct Livro {

  char titulo[100];
  char autor[100];
  int anoPublicacao;
  int qntDisponivel;
};

struct Livro livros[limite];

int totalLivros = 0;

void cadastrarLivro() {

  if (totalLivros >= limite) {
    printf("\nLimite de livros atingido!\n");
    return;
  }

  printf("\n=== Cadastro de Livro ===\n");

  printf("Titulo: ");
  scanf("%s", livros[totalLivros].titulo);

  printf("Autor: ");
  scanf("%s", livros[totalLivros].autor);

  printf("Ano de Publicacao: ");
  scanf("%d", &livros[totalLivros].anoPublicacao);

  while (1) {

    printf("Quantidade Disponivel: ");
    scanf("%d", &livros[totalLivros].qntDisponivel);

    if (livros[totalLivros].qntDisponivel >= 0) {
      break;
    } else {
      printf("Quantidade invalida!\n");
    }
  }

  totalLivros++;

  printf("\nLivro cadastrado com sucesso!\n");
}

void listarLivros() {

  int i;

  if (totalLivros == 0) {
    printf("\nNenhum livro cadastrado.\n");
    return;
  }

  printf("\n=== Lista de Livros ===\n");

  for (i = 0; i < totalLivros; i++) {

    printf("\nLivro %d\n", i + 1);
    printf("Titulo: %s\n", livros[i].titulo);
    printf("Autor: %s\n", livros[i].autor);
    printf("Ano de Publicacao: %d\n", livros[i].anoPublicacao);
    printf("Quantidade Disponivel: %d\n", livros[i].qntDisponivel);

    if (livros[i].qntDisponivel > 0) {
      printf("Status: Disponivel\n");
    } else {
      printf("Status: Indisponivel\n");
    }
  }
}

void buscarPorAno() {

  int anoBusca;
  int i;
  int encontrou = 0;

  printf("\nDigite o ano: ");
  scanf("%d", &anoBusca);

  printf("\n=== Livros publicados apos %d ===\n", anoBusca);

  for (i = 0; i < totalLivros; i++) {

    if (livros[i].anoPublicacao > anoBusca) {

      printf("\nTitulo: %s\n", livros[i].titulo);
      printf("Autor: %s\n", livros[i].autor);
      printf("Ano: %d\n", livros[i].anoPublicacao);

      encontrou = 1;
    }
  }

  if (encontrou == 0) {
    printf("Nenhum livro encontrado.\n");
  }
}

int main() {

  int opcao;

  while (1) {

    printf("\n======= MENU =======\n");
    printf("1 - Cadastrar Livro\n");
    printf("2 - Listar Livros\n");
    printf("3 - Buscar por Ano\n");
    printf("4 - Sair\n");
    printf("====================\n");

    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {

    case 1:
      cadastrarLivro();
      break;

    case 2:
      listarLivros();
      break;

    case 3:
      buscarPorAno();
      break;

    case 4:
      printf("\nPrograma encerrado.\n");
      return 0;

    default:
      printf("\nOpcao invalida!\n");
    }
  }

  return 0;
}
