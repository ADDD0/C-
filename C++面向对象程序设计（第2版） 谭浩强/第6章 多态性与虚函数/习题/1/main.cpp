/**
 * 在例6.1程序基础上作一些修改。定义Point（点）类，由Point类派生出
 * Circle（圆）类，再由Circle类派生出Cylinder（圆柱体）类。
 * 将类的定义部分分别作为3个头文件，对它们的成员函数的声明部分分别
 * 作为3个源文件（.cpp文件），在主函数中用#include命令把它们包含进来，
 * 形成一个完整的程序，并上机运行。
 */
#include "Point.h"
#include "Circle.h"
#include "Cylinder.h"
#include <iostream>

using namespace std;

int main() {
    Cylinder cy1(3.5, 6.4, 5.2, 10);
    Point &pRef=cy1;
    Circle &cRef=cy1;

    cout << "original cylinder:\nx=" << cy1.getX() << ",y="
         << cy1.getY() << ",r=" << cy1.getRadius() << ",h="
         << cy1.getHeight() << "\narea=" << cy1.area()
         << ",volume=" << cy1.volume() << endl;
    cy1.setHeight(15);
    cy1.setRadius(7.5);
    cy1.setPoint(5,5);
    cout << "\nnew cylinder:\n" << cy1;
    cout << "\npRef as a point:" << pRef;
    cout << "\ncRef as a Circle:" << cRef;
    return 0;
}