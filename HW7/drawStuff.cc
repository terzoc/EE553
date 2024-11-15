#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;


// -------------- Design your Shape class here ---------------
// -----------------------------------------------------------
// Shape abstract class with private double variable x and y that indicate shape position
// make the following functions
//  1. Constructor shape (x, y)
//  2. function area take no parameters return double const  equal zero
//  3. function draw take ostream file return void  equal zero
//  4. make deconstruct ~Shape

class Shape{
private:
    double x,y;
public:
    Shape(double x,double y):x(x),y(y){};
    
    virtual double area() const{
        return 0.0;
    }

    virtual void draw(ostream& file){
    }

    ~Shape(){}
};

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
class Circle: public Shape{
private:
    double x,y,radius;
    
public:
    Circle(double x, double y, double radius):Shape(x,y), x(x), y(y), radius(radius){};

    double area() const override{
        return radius*radius*M_PI;
    }

    void draw(ostream& file) override{
        file << x << " " << y << " " << radius << " 0  360  arc \n";
        file << "stroke \n";
    }

    ~Circle(){}

};

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

class Rect: public Shape{
private:
    double x,y,width, height;

public:
    Rect(double x, double y, double h, double w): Shape(x,y), x(x), y(y), width(w), height(h){};

    double area() const override{
        return width * height;
    }

    void draw(ostream& file) override{
        file << x << " " << y << " moveto \n";
        file << x + width << " " << y << " lineto \n";
        file << x+width << " " << y + height << " lineto \n";
        file << x << " " << y+height << " lineto \n";
        file << "closepath \n";
        file << "stroke \n";
    }

    ~Rect(){}
};


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
class FilledRect : public Shape{
private:
    double x,y,height, width;

public:
    FilledRect(double x, double y, double h, double w): Shape(x,y), x(x), y(y), height(h), width(w){};

    double area() const override{
        return height * width;
    }

    void draw(ostream& file) override{
        file << x << " " << y << " moveto \n";
        file << x + width << " " << y << " lineto \n";
        file << x+width << " " << y + height << " lineto \n";
        file << x << " " << y+height << " lineto \n";
        file << "closepath \n";
        file << "fill \n";
    }

    ~FilledRect(){}
};


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
class Drawing{
private:
    ofstream file;
    vector<Shape*> shapes;

public:
    Drawing(string filename):file(filename.c_str()) {}

    void add(Shape* shape){
        shapes.push_back(shape);
    }

    void draw(){
        for (int i = 0; i < shapes.size(); i++){
            shapes.at(i)->draw(file);
        }
        file << "showpage\n";
        file.close();
    }

    void showArea(){
        double area = 0;
        for (int i = 0; i < shapes.size(); i++){
            area += shapes.at(i)->area();
        }
        cout << "Total Area: " << area << endl;
    }
    void setrgb(double r, double g, double b){
        file << r << " " << g << " " << b << " setrgbcolor \n";
    }
};

int main() {
    cout << "########" << endl;
    cout << "Main Problem" << endl;
    cout << "########" << endl;

    // set path to create .ps file to write postscript instructions
    Drawing d("test.ps");
    // set color
    d.setrgb(1,0,0); // set drawing color to be bright red:  1 0 0 setrgbcolor
    // add FilledRect
    d.add(new FilledRect(100.0, 550.0, 200.0, 50)); // x y moveto x y lineto ... fill
    // add Rect
    d.add(new Rect(200.0, 450.0, 200.0, 50));       // x y moveto x y lineto ... stroke
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