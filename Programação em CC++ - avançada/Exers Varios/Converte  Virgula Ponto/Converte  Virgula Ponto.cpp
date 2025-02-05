#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleOutputCP(1252);

    string strnum;
    double numero;
    bool valido;

    do
    {
        valido = true;
        cout << "\n\tDigite um n� com casas decimais (use , ou .):  ";
        cin >> strnum;
        cout << "\n\tString digitada: " << strnum << endl;
        // Se o 1� digito n�o for . ou , ou - ou algarismo ent�o n�o � v�lido
        if (!(strnum[0] == '.' || strnum[0] == ',' || strnum[0] == '-' || isdigit(strnum[0])))
            valido = false;
        else {
            if (strnum[0] == ',') { // Para o caso de come�ar com parte fracion�ria (sem zero)
                strnum[0] = '.';    // Substitui a , por .
            }
            for (int i = 1; i < size(strnum); i++)
            {
                if (!(isdigit(strnum[i]) || strnum[i] == ',' || strnum[i] == '.')) {
                    valido = false;
                    break;
                }
                if (strnum[i] == ',') {
                    strnum[i] = '.';
                }
            }
        }
    } while (!valido);
    numero = stod(strnum);
    cout << "\n\tN�mero convertido:  " << numero << endl;
}