/**
 * 修改上面第（2）题的程序，改为用公用继承方式。上机调试程序，使之能正确运行
 * 并得到正确的结果。本题是《C++面向对象程序设计》第5章第4题。
 * 对这两种继承方式作比较分析，考虑在什么情况下二者不能互相代替。
 */
#include <iostream>

using namespace std;

class Student {
    public:

    protected:
        int num;
        string name;
        char sex;
};

class Student1: public Student {
    public:
        void get_value();
        void display();
    private:
        int age;
        string addr;
};

void Student1::get_value() {
    cin >> num >> name >> sex;
    cin >> age >> addr;
}

void Student1::display() {
    cout << "num:" << num << endl;
    cout << "name:" << name << endl;
    cout << "sex:" << sex << endl;
    cout << "age:" << age << endl;
    cout << "address:" << addr << endl;
}

int main() {
    Student1 stud;

    stud.get_value();
    stud.display();
    return 0;
}