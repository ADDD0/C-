/**
 * 将例5.3的程序修改、补充，写成一个完整、正确的程序，用保护继承方式。
 * 在程序中应包括输入数据的函数。
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

class Student1: protected Student {
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