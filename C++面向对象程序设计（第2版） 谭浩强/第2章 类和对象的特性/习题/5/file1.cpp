/* 将本章的例2.4改写为一个多文件的程序：
（1）将类定义放在头文件arraymax.h中；
（2）将成员函数定义放在源文件arraymax.cpp中；
（3）主函数放在源文件file1.cpp中。
请写出完整的程序，上机调试并运行。 */
#include "arraymax.h"
using namespace std;

int main()
{
    Array_max arrmax;

    arrmax.set_value();
    arrmax.max_value();
    arrmax.show_value();
    return 0;
}