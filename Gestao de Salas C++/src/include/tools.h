/*A BIBLIOTECA TOOLS.H CONTEM APENAS FUNCOES*/
#ifndef TOOLS_H
#define TOOLS_H
#include <iostream>
#include <string>
#include <vector>
#include "classPessoa.h"
#include "classAluno.h"
#include "classCurso.h"
#include "classSala.h"
#include "classGestor.h"
#include "classProfessor.h"
// #include "display.h"
void relatorioCursos(vector<Curso> cursos)
{
  int end = cursos.size();
  for (int i = 0; i < end; i++)
  {
    cursos[i].imprimirDados();
    cout << "----------------------------------\n";
  }
}

void relatorioProfessor(vector<Curso> cursos, vector<Professor> professores)
{
  int endCursos = cursos.size();
  int endProf = professores.size();
  int endCod;
  // Percorre Professores
  for (int i = 0; i < endProf; i++)
  {
    professores[i].imprimirDados();
    cout << "Curso Ministrado: ";
    // Percorre os Cursos
    for (int j = 0; j < endCursos; j++)
    {
      // Comparacao entre cod do professor e cod do curso
      if (professores[i].codCurso == cursos[j].getCod())
      {
        cout << cursos[j].getNome() << endl;
      }
    }
    cout << "----------------------------------\n";
  }
}

void relatorioAlunos(vector<Aluno> alunos)
{
  system("clear");
  cout << "[RELATORIO DE ALUNOS]\n\n";
  int end = alunos.size();
  int endCursos;
  for (int i = 0; i < end; i++)
  {
    cout << "Aluno " << i + 1 << " ------------------------" << endl;
    alunos[i].imprimirDadosAluno();
    endCursos = alunos[i].cursos.size();
    cout << "Cursos:\n";
    for (int j = 0; j < endCursos; j++)
    {
      cout << "  ";
      alunos[i].cursos[j].imprimirNomeECod();
    }
  }
  cout << "\n";
}

void relatorioSalas(vector<Sala> salas)
{
  int end = salas.size();
  for (int i = 0; i < end; i++)
  {
    salas[i].relatorio();
    cout << "-----------------------------------\n";
  }
}

int entradaMenu()
{
  string string_digitada;
  getline(cin, string_digitada);
  return string_digitada.compare("0");
}

int tratamentoDeEntrada()
{
  int opcao;
  while (true)
  {
    opcao = entradaMenu();
    if (opcao >= 0 && opcao < 6)
    {
      return opcao;
    }
    cout << " Opção Invalida\n";
  }
  return -1;
}

void inicializadorPadrao(vector<Sala> &salas)
{
  Sala sala1(210, 10);
  Sala sala2(251, 5);
  Sala sala3(252, 5);
  Sala sala4(230, 3);
  salas.push_back(sala1);
  salas.push_back(sala2);
  salas.push_back(sala3);
  salas.push_back(sala4);
}

vector<Professor> inicializaProfessor()
{
  Professor professor;
  vector<Professor> professores;
  professor.novosDados("Maria Silva", "123.456.789-10", "(11) 98765-4321");
  professores.push_back(professor);
  professor.novosDados("João Oliveira", "987.654.321-20", "(22) 12345-6789");
  professores.push_back(professor);
  professor.novosDados("Ana Rodrigues", "111.222.333-44", " (33) 56789-1234");
  professores.push_back(professor);
  professor.novosDados("Pedro Costa", "444.333.222-11", "(44) 98765-1234");
  professores.push_back(professor);
  professor.novosDados("Juliana Souza", "555.666.777-22", "(55) 12345-6789");
  professores.push_back(professor);
  professor.novosDados("Lucas Nunes", "888.999.000-33", "(66) 98765-4321");
  professores.push_back(professor);
  professor.novosDados("Isabela Santos", "101.102.103-44", "(77) 12345-1234");
  professores.push_back(professor);
  professor.novosDados("Rafaela Ferreira", "201.202.203-55", "(88) 56789-6789");
  professores.push_back(professor);
  int end = professores.size();
  for (int i = 0; i < 8; i++)
  {
    professores[i].codCurso = i + 701;
  }
  return professores;
}

