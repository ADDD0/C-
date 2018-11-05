/**
 * 编一个程序，用来求2个或3个正整数中的最大数。
 * ①用不带默认参数的函数实现。
 * ②用带有默认参数的函数实现。
 * (本题是《C++面向对象程序设计》第1章习题第11题)
 * 对比两种方法，分析用带有默认参数的函数的优点和应用的场合。
 * 总结如何选择默认参数的值。请分析本题中默认参数的值应该在什么范围。
 */
#include <iostream>

using namespace std;

unsigned maxf(unsigned x, unsigned y, unsigned z) {
    x = x < y ? y : x;
    x = x < z ? z : x;
    return x;
}

int main() {
    unsigned a, b, c;

    cin >> a >> b;
    if (cin.get() == '\n')  // 有小bug
        c = 0;
    else
        cin >> c;
    cout << "max=" << maxf(a, b, c) << endl;
    return 0;
}