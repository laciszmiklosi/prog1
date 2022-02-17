#include "../GUI/Simple_window.h"
#include "../GUI/Graph.h"

#include <string>
#include <iostream>

using namespace Graph_lib;

int main(){
    try {

        //F1
        Point t1 {300, 50};
        Simple_window win {t1, 1000, 800, "My window"};
        win.wait_for_button();

        //F2
        Lines grid;
        int x_size = 800;
        int y_size = 800;
        for(int i = 0; i <= 800; i+=100){
            grid.Add(Point(i, 0), Point(i, y_size));
            grid.Add(Point(0, i), Point(x_size, 1));
        }

        win.attach(grid);
        win.wait_for_button();

        //F3
        Rectangle diagonal[8];
        for(int i = 0; i < 8; i++){
            diagonal[i] {Point[i*100, i*100], 100, 100};
            diagonal[i].set_fill_color(Color::red);
        }

    } catch(exception& e){
        cerr << "exception: " << e.what() << endl;
        return 1;
    } catch(...) {
        cerr << "error" << endl;
        return 2;
    }
}