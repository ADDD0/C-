/**
 * 包含成员函数定义的源文件student.cpp。
 *
 * //student.cpp            在此文件中进行函数的定义
 * #include<iostream>
 * #include"student.h"      //不要漏写此行，否则编译通不过
 * void Student::display()  //在类外定义display类函数
 *        {cout<<"num:"<<num<<endl;
 *         cout<<"name:"<<name<<endl;
 *         cout<<"sex:"<<sex<<endl;
 *        }
 */
#include <iostream>
#include "student.h"

using namespace std;

void Student::set_value() {
    cout << "num:";
    cin >> num;
    cout << "name:";
    cin >> name;
    cout << "sex:";
    cin >> sex;
}

void Student::display() {
    cout << "num:" << num << endl;
    cout << "name:" << name << endl;
    cout << "sex:" << sex << endl;
}