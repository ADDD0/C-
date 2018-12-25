/**
 * 将例8.3程序改为下面的程序，请分析执行过程，写出运行结果。
 * 并指出由于异常处理而调用了哪些析构函数。
 */
#include <iostream>
#include <string>

using namespace std;

class Student {
    public:
        Student(int n, string nam) {
            cout << "construtor - " << n << endl;
            num = n;
            name = nam;
        }
        ~Student() {
            cout << "destructor - " << num << endl;
        }
        void get_data();
    private:
        int num;
        string name;
};

void Student::get_data() {
    if (num == 0)
        throw num;
    else
        cout << num << " " << name << endl;
    cout << "in get_data()" << endl;
}

void fun() {
    Student stud1(1101, "tan");
    stud1.get_data();
    try {
        Student stud2(0, "Li");
        stud2.get_data();
    } catch(int n) {
        cout << "num=" << n << ",error!" << endl;
    }
}

int main() {
    cout << "main begin" << endl;
    cout << "call fun()" << endl;
    fun();
    cout << "main end" << endl;
    return 0;
}