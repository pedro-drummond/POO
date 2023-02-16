#ifndef CLASSCURSO_H
#define CLASSCURSO_H

#include <string.h>
#include <vector>
#include <string>
#include <iostream>
#include "classAluno.h"
#include "classProfessor.h"
#include "classCurso.h"
#include "classSala.h"
using namespace std;

class Curso
{
private:
  int cod;
  int alunos = 0;
  string nome;
  vector<int> dias;
  Professor professor;
  int Alocado = 0;

public:
  Curso();
  int getCod();
  Professor getProfessor();
  string getNome();
  void setCod(int cod);
  void imprimirDados();
  int getNumeroAlunos();
  void setNumeroAlunos(int i);
  void setAlunos(int i);
  vector<int> getDias();
  void imprimirDadosProfessor();
  void imprimirNomeECod();
  void setNome(string nome);
  Curso(int cod, string nome);
  bool disponibilidade(vector<Curso>cursos);
  void setNomeECod(string nome, int cod);
  void setProfessor(Professor professor);
  string getCpfProfessor();
  int verificaAlocacao();
  void setNomeProfessor(string nome);
  string getNomeProfessor();
  void adicionarCursoProfessor(Professor professor, vector <Professor>&professores);
  void alocaAuto(vector<Sala> &salas);
  void alocar(int dia);
};

void Curso::alocaAuto(vector<Sala> &salas){

  int posMaiorSala = 0;

  for( int i = 1; i < salas.size(); i++){
    if(salas[i].qtdDisponivel()>0 && salas[i].getCapacidade()>salas[posMaiorSala].getCapacidade()) posMaiorSala = i;   
  }
  int dia = salas[posMaiorSala].setAlocar(this->getCod());
  this->alocar(dia);
}
vector<int> Curso::getDias(){
    return this->dias;
}

void Curso::setNumeroAlunos(int i){
  this->alunos+= i;
}

void Curso::setAlunos(int i){
  this->alunos= i;
}

void Curso::setNomeProfessor(string nome)
{
  professor.setNome(nome);
}

string Curso::getNomeProfessor()
{
  return professor.getNome();
}

// Professor Curso::getProfessor(){
//   return this->professor;
// }

int Curso:: verificaAlocacao(){
  return this->Alocado;
}

void Curso::alocar( int dia){
  this->Alocado++;
  this->dias.push_back(dia);
}

bool Curso::disponibilidade(vector<Curso>cursos)
{
  vector<int> diasC;
  for(int i = 0; i < cursos.size(); i++){
    vector<int> diass = cursos[i].getDias();
    for(int j = 0; j<diass.size(); j++)
      diasC.push_back(diass[j]);
  }
  for(int i = 0; i < this->verificaAlocacao();i++){
    for(int j = 0; j<diasC.size(); j++)
      if(this->dias[i] == diasC[j])
        return false;
  }
  return true;
}
int Curso::getNumeroAlunos()
{
  return alunos;
}

Curso::Curso()
{
  cod = 0;
  nome = "Nome indefinido";
}
Curso::Curso(int cod, string nome)
{
  this->cod = cod;
  this->nome = nome;
}
void Curso::setCod(int cod)
{
  this->cod = cod;
}
int Curso::getCod()
{
  return this->cod;
}
void Curso::setNome(string nome)
{
  this->nome = nome;
}
string Curso::getNome()
{
  return this->nome;
}

void Curso::setNomeECod(string nome, int cod)
{
  this->nome = nome;
  this->cod = cod;
}

void Curso::imprimirDadosProfessor()
{
  professor.imprimirDados();
}

string retornaDiaDaSemana(int dia)
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
  default:
    return "indefinido";
    break;
  }
}
void Curso::adicionarCursoProfessor(Professor professor, vector <Professor>&professores)
{

    Curso::setProfessor(professor);
    professor.setCodCurso(this->getCod());
}


void Curso::imprimirNomeECod()
{
  cout << nome << " | Cod:" << cod << endl;
}

void Curso::imprimirDados()
{
  cout << "Curso     : " << Curso::getNome() << endl
       << "Codigo    : " << Curso::getCod() << endl
       << "Professor : " << professor.getNome() << endl;

  for (int i = 0; i < this->dias.size() ; i++)
  {
    cout << retornaDiaDaSemana(this->dias[i] +1) << " | ";
  }
  cout << endl;
}

void Curso::setProfessor(Professor professor)
{
  this->professor = professor;
}

string Curso::getCpfProfessor()
{
  return professor.getCpf();
}

#endif