// Write Files.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;

// Criar um ficheiro de texto para escrita

int main()
{
    ofstream fwrite;    // Cria um stream para escrever num ficheiro de texto
    // fwrite.open("C:\\Users\\leand\\EFA57 Cinel - Programador\Programação em CC++ - avançada.txt")     // O ficheiro vai ser criado na pasta com os nomes indicados  
    fwrite.open("Fich2Texto.txt");                                                                     // O ficheiro é criado na pasta do projeto

    // Verificar se houve erro
    // if (fwrite.fail())
    if(!fwrite)     // Se devolveu falso
    {
        cout << "\n\tErro na criação do ficheiro para escrita";
        exit(1);
    }
    else
    {
        cout << "\n\tFicheiro criado com sucesso!" << endl;
        fwrite << "Este é um texto exemplo\n\tPara explorar a utilização de ficheiros em C++";
        fwrite.close();     // Fecha o stream. Boa prática e liberta memória
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
