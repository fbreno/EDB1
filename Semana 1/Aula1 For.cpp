#include <iostream>
#include <chrono>
using namespace std::chrono;
int main(){
    auto start = high_resolution_clock::now();
    double soma = 0;
    long long n = 10000000000;
    long long i = 0;

    for (i ; i < n; i++)
    {
        soma+=i;
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    std::cout << duration.count() << "  milissegundos"<< std::endl;
    system("pause");
}