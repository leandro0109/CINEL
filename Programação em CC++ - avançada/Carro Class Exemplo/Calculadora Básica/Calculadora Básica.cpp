// Calculadora Básica.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include "Aritmetica.h"
#include <conio.h>

using namespace std;

int main()
{
	SetConsoleOutputCP(1252);
	Aritmetica calculadora;
	double num1, num2;
	char op;
	
	do
	{
		system("cls");
		cout << "\n\t___________________________________________________________";
		cout << "\n\t		Calculadora Básica";
		cout << "\n\t___________________________________________________________";
		cout << "\n";

		cout << "\n\tDigite o operando 1 e o operando 2:	";
		cin >> num1 >> num2;
		cout << "\n\tDigite a operação:		";
		op = _getche();
		calculadora.setOperandos(num1, num2);
		calculadora.setOperacao(op);
		try
		{
			cout << "\n\tResultado = " << calculadora.executarCalculo() << endl;
		}
		catch (exception ex)
		{
			cout << "\n\t" << ex.what() << endl;
		}
		cout << "\n\tQuer realizar outra operação (S/N)?	";
	} while (toupper(_getch()) == 'S');
}
