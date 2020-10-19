#if !defined(_FUNCOES_)
#define _FUNCOES_
#include <iostream>
#include "Candidato.hpp"
using namespace std;

unsigned int contarParticipantes(string nome);
void initBlank(int blank[], int tam_gab);
void sortByPoints(Candidato c[], int left, int right);
void sortByBlank(Candidato c[], int left, int right);
void preencher(string dir, Candidato * &c);
void gabaritoP(string dir, char *gab, int tam);
void analisarProvas(Candidato *c, int tam,string gabarito);
int contarPontos(char *resp, char *gab, int tam);
void swap(Candidato &um, Candidato &dois);
void xMelhores(Candidato c[], int x, int tam);
void xPiores(Candidato c[], int x,int tam);
void contarPiores(Candidato c[], int x, int tam);
void contarMelhores(Candidato c[], int x, int tam);
void realizarOpcao(Candidato c[],string opcao,int x, int tam);
void contarBlank(Candidato c[], int x, int tam);


#endif // _FUNCOES_
