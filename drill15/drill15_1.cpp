//drill15_1(graph)

/*
1. Make an empty 600-by-600 Window labeled “Function graphs.”

2. Note that you’ll need to make a project with the properties specified in the 
“installation of FLTK” note from the course website.

3. You’ll need to move Graph.cpp and Window.cpp into your project.

4. Add an x axis and a y axis each of length 400, labeled “1 = = 20 pixels” and with a notch every 20 pixels. 
The axes should cross at (300,300).

5. Make both axes red.

In the following, use a separate Shape for each function to be graphed:
{
1. Graph the function double one(double x) { return 1; } in the range [–10,11] with (0,0) at (300,300) using 400 points and no scaling (in the window).
2. Change it to use x scale 20 and y scale 20.
3. From now on use that range, scale, etc. for all graphs.
4. Add double slope(double x) { return x/2; } to the window.
5. Label the slope with a Text "x/2" at a point just above its bottom left end point.}

6. Add double square(double x) { return x*x; } to the window.

7. Add a cosine to the window (don’t write a new function).

8. Make the cosine blue.

9. Write a function sloping_cos() that adds a cosine to slope() (as defined above) and add it to the window.*/

//g++ drill15_1.cpp ../header/Graph.cpp ../header/Window.cpp ../header/GUI.cpp ../header/Simple_window.cpp -o drill15_1 `fltk-config --ldflags --use-images`

#include "../header/Graph.h"
#include "../header/Simple_window.h"
#include <iostream>
#include <string>
#include <stdexcept>

double one(double x) { return 1;}

double slope(double x) { return x/2;}

double square(double x) { return x*x;}

double sloping_cos(double x) { return cos(x) + slope(x);}

int main() {
	
	//1.
	Point tl(500,250);
	
	Simple_window win {tl, 600, 600, "Function graphs"};
	win.wait_for_button();

	constexpr int x_orig = 300;
	constexpr int y_orig = 300;

	Point orig {x_orig, y_orig};		//origo point

	constexpr int r_min = -10;
	constexpr int r_max =  11;
	constexpr int points = 400;
	constexpr int x_scale = 20;
	constexpr int y_scale = 20;

	//4. - 5.
	Axis xa {Axis::x, Point{100,300}, 400, 20, "1 == 20 pixels"};
	xa.set_color(Color::red);

	Axis ya {Axis::y, Point{300,500}, 400, 20, "1 = 20 pixels"};
	ya.set_color(Color::red);

	win.attach(xa);
	win.attach(ya);
	win.set_label("Axis");
	win.wait_for_button();

	Function s {one, r_min, r_max, orig, points, x_scale, y_scale};

	win.attach(s);
	win.set_label("One");
	win.wait_for_button();

	Function s2 {slope, r_min, r_max, orig, points, x_scale, y_scale};
	Text ts2 {Point{100, 430}, "x/2"};
	
	win.attach(s2);
	win.attach(ts2);
	win.set_label("Slope");
	win.wait_for_button();

	//6.
	Function s3 {square, r_min, r_max, orig, points, x_scale, y_scale};
	
	win.attach(s3);
	win.set_label("Parabola");
	win.wait_for_button();

	//7.
	Function s4 {cos, r_min, r_max, orig, points, x_scale, y_scale};

	//8.
	s4.set_color(Color::blue);

	win.attach(s4);
	win.set_label("Cos");
	win.wait_for_button();

	//9.
	Function s5 {sloping_cos, r_min, r_max, orig, points, x_scale, y_scale};

	win.attach(s5);
	win.set_label("Sloping_cos");
	win.wait_for_button();
	
};
