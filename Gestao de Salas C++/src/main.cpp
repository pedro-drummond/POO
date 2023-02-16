#include <iostream>
#include <string>
#include <vector>
#include "include/classPessoa.h"
#include "include/classAluno.h"
#include "include/classCurso.h"
#include "include/classSala.h"
#include "include/classGestor.h"
#include "include/classProfessor.h"
#include "include/display.h"
#include "include/tools.h"
#include "include/arquivo.h"
using namespace std;

int main()
{
  Gestor gestor;
  vector<Curso> cursos;
  vector<Aluno> alunos;
  vector<Sala> salas;
  vector<Professor> professores;
  string string_digitada;
  //carregar dados do arquivo
  carregarSalas(salas);
  carregarAlunos(alunos);
  carregarCursos(cursos);
  carregarProfessores(professores);

  int opcao = -3;
  while (opcao != -1)
  {
    alocarAutomatico(cursos,salas);
    /* ---- Menu do Gestor ----*/
    if (opcao > 0 && opcao < 6)
    {
      switch (opcao)
      {
      case 1:
        menuGerenciarAluno(cursos, alunos);
        break;
      case 2:
        menuGerenciarProfessor(cursos,alunos, professores);
        break;
      case 3:
        menuGerenciarCursos(cursos);
        break;
      case 4:
         menuGerenciarSalas(cursos,salas, alunos,professores);
        break;
      case 5:
        menuRelatorios(cursos, alunos, salas, professores);
        break;

      default:
        break;
      }
    }
    /*MENU ALUNO*/
    if (opcao > 10)
    {
      if (opcao == 11)
      {
        cout << "Digite seu CPF\n";
        getline(cin, string_digitada);
        if (!visualizar(alunos, string_digitada))
        {
          cout << "Não encontrado\n";
        }
        getline(cin, string_digitada);
      }
    }
    if (opcao == 12)
    {
      cout << "Digite seu CPF\n";
      getline(cin, string_digitada);
      if (opcao == 12)
      {

        if (!visualizarProfessor(professores, cursos, alunos, string_digitada))
        {
          cout << "Não encontrado\n";
        }
        getline(cin, string_digitada);
      }
    }
    opcao = menuPrincipal(gestor);
    if (opcao == 0)
    {
      cout << "Saindo\n";
      break;
    }
  }

    //salvar dados no arquivo
  salvarCursos(cursos);
  salvarAlunos(alunos);
  salvarSalas(salas);
  salvarProfessores(professores);
  return 0;
}