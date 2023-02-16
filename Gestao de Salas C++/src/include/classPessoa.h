#ifndef CLASSPESSOA_H
#define CLASSPESSOA_H
#include <iostream>
#include <string>
using namespace std;
class Pessoa
{
private:
  string nome;
  string contato;
  string cpf;
  void imprimirDados();
  void setNome(string nome);
  void setCpf(string cpf);
  void setContato(string contato);
  string getNome() const;
  string getCpf() const;
  string getContato() const;

public:
  Pessoa();
  void cadastro(string auxNome, string auxCpf, string auxContato);
  friend class Aluno;
  friend class Curso;
  friend class Professor;
};

Pessoa::Pessoa()
{
  nome = "N/A";
  cpf = "N/A";
  contato = "N/A";
}
string Pessoa::getNome() const
{
  return nome;
}

string Pessoa::getContato() const
{
  return contato;
}
string Pessoa::getCpf() const
{
  return cpf;
}

void Pessoa::setNome(string nome)
{
  this->nome = nome;
}
void Pessoa::setContato(string contato)
{
  this->contato = contato;
}
void Pessoa::setCpf(string cpf)
{
  this->cpf = cpf;
}
void Pessoa::cadastro(string auxNome, string auxCpf, string auxContato)
{
  setNome(auxNome);
  setCpf(auxCpf);
  setContato(auxContato);
}
void Pessoa::imprimirDados()
{
  cout << "Nome     : " << this->nome << endl;
  cout << "CPF      : " << this->cpf << endl;
  cout << "Contato  : " << this->contato << endl;
}

#endif