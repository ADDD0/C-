/**
 * 修改第6题的程序，增加一个fun函数，改写main函数。改为在fun函数中调用
 * change和display函数。在fun函数中使用对象的引用（Student &）作为形参。
 */
#include <iostream>

using namespace std;

class Student {
    public:
        Student(int n, float s): num(n), score(s) {}

        void change(int n, float s) {
            num = n;
            score = s;
        }

        void display() {
            cout << num << " " << score << endl;
        }
    private:
        int num;
        float score;
};

int main() {
    void fun(Student &);

    Student stud(101, 78.5);

    fun(stud);
    return 0;
}

void fun(Student &stu) {
    stu.display();
    stu.change(101, 80.5);
    stu.display();
}