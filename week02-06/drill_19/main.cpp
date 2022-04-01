#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename T>
struct S {
    S (T vv = 0) : val{vv}{};
    T& get();
    const T& get() const;
    void set(T v);
    void operator=(const T& s);
    
    private:
        T val;
};

template<typename T>
T& S<T>::get(){
    return val;
}

template<typename T>
const T& S<T>::get() const{
    return val;
}

template<typename T>
void S<T>::set(T v){
    val = v;
}

template<typename T>
void S<T>::operator=(const T& s){
    val = s;
}

template<typename T> 
void read_val(T& v){
    cin >> v;
}

template<typename T>
ostream& operator<<(ostream& os, vector<T>& v){
    os << "{ ";
    for(int i = 0; i < v.size(); ++i){
        os << v[i] << (i < v.size()-1 ? ", " : " ");
    }

    os << "}\n";
    return os;
}

template<typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& v)
{
    char ch = 0;
    is >> ch;
    if (ch != '{') {
        is.unget();
        return is;
    }

    for (T val; is >> val; ) {
        v.push_back(val);
        is >> ch;
        if (ch != ',') break;
    }

    return is;
}

int main(){
    S<int> s;
    S<int> si {37};
    S<char> sc {'c'};
    S<double> sd {3.2};
    S<std::string> ss {"Hello"};
    S<std::vector<int>> svi {std::vector<int>{1, 1, 2, 3, 5, 8}}; //S típusú objektum, ami egy vector ami inteket tartalmaz

    cout << "S<int> : " << s.get() << endl;
    cout << "S<int> : " << si.get() << endl;
    cout << "S<char> : " << sc.get() << endl;
    cout << "S<double> : " << sd.get() << endl;
    cout << "S<string> : " << ss.get() << endl;
    //cout << "S<vector<int>> : " << svi.val << endl;
    cout << "S<vector<int>> : ";
    for(auto& a : svi.get()){
        cout << a << ' ';
    }
    cout << endl;

    si.set(5);
    cout << "S<int> : " << si.get() << endl;

    sd = 456.2;
    cout << "S<double> : " << sd.get() << endl;

    int ii;
    read_val(ii);
    S<int> sii {ii};

    double dd;
    read_val(dd);
    S<double> sdd {dd};

    string str;
    read_val(str);
    S<string> sstr {str};

    cout << "S<int> : " << sii.get() << endl;
    cout << "S<double> : " << sdd.get() << endl;
    cout << "S<string> : " << sstr.get() << endl;

    vector<int> vec;
    read_val(vec);
    S<vector<int>> svii {vec};
}
