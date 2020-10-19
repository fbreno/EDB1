#if !defined(_CANDIDATO_)
#define _CANDIDATO_

#include <iostream>
using std::string;

typedef struct 
{
    string nome;
    char respostas[10];
    int pontos;

}Candidato;

void imprimir(Candidato c);
int contarPontos(char* resp, char* gab, int tam);

#endif // _CANDIDATO_
