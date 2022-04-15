//drill12

/*
1. Get an empty Simple_window with the size 600 by 400 and a label My window compiled, linked, and run. Note that you have to link 
the FLTK library as described in Appendix D; #include Graph.h and Simple_window.h in your code; and 
include Graph.cpp and Window.cpp in your project.
*/
//2. Now add the examples from §12.7 one by one, testing between each added subsection example.
//3. Go through and make one minor change (e.g., in color, in location, or in number of points) to each of the subsection examples.

//g++ drill12.cpp ../header/Graph.cpp ../header/Window.cpp ../header/GUI.cpp ../header/Simple_window.cpp -o drill12 `fltk-config --ldflags --use-images`

#include "../header/Graph.h"
#include "../header/Simple_window.h"
#include <iostream>
#include <string>
using namespace Graph_lib;

int main(){

    try
    {
    		//1.
    		Point tl {500,0};
    		Simple_window win {tl,600,400,"My window #1"};
     		win.wait_for_button();

     		//2.
	    	Axis xa {Axis::x, Point{20,300}, 280, 10, "x axis"}; 
	   	xa.set_color(Color::green);
	   	xa.label.set_color(Color::yellow);
		win.attach(xa); 
		win.set_label("My window #2"); 
		win.wait_for_button();

		//3.
		Axis ya {Axis::y, Point{20,300}, 280, 10, "y axis"};
		ya.set_color(Color::cyan); 
		ya.label.set_color(Color::dark_red); 
		win.attach(ya);
		win.set_label("My window #3");
		win.wait_for_button(); 

		//4.
		Function sine {sin,0,100,Point{20,150},1000,50,50}; 
		win.attach(sine);
		win.set_label("My window #4");
		win.wait_for_button();
		sine.set_color(Color::blue);

		//5.
		Polygon poly;						//line 
		poly.add(Point{300,200}); 
		poly.add(Point{350,100});
		poly.add(Point{400,200});
		poly.set_color(Color::green);
		poly.set_style(Line_style::dash);
		win.attach(poly);
		win.set_label("My window #5");
		win.wait_for_button();

		//6.
		Rectangle r {Point{200,200}, 100, 50}; 
		win.attach(r);						//I (||)
		win.set_label("My window #6");			
		win.wait_for_button();

		Closed_polyline poly_rect;
		poly_rect.add(Point{100,50});			
		poly_rect.add(Point{200,50});
		poly_rect.add(Point{200,100});
		poly_rect.add(Point{100,100});
		win.attach(poly_rect);					//II (||)
		win.wait_for_button();

		poly_rect.add(Point{50,75});				//modify II (+1 point <||)
		win.wait_for_button();

		//7.
		r.set_fill_color(Color::red); 
		poly.set_style(Line_style(Line_style::dash,4));
		poly_rect.set_style(Line_style(Line_style::dash,2));
		poly_rect.set_fill_color(Color::yellow);
		win.set_label("My window #7");
		win.wait_for_button();

		//8.
		Text t {Point{150,150}, "Hello, graphical world! :)"};
		win.attach(t);
		win.set_label("My window #8");
		win.wait_for_button();      

		//9.
		t.set_font(Font::times_bold_italic);
		t.set_font_size(20);
		win.set_label("My window #9");
		win.wait_for_button();   

		//10.
		Image ii {Point{100,50},{"badge.jpg"}}; 
		win.attach(ii);
		win.set_label("My window #10");
		win.wait_for_button();      

		//11.
		ii.move(100,200);
		win.set_label("My window #11");
		win.wait_for_button(); 

		//12
		Circle c {Point{100,200},50};
		Ellipse e {Point{100,200}, 75,25};
		e.set_color(Color::dark_red);
		Mark m {Point{100,200},'x'};
		ostringstream oss;
		oss << "screen size: " << x_max() << "*" << y_max()			//info
		<< "; window size: " << win.x_max() << "*" << win.y_max();
		Text sizes {Point{100,20},oss.str()};
		Image stellaris {Point{225,225},"stellaris.jpg"}; 
		stellaris.set_mask(Point{40,40},145,82);
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
