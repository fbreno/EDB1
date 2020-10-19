#if !defined(_FUNCOES_)
#define _FUNCOES_
#include <iostream>
#include "Candidato.hpp"
using namespace std;

unsigned int contarParticipantes(string nome);
void preencher(string dir, Candidato * &c);
int gabarito(string g);
void analisarProvas(Candidato *c, int tam,string opcao,string gabarito);
void quickSort(int array[], int left, int right);

#endif // _FUNCOES_
