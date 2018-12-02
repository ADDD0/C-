/**
 * 写一个程序，定义抽象基类Shape，由它派生出5个派生类：Circle（圆形）、
 * Square（正方形）、Rectangle（矩形）、Trapezoid（梯形）、Triangle
 * （三角形）。用虚函数分别计算几种图形面积，并求它们的和。
 * 要求用基类指针数组，使它的每一个元素指向一个派生类对象。
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
            return "Rectangle:";
        }
        float printArea() const;
    protected:
        float length, width;
};

float Rectangle::printArea() const {
    return length * width;
}

class Square: public Rectangle {
    public:
        Square(float x=0): Rectangle(x, x){}
        string shapeName() const {
            return "Square";
        }
};

class Trapezoid: public Shape {
    public:
        Trapezoid(float t=0, float b=0, float h=0)
        : topline(t), baseline(b), height(h){}
        string shapeName() const {
            return "Trapezoid";
        }
        float printArea() const;
    protected:
        float topline, baseline, height;
};

float Trapezoid::printArea() const {
    return (topline + baseline) * height / 2;
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
    Circle circle(5.6);
    Square square(10);
    Rectangle rectangle(2.4, 1.2);
    Trapezoid trapezoid(3.2, 4.5, 3.5);
    Triangle triangle(6.4, 5.2, 10.5);
    Shape *p[5] = {
        &circle,
        &square,
        &rectangle,
        &trapezoid,
        &triangle
    };
    float total=0;

    for (int i=0; i < 5; ++i) {
        float area = p[i]->printArea();
        total += area;
        cout << p[i]->shapeName() << ':' << area << endl;
    }
    cout << "total area:" << total << endl;
    return 0;
}