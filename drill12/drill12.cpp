#include "Graph.h"
#include "Simple_window.h"

#include <iostream>
#include <string>

//g++ drill12.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill12 `fltk-config --ldflags --use-images`
using namespace Graph_lib;

int main(){

    try{

     Point tl {500,0};

     Simple_window win {tl,600,400,"My window #1"};

     win.wait_for_button();

     Axis xa {Axis::x, Point{20,300}, 280, 10, "x axis"}; // make an Axis
	// an Axis is a kind of Shape
	// Axis::x means horizontal
	// starting at (20,300)
	// 280 pixels long
	// 10 “notches”
	// label the axis "x axis"
    xa.set_color(Color::green);
    xa.label.set_color(Color::yellow);
	win.attach(xa); // attach xa to the window, win
	win.set_label("My window #2"); // relabel the window
	win.wait_for_button(); // display!

	Axis ya {Axis::y, Point{20,300}, 280, 10, "y axis"};
	ya.set_color(Color::cyan); // choose a color
	ya.label.set_color(Color::dark_red); // choose a color for the text

	win.attach(ya);
	win.set_label("My window #3");
	win.wait_for_button(); // display!

	Function sine {sin,0,100,Point{20,150},1000,50,50}; // sine curve

	// plot sin() in the range [0:100) with (0,0) at (20,150)
	// using 1000 points; scale x values *50, scale y values *50

	win.attach(sine);
	win.set_label("My window #4");
	win.wait_for_button();

	sine.set_color(Color::blue); // we changed our mind about sine’s color
	Polygon poly; // a polygon; a Polygon is a kind of Shape
	poly.add(Point{300,200}); // three points make a triangle
	poly.add(Point{350,100});
	poly.add(Point{400,200});
	poly.set_color(Color::green);
	poly.set_style(Line_style::dash);
	win.attach(poly);
	win.set_label("My window #5");
	win.wait_for_button();

	Rectangle r {Point{200,200}, 100, 50}; // top left corner, width, height
	win.attach(r);
	win.set_label("My window #6");
	win.wait_for_button();

	Closed_polyline poly_rect;
	poly_rect.add(Point{100,50});
	poly_rect.add(Point{200,50});
	poly_rect.add(Point{200,100});
	poly_rect.add(Point{100,100});
	win.attach(poly_rect);
	win.wait_for_button();

	poly_rect.add(Point{50,75});
	win.wait_for_button();

	r.set_fill_color(Color::red); // color the inside of the rectangle
	poly.set_style(Line_style(Line_style::dash,4));
	poly_rect.set_style(Line_style(Line_style::dash,2));
	poly_rect.set_fill_color(Color::yellow);
	win.set_label("My window #7");
	win.wait_for_button();

	Text t {Point{150,150}, "Hello, graphical world! :)"};
	win.attach(t);
	win.set_label("My window #8");
	win.wait_for_button();      

	t.set_font(Font::times_bold_italic);
	t.set_font_size(20);
	win.set_label("My window #9");
	win.wait_for_button();   

	Image ii {Point{100,50},"badge.jpg"}; // 400*212-pixel jpg
	win.attach(ii);
	win.set_label("My window #10");
	win.wait_for_button();      

	ii.move(100,200);
	win.set_label("My window #11");
	win.wait_for_button(); 

	Circle c {Point{100,200},50};
	Ellipse e {Point{100,200}, 75,25};
	e.set_color(Color::dark_red);
	Mark m {Point{100,200},'x'};
	ostringstream oss;
	oss << "screen size: " << x_max() << "*" << y_max()
	<< "; window size: " << win.x_max() << "*" << win.y_max();
	Text sizes {Point{100,20},oss.str()};
	Image stellaris {Point{225,225},"stellaris.jpg"}; 
	stellaris.set_mask(Point{40,40},145,82); // display center part of image
	win.attach(c);
	win.attach(m);
	win.attach(e);
	win.attach(sizes);
	win.attach(stellaris);
	win.set_label("My Window #12");
	win.wait_for_button();

    }catch(exception & e){

        cerr<<"exception: " << e.what() << endl;
        return 1;

    }catch(...){

        cerr << "exception\n";
        return 2;

    }

}
