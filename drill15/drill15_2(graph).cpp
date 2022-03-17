// g++ drill15graph.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill15graph `fltk-config --ldflags --use-images`

#include "Graph.h"
#include "Simple_window.h"

#include <iostream>
#include <string>
#include <stdexcept>

double one(double x) { 
	return 1; 
}


double slope(double x) { 
	return x/2; 
}


double square(double x) {
 	return x*x; 
 }

double sloping_cos(double x) {
	return cos(x) + slope(x);
}


int main() {
	Point tl(500,250);
	
	constexpr int xmax = 600;
	constexpr int ymax = 600;
	Simple_window win {tl, xmax, ymax, "Function graphs"};

	
	constexpr int x_orig = xmax/2;
	constexpr int y_orig = ymax/2;
	Point orig {x_orig, y_orig};

	constexpr int r_min = -10;
	constexpr int r_max = 11;

	constexpr int n_points = 400;

	constexpr int x_scale = 20;
	constexpr int y_scale = 20;

	constexpr int xlength = xmax - 40;
	constexpr int ylength = ymax - 40;

	Axis xa {Axis::x, Point{20,y_orig}, xlength, xlength/x_scale, "1 == 20 pixels"};
	xa.set_color(Color::red);

	Axis ya {Axis::y, Point{x_orig,ylength+20}, ylength, ylength/y_scale, "1 = 20 pixels"};
	ya.set_color(Color::red);

	Function s {one, r_min, r_max, orig, n_points, x_scale, y_scale};

	Function s2 {slope, r_min, r_max, orig, n_points, x_scale, y_scale};
	Text ts2 {Point{100, y_orig+y_orig/2-20}, "x/2"};

	Function s3 {square, r_min, r_max, orig, n_points, x_scale, y_scale};

	Function s4 {cos, r_min, r_max, orig, n_points, x_scale, y_scale};
	s4.set_color(Color::blue);

	Function s5 {sloping_cos, r_min, r_max, orig, n_points, x_scale, y_scale};

	win.attach(xa);
	win.attach(ya);
	win.attach(s);
	win.attach(s2);
	win.attach(ts2);
	win.attach(s3);
	win.attach(s4);
	win.attach(s5);
	win.wait_for_button();
};
