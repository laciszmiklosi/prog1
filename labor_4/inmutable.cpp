#include <iostream>

using namespace std;

constexpr int fibonacchi(int x){
    return (x<=1) ? x : fibonacchi(x-1) + fibonacchi(x-2);
}

int main(){
    const int series = fibonacchi(10);
    cout << series << endl;
}