/**
 * 对3个变量按由小到大顺序排序，要求使用变量的引用
 * （本题是《C++面向对象程序设计》第1章习题第13题）。
 * ①使用指针方法。
 * ②使用变量的引用。
 * 请总结使用引用时要注意什么问题。
 */
#include <iostream>

using namespace std;

int main() {
    const int N=3;
    int a[N], i, j;

    for (int i=0; i < N; ++i)
        cin >> a[i];
    for (int i=0; i < N; ++i)
        for (int j=0; j < N - 1 - i; ++j)
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
    for (int i=0; i < N; ++i)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}

void swap(int *x, int *y) {  // 不声明也可运行?
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}