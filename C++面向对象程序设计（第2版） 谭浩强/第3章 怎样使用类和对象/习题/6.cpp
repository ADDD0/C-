/**
 * 阅读下面程序，分析其执行过程，写出输出结果。
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
    Student stud(101, 78.5);

    stud.display();
    stud.change(101, 80.5);
    stud.display();
    return 0;
}