/**
 * 有以下程序：
 * #include<iostream>
 * class Student
 *   {public:
 *     Student(int n, float s):num(n), score(s){}
 *     void change(int n, float s){num=n;score=s;}
 *     void display(){cout<<num<<" "<<score<<endl;}
 *    private:
 *     int num;
 *     float score;
 *   };
 *
 * void main()
 * {Student stud(101, 78.5);
 *  stud.display();
 *  stud.change(101, 80.5);
 *  stud.display();
 * }
 * ①阅读此程序，分析其执行过程，然后上机运行，对比输出结果。
 *  本题是《C++面向对象程序设计》第3章第6题。
 * ②修改上面的程序，增加一个fun函数，改写main函数。在main函数中调用fun函数，
 *  在fun函数中调用change和display函数。在fun函数中使用对象的引用（Student&）
 *  作为形参。本题是《C++面向对象程序设计》第3章第8题。
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

void fun(Student &s) {
    s.change(101, 80.5);
    s.display();
}

int main() {
    Student stud(101, 78.5);

    stud.display();
    fun(stud);
    return 0;
}