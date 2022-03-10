#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

class Person{
    public:
        //void kiIr() {cout << "Name: " << name << " Age: " << age << endl;};
        
        Person(){};
        //Person(string s, int n) : n{s}, a{n}{
        Person(string f, string l, int a) : first_name{f}, last_name{l}, a{a}{
            if(a < 0 || a >= 150){
                throw runtime_error("Bad age");
            }

            /*vector<char> chars(';', ':', '*');
            (';', ':', '/'','"', '[', ']', '*', '&', '^', '%', '$', '#', '@', '!');

            string n = first_name + last_name;

            for(char c : n){
                switch(c){
                    case ';':
                    case ':':
                    case '\'':
                    case '"':
                    case '[': 
                    case ']': '*', '&', '^', '%', '$', '#', '@', '!'
                }
            }*/
        };
        string first_n() const {return first_name;}
        string last_n() const {return last_name;}
        int age() const {return a;}
    private:
        //string n;
        string first_name;
        string last_name;
        int a;
};

ostream& operator<<(ostream& os, const Person& p){
    return os<< p.first_n() << " " << p.last_n() << " " << p.age();
}

istream& operator>>(istream& is, Person& p){
    string f;
    string l;
    int a;

    is >> f >> l >> a;
    p = Person(f, l, a);

    return is;
}

int main(){
    Person p1 = Person("Goofy", "A", 63);
    cout << p1 << endl;

    Person p2 = Person("A", "B", 3);
    cout << p2 << endl;

    Person p3;
    Person p4;
    cin >> p3 >> p4;
    cout << p3 << " " << p4 << endl;

    vector<Person> vec;

    for(Person p; cin >> p;){//while(cin >> p)
        if(p.first_n() == "end") break;
        vec.push_back(p);
    }

    for(Person p : vec){
        cout << p << endl;
    }
}