#include <stdio.h>

#define MAX 100

struct Produto {
  int codigo;
  char nome[50];
  float valorUnitario;
  int estoque;
};

struct Produto produtos[MAX];
int totalProdutos = 0;

void cadastroProdutos() {
  if (totalProdutos >= MAX) {
    printf("Estoque Cheio");
    return;
  }

  struct Produto p;

  printf("Qual o código do produto ?");
  scanf("%i", &p.codigo);

  printf("Nome: ");
  scanf(" %[^\n]", p.nome);

  do {
    printf("Valor unitario: ");
    scanf("%f", &p.valorUnitario);
  } while (p.valorUnitario <= 0);

  do {
    printf("Estoque: ");
    scanf("%i", &p.estoque);
  } while (p.estoque < 0);

  produtos[totalProdutos] = p;
  totalProdutos++;

  printf("Produto cadastrado com sucesso!\n");
}

void listarProdutos() {
  if (totalProdutos == 0) {
    printf("Tem nada no estoque chefe");
    return;
  }

  for (int i = 0; i < totalProdutos; i++) {
    printf("\nCodigo: %i\n", produtos[i].codigo);
    printf("Nome: %s\n", produtos[i].nome);
    printf("Valor: %.2f\n", produtos[i].valorUnitario);
    printf("Estoque: %i\n", produtos[i].estoque);
  }
}

void venderProduto() {
  int codigo;
  int qnt;
  int encontrado = -1;

  if (totalProdutos == 0) {
    printf("Nenhum produto cadastrado.\n");
    return;
  }

  printf("Digite o codigo do produto: ");
  scanf("%i", &codigo);

  for (int i = 0; i < totalProdutos; i++) {
    if (produtos[i].codigo == codigo) {
      encontrado = i;
      break;
    }
  }

  if (encontrado == -1) {
    printf("Produto nao encontrado.\n");
    return;
  }

  printf("Quantidade: ");
  scanf("%d", &qnt);

  if (qnt <= 0) {
    printf("Quantidade invalida.\n");
    return;
  }

  if (qnt > produtos[encontrado].estoque) {
    printf("Estoque insuficiente.\n");
    return;
  }

  float total = qnt * produtos[encontrado].valorUnitario;

  produtos[encontrado].estoque -= qnt;

  printf("Venda realizada! Total: %.2f\n", total);
}

int main() {

  int opcao;

  do {
    printf("\n===== MENU =====\n");
    printf("1 - Cadastrar produto\n");
    printf("2 - Listar produtos\n");
    printf("3 - Vender produto\n");
    printf("4 - Listar Vendas (nao implementado)\n");
    printf("5 - Sair\n");
    printf("Opcao: ");
    scanf("%i", &opcao);

    switch (opcao) {
    case 1:
      cadastroProdutos();
      break;
    case 2:
      listarProdutos();
      break;
    case 3:
      venderProduto();
      break;
    case 4:
      printf("Ainda nao implementado.\n");
      break;
    case 5:
      printf("Saindo...\n");
      break;
    default:
      printf("Opcao invalida.\n");
    }

  } while (opcao != 5);

  return 0;
}
