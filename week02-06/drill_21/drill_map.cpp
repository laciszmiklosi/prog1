#include <iostream>
#include <map>
#include <string>
#include <stdexcept>
#include <numeric>

template<typename K, typename V>
void print(const std::map<K, V>& m){
    for(auto& a : m){
        std::cout << "["<< a.first << "] = " << a.second << std::endl;
    }

    std::cout << std::endl;
}

template<typename K>
int sum(const std::map<K, int>& m){
    int sum = 0;
    for(auto& a : m){
        sum += a.second;
    }

    return sum;
}


template<typename K, typename V>
void swap(const std::map<K, V>& m, std::map<V, K>& n){
    for(auto& a : m){
        n.insert(std::make_pair(a.second, a.first));
    }
}

void read_map(std::map<std::string, int>& m){
    std::string s;
    int i = 0;

    while(m.size() < 10){
        std::cin >> s >> i;
        m.insert(std::make_pair(s, i));
    }
}

int main(){
    try{
        std::map<std::string, int> msi;
        msi["a"] = 1;
        msi["b"] = 3;
        msi["ab"] = 7;
        msi["efgh"] = 98;
        msi["xy"] = 70;
        msi["qw"] = 61;
        msi["efh"] = 60;
        msi["xc"] = 23;
        msi["qwertz"] = 11;
        msi["ax"] = 1;
        
        std::cout << "A teljes msi" << std::endl;
        print(msi);

        std::cout << "Egy elem törlése" << std::endl;
        msi.erase("a");
        print(msi);

        std::cout << "Teljes msi törlése" << std::endl;
        msi.erase(msi.begin(), msi.end());
        print(msi);

        std::cout << "msi beolvasás\nAdj meg 10 kulcs érték párt" << std::endl;
        read_map(msi);
        print(msi);

        std::cout << "msi értékeinek összege: " << sum(msi) << std::endl;

        std::map<int, std::string> mis; 
        swap(msi, mis);
        print(mis);
    }
    catch (std::exception& e){
        std::cout << "exception: " << e.what() << std::endl;
        return 1;
    }
    catch (...){
        std::cout << "error" << std::endl;
        return 2;
    }
}