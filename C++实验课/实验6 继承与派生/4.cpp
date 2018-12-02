/**
 * 分别声明Teacher（教师）类和Cadre（干部）类，采用多重继承方式由这两个类
 * 派生出新类Teacher_Cadre（教师兼干部）类。要求：
 * ①在两个基类中都包含姓名、年龄、性别、地址、电话等数据成员。
 * ②在Teacher类中还包含数据成员title（职称），在Cadre类中还包含数据成员
 * post（职务）。在Teacher_Cadre类中还包含数据成员wages（工资）。
 * ③对两个基类中的姓名、年龄、性别、地址、电话等数据成员用相同的名字，
 * 在引用这些数据成员时，指定作用域。
 * ④在类体中声明成员函数，在类外定义成员函数。
 * ⑤在派生类Teacher_Cadre的成员函数show中调用Teacher类中的display函数，
 * 输出姓名、年龄、性别、职称、地址、电话，然后再用cout语句输出职务与工资。
 */
#include <iostream>
#include <string>

using namespace std;

class Teacher {
    public:
        Teacher(string n, int a, char s, string ad, string p, string t)
        : name(n), age(a), sex(s), addr(ad), phone(p), title(t){}

        void display();
    private:
        string name;
        int age;
        char sex;
        string addr;
        string phone;
    protected:
        string title;
};

void Teacher::display() {
    cout << "name:" << name << endl;
    cout << "age:" << age << endl;
    cout << "sex:" << sex << endl;
    cout << "address:" << addr << endl;
    cout << "phone:" << phone << endl;
    cout << "title:" << title << endl;
}

class Cadre {
    public:
        Cadre(string n, int a, char s, string ad, string p, string po)
        : name(n), age(a), sex(s), addr(ad), phone(p), post(po){}
    private:
        string name;
        int age;
        char sex;
        string addr;
        string phone;
    protected:
        string post;
};

class Teacher_Cadre: public Teacher, public Cadre {
    public:
        Teacher_Cadre(string n, int a, char s, string ad,
                      string p, string t, string po, int w):
            Teacher(n, a, s, ad, p, t),
            Cadre(n, a, s, ad, p, po),
            wages(w){}

        void show();
    private:
        int wages;
};

void Teacher_Cadre::show() {
    display();
    cout << "post:" << post << endl;
    cout << "wage:" << wages << endl;
}

int main() {
    Teacher_Cadre tc("Wang_li", 24, 'f', "115 Beijing Road,Shanghai",
                     "110", "assistant", "civil", 2400);

    tc.show();
    return 0;
}