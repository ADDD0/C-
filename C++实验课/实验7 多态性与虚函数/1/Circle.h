#pragma once
#include "Point.h"

using namespace std;

class Circle: public Point {
    public:
        Circle(float a=0, float b=0, float r=0): Point(a, b), radius(r){}
        void setRadius(float);
        float getRadius() const;
        float area() const;
        friend ostream & operator << (ostream &, const Circle &);
    protected:
        float radius;
};