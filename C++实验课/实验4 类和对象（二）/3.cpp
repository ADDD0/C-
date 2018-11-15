/**
 * 有以下程序（这是《C++面向对象程序设计》第3章例3.13的程序）。
 * #include<iostream>
 * using namespace std;
 * class Date;               //对Date类的提前引用声明
 * class Time                //定义Time类
 *   {public:
 *     Time(int, int, int);
 *     void display(Date&);  //display是成员函数, 形参是Date类对象的引用
 *    private:
 *     int hour;
 *     int minute;
 *     int sec;
 *   };
 *
 * class Date                           //声明Date类
 * {public:
 *   Date(int, int, int);
 *   friend void Time::display(Date&);  //声明Time中的display函数为友元成员函数
 *  private:
 *   int month;
 *   int day;
 *   int year;
 * };
 *
 * Time::Time(int h, int m, int s)  //类Time的构造函数
 * {hour=h;
 * minute=m;
 *  sec=s;
 * }
 *
 * void Time::display(Date&d)       //display的作用是输出年、月、日和时、分、秒
 *  {cout<<d.month<<"/"<<d.day<<"/"<<d.year<<endl;  //引用Date类对象中的私有数据
 *   cout<<hour<<":"<<minute<<":"<<sec<<endl;       //引用本类对象中的私有数据
 *  }
 *
 * Date::Date(int m, int d, int y)  //类Date的构造函数
 *  {month=m;
 *   day=d;
 *   year=y;
 *  }
 *
 * int main()
 * {Time t1(10,13,56);              //定义Time类对象t1
 *  Date d1(12,25,2004);            //定义Date类对象d1
 *  t1.display(d1);                 //调用t1中的display函数,实参是Date类对象d1
 *  return 0;
 * }
 * 请读者分析和运行此程序，注意友元函数Time::display的作用。将程序中的display
 * 函数不放在Time类中，而作为类外的普通函数，然后分别在Time和Date类中将display
 * 声明为友元函数。在主函数中调用display函数，display函数分别引用Time和Date两个
 * 类的对象的私有数据，输出年、月、日和时、分、秒。
 * 本题是《C++面向对象程序设计》第3章第10题。
 * 修改后上机调试和运行。
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