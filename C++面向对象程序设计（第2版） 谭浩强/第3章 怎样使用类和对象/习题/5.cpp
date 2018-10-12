/**
 * 建立一个对象数组，内放5个学生的数据（学号、成绩），设立一个函数max，用指向
 * 对象的指针作函数参数，在max函数中找出5个学生中成绩最高者，并输出其学号。
 */
#include <iostream>

using namespace std;

class Student {
    public:
        Student(int n, float s): sno(n), score(s) {}
        void showSno();

        int sno;
        float score;
};

void Student::showSno() {
    cout << "sno:" << sno << endl;
}

int main() {
    Student max(Student *);

    Student arr[] = {
        Student(101, 78.5), Student(102, 85.5), Student(103, 98.5),
        Student(104, 100.0), Student(105, 95.5)
    };

    max(arr).showSno();
}

Student max(Student *p) {
    Student *max=p;

    for (int i=0; i < 5; ++i)
        if (max->score < (p + i)->score)
            max = p + i;
    return *max;
}