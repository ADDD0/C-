/**
 * 将例3.13中的Time类声明为Date类的友元类，通过Time类中的display函数引用
 * Date类对象的私有数据，输出年、月、日和时、分、秒。
 */
#include <iostream>

using namespace std;

class Date;
class Time {
    public:
        Time(int h, int m, int s): hour(h), minute(m), sec(s) {}
        void display(Date &);
    private:
        int hour;
        int minute;
        int sec;
};

class Date {
    public:
        friend Time;
        Date(int m, int d, int y): month(m), day(d), year(y) {}
    private:
        int month;
        int day;
        int year;
};

void Time::display(Date &d) {
    cout << d.month << "/" << d.day << "/" << d.year << endl;
    cout << hour << ":" << minute << ":" << sec << endl;
}

int main() {
    Date d1(12, 25, 2004);
    Time t1(10, 13, 56);

    t1.display(d1);
    return 0;
}