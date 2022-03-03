#include <iostream>

using namespace std;

int sum(int x, int y){
    return x+y;
}

class Add{
    public: 
        int operator() (int x, int y) const {return x+y;}
};

struct add_x{
    add_x(int val) : x(val) {} // add_x(int val) {x = val;}
    int operator() (int y) const {return x+y;} //operátor túlterhelés, bármely operátornak új értelmezést adhatok meg.

    //Az operátor valójában egy függvény

    int operator<< (int y) const {return x+y;}
    int operator>> (int y) const {return x+y;}
    void operator+ (int y) {x-=y;}

    private:
        int x;
};

int main(){
    //tipus (add_x) név(add42)
    add_x add42(42); //add42() objektum ami úgy néz ki és úgy viselkedik mint egy függvény - funktor
    int i = add42(8);
    cout << i << endl;

    add42+7;

    cout << (add42<<8) << endl;
    cout << (add42>>7) << endl;

    //tipus                név
    /*std::function<int(int, int)> func;
    func = sum;
    cout << func(5,7) << endl;*/

    std::function<double(double, double)> sum = [](double a, double b) {return a+b;};
    cout << sum(4.6, 5.9) << endl;


}