#include <iostream>
#include <iomanip>
#include <cmath>
#include <complex>
#include <cerrno>
#include "source/Matrix.h"
#include "source/MatrixIO.h"

using namespace std;
using namespace Numeric_lib;

int main(){
    try{
        cout << "sizeof: \n";
        cout << "char:\t" << sizeof(char) << endl;
        cout << "short:\t" << sizeof(short) << endl;
        cout << "int:\t" << sizeof(int) << endl;
        cout << "long:\t" << sizeof(long) << endl;
        cout << "float:\t" << sizeof(float) << endl;
        cout << "double:\t" << sizeof(double) << endl;
        cout << "int*:\t" << sizeof(int*) << endl;
        cout << "double*:\t" << sizeof(double*) << "\n\n";
        
        cout << "Matrix sizes: \n";
        Matrix<int> a(10);
        Matrix<int> b(100);
        Matrix<double> c(10);
        Matrix<int, 2> d(10, 10);
        Matrix<int, 3> e(10, 10, 10);
        cout << "1D int 10 elem\t\t" << sizeof(a) << endl;
        cout << "1D int 100 elem\t\t" << sizeof(b) << endl;
        cout << "1D double 10 elem\t\t" << sizeof(c) << endl;
        cout << "2D int 10x10 elem\t\t" << sizeof(d) << endl;
        cout << "3D int 10x10x10 elem\t\t" << sizeof(e) << "\n\n";

        cout << "numer of elements:\n";
        cout << "a\t" << a.size() << endl;
        cout << "b\t" << b.size() << endl;
        cout << "c\t" << c.size() << endl;
        cout << "d\t" << d.size() << endl;
        cout << "e\t" << e.size() << endl;

        //errno int-et jelent | hibák számosságát tárolja 
        cout << "sqrt of numbers:\n";
        int num;
        while(cin >> num){
            errno = 0;
            double d = sqrt(num);

            if(errno != EDOM)
                cout << "sqrt(" << num << ") = " << sqrt(num) << endl;
            else
                cout << "no square root\n";
        }
        
        cin.clear(); //tárolt hibaüzeneteket töröl
        cin.ignore(); //bekérés után fentmaradt karaktereket figyelmen kívül hagyja

        cout << "enter 10 float:\n";
        Matrix<double> m(10);
        double d2;
        for(int i = 0; i < m.size(); i++){
            cin >> d2;
            if(!cin)
                throw runtime_error("Error while reading from cin!");
            else
                m[i] = d2;
        }
        cout << "Matrix: \n" << m << endl;

        cout << "enter n and m value:\n";
        int n2, m2;
        cin >> n2 >> m2;

        Matrix<int, 2> multiplication (n2,m2);
        cout << n2 << "x" << m2 << "multiplication table:\n";

        for(int i = 1; i <= n2; i++){
            for(int j = 1; j <= m2; j++){
                multiplication(i-1, j-1) = i*j;
                cout << setw(4) << multiplication(i-1, j-1);
            }
            cout << endl;
        }

        Matrix<complex<double>> m4(10);
        cout << "enter 10 complex number (Re, Im):\n";
        complex<double> comp;
        for(int i = 0; i < m4.size(); i++){
            cin >> comp;
            if(!cin)
                throw runtime_error("Error while reading from cin!");
            else
                m4[i] = comp;
        }

        complex<double> sum;
        for(int i = 0; i < m4.size(); i++){
            sum+=m4(i);
        }

        cout << "sum: " << sum << endl;
        
        
            



    } catch(exception& e){
        cout << e.what() << endl;
        return 1;
    } catch(...){
        cout << "unknown error" << endl;
        return 2;
    }
}