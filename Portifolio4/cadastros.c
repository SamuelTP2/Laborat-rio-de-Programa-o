#include "cadastros.h"
#include <stdio.h>

struct Alunos vetor_alunos[MAX];
struct Professores vetor_professores[MAX];
struct Funcionarios vetor_funcionarios[MAX];

int total_alunos = 0;
int total_prof = 0;
int total_funcionarios = 0;

void cadastro_alunos() {

  if (total_alunos >= MAX) {
    printf("\nLimite de alunos atingido!\n");
    return;
  }

  printf("\n=== Cadastro de Alunos ===\n");

  printf("Id do Aluno: ");
  scanf("%i", &vetor_alunos[total_alunos].id_aluno);

  printf("Nome: ");
  scanf("%s", vetor_alunos[total_alunos].nome);

  printf("Idade: ");
  scanf("%d", &vetor_alunos[total_alunos].idade);

  printf("Turma: ");
  scanf(" %c", &vetor_alunos[total_alunos].turma);

  printf("\nAluno cadastrado com sucesso!\n");

  total_alunos++;
}

void listar_alunos() {

  if (total_alunos == 0) {
    printf("\nNenhum aluno cadastrado.\n");
    return;
  }

  printf("\n=== Lista de Alunos ===\n");

  for (int i = 0; i < total_alunos; i++) {
    printf("\nAluno %d\n", i + 1);
    printf("Id: %d\n", vetor_alunos[i].id_aluno);
    printf("Nome: %s\n", vetor_alunos[i].nome);
    printf("Idade: %d\n", vetor_alunos[i].idade);
    printf("Turma: %c\n", vetor_alunos[i].turma);
  }
}

void cadastro_professores() {

  if (total_prof >= MAX) {
    printf("\nLimite de professores atingido!\n");
    return;
  }

  printf("\n=== Cadastro de Professores ===\n");

  printf("Id do Professor: ");
  scanf("%i", &vetor_professores[total_prof].id_prof);

  printf("Nome: ");
  scanf("%s", vetor_professores[total_prof].nome);

  printf("Disciplina: ");
  scanf("%s", vetor_professores[total_prof].disciplina);

  printf("Telefone: ");
  scanf("%d", &vetor_professores[total_prof].telefone);

  printf("\nProfessor cadastrado com sucesso!\n");

  total_prof++;
}

void listar_professores() {

  if (total_prof == 0) {
    printf("\nNenhum professor cadastrado.\n");
    return;
  }

  printf("\n=== Lista de Professores ===\n");

  for (int i = 0; i < total_prof; i++) {
    printf("\nProfessor %d\n", i + 1);
    printf("Id: %d\n", vetor_professores[i].id_prof);
    printf("Nome: %s\n", vetor_professores[i].nome);
    printf("Disciplina: %s\n", vetor_professores[i].disciplina);
    printf("Telefone: %d\n", vetor_professores[i].telefone);
  }
}

void cadastro_funcionarios() {

  if (total_funcionarios >= MAX) {
    printf("\nLimite de funcionários atingido!\n");
    return;
  }

  printf("\n=== Cadastro de Funcionários ===\n");

  printf("Id do Funcionário: ");
  scanf("%i", &vetor_funcionarios[total_funcionarios].id_funcionario);

  printf("Nome: ");
  scanf("%s", vetor_funcionarios[total_funcionarios].nome);

  printf("Cargo: ");
  scanf("%s", vetor_funcionarios[total_funcionarios].cargo);

  printf("Telefone: ");
  scanf("%d", &vetor_funcionarios[total_funcionarios].telefone);

  printf("\nFuncionário cadastrado com sucesso!\n");

  total_funcionarios++;
}

void listar_funcionarios() {

  if (total_funcionarios == 0) {
    printf("\nNenhum funcionário cadastrado.\n");
    return;
  }

  printf("\n=== Lista de Funcionários ===\n");

  for (int i = 0; i < total_funcionarios; i++) {
    printf("\nFuncionário %d\n", i + 1);
    printf("Id: %d\n", vetor_funcionarios[i].id_funcionario);
    printf("Nome: %s\n", vetor_funcionarios[i].nome);
    printf("Cargo: %s\n", vetor_funcionarios[i].cargo);
    printf("Telefone: %d\n", vetor_funcionarios[i].telefone);
  }
}