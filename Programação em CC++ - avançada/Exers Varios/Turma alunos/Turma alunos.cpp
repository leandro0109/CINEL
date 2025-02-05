// Turma alunos.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Elaborar um programa que leia o nome, a idade, a nota e o número de cada aluno da turma e apresente:
// a) o nome e o nº dos alunos com a maior nota da turma
// b) todos os dados dos alunos
// c) a média da turma
// d) alterar dados do aluno
// e) inserir novo aluno
// f) remover aluno
// Utilize structs e vector na resolução do programa

// Bibliotecas
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <Windows.h>
#include <iomanip>

using namespace std;

struct ALUNO
{
	string nome = "";
	int idade = 0;
	float nota = 0.0;
	int nrAluno = 0;
};

// Protótipos das funções
void menuOpcoes(int& op);
void inserirAlunos(vector<ALUNO>& alunos, ALUNO aux);
void somarNotas(vector<ALUNO>& alunos, float& somaNotas, float& maiorNota);
void mostrarDadosAlunos(vector<ALUNO> alunos);
void editarAluno(vector<ALUNO>& alunos, int selecionarAluno);
void removerAluno(vector<ALUNO>& alunos, vector<ALUNO>::iterator it, ALUNO aux, bool alunoValido, int selecionarAluno);

int main()
{
	SetConsoleOutputCP(1252);

	vector<ALUNO> alunos;
	ALUNO aux;
	vector<ALUNO>::iterator it;
	float somaNotas = 0, maiorNota = 0;
	int op = 0, selecionarAluno = 0;
	bool alunoValido = false;

	inserirAlunos(alunos, aux);

	do
	{
		menuOpcoes(op);

		switch (op)
		{
		case 1:
			system("cls");
			editarAluno(alunos, selecionarAluno);
			break;
        case 2:
			system("cls");
			inserirAlunos(alunos, aux);
			somarNotas(alunos, somaNotas, maiorNota);
			break;
		case 3:
			system("cls");
			removerAluno(alunos, it, aux, alunoValido, selecionarAluno);
			cout << "\n\tPrima tecla para voltar ao menu ";
			_getch();
			break;
		case 4:
			system("cls");
			mostrarDadosAlunos(alunos);
			cout << "\n\tPrima tecla para voltar ao menu ";
			_getch();
			break;
		case 5:
			system("cls");
			somarNotas(alunos, somaNotas, maiorNota);
			cout << "\n\tMédia da turma:     " << fixed << setprecision(2) << somaNotas / alunos.size() << endl;     // Imprimir média de notas dos alunos
			cout << "\n\tPrima tecla para voltar ao menu ";
			_getch();
			break;
		case 6:
			system("cls");
			somarNotas(alunos, somaNotas, maiorNota);
			for (auto aluno : alunos)
			{
				if (aluno.nota > somaNotas / alunos.size())
					cout << "\n\tO aluno " << aluno.nome << " com o nr de aluno " << aluno.nrAluno << " teve nota acima da média (" << fixed << setprecision(2) << aluno.nota << ")";
			}
			cout << "\n\tMaior nota:     " << fixed << setprecision(2) << maiorNota << endl;
			cout << "\n\tPrima tecla para voltar ao menu ";
			_getch();
			break;
		case 7:
			system("cls");
			cout << "\n\tO programa irá encerrar em breve..." << endl;
			break;
	}
} while (op != 7);

return 0;
}

// Funções
// _________________________________________________________

void menuOpcoes(int& op)
{
	system("cls");
	cout << "\n\t--------------- Menu Opções --------------- ";
	cout << "\n";
	cout << "\n\t\t1 - Alterar dados alunos";
	cout << "\n\t\t2 - Inserir novo aluno";
	cout << "\n\t\t3 - Remover aluno";
	cout << "\n\t\t4 - Mostrar lista alunos";
	cout << "\n\t\t5 - Mostrar média turma";
	cout << "\n\t\t6 - Mostrar alunos maior nota";
	cout << "\n\t\t7 - Terminar Programa";
	cout << "\n";
	cout << "\n\t\tSelecione uma das opções:  ";
	cin >> op;
	cin.ignore(1, '\n');
}

