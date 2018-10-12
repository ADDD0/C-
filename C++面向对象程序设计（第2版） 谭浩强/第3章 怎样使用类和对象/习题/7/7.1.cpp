/**
 * 将第6题的程序分别作以下修改，分析所修改部分的含义以及编译和运行的情况。
 * （1）将main函数第2行改为
 * const Student stud(101, 78.5);
 *
 * （2）在（1）的基础上修改程序，使之能正常运行，用change函数修改数据成员
 * num和score的值。
 *
 * （3）将main函数改为
 * int main()
 * {
 *     Student stud(101, 78.5);
 *     Student *p=&stud;
 *
 *     p->display();
 *     p->change(101, 80.5);
 *     p->display();
 *     return 0;
 * }
 * 其他部分仍同第6题的程序。
 *
 * （4）在（2）的基础上将main函数第3行改为
 * const Student *p=&stud;
 *
 * （5）再把main函数第3行改为
 * Student *const p=&stud;
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
    const Student stud(101, 78.5);

    stud.display();
    stud.change(101, 80.5);
    stud.display();
    return 0;
}