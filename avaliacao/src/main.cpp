#include <iostream>
#include <fstream>
#include "Candidato.hpp"
#include "funcoes.hpp"
using namespace std;

int main(int argc, char const *argv[])
{
    string dir(argv[1]), opcao(argv[2]), gab(argv[4]);
    int x = stoi(argv[3]);
    int n = contarParticipantes(dir);
    
    Candidato *c = new Candidato[n];
    preencher(dir,c);
    analisarProvas(c,n,gab);

    realizarOpcao(c,opcao,x,n);
    
    return 0;
}
