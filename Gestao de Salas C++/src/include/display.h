#ifndef DISPLAY_H
#define DISPLAY_H
#include <iostream>
#include "tools.h"
using namespace std;

int menuPrincipal(Gestor &gestor)
{
  int opcao = 1;
  int opcaoGestor = 1;
  int opcaoProfessor = 1;

  while (opcao != 0)
  {
    system("clear");
    cout << "\n[-------- MENU INICIAL --------]\n"
         << "1. Entrar como GESTOR\n2. Entrar como ALUNO/PROFESSOR\n"
         << "Digite '0' para sair" << endl;
    opcao = tratamentoDeEntrada();
    if (opcao == 1)
    {
      gestor.Validacao();
      if (gestor.condicao() == true)
      {
        system("clear");
        cout << "1. Gerenciar Aluno\n2. Gerenciar Professor\n3. Gerenciar Curso" << endl
             << "4. Cadastrar Sala\n5. Gerar Relatório\n\nDigite '0' para sair" << endl;
        while (true)
        {
          opcaoGestor = tratamentoDeEntrada();
          if (opcaoGestor == 0)
          {
            break;
          }
          else
          {
            return opcaoGestor;
          }
        }
      }
      else
      {
        cout << "Senha ou Login invalidos\n";
      }
    }
    else if (opcao == 2)
    {

      system("clear");
      cout << "1. Consultar Aluno\n2. Consultar Professor\n"
           << endl
           << "Digite '0' para sair" << endl;
      while (true)
      {
        opcaoProfessor = tratamentoDeEntrada();
        if (opcaoProfessor == 1 || opcaoProfessor == 2)
        {
          return opcaoProfessor + 10;
        }
        else if (opcaoProfessor == 0)
        {
          break;
        }
        cout << " Opção Invalida\n";
      }
    }
    else if (opcao == 0)
    {
      opcao = 1;
      break;
    }
    if (opcao != 1)
      cout << " Opção Invalida\n";
  }
  return 0;
}

int menuRelatorio(Gestor gestor)
{
  int aux;
  if (!gestor.condicao())
    return 5;
  system("clear");
  cout << "\t[----  RELATORIO  ----]\n"
       << "1. Aluno\n2. Professor\n3. Curso" << endl
       << "4. Sala\n5. Voltar ao MENU PRINCIPAL" << endl;
  while (true)
  {
    aux = tratamentoDeEntrada();
    if (aux == 0)
    {
      cout << " Opção Invalida\n";
    }
    else
    {
      return aux;
    }
  }
  return 5;
}
#endif