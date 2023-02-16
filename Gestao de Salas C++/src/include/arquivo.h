#ifndef ARQUIVO_H
#define ARQUIVO_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "classAluno.h"
#include "classCurso.h"
#include "classPessoa.h"
using namespace std;
void salvarAlunos(vector<Aluno> alunos){
    ofstream arquivo;
    int numAlunos = alunos.size();
    arquivo.open("alunos.txt");
    //numero de alunos
    arquivo << alunos.size() << endl;
    for (int i = 0; i < numAlunos; i++){
        arquivo << alunos[i].getNome() << endl;
        arquivo << alunos[i].getCpf() << endl;
        arquivo << alunos[i].getContato() << endl;
        arquivo << alunos[i].getMatricula() << endl;
        //numero de cursos
        arquivo << alunos[i].cursos.size() << endl;
        int numCursos = alunos[i].cursos.size();
        for (int j = 0; j < numCursos; j++){
            arquivo << alunos[i].cursos[j].getNome() << endl;
            //salvar codigo
            arquivo << alunos[i].cursos[j].getCod() << endl;
    
        }
    }
    arquivo.close();
}
// carregar alunos do arquivo txt

void carregarAlunos(vector<Aluno> &alunos){
    ifstream arquivo;
    arquivo.open("alunos.txt");
    int numAlunos;
    arquivo >> numAlunos;
    for (int i = 0; i < numAlunos; i++){
        string nome, cpf, contato;
        int matricula;
        //ler uma linha inteira do arquivo
        //arquivo.ignore();
        getline(arquivo >> ws, nome);
        //arquivo.ignore();
        getline(arquivo >> ws, cpf);
        //arquivo.ignore();
        getline(arquivo >> ws, contato);
        //arquivo.ignore();
        arquivo >> matricula;
        int numCursos;    
        arquivo >> numCursos;     
        Aluno aluno(nome, cpf, contato, matricula);

        for (int j = 0; j < numCursos; j++){
            string nomeCurso;
            getline(arquivo >> ws, nomeCurso);
            int codigoCurso;
            arquivo >> codigoCurso;
            Curso curso;
            curso.setNomeECod(nomeCurso, codigoCurso);
            aluno.adicionarCurso(curso);
        }
        alunos.push_back(aluno);
    }
    arquivo.close();
}

// salvar cursos no arquivo txt
void salvarCursos(vector<Curso> cursos){
    ofstream arquivo;
    arquivo.open("cursos.txt");
    //numero de cursos
    arquivo << cursos.size() << endl;
    int numCursos = cursos.size();
    for (int i = 0; i < numCursos; i++){
        arquivo << cursos[i].getNome() << endl;
        arquivo << cursos[i].getNumeroAlunos() << endl;
        arquivo << cursos[i].getCod() << endl;
        arquivo << cursos[i].getNomeProfessor() << endl;
    }    
    arquivo.close();
}

void carregarCursos(vector<Curso> &cursos){
    ifstream arquivo;
    arquivo.open("cursos.txt");
    int numCursos;
    arquivo >> numCursos;
    for (int i = 0; i < numCursos; i++){
        string nome, nomeProfessor;
        int codigo;
        int numeroaluno;
    
        getline(arquivo >> ws, nome);
        arquivo >> numeroaluno;
        arquivo >> codigo;
    
        getline(arquivo >> ws, nomeProfessor);

        Curso curso;
        curso.setNome(nome);
        curso.setNumeroAlunos(numeroaluno);
        curso.setCod(codigo);
        curso.setNomeProfessor(nomeProfessor);
        cursos.push_back(curso);
    }
    arquivo.close();
}

//salvar salas em arquivo txt

void salvarSalas(vector<Sala> salas){
    ofstream arquivo;
    arquivo.open("salas.txt");
    //numero de salas
    arquivo << salas.size() << endl;
    int numSalas = salas.size();
    for (int i = 0; i < numSalas; i++){
        arquivo << salas[i].getIdentificador() << endl;
        arquivo << salas[i].getCapacidade() << endl;
        arquivo << salas[i].getAlunos() << endl;
        //numero de dias
        int numDias = salas[i].semana.size();
        arquivo << salas[i].semana.size() << endl;
        for (int j = 0; j < numDias; j++){
            arquivo << salas[i].semana[j] << endl;
        }
    }
    arquivo.close();
}

//carregar salas do arquivo txt

void carregarSalas(vector<Sala> &salas){
    ifstream arquivo;
    arquivo.open("salas.txt");
    int numSalas;
    arquivo >> numSalas;
    for (int i = 0; i < numSalas; i++){
        int identificador;
        int capacidade, alunos;
        arquivo >> identificador;
        arquivo >> capacidade;
        arquivo >> alunos;
        int numDias;
        arquivo >> numDias;
        Sala sala;
        sala.setIdentificador(identificador);
        sala.setCapacidade(capacidade);
        sala.setAlunos(alunos);

        for (int j = 0; j < numDias; j++){
            string disponibilidade;
            getline(arquivo >>ws, disponibilidade);
            sala.setDisponibilidade(j, disponibilidade);
        }
        salas.push_back(sala);
    }
    arquivo.close();
}

//salvar professores em arquivo txt
void salvarProfessores(vector<Professor> professores){
    ofstream arquivo;
    arquivo.open("professores.txt");
    //numero de professores
    arquivo << professores.size() << endl;
    int numProfessores = professores.size();
    for (int i = 0; i < numProfessores; i++){
        arquivo << professores[i].getNome() << endl;
        arquivo << professores[i].getCpf() << endl;
        arquivo << professores[i].getContato() << endl;
        arquivo << professores[i].codCurso << endl;
        }
    arquivo.close();
}

void carregarProfessores(vector<Professor> &professores){
    ifstream arquivo;
    arquivo.open("professores.txt");
    int numProfessores;
    arquivo >> numProfessores;
    for (int i = 0; i < numProfessores; i++){
        string nome, cpf, contato;
        int codCurso;
        //ler uma linha inteira do arquivo
        getline(arquivo >> ws, nome);
        getline(arquivo >> ws, cpf);
        getline(arquivo >> ws, contato);
        arquivo >> codCurso;
        Professor professor(nome, cpf, contato);
        professor.setCodCurso(codCurso);
        professores.push_back(professor);
    }
    arquivo.close();
}

#endif
