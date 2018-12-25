/**
 * 学校的人事部门保存了前关学生的部分数据（学号、姓名、年龄、住址），
 * 教务部门也保存了学生的另外一些部分数据（学号、姓名、性别、成绩），
 * 两个部门分别编写了本部门的学生数据管理程序，其中都用了Student作为类名。
 * 现在要求在全校的学生数据管理程序中调用这两个部门的学生数据，
 * 分别输出两种内容的学生数据。要求用ANSI C++编程，使用命名空间。
 */
#include <iostream>

using namespace std;

namespace ns1 {
    class Student {
        public:
            Student(int n, string nam, int a) {
                num = n; name = nam; age = a;
            }
        void get_data();
        private:
            int num;
            string name;
            int age;
    };
    void Student::get_data() {
        cout << num << " " << name << " " << age << endl;
    }
};

namespace ns2 {
    class Student {
        public:
            Student(int n, string nam, char s) {
                num = n; name = nam; sex = s;
            }
        void get_data();
        private:
            int num;
            string name;
            char sex;
    };
    void Student::get_data() {
        cout << num << " " << name << " " << sex << endl;
    }
};

int main() {
    ns1::Student stud1(101, "Wang", 18);
    stud1.get_data();
    ns2::Student stud2(102, "Li", 'f');
    stud2.get_data();

   return 0;
}