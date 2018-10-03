/**
 * 如果将第2题中程序的第4行改为用默认参数，即
 * Date(int=1, int=1, int=2005);
 * 分析程序有无问题。上机编译，分析出错信息，修改程序使之能通过编译。
 * 要求保留上面一行给出的构造函数，同时能输出与第2题程序相同的输出结果。
 */
#include <iostream>

using namespace std;

class Date
{
    public:
        Date(int=1, int=1, int=2005);
        void display();
    private:
        int month;
        int day;
        int year;
};

Date::Date(int m, int d, int y): month(m), day(d), year(y)
{
    ;
}

void Date::display()
{
    cout << month << "/" << day << "/" << year <<endl;
}

int main()
{
    Date d1(10, 13, 2005);
    Date d2(12, 30);
    Date d3(10);
    Date d4;

    d1.display();
    d2.display();
    d3.display();
    d4.display();
    return 0;
}