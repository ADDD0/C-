/**
 * 有5个字符串，要求对它们按由小到大顺序排列，用string方法
 * （本题是《C++面向对象程序设计》第1章习题第16题）。
 */
#include <iostream>

using namespace std;

int main() {
    const int N=5;
    string s[N], i, j;

    for (int i=0; i < N; ++i)
        cin >> s[i];
    for (int i=0; i < N; ++i)
        for (int j=0; j < N - 1 - i; ++j)
            if (s[j] > s[j + 1])
                swap(s[j], s[j + 1]);
    for (int i=0; i < N; ++i)
        cout << s[i] << endl;
    return 0;
}

void swap(int &x, int &y) {
    int temp;

    temp = x;
    x = y;
    y = temp;
}