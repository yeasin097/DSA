#include<bits/stdc++.h>
using namespace std;

#define pi 3.1416

class Shape {
protected:
    string name;
    string shape;
public:
    Shape(string name) {
        this->name = name;
    }
    Shape(string name, string shape) {
        this->name=name;
        this->shape=shape;
    }
};

class Circle:public Shape {
    double radius;
public:
    Circle(double radius) {
        this->radius=radius;
        Shape("Circle", "Circle1");
    }
    double Area(void) {
        return pi*radius*radius;
    }
};

