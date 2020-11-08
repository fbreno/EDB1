#include "LinkedList.hpp"

#include <vector>

struct Carro
{
    std::string nome;
    std::string marca;
    int ano;
};

int main(int argc, char* argv[])
{
    Carro a;
    a.nome = "UNO";
    a.marca = "fiat";
    a.ano = 2020;

    Carro b;
    b.nome = "Gol";
    b.marca = "vw";
    b.ano = 2013;

    LinkedList<Carro> carros;

    carros.insert(a);
    carros.insert(b);

    carros[1].nome = "Outro Carro";

    std::cout << carros[1].nome << std::endl;
}
