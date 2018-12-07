/**
 * 声明抽象基类Shape，由它派生出3个派生类：Circle（圆形）、
 * Rectangle（矩形）、Triangle（三角形），用一个函数printArea
 * 分别输出以上三者的面积，3个图形的数据在定义对象时给定。
 * 本题是《C++面向对象程序设计》第6章第4题。
 */
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Shape {
    public:
        virtual string shapeName() const = 0;
        virtual float printArea() const = 0;
};

class Circle: public Shape {
    public:
        Circle(float r=0): radius(r){}
        string shapeName() const {
            return "Circle";
        }
        float printArea() const;
    protected:
        float radius;
};

float Circle::printArea() const {
    return 3.14159 * radius * radius;
}

class Rectangle: public Shape {
    public:
        Rectangle(float l=0, float w=0): length(l), width(w){}
        string shapeName() const {
            return "Rectangle";
        }
        float printArea() const;
    protected:
        float length, width;
};

float Rectangle::printArea() const {
    return length * width;
}

class Triangle: public Shape {
    public:
        Triangle(float x=0, float y=0, float z=0): a(x), b(y), c(z){}
        string shapeName() const {
            return "Triangle";
        }
        float printArea() const;
    protected:
        float a, b, c;
};

float Triangle::printArea() const {
    float p = (a + b + c) / 2;

    return sqrt(p * (p - a) * (p - b) * (p - c));
}

int main() {
    Shape *p;
    Circle c(5.6);
    Rectangle r(2.4, 1.2);
    Triangle t(3, 4, 5);

    p = &c;
    cout << p->shapeName() << ':' << p->printArea() << endl;
    p = &r;
    cout << p->shapeName() << ':' << p->printArea() << endl;
    p = &t;
    cout << p->shapeName() << ':' << p->printArea() << endl;
    return 0;
}