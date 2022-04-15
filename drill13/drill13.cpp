//drill13

/*
1. Make an 800-by-1000 Simple_window.   

2. Put an 8-by-8 grid on the leftmost 800-by-800 part of that window (so that each square is 100 by 100).

3. Make the eight squares on the diagonal starting from the top left corner red (use Rectangle).

4. Find a 200-by-200-pixel image (JPEG or GIF) and place three copies of it on the grid (each image covering foursquares). 
If you can’t find an image that is exactly 200 by 200, use set_mask() to pick a 200-by-200 section of a larger
image. Don’t obscure the red squares.

5. Add a 100-by-100 image. Have it move around from square to square when you click the “Next” button. Just put
wait_for_button() in a loop with some code that picks a new square for your image.*/

//g++ drill13.cpp ../header/Graph.cpp ../header/Window.cpp ../header/GUI.cpp ../header/Simple_window.cpp -o drill13 `fltk-config --ldflags --use-images`

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
        Simple_window win {tl,800,1000,"My window #1"};
        win.wait_for_button();

        //2.
        Lines grid;
        int x = 800;
        int y = 800;

        for (int i = 0; i <= x; i+=100)
        {
            grid.add(Point(0,i), Point(x, i));          //(x)
        }
        for (int i = 0; i <= y; i+=100)
        {
            grid.add(Point(i,0), Point(i, y));          //(y)
        }
        win.attach(grid); 
        win.set_label("My window #2");
        win.wait_for_button();

        //3.
        Vector_ref<Rectangle> rects;
        for (int i = 0; i < 8; i++)
        {
            rects.push_back(new Rectangle{Point{i*100,i*100},100,100});
            rects[i].set_fill_color(Color::red);
            //rects[i].set_color(Color::invisible);
            win.attach(rects[i]);                
        }
        win.set_label("My window #3");
        win.wait_for_button();

        //4. 
        Image vibe_1 {Point{0,400},"vibe22.jpg"};
        Image vibe_2 {Point{400,600},"vibe22.jpg"};
        Image vibe_3 {Point{600,200},"vibe22.jpg"};
        win.attach(vibe_1);
        win.attach(vibe_2);
        win.attach(vibe_3);
        win.set_label("My window #4");
        win.wait_for_button();

        //5.
        vector<int>coordinate;
        for (int i = 0; i <= 800; i+=100)              //i*100 
        {
            coordinate.push_back(i);
        }
        int r_coordinate;                              //r_index
        int r_coordinate2;   
        while(true)
        {
            r_coordinate = rand() % 8;
            r_coordinate2 = rand() % 8;
            Image vibe {Point{coordinate[r_coordinate],coordinate[r_coordinate2]},"vibe11.jpg"}; 
            win.attach(vibe);
            win.set_label("My window #5");
            win.wait_for_button();
        }

    }
    catch(exception & e){

        cerr<<"exception: " << e.what() << endl;
        return 1;

    }
    catch(...){

        cerr << "exception\n";
        return 2;
    }
    
}
