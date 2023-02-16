#ifndef CLASSGESTOR_H
#define CLASSGESTOR_H
#include <string>
#include <iostream>

using namespace std;

class Gestor
{
private:
  string login;
  string senha;
  bool autorizado;

public:
  Gestor();
  Gestor(string login, string senha);
  void Validacao();
  bool condicao();
};
//Retorna a condicao se autorizado
bool Gestor::condicao()
{
  return this->autorizado;
}

Gestor::Gestor()
{
  login = "123";
  senha = "123";
  autorizado = false;
}
Gestor::Gestor(string login, string senha)
{
  this->login = login;
  this->senha = senha;
}
//Validacao de Login e Senha do Gestor
void Gestor::Validacao()
{
  string log, key;
  system("clear");
  cout << "\t[---- LOGIN ----]\nCaso seja aluno ou professor apenas digite \"Enter\n"
       << "\nLogin:";
  getline(cin, log);
  cout << "Senha:";
  getline(cin, key);
  if (log.compare(Gestor::login) == 0 && key.compare(Gestor::senha) == 0)
  {
    this->autorizado = true;
  }
  else
  {
    this->autorizado = false;
  }
}
#endif