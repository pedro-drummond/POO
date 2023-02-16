#ifndef CLASSSALA_H
#define CLASSSALA_H
#include <string>
#include <iostream>
#include <vector>
#include "classCurso.h"
#define SEMANA 5
using namespace std;
class Sala
{
private:
  int identificador;
  int alunos;
  int capacidade;
  int disponivel[5] = {0, 0, 0, 0, 0};

public:
  void relatorio();
  vector<string> semana;
  Sala();
  Sala(int sala, int capacidade);
  void subAlunos();
  void sumAlunos();
  void setDisponibilidade(int dia, string disponibilidade);
  void setAlunos(int alunos);
  int getAlunos();
  void setCapacidade(int capacidade);
  int getCapacidade();
  void cadastrarSala(vector<Sala> &salas);
  int qtdDisponivel();
  int getIdentificador();
  void setIdentificador(int identificador);
  int setAlocar(int codigo);
};



int Sala::getIdentificador()
{
  return this->identificador;
}

void Sala::setIdentificador(int identificador)
{
  this->identificador = identificador;
}


string diaDaSemana(int dia)
{
  switch (dia)
  {
  case 1:
    return "Segunda-Feira";
    break;
  case 2:
    return "Terça-Feira";
    break;
  case 3:
    return "Quarta-Feira";
    break;
  case 4:
    return "Quinta-Feira";
    break;
  case 5:
    return "Sexta-Feira";
    break;
  }
  return "Indefinido";
}

Sala::Sala()
{
  this->identificador = -1;
  this->capacidade = -1;
  alunos = 0;
  for (int i = 0; i < SEMANA; i++)
  {
    semana.push_back("Disponivel");
  }
}
Sala::Sala(int identificador, int capacidade)
{
  this->identificador = identificador;
  this->capacidade = capacidade;
  alunos = 0;
  for (int i = 0; i < SEMANA; i++)
  {
    semana.push_back("Disponivel");
  }
}
int Sala::qtdDisponivel()
{
  int qtd = 0;
  for (int i = 0; i < 5; i++)
  {
    if (this->disponivel[i] == 0)
      qtd++;
  }
  return qtd;
}
void Sala::setCapacidade(int capacidade)
{
  this->capacidade = capacidade;
}
int Sala::getCapacidade()
{
  return this->capacidade;
}
void Sala::setAlunos(int alunos)
{
  this->alunos = alunos;
}
int Sala::getAlunos()
{
  return this->alunos;
}
void Sala::subAlunos()
{
  this->alunos--;
}
void Sala::sumAlunos()
{
  this->alunos++;
}

int Sala::setAlocar(int codigo)
{

  for (int i = 0; i < 5; i++)
  {

    if (this->disponivel[i] == 0)
    {
      int dia = i;
      switch (dia)
      {
      case 0:
        this->disponivel[dia] = codigo;
        break;
      case 1:
        this->disponivel[dia] = codigo;
        break;
      case 2:
        this->disponivel[dia] = codigo;
        break;
      case 3:
        this->disponivel[dia] = codigo;
        break;
      case 4:
        this->disponivel[dia] = codigo;
        break;
      default:
        break;
      }
      return dia;
    }
  }

  return -1;
}

void Sala::cadastrarSala(vector<Sala> &salas)
{

  cout << "Escreva o código da sala:";
  cin >> this->identificador;

  cout << "Escreva o código da sala:";
  cin >> this->capacidade;

  Sala sala1(identificador, capacidade);

  salas.push_back(sala1);
}

void Sala::relatorio()
{
  cout << "[RELATORIO SALA " << identificador << " ]" << endl;
  cout << "Capacidade: " << capacidade << " | Alunos: " << alunos << "\n\n";
  for (int i = 0; i < SEMANA; i++)
  {
    if (this->disponivel[i] == 0)
      cout << diaDaSemana(i + 1) << ": " << semana[i] << endl;
    else
      cout << diaDaSemana(i + 1) << ": " << disponivel[i] << endl;
  }
}
void Sala::setDisponibilidade(int dia, string disponibilidade)
{
  this->semana[dia] = disponibilidade;
}

#endif