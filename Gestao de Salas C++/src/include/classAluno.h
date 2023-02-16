#ifndef CLASSALUNO_H
#define CLASSALUNO_H
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "classCurso.h"
#include "classPessoa.h"

using namespace std;

class Aluno : public Pessoa
{
private:
  int matricula;

public:
  vector<Curso> cursos;
  Aluno();
  Aluno(string nome, string cpf, string contato, int matricula);
  void setMatricula(int matricula);
  void setCurso(Curso &curso);
  int getMatricula();
  string getNome();
  string getCpf();
  string getContato();
  void preencherDadosAluno(vector<Aluno> alunos, vector<Curso> &cursos);
  void imprimirDadosAluno();
  bool dataCompativel(Curso curso);
  void adicionarCurso(Curso &curso);
  bool verificaDuplicidade(Curso curso);
  // void visualizar(vector<Aluno> alunos, string cpf);
  friend bool visualizar(vector<Aluno> alunos, string cpf);
};

string Aluno::getNome()
{
  return Pessoa::getNome();
}
string Aluno::getCpf()
{
  return Pessoa::getCpf();
}
string Aluno::getContato()
{
  return Pessoa::getContato();
}

Aluno::Aluno()
{
  matricula = 1000;
}
Aluno::Aluno(string nome, string cpf, string contato, int matricula)
{
  Pessoa::cadastro(nome, cpf, contato);
  Aluno::setMatricula(matricula);
}
void Aluno::setMatricula(int matricula)
{
  this->matricula = matricula;
}

int Aluno::getMatricula()
{
  return this->matricula;
}

void Aluno::imprimirDadosAluno()
{
  Pessoa::imprimirDados();
  cout << "Matricula: " << Aluno::getMatricula() << endl;
}

void Aluno::setCurso(Curso &curso)
{
  this->cursos.push_back(curso);
  curso.setNumeroAlunos(+1);
}

void Aluno::adicionarCurso(Curso &curso)
{
  if (!Aluno::verificaDuplicidade(curso) && curso.disponibilidade(this->cursos))
  {
    Aluno::setCurso(curso);
    curso.setNumeroAlunos(+1);
  }
}

bool Aluno::verificaDuplicidade(Curso curso)
{
  int end = cursos.size();
  for (int i = 0; i < end; i++)
  {
    if (cursos[i].getCod() == curso.getCod())
    {
      return true;
    }
  }
  return false;
}

bool visualizar(vector<Aluno> alunos, string cpf)
{
  int end = alunos.size();
  int endCurso;
  for (int i = 0; i < end; i++)
  {
    if (cpf.compare(alunos[i].getCpf()) == 0)
    {
      system("clear");
      cout << "Nome     : " << alunos[i].getNome() << endl
           << "Matricula:" << alunos[i].getMatricula() << endl
           << "Cursos   : " << endl;
      endCurso = alunos[i].cursos.size();
      for (int j = 0; j < endCurso; j++)
      {
        alunos[i].cursos[j].imprimirNomeECod();
        cout << "Ocorrencia: ";
        alunos[i].cursos[j].imprimirDados();
        cout << endl;
        return true;
      }
    }
  }
  return false;
}
#endif