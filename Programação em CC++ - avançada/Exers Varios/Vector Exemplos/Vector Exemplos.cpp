// Vector Exemplos.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Vector ao contrário do array é dinâmico e permite adicionar e remover elementos
// Funciona como um array redimensionável

#include <iostream>
#include <vector>
#include <Windows.h>
#include <conio.h>
#include <string>

using namespace std;

struct CARRO
{
    string marca = "";
    int anoFabrico = 0;
    float autonomia = 0.0;
};

int main()
{
    SetConsoleOutputCP(1252);

    vector <string> apelidos;   // Vector vazio
    vector <string> nomes = { "Maria", "Nuno", "Joana", "Rui", "Marta" };

    cout << "\n\tTamanho do vector apelidos:    " << apelidos.size();
    cout << "\n\tTamanho do vector nomes:    " << nomes.size() << endl;
    // Imprimir os valores do vector através da indexação
    for (int i = 0; i < nomes.size(); i++)
    {
        cout << "\t" << nomes[i];
    }
    cout << endl;

    // Imprimir os valores do vector sem usar indexação
    for (string nome : nomes)
    {
        cout << "\t" << nome;
    } 
    cout << endl;

    for (auto nome : nomes)
    {
        cout << "\t" << nome;
    }
    cout << endl;

    nomes[0] = "Susana";
    nomes.push_back("Vitor");   // Adiciona a nova no fim do vector
    nomes.push_back("Maria");
        
    // Imprimir os valores do vector sem usar indexação
    for (string nome : nomes)
    {
        cout << "\t" << nome;
    }
    nomes.pop_back();           // Remove o ultimo elemento do vector
    cout << endl;

    for (string nome : nomes)
    {
        cout << "\t" << nome;
    }
    cout << endl;

    // Acedendo através de [] não permite apanhar a exceção gerada
    try
    {
        // cout << "\n\t" << nomes[7] << endl;
        // cout << "\n\t" << nomes.at(7) << endl;      // A função at permite devolver o erro gerado
        nomes.at(7) = " Sara";
    }
    catch (const std::exception& ex)
    {
        cout << "\n\tValor do elemento no indice 7:     " << ex.what() << endl;
    }

    apelidos.push_back("Santos");
    if (apelidos.empty())
        cout << "\n\tApelidos está vazio" << endl;
    else 
        cout << "\n\tApelidos tem elementos" << endl;

    // vector de struct (tipo definido pelo utilizador)
    vector<CARRO> carritos;
    CARRO aux;

    do
    {
        cout << "\n\tMarca:      ";
        // cin >> aux.marca; só serve para ler 1 palavra
        getline(cin, aux.marca);
        cout << "\n\tAno de fabrico:    ";
        cin >> aux.anoFabrico;
        cout << "\n\tAutonomia:    ";
        cin >> aux.autonomia;
        carritos.push_back(aux);        // Adiciona a struct preenchida no fim do vector
        cout << "\n\tInserir outro carro (S/N)?      ";
        cin.ignore(1, '\n');            // Consome o Enter que ficou no buffer
    } while (toupper(_getch()) == 'S');

    system("cls");
    cout << "\n\tDados dos carros" << endl;
    // Imprimir os dados inseridos no vector
    for (auto car : carritos)
    {
        cout << "\n\t" << car.marca << "\n\tAno de fabrico" << car.anoFabrico << "\n\tAutonomia:    " << car.autonomia << " km" << endl;
    }

    cout << "\n\n";
    return 0;
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
