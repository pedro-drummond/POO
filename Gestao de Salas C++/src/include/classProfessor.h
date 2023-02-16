#ifndef CLASSPROFESSOR_H
#define CLASSPROFESSOR_H
#include <string>
#include <iostream>
#include <vector>
#include "classPessoa.h"
#include "classAluno.h"
#include "classCurso.h"
using namespace std;
class Professor : public Pessoa
{
public:
  int codCurso;
  friend class Gestor;
  friend class Curso;
  Professor();
  Professor(string nome, string cpf, string contato);
  void cadastroProfessor();
  void imprimirDados();
  void novosDados(string nome, string cpf, string contato);
  void preencherDadosProfessor();
  string getCpf();
  string getContato();
  string getNome();
  void setCodCurso(int codCurso);
};
Professor::Professor() {}
Professor::Professor(string nome, string cpf, string contato)
{
  Pessoa::cadastro(nome, cpf, contato);
}
void Professor::setCodCurso(int codCurso)
{
  this->codCurso = codCurso;
}

string Professor::getNome()
{
  return Pessoa::getNome();
}

string Professor::getContato()
{
  return Pessoa::getContato();
}

string Professor::getCpf()
{
  return Pessoa::getCpf();
}

void Professor::imprimirDados()
{
  Pessoa::imprimirDados();
}
void Professor::novosDados(string nome, string cpf, string contato)
{
  Pessoa::setNome(nome);
  Pessoa::setCpf(cpf);
  Pessoa::setContato(contato);
}
void Professor::preencherDadosProfessor()
{
  string nome, cpf, contato, matricula;
  int opc;
  system("clear");
  cout << "[CADASTRO DE PROFESSORES]\nNome: ";
  getline(cin, nome);
  cout << "CPF: ";
  getline(cin, cpf);
  cout << "Contato: ";
  getline(cin, contato);

  Pessoa::setNome(nome);
  Pessoa::setContato(contato);
  Pessoa::setCpf(cpf);
}



#endif