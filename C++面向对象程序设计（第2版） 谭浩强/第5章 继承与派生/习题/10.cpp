/**
 * 将本章5.8节中的程序片段加以补充完善，成为一个完整的程序。在程序中
 * 使用继承和组合。在定义Professor类对象prof1时给出所有数据的初值，
 * 然后修改prof1的生日数据，最后输出prof1的全部最新数据。
 */
#include <iostream>
#include <string>

using namespace std;

class Teacher {
    public:
        Teacher(string n, int a, char s): name(n), num(a), sex(s){}

        void show();
    private:
        string name;
        int num;
        char sex;
};

void Teacher::show() {
    cout << "name:" << name << endl;
    cout << "num:" << num <<endl;
    cout << "sex:" << sex <<endl;
}

class BirthDate {
    public:
        BirthDate(int y, int m, int d): year(y), month(m), day(d){}

        void setBirthday();
        void show();
    private:
        int year;
        int month;
        int day;
};

void BirthDate::setBirthday() {
    cout << "input y/m/d(1900 1 1):" << endl;
    cin >> year >> month >> day;
}

void BirthDate::show() {
    cout << "birthday:" << year << "/" << month << "/" << day << endl;
}

class Professor: public Teacher {
    public:
        Professor(string n, int a, char s, int y, int m, int d)
        : Teacher(n, a, s), birthday(y, m, d){}

        void display();
        void setBirthday();
    private:
        BirthDate birthday;
};

void Professor::display() {
    show();
    birthday.show();
}

void Professor::setBirthday() {
    birthday.setBirthday();
}

int main() {
    Professor prof1("Wang_li", 24, 'f', 1994, 1, 1);

    prof1.display();
    prof1.setBirthday();
    prof1.display();
    return 0;
}