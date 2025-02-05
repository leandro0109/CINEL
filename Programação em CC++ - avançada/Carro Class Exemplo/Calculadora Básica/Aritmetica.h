#pragma once
#include <iostream>
using namespace std;

class Aritmetica
{
	// Os atributos e estas funções são private
	double op1, op2;
	char oper;

	double adicao()
	{
		return op1 + op2;
	}

	double subtracao()
	{
		return op1 - op2;
	}

	double multiplicacao()
	{
		return op1 * op2;
	}

	double divisao()
	{
		if (op2 == 0)
			throw invalid_argument("Divisão por zero é impossivel...");
		return op1 / op2;
	}

public:		// Funções publicas
	void setOperandos(double n1, double n2)
	{
		op1 = n1;
		op2 = n2;
	}

	void setOperacao(char op)
	{
		oper = op;
	}

	double executarCalculo()
	{
		switch (oper)
		{
		case '+': return adicao(); break;
		case '-': return subtracao(); break;
		case '*': return multiplicacao(); break;
		case '/': return divisao(); break;
		default: throw invalid_argument("Operação inválida"); break;
		}
	}
};

