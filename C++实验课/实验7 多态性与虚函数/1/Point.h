#pragma once
#include <iostream>

using namespace std;

class Point {
    public:
        Point(float a=0, float b=0): x(a), y(b){}
        void setPoint(float, float);
        float getX() const;
        float getY() const;
        friend ostream & operator << (ostream &, const Point &);
    protected:
        float x, y;
};