vector<Curso> inicializaCursos(vector<Professor> professores)
{
  Curso curso;
  int cod = 701;
  vector<Curso> cursos;
  Professor professor;
  for (int i = 0; i < 8; i++)
  {
    switch (i)
    {
    case 0:
      curso.setNomeECod("Artes Cenicas", cod + i);
      curso.setProfessor(professores[i]);
      break;
    case 1:
      curso.setNomeECod("Ciencia da Computacao", cod + i);
      curso.setProfessor(professores[i]);
      break;
    case 2:
      curso.setNomeECod("Engenharia de Energias", cod + i);
      curso.setProfessor(professores[i]);
      break;
    case 3:
      curso.setNomeECod("Engenharia Metalurgica", cod + i);
      curso.setProfessor(professores[i]);
      break;
    case 4:
      curso.setNomeECod("Engenharia Geologica", cod + i);
      curso.setProfessor(professores[i]);
      break;
    case 5:
      curso.setNomeECod("Quimica Industrial", cod + i);
      curso.setProfessor(professores[i]);
      break;
    case 6:
      curso.setNomeECod("Odontologia", cod + i);
      curso.setProfessor(professores[i]);
      break;
    case 7:
      curso.setNomeECod("Enfermagem", cod + i);
      curso.setProfessor(professores[i]);
      break;
    }
    cursos.push_back(curso);
  }
  return cursos;
}
void menuRelatorios(vector<Curso> cursos, vector<Aluno> alunos, vector<Sala> salas, vector<Professor> professores)
{
  int opcao = 3;
  string str;
  while (opcao != 5)
  {
    system("clear");
    cout << "[---- RELATORIOS ----]" << endl
         << "1.Alunos\n2.Professor\n3.Curso\n4.Sala\n5. Voltar ao menu\n";
    if (opcao < 1 && opcao > 6)
      cout << " Opção Invalida\n";
    opcao = tratamentoDeEntrada();
    switch (opcao)
    {
    case 1:
      system("clear");
      relatorioAlunos(alunos);
      cout << "\nDigite qualquer tecla\n";
      getline(cin, str);
      break;
    case 2:
      system("clear");
      relatorioProfessor(cursos, professores);
      cout << "\nDigite qualquer tecla\n";
      getline(cin, str);
      break;
    case 3:
      system("clear");
      relatorioCursos(cursos);
      cout << "Digite qualquer tecla\n";
      getline(cin, str);
      break;
    case 4:
      system("clear");
      relatorioSalas(salas);
      cout << "Digite qualquer tecla\n";
      getline(cin, str);
      break;
    }
  }
}

string DiaDaSemana(int dia)
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

int atribuirCurso(vector<Curso> cursos)
{
  int opcao, endCurso;
  endCurso = cursos.size();
  cout << "[---- Opções de Curso ----]\n";
  for (int i = 0; i < endCurso; i++)
  {
    cout << "Curso " << i + 1 << " - ";
    cursos[i].imprimirNomeECod();
  }
  cout << "------------------------------------\n";
  while (true)
  {
    opcao = entradaMenu();
    if (opcao > 0 && opcao <= cursos.size())
    {
      return opcao - 1;
    }
    if (opcao == 0)
    {
      return -1;
    }
  }
  return opcao;
}

void Aluno::preencherDadosAluno(vector<Aluno> alunos, vector<Curso> &cursos)
{
  string nome, cpf, contato, matricula;
  int aux, opc;
  system("clear");
  cout << "[CADASTRO DE ALUNOS]\nNome: ";
  getline(cin, nome);
  cout << "CPF: ";
  getline(cin, cpf);
  cout << "Contato: ";
  getline(cin, contato);
  while (true)
  {
    aux = atribuirCurso(cursos);
    if (aux == -1)
    {
      break;
    }

    Aluno::adicionarCurso(cursos[aux]);
    cursos[aux].setNumeroAlunos(+1);
    cout << "Deseja atribuir mais cursos Digite 1\n"
         << "Se deseja continuar digite 0" << endl;
    if (tratamentoDeEntrada() == 0)
    {
      break;
    }
  }
  Pessoa::setNome(nome);
  Pessoa::setContato(contato);
  Pessoa::setCpf(cpf);
  setMatricula(alunos.size() + 1000);
}

void cadastrarNovoAluno(Aluno aluno, vector<Aluno> &alunos)
{
  alunos.push_back(aluno);
}
void cadastrarNovoProfessor(Professor novoProfessor, vector<Professor> &professores)
{
  professores.push_back(novoProfessor);
}

