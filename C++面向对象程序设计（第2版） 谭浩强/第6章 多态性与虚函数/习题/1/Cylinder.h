#pragma once
#include "Circle.h"

using namespace std;

class Cylinder: public Circle {
    public:
        Cylinder(float a=0, float b=0, float r=0, float h=0)
        : Circle(a, b, r), height(h){}
        void setHeight(float);
        float getHeight() const;
        float area() const;
        float volume() const;
        friend ostream & operator << (ostream &, const Cylinder &);
    protected:
        float height;
};