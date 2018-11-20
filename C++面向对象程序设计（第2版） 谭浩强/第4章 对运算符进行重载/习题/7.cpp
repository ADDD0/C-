/**
 * 定义一个Teacher（教师）类和一个Student（学生）类，二者有一部分数据成员是
 * 相同的，例如num（号码），name（姓名），sex（性别）。
 * 编写程序，将一个Student对象（学生）转换为Teacher（教师）类，只将以上3个相同
 * 的数据成员移植过去。可以设想为：一位学生大学毕业了，留校担任教师，他原有的
 * 部分数据对一位教师来说仍然是有用的，应当保留并成为其教师的数据的一部分。
 */
#include <iostream>

using namespace std;

class Teacher {
    public:
        Teacher(int num=0, char *na=NULL, char s='m') {
            number = num, name = na, sex = s;
        }
        void display();
    private:
        int number;
        char *name;
        char sex;
};

class Student {
    public:
        Student(int num=0, char *na=NULL, char s='m') {
            number = num, name = na, sex = s;
        }
        operator Teacher() {return Teacher(number, name, sex);}
    private:
        int number;
        char *name;
        char sex;
};

void Teacher::display() {
    cout << "num:" << number << endl
         << "name:" << name << endl
         << "sex:" << sex << endl;
}

int main() {
    Student s(110, "XiaoFang", 'w');

    Teacher(s).display();
    return 0;
}