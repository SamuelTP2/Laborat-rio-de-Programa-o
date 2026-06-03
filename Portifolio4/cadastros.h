#ifndef CADASTROS_H
#define CADASTROS_H

#define MAX 20

struct Alunos {
  int id_aluno;
  char nome[50];
  int idade;
  char turma;
};

struct Professores {
  int id_prof;
  char nome[50];
  char disciplina[50];
  int telefone;
};

struct Funcionarios {
  int id_funcionario;
  char nome[50];
  char cargo[50];
  int telefone;
};

void cadastro_alunos();
void listar_alunos();

void cadastro_professores();
void listar_professores();

void cadastro_funcionarios();
void listar_funcionarios();

#endif