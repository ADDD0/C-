/**
 * 三位老师对数学竞赛进行了预测:
 * 甲说:学生A得了第一名,学生B得了第三名;
 * 乙说:学生C得了第一名,学生D得了第四名;
 * 丙说:学生D得了第二名,学生A得了第三名;
 * 他们每个人只说对了一半,并无并列名次,求每名同学的真实名次
 */
#include <iostream>

using namespace std;

int main() {
    for (int a=1; a < 5; ++a)
        for (int b=1; b < 5 && b != a; ++b)
            for (int c=1; c < 5 && c != b && c != a; ++c) {
                int d = 10 - a - b - c;
                int flag = 0;
                if (a == 1 ^ b == 3)
                    ++flag;
                if (c == 1 ^ d == 4)
                    ++flag;
                if (d == 2 ^ a == 3)
                    ++flag;
                if (flag == 3) {
                    cout << "a=" << a << endl;
                    cout << "b=" << b << endl;
                    cout << "c=" << c << endl;
                    cout << "d=" << d << endl;
                }
            }
    return 0;
}