#include <iostream>
#include <chrono>
using namespace std::chrono;
int main(){
    auto start = high_resolution_clock::now();
    long soma = 0;
    long long n = 10000000000;
    soma=(n*(n+1))/2;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    std::cout << soma<< std::endl;
    std::cout << duration.count() << "  milissegundos"<< std::endl;
    system("pause");
}