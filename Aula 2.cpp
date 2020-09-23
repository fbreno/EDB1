#include<cstdio>
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

void somatoria(){
    int x = 2+5;
}

int main(){

    return 0;
}