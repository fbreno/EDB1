#if !defined(_CANDIDATO_)
#define _CANDIDATO_

#include <iostream>
using std::string;

typedef struct 
{
    string nome;
    char respostas[10];
    int pontos;
    int blank[10];
    int certos[10];
    int errados[10];

}Candidato;


void imprimir(Candidato c);
int contarPontos(char* resp, char* gab, int tam);

#endif // _CANDIDATO_
