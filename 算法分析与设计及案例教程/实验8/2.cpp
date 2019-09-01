/**
 * 8皇后问题
 * 要求在8*8的国际象棋棋盘中放8个皇后,使任意两个皇后都不能互相吃掉
 * 规则是皇后能吃掉同一行,同一列及同一对角线的任意棋子,求所有解
 */
#include <iostream>

using namespace std;

int check(int a[], int n) {
    for (int i=1; i < n; ++i)
        if(abs(a[i]-a[n]) == abs(i-n) || a[i] == a[n])
            return 0;
    return 1;
}

void print(int a[], int n, int s) {
    cout << "第" << s << "种解法:" << endl;
    for (int i=1; i <= n; ++i) {
        for (int j=a[i]; j > 1; --j)
            cout << "0 ";
        cout << "1 ";
        for (int j=a[i]; j < n; ++j)
            cout << "0 ";
        cout << endl;
    }
}

int main() {
    int a[256]={0};
    int i=1, j, n, t=1;

    cout << "请输入皇后数n=";
    cin >> n;
    while (i) {
        for (a[i]++; a[i] <= n; ++a[i])
            if(check(a, i))
                break;
        if (a[i] > n)
            i--;
        else if (a[i] <= n)
            if (i == n)
                print(a, n, t++);
            else {
                i++;
                a[i]=0;
            }
    }
    return 0;
}