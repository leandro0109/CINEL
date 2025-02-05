// Iteradores.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

// Iterador - Funciona como um apontador no C
 //            Aponta o endereço de memoria de um elemento do vector
 // Funções do iterador:
 // begin() - Retorna um iterador que aponta para o 1º elemento
 // end()   - Aponta a posição de memoria a seguir ao ultimo elemento 
 // Para o percurso inverso
 // rbegin()- Retorna um iterador para o ultimo elemento
 // rend()  - Retorna um iterador para o 1º elemento

struct DADO
{
	int num;
	string nome;
	bool val;
};

int main()
{
	vector<int> numeros1 = { 100,200,300,400 };
	vector<int> numeros2(3, 0);		// 3 é a dimensão do vector;	0:	valor que preencherá todos os elementos

	vector<int>::iterator iter;		// cria um iterador para inteiro
	iter = numeros1.begin();
	cout << "\n\tPrimeiro elemento do vector:		" << *iter;

	iter = numeros1.end() - 1;
	cout << "\n\tUltimo elemento do vector:		" << *iter;

	cout << "\n\tImprimir os valores do vector com for range" << endl;
	for (int n : numeros1)
	{
		cout << " " << n;
	}

	cout << "\n\tImprimir os valores do vector com Iterador" << endl;
	for (iter = numeros1.begin(); iter <= numeros1.end() - 1; iter++)
	{
		cout << " " << *iter;
	}

	cout << "\n\tImprimir os valores do vector com Iterador" << endl;
	for (iter = numeros1.begin(); iter != numeros1.end(); iter++)
	{
		cout << " " << *iter;
	}

	// Eliminar o valor 200 do vector
	for (iter = numeros1.begin(); iter != numeros1.end(); iter++)
	{
		int x = *iter;
		if (x == 200)
			iter = numeros1.erase(iter);
	}
	cout << "\n\tImprimir os valores do vector com Iterador" << endl;
	for (iter = numeros1.begin(); iter != numeros1.end(); iter++)
	{
		cout << " " << *iter;
	}

	vector<string> nomes = { "Maria", "Carlos", "Miguel", "Beatriz", "Marta" };
	vector<string>::iterator itNomes;

	for (itNomes = nomes.begin(); itNomes != nomes.end();)
	{
		string str = *itNomes;
		for (int i = 0; i < size(str); i++)
		{
			if (str[i] == 't')
			{
				itNomes = nomes.erase(itNomes);
				break;
			}
		}
		itNomes++;
	}

	for (itNomes = nomes.begin(); itNomes != nomes.end();)
	{
		string str = *itNomes;

		if (toupper(str[0]) == 'M')
		{
			itNomes = nomes.erase(itNomes);		// Remove todos os nomes começados por 'M'
		}
		else
			itNomes++;
	}
	cout << "\n\tImprimir os valores do vector com Iterador" << endl;
	for (string nome : nomes)
	{
		cout << " " << nome;
	}

	vector<DADO> dados;
	DADO dad;
	for (int i = 0; i < 3; i++)
	{
		cout << "\n\tDigite o numero:	";
		cin >> dad.num;
		cin.ignore(1, '\n');
		cout << "\n\tDigite o nome:	";
		cin >> dad.nome;
		cout << "\n\tDigite um valor booleano:	";
		cin >> dad.val;
		dados.push_back(dad);
	}

	DADO d;
	int n;
	cout << "\n\tIndique o numero do elemento a remover:	";
	cin >> n;

	vector<DADO>::iterator it;
	for (it = dados.begin(); it != dados.end();)
	{
		d = *it;
		if (d.num == n)
		{
			it = dados.erase(it);
		}
		else
			it++;
	}
	cout << "\n\tImprimir os valores do vector com Iterador" << endl;
	for (auto elemento : dados)
	{
		cout << " " << elemento.num << " " << elemento.nome << " " << elemento.val << endl;
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
