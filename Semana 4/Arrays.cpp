#include <iostream>

void selectionSort(int t,int* &vet)
{   
    for (size_t i = 0; i < t; ++i)
    {
        int min = vet[i];
        for (size_t j = 1; j < t; ++j)
        {
            if (vet[j]<vet[i])
            {
                min=vet[j];
                vet[i]=vet[j];
                vet[i]=min;
            }
        }
    }
}


int main(int argc, char const *argv[])
{
    
    return 0;
}