void inserirAlunos(vector<ALUNO>& alunos, ALUNO aux)
{
	do
	{
		cout << "\n\tNome:  ";
		getline(cin, aux.nome);
		cout << "\n\tIdade:     ";
		cin >> aux.idade;
		cout << "\n\tNota:     ";
		cin >> aux.nota;
		cout << "\n\tNr de aluno:     ";
		cin >> aux.nrAluno;
		alunos.push_back(aux);

		cout << "\n\tDeseja introduzir dados de mais alunos (S/N)?  " << endl;
		cin.ignore(1, '\n');
	} while (toupper(_getch()) == 'S');

}

void somarNotas(vector<ALUNO>& alunos, float& somaNotas, float& maiorNota)
{
	// Reset na soma e maior nota, para caso tenham sido inseridas novas notas ou modificadas
	somaNotas = 0;
	maiorNota = 0;
	// Soma notas dos alunos para calcular a média
	for (auto aluno : alunos)
	{
		somaNotas += aluno.nota;
		if (aluno.nota > maiorNota)
			maiorNota = aluno.nota;
	}
}

void mostrarDadosAlunos(vector<ALUNO> alunos)
{
	cout << "\n\tDados da turma" << endl;
	// Imprimir os dados inseridos no vector
	for (auto aluno : alunos)
	{
		cout << "\n\t" << "\n\tNome:     " << aluno.nome << "\n\tIdade:    " << aluno.idade << "\n\tNota:    " << fixed << setprecision(2) << aluno.nota << "\n\tNr de aluno:    " << aluno.nrAluno << endl;
	}
}

void editarAluno(vector<ALUNO>& alunos, int selecionarAluno)
{
	system("cls");
	escolhernovoaluno:
	mostrarDadosAlunos(alunos);
	cout << "\n\tDigite o nr do aluno que deseja editar:    ";
	cin >> selecionarAluno;
	for (auto& aluno : alunos)
	{
		if (aluno.nrAluno == selecionarAluno)
		{
			int opEditarAluno = 0;
			do
			{
				system("cls");
				cout << "\n\t1 - Alterar nome do aluno";
				cout << "\n\t2 - Alterar idade do aluno";
				cout << "\n\t3 - Alterar nota do aluno";
				cout << "\n\t4 - Alterar nr do aluno";
				cout << "\n\t5 - Escolher outro aluno";
				cout << "\n\t6 - Sair";
				cout << "\n\n\tSelecione uma opção:   ";
				cin >> opEditarAluno;
				cin.ignore(1, '\n');

				switch (opEditarAluno)
				{
				case 1:
					cout << "\n\tNovo nome:     ";
					getline(cin, aluno.nome);
					cout << "\n\tNome alterado com sucesso.";
					cout << "\n\tPrima tecla para sair ";
					_getch();
					break;
				case 2:
					cout << "\n\tNova idade:     ";
					cin >> aluno.idade;
					cout << "\n\tIdade alterada com sucesso.";
					cout << "\n\tPrima tecla para sair ";
					_getch();
					break;
				case 3:
					cout << "\n\tNova nota:     ";
					cin >> aluno.nota;
					cout << "\n\tNota alterada com sucesso.";
					cout << "\n\tPrima tecla para sair ";
					_getch();
					break;
				case 4:
					cout << "\n\tNovo nr aluno:     ";
					cin >> aluno.nrAluno;
					cout << "\n\tNr aluno alterado com sucesso.";
					cout << "\n\tPrima tecla para sair ";
					_getch();
					break;
				case 5:
					goto escolhernovoaluno;
					break;
				}
			} while (opEditarAluno != 6);
		}
	}
}

void removerAluno(vector<ALUNO>& alunos, vector<ALUNO>::iterator it, ALUNO aux, bool alunoValido, int selecionarAluno)
{
	if (alunos.size() <= 0)
	{
		cout << "\n\t0 elementos restantes na turma, adicione mais elementos." << endl;
		cout << "\n\tPrima tecla para voltar ao menu ";
		_getch();
		return;
	}

	do
	{
		for (auto aluno : alunos)
		{
			cout << "\n\tDigite o nº do aluno a ser removido:   ";
			cin >> selecionarAluno;
			if (selecionarAluno == aluno.nrAluno)
			{
				alunoValido = true;
				break;
			}
			else
				cout << "\n\tNº Aluno inserido inválido...";
		}
	} while (alunoValido == false);

	for (it = alunos.begin(); it != alunos.end();)
	{
		aux = *it;
		if (aux.nrAluno == selecionarAluno)
		{
			it = alunos.erase(it);
			cout << "\n\tAluno nº " << selecionarAluno << " removido com sucesso." << endl;
			break;
		}
		it++;
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
