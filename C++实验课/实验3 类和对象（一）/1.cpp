/**
 * 有以下程序：
 * #include<iostream>
 * using namespace std;
 * class Time                                             //定义Time类
 *   {public:                                             //数据成员为公用的
 *     int hour;
 *     int minute;
 *     int sec;
 *   };
 *
 * int main()
 *   { Time t1;                                           //定义t1为Time类对象
 *     cin>>t1.hour;                                      //输入设定的时间
 *     cin>>t1.minute;
 *     cin>>t1.sec;
 *     cout<<t1.hour<<":"<<t1.minute<<":"<<t1.sec<<endl;  //输出时间
 *     return 0;
 *   }
 * 改写程序，要求：
 * ①将数据成员改为私有的；
 * ②将输入和输出的功能改为由成员函数实现；
 * ③在类体内定义成员函数。
 * 然后编译和运行程序。请分析什么成员应指定为公用的？什么成员应指定为私有的？
 * 什么函数最好放在类中定义？什么函数最好放在类外定义？
 * 本题是《C++面向对象程序设计》第8章第2题。
 */
#include <iostream>

using namespace std;

class Time {
    public:
        void set() {
            cin >> hour >> minute >> sec;
        }

        void get() {
            cout << hour << ":" << minute << ":" << sec << endl;
        }
    private:
        int hour;
        int minute;
        int sec;
};

int main() {
    Time t1;

    t1.set();
    t1.get();
    return 0;
}