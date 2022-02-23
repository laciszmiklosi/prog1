#include "../GUI/Simple_window.h"
#include "../GUI/Graph.h"

#include <string>
#include <iostream>
#include <vector>

//g++ -w -Wall -std=c++11 ../GUI/Graph.cpp ../GIU/Window.cpp ../GUI/Simple_window.cpp main.cpp `fltk-config -ldflags --use-images` -o main.out

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
        vector<Rectangle> diagonal;
        for(int i = 0; i < 8; i++){
            diagonal.push_back(new Rectangle {Point{i*100, i*100}, 100, 100});
            diagonal[i].set_fill_color(Color::red);
            diagonal[i].set_color(Color::invisible);
            win.attach(diagonal[i]);
        }

        win.wait_for_button();

        //F4
        Image i1 {Point{0, 0}, "../GUI/badge.jpg"};
        i1.set_mask(Point{0, 200}, 200, 200);
        Image i2 {Point{0, 0}, "../GUI/badge.jpg"};
        i2.set_mask(Point{400, 0}, 200, 200);
        Image i3 {Point{0, 0}, "../GUI/badge.jpg"};
        i3.set_mask(Point{600, 300}, 200, 200);
        win.attach(i1);
        win.attach(i2);
        win.attach(i3);

        win.wait_for_button();

        //F5
        int x, y;
        Image i4 {Point{0, 0}, "../GUI/badge.jpg"};
        i3.set_mask(Point{100, 100}, 100, 100);
        win.attach(i4);

        win.wait_for_button();  

        while(true){
            x = rand() % 8;
            y = rand() % 8;

            i4.move(x*100, y*100);
            win.wait_for_button();
        }

    } catch(exception& e){
        cerr << "exception: " << e.what() << endl;
        return 1;
    } catch(...) {
        cerr << "error" << endl;
        return 2;
    }
}