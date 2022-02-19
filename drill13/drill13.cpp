#include "Graph.h"
#include "Simple_window.h"

#include <iostream>
#include <string>

//g++ drill13.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill13 `fltk-config --ldflags --use-images`

using namespace Graph_lib;

int main(){


    try{

        //1.

        Point tl {500,0};
        Simple_window win {tl,800,1000,"My window"};

        //.2

        Lines grid;
        int x = 800;
        int y = 800;

        for (int i = 0; i <= x; i+=100)
        {
            grid.add(Point(0,i), Point(x, i));
        }

        for (int i = 0; i <= y; i+=100)
        {
            grid.add(Point(i,0), Point(i, y));
        }
        win.attach(grid); 
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
        win.wait_for_button();

        //4.

        Image vibe_1 {Point{0,400},"vibe22.jpg"};
        Image vibe_2 {Point{400,600},"vibe22.jpg"};
        Image vibe_3 {Point{600,200},"vibe22.jpg"};
        win.attach(vibe_1);
        win.attach(vibe_2);
        win.attach(vibe_3);
        win.wait_for_button();

        //5.

        vector<int>coordinate;
        for (int i = 0; i <= 800; i+=100)
        {
            coordinate.push_back(i);
        }
        vector<int>coordinate2;
        for (int i = 0; i <= 800; i+=100)
        {
            coordinate2.push_back(i);
        }
        int rcoordinate;
        int rcoordinate2;
        while(true)
        {
            rcoordinate = rand() % 8;
            rcoordinate2 = rand() % 8;
            Image vibe {Point{coordinate[rcoordinate],coordinate[rcoordinate2]},"vibe11.jpg"};
            win.attach(vibe);
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