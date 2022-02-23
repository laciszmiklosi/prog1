#include "../GUI/Simple_window.h"
#include "../GUI/Graph.h"

#include <string>
#include <iostream>

using namespace Graph_lib;

int main(){
    try {
        Point t1 {100, 100};
        Simple_window win {t1, 600, 400, "My window"};
        win.wait_for_button();


        Axis xa {Axis::x, Point{30,300}, 280, 10, "x axis"};
        win.attach(xa);

        win.set_label("x axis");
        win.wait_for_button();


        Axis ya {Axis::y, Point{30,300}, 280, 10, "y axis"};
        ya.set_color(Color::cyan);
        ya.label.set_color(Color::dark_red);
        win.attach(ya);

        win.set_label("y axis");
        win.wait_for_button();


        Function sine {sin, 0, 100, Point{20, 250}, 1000, 50, 50};
        win.attach(sine);

        win.set_label("sine");
        win.wait_for_button();


        Poligon poly;
        poly.add(Point{300, 200});
        poly.add(Point{350, 100});
        poly.add(Point{400, 200});

        poly.set_color(Color::green);
        poly.set_style(Line_style::desh);
        win.attach(poly);

        win.set_label("triangle");
        win.wait_for_button();


        Rectangle r {Point{250, 200}, 100, 50};
        win.attach(r);

        Closed_polyline poly_rect;
        poly_rect.add(Point{100, 50});
        poly_rect.add(Point{200, 50});
        poly_rect.add(Point{200, 100});
        poly_rect.add(Point{100, 100});
        poly_rect.add(Point{50, 75});
        win.attach(Closed_polyline);

        win.set_label("rectangle");
        win.wait_for_button();


        r.set_fill_color(Color::yellow);
        poly.set_style(Line_style(Line_style::dash, 5));
        poly_rect.set_style(Line_style(Line_style::dash, 3));
        poly_rect.set_fill_color(Color::green);

        win.set_label("fill colors");
        win.wait_for_button();


        Text t {Point{150, 150}, "Hello, Graphical World!"};
        t.set_font(Font::times_bold); //t.set_font(Graph_lib::Font::times_bold);
        t.set_font_size(30);
        win.attach(t);

        win.set_label("Hello, graphical world!"); // 12.8
        win.wait_for_button();


        Image ii {Point{100,70), "../GUI/badge.jpg"}; 
        win.attach(ii);

        win.set_label("image");
        win.wait_for_button();


        ii.move(150, 200);

        win.set_label("image move");
        win.wait_for_button();


        Circle c {Point{100, 200}, 50};
        Ellipse e {Point{100, 200}, 75, 25};
        e.set_color(Color::dark_red);
        Mark m {Point{100, 200}, 'x'};

        ostringstream oss;
        oss << "screen size: " << x_max() << "*" << y_max() << "; window size: " << win.x_max() << "*" << win.y_max();
        Text sizes {Point{100, 20}, oss.str()};

        Image cal {Point{225, 225}, "../GUI/badge.jpg"};
        cal.set_mask(Point{40, 40}, 200, 150);

        win.attach(c);
        win.attach(m);
        win.attach(e);

        win.attach(sizes);
        win.attach(cal);
        win.set_label("and much more");
        win.wait_for_button();

    } catch(exception& e){
        cerr << "exception: " << e.what() << endl;
        return 1;
    } catch(...) {
        cerr << "error" << endl;
        return 2;
    }
}