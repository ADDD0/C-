#include <iostream>

using namespace std;

class Point {
    public:
        Point(float a=0, float b=0): x(a), y(b){}
        virtual ~Point() {
            cout << "executing Point destructor" << endl;
        }
    protected:
        float x, y;
};

class Circle: public Point {
    public:
        Circle(float a=0, float b=0, float r=0): Point(a, b), radius(r){}
        ~Circle() {
            cout << "executing Circle destructor" << endl;
        }
    protected:
        float radius;
};

int main() {
    Point *p=new Circle;

    delete p;
    return 0;
}