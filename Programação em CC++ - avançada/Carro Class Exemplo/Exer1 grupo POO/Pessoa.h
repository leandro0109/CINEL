#pragma once
#include <iostream>
using namespace std;

class Pessoa
{
	string nome;
	int anoNascimento;

	int calcularIdade()
	{
		return 2025 - anoNascimento;
	}

public:
	void setDados(string nom, int anoNasc)
	{
		nome = nom;
		anoNascimento = anoNasc;
	}

	void mostrarDados()
	{
		cout << "\n\tNome\t" << nome << "\n\tAno Nascimento\t" << anoNascimento << "\n\tIdade:\t" << calcularIdade();
	}
};

