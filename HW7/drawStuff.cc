#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


// -------------- Design your Shape class here ---------------
// -----------------------------------------------------------
// Shape abstract class with private double variable x and y that indicate shape position
// make the following functions
//  1. Constructor shape (x, y)
//  2. function area take no parameters return double const  equal zero
//  3. function draw take ostream file return void  equal zero
//  4. make deconstruct ~Shape


// -------------- Design your Circle class here ---------------
// -----------------------------------------------------------
// Class Circle inherit Class Shape
// private variable x, y, radius
// Make the following functions:
// Circle constructor that take x, y, radius, Note that x and y are assigned to Shape(x,y)
//  for example constructor_name(double x, double y) : Shape(x,y)
// draw that take ostream file to write postscript instruction the function return void
//   postscript:
//    x y radius  0  360  arc \n
//    stroke \n
// for example for x = 200 pixels, y = 3 pixels, and radius 100 pixels. then your function should write this in test.ps
// stroke
// 200 300 100 0 360 arc
// area take no parameters and return double
// ~Circle deconstruction


// -------------- Design your Rect class here ---------------
// -----------------------------------------------------------
// Class Rect inherit Class Shape
// private variable x, y, width, and height
// Make the following functions:
// Rect constructor that take x, y,  width,  height
// draw that take ostream file to write postscript instruction the function return void
// draw that take ostream file to write postscript instruction the function return void
//   postscript:
//    x y moveto \n
//    x+w y lineto \n
//    x+w y+h lineto \n
//    x y+h lineto \n
//    closepath \n
//    stroke \n
// area take no parameters and return double
// ~Rect deconstruction


// -------------- Design your FilledRect class here ---------------
// -----------------------------------------------------------
// Class FilledRect inherit Class Shape
// private variable x, y, width, and height
// Make the following functions:
// FilledRect constructor that take x, y,  width,  height
// draw that take ostream file to write postscript instruction the function return void
//   postscript:
//    x y moveto \n
//    x+w y lineto \n
//    x+w y+h lineto \n
//    x y+h lineto \n
//    closepath \n
//    fill \n
// area take no parameters and return double
// ~FilledRect deconstruction


// -------------- Design your Drawing class here ---------------
// -----------------------------------------------------------
// private variables ofstream and vector<shape*>
// Make the following functions:
// Drawing constructor as following (is given):
//  Drawing(string filename) : f(filename.c_str()), shapes() {} // where f is ofstream
// void add that take shape and push_back to vector
// void draw take no parameters and loop inside vector to rum draw function for each shape class
// void showArea take no parameters and loop inside vector to run area function for each shape class
// void setrgb take three double for red, green, and blue and write postscript line to change color
//   postscript:
//    r_value g_value b_value setrgbcolor \n


int main() {
    cout << "########" << endl;
    cout << "Main Problem" << endl;
    cout << "########" << endl;

    // set path to create .ps file to write postscript instructions
    Drawing d("/test.ps");
    // set color
    d.setrgb(1,0,0); // set drawing color to be bright red:  1 0 0 setrgbcolor
    // add FilledRect
    d.add(new FilledRect(100.0, 550.0, 200.0, 50)); // x y moveto x y lineto ... fill
    // add Rect
    d.add(new Rect(200.0, 650.0, 200.0, 50));       // x y moveto x y lineto ... stroke
    // add Circle
    d.add(new Circle(300,300, 100)); // centered in 300 , 300 pixel with radius
    // draw all shapes added to d
    d.draw();
    // print out all shapes area
    d.showArea();

    cout << "====[ end ]====" << endl;
    cout << "               " << endl;

    return 0;
}