bool removerAluno(vector<Aluno> &alunos, vector<Curso> &cursos, int matricula)
{
  int endAlunos = alunos.size();
  int endCursos = cursos.size();
  int end;
  for (int i = 0; i < endAlunos; i++)
  {
    if (alunos[i].getMatricula() == matricula)
    {
      endCursos = alunos[i].cursos.size();
      for (int j = 0; j < endCursos; j++)
      {
        end = cursos.size();
        for (int k = 0; k < end; k++)
        {
          if (cursos[k].getCod() == alunos[i].cursos[j].getCod())
          {
            cursos[k].setNumeroAlunos(-1);
          }
        }
      }
      alunos.erase(alunos.begin() + i);
      return true;
    }
  }
  return false;
}

bool removerProfessor(vector<Aluno> &professores, vector<Curso> &cursos, int matricula)
{
  int endprofessores = professores.size();
  int endCursos = cursos.size();
  int end;
  for (int i = 0; i < endprofessores; i++)
  {
    if (professores[i].getMatricula() == matricula)
    {
      endCursos = professores[i].cursos.size();
      for (int j = 0; j < endCursos; j++)
      {
        end = cursos.size();
        for (int k = 0; k < end; k++)
        {
          // if (cursos[k].getProfessor == professores[i]);
          // {
          //   //cursos[k].setProfessor();
          // }
        }
      }
      professores.erase(professores.begin() + i);
      return true;
    }
  }
  return false;
}

void menuGerenciarProfessor(vector<Curso> &cursos, vector<Aluno> &alunos, vector<Professor> &professores)
{

  int opc;
  string matricula;
  Professor novoProfessor;

  while (true)
  {
    system("clear");
    cout << "1.Cadastrar Professor" << endl
         << "2.Remover Professor" << endl
         << "Digite 0 para voltar\n";
    opc = tratamentoDeEntrada();
    int aux;
    if (opc != 0 || opc != 1 || opc != 2)
    {
      cout << "Opcao invalida\n";
    }
    if (opc == 1)
    {

      novoProfessor.preencherDadosProfessor();
      int aux = atribuirCurso(cursos);
      if (aux == -1)
      {
        break;
      }
      cursos[aux].adicionarCursoProfessor(novoProfessor, professores);
      cadastrarNovoProfessor(novoProfessor, professores);
    }
    else if (opc == 2)
    {
      system("clear");
    }
    else if (opc == 0)
    {
      break;
    }
  }
}
void excluirSala(vector<Sala> &salas)
{

  int opcao;
  cout << "Digite o cod da sala:" << endl;
  relatorioSalas(salas);
  cin >> opcao;
  for (int i = 0; i < salas.size(); i++)
  {
    if (salas[i].getIdentificador() == opcao)
    {
      salas.erase(salas.begin() + i);
    }
  }
}

void menuGerenciarSalas(vector<Curso> &cursos, vector<Sala> &salas, vector<Aluno> &alunos, vector<Professor> &professores)
{

  Sala novaSala;
  system("clear");
  cout << "1.Cadastrar sala" << endl
       << "2.Consultar Salas" << endl
       << "3.Excluir Salas" << endl
       << "Digite 0 para voltar\n";
  int opc = tratamentoDeEntrada();
  int aux;

  switch (opc)
  {
  case 1:
    novaSala.cadastrarSala(salas);
    break;
  case 2:
    relatorioSalas(salas);
    break;
  case 3:
    excluirSala(salas);
    break;
  case 0:
    break;

  default:
    break;
  }
}

void menuGerenciarAluno(vector<Curso> &cursos, vector<Aluno> &alunos)
{
  int opc;
  string matricula;
  Aluno novoAluno, alunoAux;

  while (true)
  {
    novoAluno = alunoAux;
    system("clear");
    cout << "1.Cadastrar Aluno" << endl
         << "2.Remover Aluno" << endl
         << "Digite 0 para voltar\n";
    opc = tratamentoDeEntrada();
    int aux;
    if (opc != 0 || opc != 1 || opc != 2)
    {
      cout << "Opcao invalida\n";
    }
    if (opc == 1)
    {
      novoAluno.preencherDadosAluno(alunos, cursos);
      cadastrarNovoAluno(novoAluno, alunos);
    }
    else if (opc == 2)
    {
      system("clear");
      cout << "Digite a matricula do Aluno que deseja remover\nou digite 0 para voltar";
      getline(cin, matricula);
      aux = stoi(matricula);
      if (!removerAluno(alunos, cursos, aux))
      {
        cout << "Aluno não encontrado\nPressione qualquer tecla" << endl;
        getline(cin, matricula);
      }
    }
    else if (opc == 0)
    {
      break;
    }
  }
}

