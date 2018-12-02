/**
 * 在例6.3的基础上作以下修改，并作必要的讨论。
 * （1）把构造函数修改为带参数的函数，在建立对象时初始化。
 * （2）先不将析构函数声明为virtual，在main函数中另设一个指向
 * Circle类对象的指针变量，使它指向grad1。运行程序，分析结果。
 * （3）不作第（2）点的修改而将析构函数声明为virtual，
 * 运行程序，分析结果。
 */
#include <iostream>

using namespace std;

class Point {
    public:
        Point(float a=0, float b=0): x(a), y(b){}
        ~Point() {
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
    Circle grad1(2.4,1.2,5.6);
    Circle *c=&grad1;

    delete p;
    cout << endl;
    delete c;
    return 0;
}