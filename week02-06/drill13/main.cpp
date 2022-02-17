#include "../GUI/Simple_window.h"
#include "../GUI/Graph.h"

#include <string>
#include <iostream>

using namespace Graph_lib;

int main(){
    try {
        

    } catch(exception& e){
        cerr << "exception: " << e.what() << endl;
        return 1;
    } catch(...) {
        cerr << "error" << endl;
        return 2;
    }
}