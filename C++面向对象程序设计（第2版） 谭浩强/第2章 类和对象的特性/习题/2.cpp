/* 改写本章例2.1程序，要求：
（1）将数据成员改为私有的；
（2）将输入和输出的功能改为由成员函数实现；
（3）在类体内定义成员函数。 */
#include <iostream>
using namespace std;

class Time
{
    private:
        int hour;
        int minute;
        int sec;
    public:
        void set_time()
        {
            cin >> hour;
            cin >> minute;
            cin >> sec;
        }

        void show_time()
        {
            cout << hour << ":" << minute << ":" << sec << endl;
        }
};

int main()
{

    Time t;

    t.set_time();
    t.show_time();
    return 0;
}