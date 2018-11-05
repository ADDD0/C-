/**
 * 包含主函数的源文件main.cpp。
 * 为了组成一个完整的源程序，应当有包括主函数的源文件：
 *
 *
 * //main.cpp  主函数模块
 * #include <iostream>
 * #include "student.h"  //将类声明头文件包含进来
 * int main()
 * {Student stud;        //定义对象
 *  stud.display();      //执行stud对象的display函数
 *  return 0;
 * }
 * 请完善该程序，在类中增加一个对数据成员赋初值的成员函数set_value。
 * 上机调试并运行。本题是《C++面向对象程序设计》第2章第4题。
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