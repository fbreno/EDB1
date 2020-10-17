#if !defined(_CANDIDATO_)
#define _CANDIDATO_

#include <iostream>
using std::string;

typedef struct 
{
    string nome;
    char respostas[10];

}Candidato;

void imprimir(Candidato c);

#endif // _CANDIDATO_
