#include "funcoes.hpp"
#include "Candidato.hpp"
#include <iostream>
#include <fstream>
using namespace std;

unsigned int contarParticipantes(string nome)
{
    ifstream arquivo(nome);
    unsigned int n = 0;
    string x;
    while (getline(arquivo, x))
    {
        n++;
    }

    return n;
}

void preencher(string dir,Candidato c)
{

    ifstream arquivo(dir);
    if (arquivo.is_open())
    {
        while (arquivo.good())
        {
            char respTemp[10];
            arquivo >> c.nome;
            for (size_t i = 0; i < 10; i++)
            {
                arquivo >> c.respostas[i];
            }
        }
    }

    else
    {
        cout << "Nome de arquivo de respostas inválido" << endl;
        exit(EXIT_FAILURE);
    }
}

int gabarito(string g)
{
    ifstream arquivo(g);
    int n = 0;
    if (arquivo.is_open())
    {
        string s;
        getline(arquivo, s);
        int i = 0;
        while (s[i] != '\0')
        {
            if (!isblank(s[i]))
            {
                n++;
            }

            i++;
        }
        return n;
    }
    else
    {
        cout << "Nome de arquivo de gabarito inválido" << endl;
        exit(EXIT_FAILURE);
    }
}
