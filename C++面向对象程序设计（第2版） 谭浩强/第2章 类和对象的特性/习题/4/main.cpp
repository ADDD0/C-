/**
 * 在本章第2.3.3节中分别给出了包含类定义的头文件student.h，包含成员函数定义的
 * 源文件student.cpp以及包含主函数的源文件main.cpp。请完善该程序，在类中增加
 * 一个对数据成员赋初值的成员函数set_value。上机调试并运行。
 */
#include <iostream>
#include "student.h"

using namespace std;

int main() {
    Student stud;

    stud.set_value();
    stud.display();
    return 0;
}