void apresentarAlunos(Curso curso, vector<Aluno> alunos)
{
  int end = alunos.size();
  int endCurso;
  for (int i = 0; i < end; i++)
  {
    endCurso = alunos[i].cursos.size();
    for (int j = 0; j < endCurso; j++)
    {
      if (alunos[i].cursos[j].getCod() == curso.getCod())
      {
        cout << "Nome     : " << alunos[i].getNome() << endl;
        cout << "Matricula: " << alunos[i].getMatricula() << endl;
        cout << "----------------------------------------\n";
      }
    }
  }
}

bool visualizarProfessor(vector<Professor> professores, vector<Curso> cursos, vector<Aluno> alunos, string cpf)
{
  int end = professores.size();
  int endCurso;
  for (int i = 0; i < end; i++)
  {
    if (cpf.compare(professores[i].getCpf()) == 0)
    {
      system("clear");
      cout << "Nome           : " << professores[i].getNome() << endl
           << "Curso Lecionado: ";
      endCurso = cursos.size();
      for (int k = 0; k < endCurso; k++)
      {
        if (cpf.compare(cursos[k].getCpfProfessor()) == 0)
        {
          cursos[i].imprimirNomeECod();
          cout << endl;
          apresentarAlunos(cursos[i], alunos);
          return true;
        }
      }
    }
  }
  return false;
}

void alocarAutomatico(vector<Curso> &cursos, vector<Sala> &salas)
{

  int posMaiorCurso = 0;
  int posMaiorSala = 0;
  int qtdAlocadas = 0;
  int qtdDesalocadas = 0;

  for (int i = 0; i < cursos.size(); i++)
  {
    if (cursos[i].getNumeroAlunos() > 0)
      qtdDesalocadas += (2 - cursos[i].verificaAlocacao());
  }

  while (qtdAlocadas < qtdDesalocadas)
  {
    for (int i = 0; i < cursos.size(); i++)
    {
      if (cursos[i].verificaAlocacao() < 2 && cursos[i].getNumeroAlunos() > 0 && cursos[i].getNumeroAlunos() > cursos[posMaiorCurso].getNumeroAlunos())
        posMaiorCurso = i;
    }
    for (int i = 0; i < salas.size(); i++)
    {
      if (salas[i].qtdDisponivel() > 1 && salas[i].getCapacidade() > salas[posMaiorSala].getCapacidade())
        posMaiorSala = i;
    }

    int dia = salas[posMaiorSala].setAlocar(cursos[posMaiorCurso].getCod());
    cursos[posMaiorCurso].alocar(dia);
    qtdAlocadas++;

    for (int i = 0; i < cursos.size(); i++)
    {
      if (cursos[i].verificaAlocacao() < 2 && cursos[i].getNumeroAlunos() > 0 && cursos[i].getNumeroAlunos() <= cursos[posMaiorCurso].getNumeroAlunos())
        posMaiorCurso = i;
    }
    for (int i = 0; i < salas.size(); i++)
    {
      if (salas[i].qtdDisponivel() > 1 && salas[i].getCapacidade() <= salas[posMaiorSala].getCapacidade())
        posMaiorSala = i;
    }
  }
}

bool consultarCurso(vector<Curso> cursos, int cod)
{
  int end = cursos.size();
  for (int i = 0; i < end; i++)
  {
    if (cursos[i].getCod() == cod)
    {
      cursos[i].imprimirDados();
      return true;
    }
  }
  return false;
}

void menuGerenciarCursos(vector<Curso> cursos)
{
  int opc;
  bool encontrou;
  string codigo;

  system("clear");
  cout << "1.Cadastrar Curso" << endl
       << "2.Consultar Curso" << endl
       << "Digite 0 para voltar\n";

  opc = tratamentoDeEntrada();
  if (opc == 2)
  {
    cout << "Digite o codigo do Curso:";
    getline(cin, codigo);
    encontrou = consultarCurso(cursos, stoi(codigo));
    cout << "\nPressione qualquer tecla\n";
    getline(cin, codigo);
  }
}

#endif