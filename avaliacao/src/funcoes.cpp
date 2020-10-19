#include "funcoes.hpp"
#include "Candidato.hpp"
#include <iostream>
#include <fstream>
using namespace std;

void sortByBlank(Candidato c[], int left, int right)
{
    int i = left, j = right;
    Candidato pivo = c[(left + right) / 2];

    while (i <= j)
    {
        while (c[i].blank < pivo.blank)
        {
            i++;
        }

        while (c[j].blank > pivo.blank)
        {
            j--;
        }
        if (i <= j)
        {
            swap(c[i], c[j]);
            i++;
            j--;
        }
    }
    if (left < j)
    {
        sortByBlank(c, left, j);
    }
    if (i < right)
    {
        sortByBlank(c, i, right);
    }
}

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
    if (isblank(dir[0]))
    {
        char g[] = {'A', 'B', 'C', 'D', 'E', 'E', 'D', 'C', 'B', 'A'};
        gab = g;
    }
    else
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

void initBlank(Candidato c, int tam_gab)
{
    for (size_t i = 0; i < tam_gab; i++)
    {
        c.certos[i] = 0;
        c.errados[i] = 0;
        c.blank[i] = 0;
    }
}

int contarPontos(Candidato c, char *gab, int tam)
{
    initBlank(c, tam);
    int acertos = 0;
    for (size_t i = 0; i < tam; i++)
    {
        if ((c.respostas[i] != 'A') || (c.respostas[i] != 'B') || (c.respostas[i] != 'C') || (c.respostas[i] != 'D') || (c.respostas[i] != 'E'))
        {
            c.blank[i]++;
        }
        else
        {
            if (c.respostas[i] == gab[i])
            {

                c.certos[i];
                acertos++;
            }
            else
            {
                c.errados[i]++;
            }
        }
    }
    return acertos;
}

void swap(Candidato &um, Candidato &dois)
{
    Candidato temp = um;
    um = dois;
    dois = temp;
}

void sortByPoints(Candidato c[], int left, int right)
{
    int i = left, j = right;
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
            swap(c[i], c[j]);
            i++;
            j--;
        }
    }
    if (left < j)
    {
        sortByPoints(c, left, j);
    }
    if (i < right)
    {
        sortByPoints(c, i, right);
    }
}

void xMelhores(Candidato c[], int x, int tam)
{
    cout << "Melhores candidatos:" << endl;
    sortByPoints(c, 0, tam);
    for (size_t i = tam; i >= x; i--)
    {
        imprimir(c[i]);
    }
}

void xPiores(Candidato c[], int x, int tam)
{
    cout << "Piores candidatos:" << endl;
    sortByPoints(c, 0, tam);
    for (size_t i = 0; i < x; i++)
    {
        imprimir(c[i]);
    }
}

void analisarProvas(Candidato *c, int tam, string gabarito_dir)
{
    int tam_gab = 10;
    char gabarito[tam_gab];
    gabaritoP(gabarito_dir, gabarito, tam_gab);
    for (size_t i = 0; i < tam; i++)
    {
        c[i].pontos = contarPontos(c[i], gabarito, tam_gab);
    }
}

void ajustar(int id[], int na[], int left, int right)
{
    int i = left, j = right;
    int temp;
    int piv = na[(left + right) / 2];
    while (i <= j)
    {
        while (na[i] < piv)
        {
            i++;
        }

        while (na[j] > piv)
        {
            j--;
        }

        if (i<=j)
        {
            temp=na[i];
            na[i]=na[j];
            na[j]=temp;
            temp=id[i];
            id[i]=id[j];
            id[j]=temp;
            i++;
            j--;
        }
        
    }
    if (left<j)
    {
        ajustar(id,na,left,j);
    }
    if (i<right)
    {
        ajustar(id,na,i,right);
    }
    
    
}

void contarMelhores(Candidato c[], int x, int tam)
{

    int id[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int na[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (size_t i = 0; i < tam; i++)
    {
        for (size_t j = 0; j < 10; j++)
        {
            if (c[i].certos[j])
            {
                na[j]++;
            }
        }
    }

    ajustar(id,na,0,10);

    for (size_t i = 10; i > 10-x; i--)
    {
        cout << "Questao " << id[i] << ":" << na[i]<<" acertos"<<endl;
    }
}

void contarPiores(Candidato c[], int x, int tam)
{

    int id[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int na[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (size_t i = 0; i < tam; i++)
    {
        for (size_t j = 0; j < 10; j++)
        {
            if (c[i].certos[j])
            {
                na[j]++;
            }
        }
    }

    ajustar(id,na,0,10);

    for (size_t i = 0; i > x; i++)
    {
        cout << "Questao " << id[i] << ":" << na[i]<<" erros"<<endl;
    }
}


void contarBlank(Candidato c[], int x, int tam)
{

    int id[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int na[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (size_t i = 0; i < tam; i++)
    {
        for (size_t j = 0; j < 10; j++)
        {
            if (c[i].blank[j])
            {
                na[j]++;
            }
        }
    }

    ajustar(id,na,0,10);

    for (size_t i = 10; i > 10-x; i--)
    {
        cout << "Questao " << id[i] << ":" << na[i]<<" erros"<<endl;
    }
}

void realizarOpcao(Candidato c[], string opcao, int x, int tam)
{
    string parametro[5] = {"best", "worst", "best-questions", "worst-questions", "blank-questions"};
    int controle = 0;
    for (size_t i = 0; i < 5; i++)
    {
        if (parametro[i] == opcao)
        {
            controle = i + 1;
        }
    }

    switch (controle)
    {
    case 1:
        xMelhores(c, x, tam);
        break;
    case 2:
        xPiores(c, x, tam);
        break;
    case 3:
        contarMelhores(c, x, tam);
        break;
    case 4:
        contarPiores(c,x,tam);
        break;
    case 5:
        contarBlank(c,x,tam);
        break;

    default:
        cout << "Parâmetro inválido." << endl;
        break;
    }
}