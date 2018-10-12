/**
 * 将例3.13程序中的display函数不放在Time类中，而作为类外的普通函数，然后
 * 分别在Time和Date类中将display声明为友元函数。在主函数中调用display函数，
 * display函数分别引用Time和Date两个类的对象的私有数据，输出年、月、日和
 * 时、分、秒。请读者自己完成并上机调试。
 */
#include <iostream>

using namespace std;

class Date;
class Time {
    public:
        Time(int h, int m, int s): hour(h), minute(m), sec(s) {}
        friend void display(Date &, Time &);
    private:
        int hour;
        int minute;
        int sec;
};

class Date {
    public:
        Date(int m, int d, int y): month(m), day(d), year(y) {}
        friend void display(Date &, Time &);
    private:
        int month;
        int day;
        int year;
};

void display(Date &d, Time &t) {
    cout << d.month << "/" << d.day << "/" << d.year << endl;
    cout << t.hour << ":" << t.minute << ":" << t.sec << endl;
}

int main() {
    Date d1(12, 25, 2004);
    Time t1(10, 13, 56);

    display(d1, t1);
    return 0;
}