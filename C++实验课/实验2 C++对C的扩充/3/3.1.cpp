/**
 * 输入两个整数，将它们按由大到小的顺序输出
 * （本题是《C++面向对象程序设计》第1章习题第12题）。
 * ①使用指针方法。
 * ②使用变量的引用。
 * 比较这两种方法的特点和使用方法。
 */
#include <iostream>

using namespace std;

void display(int *a, int *b) {
    if (*a > *b)
        cout << *a << " " << *b << endl;
    else
        cout << *b << " " << *a << endl;
}

int main() {
    int a, b;

    cin >> a >> b;
    display(&a, &b);
    return 0;
}