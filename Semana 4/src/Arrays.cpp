#include <iostream>
#include <random>
#include <ctime>
#include <string>

void preencherRandom(int *vet, int t){
    std::mt19937 gerador;
    gerador.seed(std::time(0));
    std::uniform_int_distribution<uint32_t> teste(1,50000);

    for (size_t i = 0; i < t; i++)
    {
        vet[i]=teste(gerador);
    }
}

void selectionSort(int t,int* vet)
{   
    for (size_t i = 0; i < t; ++i)
    {
        int min = vet[i];
        for (size_t j = i+1; j < t; ++j)
        {
            if (vet[j]<vet[i])
            {
                min=j;
            }
        }
        int aux = vet[i];
        vet[i]=vet[min];
        vet[min]=aux;
    }
}

void insertionSort(int t,int* vet)
{   
    for (size_t i = 1; i < t; ++i)
    {   
        int atual = vet[i];
        int j = i-1;
        while (j>=0 && atual<vet[j])
        {
            vet[j+1]=vet[j];
            j--;
        }
        vet[j+1]=atual;
    }
}

void mostrar(int vet[],int t){
    for (size_t i = 0; i < t; i++)
    {
        std::cout<<vet[i]<<std::endl;
    }
}


int main(int argc, char *argv[])
{
    int tam = atoi(argv[1]);
    int vet[tam];
    std::string word = argv[2];
    preencherRandom(vet,tam);
    if (word=="selection")
    {   
        std::cout<<"selection:"<<std::endl;
        selectionSort(tam,vet);
        mostrar(vet,tam);
    }else if (word=="insertion")
    {
        std::cout<<"insertion:"<<std::endl;
        insertionSort(tam,vet);
        mostrar(vet,tam);
    }
    
    
    return 0;
}
