#if !defined(_FUNCOES_)
#define _FUNCOES_
#include <iostream>
#include "Candidato.hpp"
using namespace std;

unsigned int contarParticipantes(string nome);
void preencher(string dir, Candidato * &c);
void gabaritoP(string dir, char *gab, int tam);
void analisarProvas(Candidato *c, int tam,string opcao,string gabarito);
int contarPontos(char *resp, char *gab, int tam);
void swap(Candidato &um, Candidato &dois);
void quickSort(Candidato c[], int left, int right);


#endif // _FUNCOES_
