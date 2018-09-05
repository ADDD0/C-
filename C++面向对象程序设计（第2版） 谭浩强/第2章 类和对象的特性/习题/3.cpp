/* 在第2题的基础上进行如下修改：
在类体内声明成员函数，而在类外定义成员函数。 */
#include <iostream>
using namespace std;

class Time
{
    private:
        int hour;
        int minute;
        int sec;
    public:
        void set_time();
        void show_time();
};

int main()
{

    Time t;

    t.set_time();
    t.show_time();
    return 0;
}

void Time::set_time()
{
    cin>>hour;
    cin>>minute;
    cin>>sec;
}

void Time::show_time()
{
    cout<<hour<<":"<<minute<<":"<<sec<<endl;
}