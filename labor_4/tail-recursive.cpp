#include <iostream>

using namespace std;

unsigned int factorial_rec(int x){
    if(x == 0) return 1;
    return x*factorial_rec(x-1);
}
unsigned int factorial_TR(int x, int y){
    if(x == 0) return y;
    return factorial_TR(x-1, x*y);
}

unsigned int factorial(int x){
    return factorial_TR(x, 1);
}

int main(){
    cout << factorial(3) << endl;
    cout << factorial_rec(3) << endl;
}
    