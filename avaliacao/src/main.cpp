#include <iostream>
#include <fstream>
#include "Candidato.hpp"
#include "funcoes.hpp"
using namespace std;
unsigned int numeroDeQuestoes = 0;

int main(int argc, char const *argv[])
{
    string dir(argv[1]), gab(argv[2]);
    numeroDeQuestoes = gabarito(gab);
    char *q = new char[numeroDeQuestoes];
    int n = contarParticipantes(dir);
    
    Candidato *c = new Candidato[n];

    /*for (size_t i = 0; i < n; i++)
    {
        c[i].setTamanho(numeroDeQuestoes);
    }*/
    preencher(dir);

    return 0;
}
