// Jogo da forca.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <Windows.h>
#include <conio.h>
#include <fstream>
#include <string>
#include <ctime>
#include <algorithm>

using namespace std;

// Macros
#define UP    72
#define DOWN  80
#define ENTER 13

// Enumerated das cores 
enum cores {
	color_black = 0,
	color_dark_blue = 1,
	color_dark_green = 2,
	color_light_blue = 3,
	color_dark_red = 4,
	color_magenta = 5,
	color_orange = 6,
	color_light_gray = 7,
	color_gray = 8,
	color_blue = 9,
	color_green = 10,
	color_cyan = 11,
	color_red = 12,
	color_pink = 13,
	color_yellow = 14,
	color_white = 15
};

struct BONECO
{
	// Est�gio 0: Sem nenhum desenho do boneco
	string estagio0 =
		"\t\t   _______\n"
		"\t\t   |/     |\n"
		"\t\t   |      \n"
		"\t\t   |      \n"
		"\t\t   |      \n"
		"\t\t   |      \n"
		"\t\t___|___		";
	// Est�gio 1: Apenas a cabe�a
	string estagio1 =
		"\t\t   _______\n"
		"\t\t   |/     |\n"
		"\t\t   |      O\n"
		"\t\t   |      \n"
		"\t\t   |      \n"
		"\t\t   |      \n"
		"\t\t___|___		";

	// Est�gio 2: Cabe�a + Tronco
	string estagio2 =
		"\t\t   _______\n"
		"\t\t   |/     |\n"
		"\t\t   |      O\n"
		"\t\t   |      |\n"
		"\t\t   |      \n"
		"\t\t   |      \n"
		"\t\t___|___		";

	// Est�gio 3: Cabe�a + Tronco + Bra�o Esquerdo
	string estagio3 =
		"\t\t   _______\n"
		"\t\t   |/     |\n"
		"\t\t   |      O\n"
		"\t\t   |     /|\n"
		"\t\t   |      \n"
		"\t\t   |      \n"
		"\t\t___|___		";

	// Est�gio 4: Cabe�a + Tronco + Bra�os (Esquerdo e Direito)
	// Para mostrar a barra invertida � necess�rio usar duas barras invertidas (\\)
	string estagio4 =
		"\t\t   _______\n"
		"\t\t   |/     |\n"
		"\t\t   |      O\n"
		"\t\t   |     /|\\\n"
		"\t\t   |      \n"
		"\t\t   |      \n"
		"\t\t___|___		";

	// Est�gio 5: Cabe�a + Tronco + Bra�os + Perna Esquerda
	string estagio5 =
		"\t\t   _______\n"
		"\t\t   |/     |\n"
		"\t\t   |      O\n"
		"\t\t   |     /|\\\n"
		"\t\t   |     /\n"
		"\t\t   |      \n"
		"\t\t___|___		";


	// Est�gio 6: Boneco Completo: Cabe�a + Tronco + Bra�os + Pernas (Esquerda e Direita)
	string estagio6 =
		"\t\t   _______\n"
		"\t\t   |/     |\n"
		"\t\t   |      O\n"
		"\t\t   |     /|\\\n"
		"\t\t   |     / \\\n"
		"\t\t   |      \n"
		"\t\t___|___		";

} estagios;

unsigned char getCode();
int menuPrincipal(HANDLE hc);
int menuNrJogadores(HANDLE hc);
void menuOpcoes(HANDLE hc, int op, string st1, string st2);
void lerPalavras(vector<string>& palavras);
void desenharEstagiosBoneco(BONECO estagios, int vidas);
int adivinharLetra(string palavraEscolhida, int& vidas, BONECO estagios, HANDLE hc);
void compararMostrarPalavra(string palavraEscolhida, char& letra, string& adivinharPalavra);
void guardarPontuacao(int pontuacaoJ1, int pontuacaoJ2);

