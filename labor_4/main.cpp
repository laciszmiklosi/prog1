#include <iostream>

using namespace std;

/*
    A szögletes zárójel [] lambda introducer
    A sima zárójel () argument list
    A kapcsos zárójel {} function body

    [] captures nothing
    [&] captures all by reference
    [=] captures all by value
    [&A, =B] A by reference, B by value
    [=, &A] A by reference, others by value

    */

int main(){
    
    [](){
        cout << "Hello c++ lambda" << endl;
    }

    ();

    //auto futás időben olyan értékké változik amilyen tipust kap
    auto sum = [](double a, double b){return a+b;}; //függvényt fog vissza adni nem double-t
    auto add = sum;
    cout << add(3.25, 5.65) << endl;

    auto add2 = [](double a, double b) -> double {return a+b;};
    cout << add2(3.25, 5.65) << endl;

    double pi = 3.1416;
    auto func = [pi](){cout << "The value of pi: " << pi << endl;};
    func();

    /*double pi2 = 3.1416;
    auto func2 = [&pi2](double a){cout << "The value of pi: " << pi2 << endl; pi2+=a};
    func2(2.5);
    func2(2.5);*/

    auto gene_lambda = [](auto arg) {return arg+arg;};
    cout << gene_lambda(3) << endl;
    cout << gene_lambda(pi) << endl;
    


}