#include "Candidato.hpp"
#include <iostream>
#include <string>
using namespace std;

void imprimir(Candidato c)
{

    cout << c.nome;
    for (size_t i = 0; i < 10; i++)
    {
        cout << " " << c.respostas[i];
    }
    cout << endl;
}