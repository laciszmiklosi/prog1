#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <list>
#include <iterator>

struct Item{
    std::string name;
    int iid;
    double value;
};

template<typename C>
void print(const C& c, char sep='\n'){
    std::cout << "Container elements:\n";

    for(const auto elem : c){
        std::cout << elem << sep;
    }

    std::cout << std::endl;
}

template<typename C>
void remove_by_name(C& c, std::string name){
    std::cout << "remove " << name << " from container\n";

    int index = 0;
    for(const auto elem : c){
        if(elem.name == name)
        {
            c.erase(c.begin() + index);
            break;
        }
        
        index++;
    }
}

template<typename C>
void remove_by_iid(C& c, int iid){
    std::cout << "remove " << iid << " from container\n";

    int index = 0;
    for(const auto elem : c){
        if(elem.iid == iid)
        {
            c.erase(c.begin() + index);
            break;
        }
        
        index++;
    }
}

void remove_by_namel(std::list<Item>& c, std::string name){
    std::cout << "remove " << name << " from container\n";

    for (std::list<Item>::iterator it = c.begin(); it != c.end(); ++it){
        if(name == it->name){
            c.erase(it);
            break;
        }
            
    }    
}

void remove_by_iidl(std::list<Item>& c, int iid){
    std::cout << "remove " << iid << " from container\n";

    for (std::list<Item>::iterator it = c.begin(); it != c.end(); ++it){
        if(iid == it->iid){
            c.erase(it);
            break;
        }
            
    }    
}

std::ostream& operator<<(std::ostream& os, const Item& it)
{
    return os << it.name << '\t' << it.iid << '\t' << it.value;
}

std::istream& operator>>(std::istream& is, Item& it)
{
    std::string n;
    int id;
    double v;
    is >> n >> id >> v;
    Item i {n, id, v};
    it = i;
    return is;
}

int main(){

    try {

    const std::string iname {"input.txt"};
    std::ifstream ifs {iname};
    if(!ifs) throw std::runtime_error("could not read file " + iname);

    std::vector<Item> vi;
    std::list<Item> li;

    for (Item i; ifs >> i;){
        vi.push_back(i);
        li.insert(li.end(), i);
    }
        

    print(vi);

    std::sort(vi.begin(), vi.end(), [](const Item& a, const Item& b) { return a.name < b.name; });
    print(vi);

    std::sort(vi.begin(), vi.end(), [](const Item& a, const Item& b) { return a.iid < b.iid; });
    print(vi);

    std::sort(vi.begin(), vi.end(), [](const Item& a, const Item& b) { return a.value > b.value; });
    print(vi);

    Item i = {"horse shoe",99,12.34};
    vi.push_back(i);
    i = {"Canon S400", 9988,499.95};
    vi.push_back(i);

    remove_by_name(vi, "kapa");
    remove_by_name(vi, "vonat");
    print(vi);

    remove_by_iid(vi, 1);
    remove_by_iid(vi, 21);
    print(vi);


    // list item
    print(li);

    li.sort([](const Item& a, const Item& b) { return a.name < b.name; });
    print(li);

    li.sort([](const Item& a, const Item& b) { return a.iid < b.iid; });
    print(li);

    li.sort([](const Item& a, const Item& b) { return a.value > b.value; });
    print(li);

    i = {"horse shoe",99,12.34};
    li.insert(li.end(), i);
    i = {"Canon S400", 9988,499.95};
    li.insert(li.end(), i);
    print(li);


    remove_by_namel(li, "kapa");
    remove_by_namel(li, "vonat");
    print(li);

    remove_by_iidl(li, 1);
    remove_by_iidl(li, 21);
    print(li);


    } catch(std::exception& e){
        std::cerr << "exception: " << e.what() << std::endl;
        return 1;
    } catch(...) {
        std::cerr << "error" << std::endl;
        return 2;
    }

}