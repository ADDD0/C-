/**
 * 编程序实现以下功能：
 * （1）按职工号由小到大的顺序将5个员工的数据（包括号码、姓名、年龄、工资）
 * 输出到磁盘文件中保存。
 * （2）从键盘输入两个员工的数据（职工号大于已有的职工号），增加到文件的末尾。
 * （3）输出文件中全部职工的数据。
 * （4）从键盘输入一个号码，从文件中查找有无此职工号，如有则显示此职工是
 * 第几个职工以及此职工的全部数据。如没有，就输出“无此人”。可以反复多次
 * 查询，如果输入查找的职工号为0，就结束查询。
 */
#include <iostream>
#include <fstream>

using namespace std;

struct staff {
    int num;
    char name[20];
    int age;
    int salary;
};

void fun1() {
    staff s[5]={1001, "Li", 18, 850,
                1002, "Fan", 19, 975,
                1004, "Wang", 17, 540,
                1006, "Tan", 15, 765,
                1010, "Ling", 16, 960};
    ofstream outfile("staff.dat", ios::ate | ios::binary);

    for (int i=0; i < 5; ++i)
        outfile.write((char *) &s[i], sizeof(staff));
    outfile.close();
}

void write() {
    staff s;
    ofstream outfile("staff.dat", ios::app | ios::binary);

    cin >> s.num >> s.name >> s.age >> s.salary;
    outfile.write((char *) &s, sizeof(staff));
    outfile.close();
}

void fun2() {
    cout << "input two staffs data:" << endl;
    write();
    write();
}

void show(staff s) {
    cout << "num:" << s.num << endl;
    cout << "name:" << s.name << endl;
    cout << "age:" << s.age << endl;
    cout << "salary:" << s.salary << endl << endl;
}

void fun3() {
    staff s;
    ifstream infile("staff.dat", ios::binary);

    infile.read((char *) &s, sizeof(staff));
    while (!infile.eof()) {
        show(s);
        infile.read((char *) &s, sizeof(staff));
    }
    infile.close();
}

void search(int sno) {
    int flag=0;
    staff s;
    ifstream infile("staff.dat", ios::binary);

    infile.read((char *) &s, sizeof(staff));
    while (!infile.eof()) {
        if (s.num == sno) {
            show(s);
            flag = 1;
        }
        infile.read((char *) &s, sizeof(staff));
    }
    infile.close();
    if (!flag)
        cout << "not found" << endl;
}

void fun4() {
    int sno;

    cout << "search in number:";
    cin >> sno;
    while (sno) {
        search(sno);
        cout << "search in number:";
        cin >> sno;
    }
}

int main() {
    fun1();
    fun2();
    fun3();
    fun4();

    return 0;
}