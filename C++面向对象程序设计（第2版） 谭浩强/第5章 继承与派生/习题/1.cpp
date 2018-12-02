/**
 * 将例5.1的程序片断补充和改写成一个完整、正确的程序，用公用继承方式。
 * 在程序中应包括输入数据的函数，在程序运行时输入
 * num，name，sex，age，addr的值，程序应输出以上5个数据的值。
 */
#include <iostream>

using namespace std;

class Student {
    public:
        void get_value() {
            cin >> num >> name >> sex;
        }

        void display() {
            cout << "num:" << num << endl;
            cout << "name:" << name << endl;
            cout << "sex:" << sex << endl;
        }
    private:
        int num;
        string name;
        char sex;
};

class Student1: public Student {
    public:
        void get_value_1() {
            cin >> age >> addr;
        }

        void display_1() {
            cout << "age:" << age << endl;
            cout << "address:" << addr << endl;
        }
    private:
        int age;
        string addr;
};

int main() {
    Student1 stud;

    stud.get_value();
    stud.get_value_1();
    stud.display();
    stud.display_1();
    return 0;
}