int main()
{
	SetConsoleOutputCP(1252);

	HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);

	bool jogar = true;

	do
	{
		int tentativas = 6, opcao = 1, nrJogadores = 1, vidas = 6, pontuacaoJ1 = 0, pontuacaoJ2 = 0;
		vector<string> palavras;
		string palavraEscolhida = "";

		opcao = menuPrincipal(hconsole);
		if (opcao == 1)
		{
			nrJogadores = menuNrJogadores(hconsole);
			if (nrJogadores == 1)
			{
				lerPalavras(palavras);
				srand(time(0));
				palavraEscolhida = palavras[rand() % palavras.size()];
				adivinharLetra(palavraEscolhida, vidas, estagios, hconsole);
			}
			else if (nrJogadores == 2)
			{
				repetirpalavraJ1:
				system("cls");
				SetConsoleTextAttribute(hconsole, color_light_blue);
				cout << "\n\tVez do jogador 1 digitar a palavra secreta:	";
				SetConsoleTextAttribute(hconsole, color_white);
				cin >> palavraEscolhida;	
				for (int i = 0; i < palavraEscolhida.length(); i++)
				{
					if (!isalpha(palavraEscolhida[i]))
					{
						SetConsoleTextAttribute(hconsole, color_red);
						cout << "\n\tPalavra inserida inv�lida...";
						SetConsoleTextAttribute(hconsole, color_white);
						Sleep(2000);
						goto repetirpalavraJ1;
					}
					else
					{
						SetConsoleTextAttribute(hconsole, color_green);
						cout << "\n\tPalavra inserida validada com sucesso!";
						SetConsoleTextAttribute(hconsole, color_white);
						break;
					}
				}
				SetConsoleTextAttribute(hconsole, color_yellow);
				cout << "\n\tVez do jogador 2 descobrir a palavra secreta!";
				SetConsoleTextAttribute(hconsole, color_white);
				cout << "\n\tO jogo ir� iniciar em breve...";
				Sleep(5500);
				pontuacaoJ2 += adivinharLetra(palavraEscolhida, vidas, estagios, hconsole);

				repetirpalavraJ2:
				system("cls");
				SetConsoleTextAttribute(hconsole, color_light_blue);
				cout << "\n\tVez do jogador 2 digitar a palavra secreta:	";
				SetConsoleTextAttribute(hconsole, color_white);
				cin >> palavraEscolhida;
				for (int i = 0; i < palavraEscolhida.length(); i++)
				{
					if (!isalpha(palavraEscolhida[i]))
					{
						SetConsoleTextAttribute(hconsole, color_red);
						cout << "\n\tPalavra inserida inv�lida...";
						SetConsoleTextAttribute(hconsole, color_white);
						Sleep(2000);
						goto repetirpalavraJ2;
					}
					else
					{
						SetConsoleTextAttribute(hconsole, color_green);
						cout << "\n\tPalavra inserida validada com sucesso!";
						SetConsoleTextAttribute(hconsole, color_white);
						break;
					}
				}
				SetConsoleTextAttribute(hconsole, color_yellow);
				cout << "\n\tVez do jogador 1 descobrir a palavra secreta!";
				SetConsoleTextAttribute(hconsole, color_white);
				cout << "\n\tO jogo ir� iniciar em breve...";
				Sleep(5500);
				pontuacaoJ2 += adivinharLetra(palavraEscolhida, vidas, estagios, hconsole);

				guardarPontuacao(pontuacaoJ1, pontuacaoJ2);	// Guarda pontua��es de ambos os jogadores
			}
		}
		else
			jogar = false;
	} while (jogar == true);


	system("cls");
	cout << "\n\n\tO programa ir� ser encerrado em breve... At� � pr�xima!" << endl;

	cout << "\n\n";
	return 0;
}

// Fun��es

// Obtem o c�digo da tecla premida
unsigned char getCode()
{
	unsigned char key = _getch();

	if (key == 0 || key == 224)
	{
		key = _getch();
		cout << (int)key << "   " << key << endl;
	}
	return key;
}

// Menu para jogar ou terminar o programa
int menuPrincipal(HANDLE hc)
{
	unsigned char key;
	int op = 1;

	// Imprime as op��es
	system("cls");
	SetConsoleTextAttribute(hc, color_dark_green);
	cout << "\n\tIniciar Jogo" << endl;
	SetConsoleTextAttribute(hc, color_white);
	cout << "\n\tTerminar Jogo" << endl;

	do
	{
		cout << "\n\n\tUse as setas direcionais verticais para escolher a op��o:    ";
		key = getCode();
		switch (key)
		{
		case UP:  op == 1 ? op = 1 : op--; break;   // Sobe no menu
		case DOWN: op == 2 ? op = 2 : op++; break;  // Desce no menu
		}
		menuOpcoes(hc, op, "\n\tIniciar Jogo", "\n\tTerminar Jogo");
	} while (key != ENTER);
	return op;
}

