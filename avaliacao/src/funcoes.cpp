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

void preencher(string dir, Candidato *&c)
{

    ifstream arquivo(dir);
    if (arquivo.is_open())
    {
        int j = 0;
        while (arquivo.good())
        {
            char respTemp[10];
            arquivo >> c[j].nome;
            for (size_t i = 0; i < 10; i++)
            {
                arquivo >> c[j].respostas[i];
            }
            j++;
        }
    }

    else
    {
        cout << "Nome de arquivo de respostas inválido" << endl;
        exit(EXIT_FAILURE);
    }
}

void gabaritoP(string dir, char *gab, int tam)
{
    ifstream arquivo(dir);
    int n = 0;
    if (arquivo.is_open())
    {
        string s;
        getline(arquivo, s);
        int i = 0;
        for (size_t i = 0; i < tam; i++)
        {
            if (!isblank(s[i]))
            {
                gab[i] = s[i];
            }
        }
    }
    else
    {
        cout << "Nome de arquivo de gabarito inválido" << endl;
        exit(EXIT_FAILURE);
    }
}

void imprimir(Candidato c)
{

    cout << c.nome;
    for (size_t i = 0; i < 10; i++)
    {
        cout << " " << c.respostas[i];
    }
    cout << endl;
}
int contarPontos(char *resp, char *gab, int tam)
{
    int acertos = 0;
    for (size_t i = 0; i < tam; i++)
    {
        if (resp[i] == gab[i])
        {
            acertos++;
        }
    }
    return acertos;
}

void analisarProvas(Candidato *c, int tam, string opcao, string gabarito_dir)
{
    int tam_gab = 10;
    char gabarito[tam_gab];
    gabaritoP(gabarito_dir, gabarito, tam_gab);
    for (size_t i = 0; i < tam; i++)
    {
        c[i].pontos = contarPontos(c[i].respostas, gabarito, tam_gab);
    }
}

void swap(Candidato um, Candidato dois)
{
    Candidato temp = um;
    um = dois;
    dois=temp;
}

void quickSort(Candidato c[], int left, int right)
{
    int i = left, j = right;
    int temp;
    Candidato pivo = c[(left + right) / 2];

    while (i <= j)
    {
        while (c[i].pontos < pivo.pontos)
        {
            i++;
        }

        while (c[j].pontos > pivo.pontos)
        {
            j--;
        }
        if (i <= j)
        {
            swap(c[i],c[j]);
            i++;
            j--;
        }
    }
    if (left < j;)
    {
        quickSort(c, left, j);
    }
    if (i < right)
    {
        quickSort(c, i, right);
    }
}