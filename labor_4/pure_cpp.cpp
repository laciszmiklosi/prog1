#include <iostream>
#include <cmath>

using namespace std;

int absolute(int a){
    //a = 2*a/2 mellékhatás
    cout << "given parameter " << a << endl; //mellékhatás, nem várt eredmény
    return abs(a);
}

int main(){
    cout << "Absolute value of 0.025: " << abs(0.025) << endl;
    cout << "Absolute value of 0.025: " << absolute(25) << endl;
}