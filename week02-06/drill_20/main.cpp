#include <vector>
#include <list>
#include <array>
#include <string>
#include <iostream>
#include <algorithm>

template<typename C>
void print(const C& c){
    for(auto& a : c){
        std::cout << a << ' ';
    }
    std::cout << std::endl;
}

template<typename C>
void inc(C& c, int n){
    for(auto& a : c){
        a += n;
    }
}

template<typename Iter1, typename Iter2>
Iter2 orai_copy(Iter1 f1, Iter1 e1, Iter2 f2){
    for(Iter1 p = f1; p != e1; ++p){
        *f2 = *p; //*f2++ = *p
        f2++;
    }
    return f2;
}

int main(){
    constexpr int size = 10;

    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::array<int, size> ai;
    std::copy(arr, arr + size, ai.begin());

    std::vector<int> vi(size);
    std::copy(arr, arr + size, vi.begin());

    std::list<int> li(size);
    std::copy(arr, arr + size, li.begin());

    std::array<int, size> ai2 = ai;

    std::vector<int> vi2 = vi;

    std::list<int> li2 = li;

    print(arr);
    print(ai);
    print(vi);
    print(li);
    print(ai2);
    print(vi2);
    print(li2);

    inc(ai2, 2);
    inc(vi2, 3);
    inc(li2, 5);

    print(ai2);
    print(vi2);
    print(li2);

    orai_copy(ai2.begin(), ai2.end(), vi2.begin());
    orai_copy(li2.begin(), li2.end(), ai2.begin());
    print(ai2);
    print(vi2);
    print(li2);

    std::vector<int>::iterator vit;
    vit = std::find(vi2.begin(), vi2.end(), 3);
    if(vit != vi2.end())
        std::cout << "found at: " << std::distance(vi2.begin(), vit) << std::endl;
    else
        std::cout << "not found" << std::endl;

    vit = std::find(vi2.begin(), vi2.end(), 27);
    if(vit != vi2.end())
        std::cout << "found at: " << std::distance(vi2.begin(), vit) << std::endl;
    else
        std::cout << "not found" << std::endl;
    return 0;
}
