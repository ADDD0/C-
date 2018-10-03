/**
 * 建立一个对象数组，内放5个学生的数据（学号、成绩），
 * 用指针指向数组首元素，输出第1，3，5个学生的数据。
 */
#include <iostream>

using namespace std;

class Student
{
    public:
        void set();
        void display();
    private:
        int sno;
        float score;
};

void Student::set()
{
    cin >> sno >> score;
}

void Student::display()
{
    cout << "sno:" << sno << " score:" << score << endl;
}

int main()
{
    Student *p = new Student[5];

    for (int i=0; i < 5; ++i) {
        cout << "student " << i + 1 << " info:";
        (p + i)->set();
    }
    for (int i=0; i < 5; i += 2) {
        cout << "student " << i + 1 << " info:";
        (p + i)->display();
    }
    return 0;
}