// Apontadores.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
    // & (operador referencia) para obter o endereço de memória de uma variável
    // * (operador de referencia) obtem o conteúdo armazenado num endereço de memória

    SetConsoleOutputCP(1252);
    
    int x = 10;
    int &add = x;
    cout << "\n\tEste é o valor de x:    " << x << endl;
    cout << "\n\tEndereço de memória da variável x:     " << add << endl;
    cout << "\n\tEndereço de memória da variável x:     " << &add << endl;
    cout << "\n\tEndereço de memória da variável x:     " << &x << endl;

    int* pt;
    pt = &x;    // Atribui o endereço de memória da variável x
    cout << "\n\tValor armazenado na variável x:    " << *pt << endl;

    // Calcular a soma de todos os valores armazenados num array

    int nums[] = { 1,2,3,4,5,6,7,8,9,10 };
    int* ptr;
    int soma = 0, i = 0;

    for (ptr = &nums[0]; i < size(nums); i++)
    {
        soma += *ptr;
        ptr++;
    }
    cout << "\n\tSoma = " << soma << endl;
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
