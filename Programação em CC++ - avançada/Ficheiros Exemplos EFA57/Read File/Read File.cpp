// Read File.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;

// Criar um stream para leitura de um ficheiro de texto
int main()
{
    SetConsoleOutputCP(1252);

    fstream fread;      // Stream para leitura de files
    fread.open("C:\\Users\\leand\\EFA57 Cinel - Programador\\Programação em CC++ - avançada\\Ficheiros Exemplos EFA57\\Write Files\\Fich1Texto.txt");

    if (fread.fail())
    {
        cout << "\n\tErro na criação do ficheiro para leitura!";
        exit(1);
    }
    else
    {
        cout << "\n\tAbertura do ficheiro para leitura com sucesso" << endl;
        cout << endl;
        string str;     // Para onde vai ser lido o texto de cada linha do ficheiro
        // Loop para ler linha a linha
        while (getline(fread, str))
        {
            cout << str << endl;        // Imprime no ecrã a linha lida
        }
        fread.close();      // Fecha o stream e liberta memória
        return 0;
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
