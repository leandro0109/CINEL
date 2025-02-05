// W_R_VectorStructAluno.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//  Elabore um programa para realizar as seguintes ações sobre os alunos da turma:  
//      Inserir os dados dos alunos
//      Imprimir os dados dos alunos
//  O programa deverá permitir gravar os dados num ficheiro, carregar os dados do ficheiro e 
//  acrescentar outros dados ao ficheiro

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <Windows.h>
#include <conio.h>

using namespace std;

#define MAX_NOME 20

struct ALUNO
{
    int numero;
    char nome[MAX_NOME];
    float nota;
};

// Prótotipos
void inserirDados(vector<ALUNO>& turma);
char menuOpcoes();
void imprimirDados(vector<ALUNO>& turma);
void escreverFicheiro(vector<ALUNO>& turma);
void lerFicheiro(vector<ALUNO>& turma);
void acrescentarFicheiro();

int main()
{
    SetConsoleOutputCP(1252);
    // Ações a realizar 
    // Loop 
    //      Menu()
    //      caso 1 - Inserir dados
    //      caso 2 - Imprimir dados
    //      caso 3 - Escrever no ficheiro
    //      caso 4 - Ler do ficheiro
    //      caso 5 - Acrescentar dados aos que já se encontram no ficheiro (append)
    //      caso 6 - Terminar programa

    vector<ALUNO> turma;
    char oper;

    do
    {
        oper = menuOpcoes();
        switch (oper)
        {
            case '1':   inserirDados(turma);        break;
            case '2':   imprimirDados(turma);       break;
            case '3':   escreverFicheiro(turma);    break;
            case '4':   lerFicheiro(turma);         break;
            case '5':   acrescentarFicheiro();      break;
            case '6': break;
        }
    } while (oper != '6');

    cout << "\n\tFim do programa..." << endl;
}

// Funções do programa
void inserirDados(vector<ALUNO>& turma)
{
    ALUNO al;
    cout << "\n\tPreencher os dados dos alunos no vector" << endl;
    do
    {
        cout << "\n\tNº ";
        cin >> al.numero;
        cin.ignore();           
        cout << "\n\tNome:  ";
        // getline(cin, al.nome);      // leitura para string
        cin.getline(al.nome, MAX_NOME);
        cout << "\n\tNota:  ";
        cin >> al.nota;
        // Adicionar este aluno ao vector
        turma.push_back(al);
        cout << "\n\tInserir outro aluno (S/N)?     ";
    } while (toupper(_getch() == 'S'));
}

char menuOpcoes()
{
    char op;
    do
    {
        system("cls");
        cout << "\n\t________________________________________________________" << endl;
        cout << "\n\t   1 - Inserir os dados do aluno" << endl;
        cout << "\n\t   2 - Imprimir os dados do aluno" << endl;
        cout << "\n\t   3 - Guardar dados no ficheiro" << endl;
        cout << "\n\t   4 - Carregar o ficheiro com dados dos alunos" << endl;
        cout << "\n\t   5 - Acrescentar dados ao ficheiro" << endl;
        cout << "\n\t   6 - Terminar o programa" << endl;
        cout << "\n\t________________________________________________________";
        cout << "\n\n\tEscolha uma opção:   ";
        op = _getch();
    } while (op < '1' || op > '6');
    return op;
}

void imprimirDados(vector<ALUNO>& turma)
{
    cout << "\n\tImprimir dados de todos os alunos da turma" << endl;
    for (ALUNO aluno : turma)
    {
        cout << "\n\tNº:    " << aluno.numero << endl;
        cout << "\tNome:    " << aluno.nome << endl;
        cout << "\tNota:    " << aluno.nota << endl; 
    }
    cout << "\n\tPrima tecla para continuar ... ";
    _getch();
}

void escreverFicheiro(vector<ALUNO>& turma)
{
    fstream file;
    file.open("DadosAlunos.dat", ios::out | ios::binary);       // Cria o ficheiro se ainda não existir
    if (file)
    {
        for (ALUNO aluno : turma)
        {
            file.write((char*)(&aluno), sizeof(aluno));
        }
        file.close();
        cout << "\n\tSucesso na escrita do ficheiro!" << endl;
        cout << "\n\tPrima tecla para continuar ... ";
        _getch();
    }
    else
    {
        cout << "\n\tErro na abertura do ficheiro para escrita ...";
        cout << "\n\tPrima tecla para continuar ... ";
        _getch();
        exit(1);
    }
}

void lerFicheiro(vector<ALUNO>& turma)
{
    fstream file;
    ALUNO aluno;

    turma.clear();
    file.open("DadosAlunos.dat", ios::in | ios::binary);
    if (file)
    {
        while (true)
        {
            file.read((char*)(&aluno), sizeof(aluno));
            if (!file)
            {
                cout << "\n\tFim do ficheiro!...";
                break;
            }
            turma.push_back(aluno);     // Adiciona a struct lida do ficheiro no final do vector
        }
        file.close();
        cout << "\n\tFicheiro lido com sucesso!" << endl;
        cout << "\n\tPrima tecla para continuar ... ";
        _getch();
    }
    else
    {
        cout << "\n\tErro na abertura do ficheiro para leitura!" << endl;
        cout << "\n\tPrima tecla para continuar ... ";
        _getch();
        exit(1);
    }
}

void acrescentarFicheiro()
{
    vector<ALUNO> alunos;
    fstream file;

    inserirDados(alunos);
    file.open("DadosAlunos.dat", ios::app | ios::binary);
    if (file)
    {
        for (ALUNO aluno : alunos)      // Já sei quantos elementos estão, em caso de leitura tem que ser while até chegar ao fim do ficheiro
        {
            file.write((char*)(&aluno), sizeof(aluno));
        }
        file.close();
        cout << "\n\tDados acrescentados no ficheiro com sucesso!" << endl;
    }
    else
    {
        cout << "\n\tErro na abertura do ficheiro para acrescentar dados ..." << endl;
        cout << "\n\tPrima tecla para continuar ... ";
        _getch();
        exit(1);
    }
}