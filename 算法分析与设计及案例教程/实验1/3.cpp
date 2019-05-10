/**
 * 编程打印出如下图所示的n*n方阵(n从键盘输入).
 *  1  2  3  4  5  6  7
 * 24 25 26 27 28 29  8
 * 23 40 41 42 43 30  9
 * 22 39 48 49 44 31 10
 * 21 38 47 46 45 32 11
 * 20 37 36 35 34 33 12
 * 19 18 17 16 15 14 13
 */
#include <iostream>

using namespace std;

int main() {
    int n;

    cin >> n;

    int **a = new int*[n];
    for (int i=0; i < n; ++i)
        a[i] = new int[n];

    int t=1;
    int k=n;
    int x=1;
    int b[2] = {0,0};

    while (x <= n*n) {
        for (int y=1; y <= 2*k-1; ++y) {
            b[y/(k+1)] += t;
            a[b[1]][b[0]-1] = x++;
        }
        t = -t;
        k--;
    }

    for (int i=0; i < n; ++i) {
        for (int j=0; j < n; ++j)
            cout << a[i][j] << ' ';
        cout << endl;
    }
    return 0;
}