// Menu de escolha do nr de jogadores
int menuNrJogadores(HANDLE hc)
{
	unsigned char key;
	int op = 1;

	system("cls");
	// Imprime as op��es
	SetConsoleTextAttribute(hc, color_dark_green);
	cout << "\n\tSingleplayer" << endl;
	SetConsoleTextAttribute(hc, color_white);
	cout << "\n\tMultiplayer" << endl;

	do
	{
		cout << "\n\n\tUse as setas direcionais verticais para escolher a op��o:    ";
		key = getCode();
		switch (key)
		{
		case UP:  op == 1 ? op = 1 : op--; break;   // Sobe no menu
		case DOWN: op == 2 ? op = 2 : op++; break;  // Desce no menu
		}
		menuOpcoes(hc, op, "\n\tSingleplayer", "\n\tMultiplayer");
	} while (key != ENTER);
	return op;
}

// Usado para todos os submenus 
void menuOpcoes(HANDLE hc, int op, string st1, string st2)
{
	// Coloca cor verde na op��o selecionada
	switch (op)
	{
	case 1:
		system("cls");
		SetConsoleTextAttribute(hc, color_dark_green);
		cout << st1 << endl;
		SetConsoleTextAttribute(hc, color_white);
		cout << st2 << endl;
		break;
	case 2:
		system("cls");
		SetConsoleTextAttribute(hc, color_white);
		cout << st1 << endl;
		SetConsoleTextAttribute(hc, color_dark_green);
		cout << st2 << endl;
		SetConsoleTextAttribute(hc, color_white);
		break;
	}
}

// L� as palavras que est�o no arquivo txt dentro da pasta do c�digo e armazena no vector palavras
void lerPalavras(vector<string>& palavras)
{
	ifstream fread;
	string palavra = "";

	fread.open("C:\\Users\\leand\\EFA57 Cinel - Programador\\Programa��o em CC++ - avan�ada\\Exercicio Forca\\Jogo da forca\\Palavras.txt");

	if (!fread.fail())
	{
		// cout << "\n\tAbertura do ficheiro de palavras para leitura com sucesso" << endl;
		// cout << endl;

		while (getline(fread, palavra))
		{
			palavras.push_back(palavra);
		}

		fread.close();
		// cout << "\n\tDados acrescentados no ficheiro com sucesso!" << endl;
	}
	else
	{
		cout << "\n\tErro ao abrir ficheiro de palavras para leitura..." << endl;
		cout << "\n\tPrima tecla para continuar ";
		_getch();
		exit(1);
	}
}

// Desenha diferentes est�gios do boneco consoante o n�mero de vidas restantes (exemp: if 5 vidas restantes == 1 erro, logo desenhar est�gio 1 cabe�a) 
void desenharEstagiosBoneco(BONECO estagios, int vidas)
{
	switch (vidas)
	{
		case 6: cout << estagios.estagio0; break;
		case 5: cout << estagios.estagio1; break;
		case 4: cout << estagios.estagio2; break;
		case 3: cout << estagios.estagio3; break;
		case 2: cout << estagios.estagio4; break;
		case 1: cout << estagios.estagio5; break;
		case 0: cout << estagios.estagio6; break;
	}
}

