/**
 * 使用递归法输出n阶杨辉三角形
 */
#include <iostream>
#include <string.h>

using namespace std;

int pascal(int **a, int i, int j) {
    if (a[i][j])
        return a[i][j];
    if (j == 0 || i == j)
        a[i][j] = 1;
    else
        a[i][j] = pascal(a, i-1, j-1) + pascal(a, i-1, j);
    return a[i][j];
}

int main() {
    int n;

    cin >> n;

    int **a = new int*[n];
    for (int i=0; i < n; ++i) {
        a[i] = new int[n];
        memset(a[i], 0, sizeof(int) * n);
    }

    for (int i=0; i < n; ++i) {
        for (int j=0; j < i+1; ++j)
            cout << pascal(a, i, j) << ' ';
        cout << endl;
    }

    return 0;
}