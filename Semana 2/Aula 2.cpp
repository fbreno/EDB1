#include<cstdio>
#include <limits>
long long somafor(int n){
    long long soma=0; //2
    for (size_t i = 0; i < n; i++)//2n+2
    {
        soma+=i;//2n
    }
    return soma;//1
    //4n+5
    // --- O(n) ---
}

long long somaFormula(int n){
    long long soma=0;//2
    soma=(n*(n+1))/2;//4
    return soma;//1
    //7
    // --- O(1) ---
}

int menorValor(int n,int vet[]){
    int min = std::numeric_limits<int>::max();//2
    for (size_t i = 0; i < n; ++i)//2n+2
    {
        if (min>vet[i])//2n
        {
            min=vet[i];//2n
        }
        
    }
    return min;//1
    //6n+3
    // --- O(n) ---
}

bool contido(int s, int A[], int n){

    for (size_t i = 0; i < n; ++i)//2n+2
    {
        if (s==A[i])//2n
        {
            return true;//1
        }
    }
    return false;//1
    //4n+3
    // --- O(n) ---
}

/*
Questão 4:
a)O(1)
b)O(n)
c)O(n)
d)O(n²)
e)O(n!)
f)O(n*log n)
g)O(n³)
h)O(n^5)
i)O(k^n)
*/

int main(){

    return 0;
}