// Pede input letra, verifica se a letra � v�lida e se encontra-se na palavra escolhida e se o jogador concluiu a palavra com vidas restantes
int adivinharLetra(string palavraEscolhida, int& vidas, BONECO estagios, HANDLE hc)
{
	string adivinharPalavra = palavraEscolhida;		// Atribui a mesma quantidade de chars da palavraEscolhida � string adivinharPalavra

	for (int i = 0; i < adivinharPalavra.length(); i++)
		adivinharPalavra[i] = '_';		// Substitui todos os chars da string por '_'

	adivinharProxLetra:
	char letra = ' ';

	system("cls");
	SetConsoleTextAttribute(hc, color_orange);
	cout << "\n\n\t=============================================";
	cout << "\n\t        BEM-VINDO AO JOGO DA FORCA!            ";
	cout << "\n\t=============================================";
	SetConsoleTextAttribute(hc, color_yellow);
	cout << "\n\n\tAdivinhe a palavra secreta relacionada � programa��o";
	SetConsoleTextAttribute(hc, color_red);
	cout << "\n\n\t\t   Vidas: " << vidas << endl;
	SetConsoleTextAttribute(hc, color_white);
	desenharEstagiosBoneco(estagios, vidas);
	compararMostrarPalavra(palavraEscolhida, letra, adivinharPalavra);

	if (vidas > 0)
	{
		// Input letra com verifica��o de entrada
		do
		{
			cout << "\n\n\tInsira uma letra:	";
			letra = _getch();
			if (!isalpha(letra))
				cout << "\n\n\tEntrada inv�lida...";
		} while (!isalpha(letra));

		for (int i = 0; i < palavraEscolhida.length(); i++)
		{
			if (tolower(letra) == tolower(palavraEscolhida[i]))		// Caso acertou letra
			{
				compararMostrarPalavra(palavraEscolhida, letra, adivinharPalavra);

				// Caso as palavras sejam iguais vence, caso contr�rio volta ao inicio da fun��o
				if (equal(palavraEscolhida.begin(), palavraEscolhida.end(), adivinharPalavra.begin(),
					[](char a, char b) { return toupper(a) == toupper(b); }))		
				{
					system("cls");
					SetConsoleTextAttribute(hc, color_yellow);
					cout << "\n\tParab�ns! Descobriu a palavra secreta:  " << palavraEscolhida << endl;
					SetConsoleTextAttribute(hc, color_white);
					cout << "\n\tPrima tecla para continuar";
					_getch();
					return 10;
				}
				else
					goto adivinharProxLetra;	
			}
		}
		// Errou letra
		vidas--;
		SetConsoleTextAttribute(hc, color_red);
		cout << "\n\n\tLetra inserida errada";
		SetConsoleTextAttribute(hc, color_green);
		cout << "\n\tPrima tecla para continuar";
		SetConsoleTextAttribute(hc, color_white);
		_getch();
		goto adivinharProxLetra;
	}
	else
	{
		// Perde sem vidas restantes
		system("cls");
		desenharEstagiosBoneco(estagios, vidas);
		SetConsoleTextAttribute(hc, color_red);
		cout << "\n\n\tPerdeu :( " << vidas << " vidas restantes" << endl;
		SetConsoleTextAttribute(hc, color_white);
		cout << "\n\tPrima tecla para continuar";
		_getch();
		return 0;
	}
}

// Respons�vel por comparar letra introduzida com letras da palavraEscolhida, por adicionar essa letra � string adicionarPalavra na devida posi��o e imprimir palavra com letras adivinhadas
void compararMostrarPalavra(string palavraEscolhida, char& letra, string& adivinharPalavra)
{
	for (int j = 0; j < palavraEscolhida.length(); j++)
	{
		if (toupper(palavraEscolhida[j]) == toupper((letra)) && adivinharPalavra[j] == '_')	// Verifica se char == '_' e se letra da palavra == letra input utilizador
		{
			adivinharPalavra[j] = letra;		// Atribui letra descoberta as devidas posi��es
			cout << adivinharPalavra[j];
		}
		else
			cout << adivinharPalavra[j];
	}
}

// Guarda pontua��es dos dois jogadores em fichero de dados
void guardarPontuacao(int pontuacaoJ1, int pontuacaoJ2)
{
	ofstream fwrite;

	fwrite.open("Pontua��o.dat", ios::out, ios::binary);

	if (fwrite)
	{
		// cout << "\n\tAbertura do ficheiro de pontua��o para escrita com sucesso" << endl;

		fwrite.write((char*)(&pontuacaoJ1), sizeof(pontuacaoJ1));
		fwrite.write((char*)(&pontuacaoJ2), sizeof(pontuacaoJ2));

		fwrite.close();
		// cout << "\n\tSucesso na escrita do ficheiro!" << endl;
	}
	else
	{
		cout << "\n\tErro ao abrir ficheiro de pontua��o para escrita..." << endl;
		cout << "\n\tPrima tecla para continuar ";
		_getch();
		exit(1);
	}
}

