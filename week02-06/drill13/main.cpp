#include "../GUI/Simple_window.h"
#include "../GUI/Graph.h"

#include <string>
#include <iostream>
#include <vector>

//g++ -std=c++11 ../GUI/Graph.cpp ../GUI/Window.cpp ../GUI/GUI.cpp ../GUI/Simple_window.cpp main.cpp `fltk-config --ldflags --use-images` -o main.out

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
            grid.add(Point{i, 0}, Point{i, y_size});
            grid.add(Point{0, i}, Point{x_size, i});
        }

        win.attach(grid);
        win.wait_for_button();

        //F3
        Vector_ref<Rectangle> diagonal;
        for(int i = 0; i < 8; i++){
            diagonal.push_back(new Rectangle {Point{i*100, i*100}, 100, 100});
            diagonal[i].set_fill_color(Color::red);
            diagonal[i].set_color(Color::invisible);
            win.attach(diagonal[i]);
        }

        win.wait_for_button();

        //F4
        
        Image i1 {Point{0, 200}, "img200.jpg"};
        Image i2 {Point{200, 600}, "img200.jpg"};
        Image i3 {Point{600, 200}, "img200.jpg"};
        win.attach(i1);
        win.attach(i2);
        win.attach(i3);

        win.wait_for_button();
	
        //F5
        int x, y;
        Image i4 {Point{0, 0}, "img100.jpg"};
        win.attach(i4);

        win.wait_for_button();  

	int x_poz = 0;
	int y_poz = 0;	
	
        while(true){
            i4.move(x_poz, y_poz);
            
            x = rand() % 8;
            y = rand() % 8;
            i4.move(x*100, y*100);
            
            x_poz = x*-100;
            y_poz = y*-100;
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
