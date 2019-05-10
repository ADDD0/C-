#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n;

    cin >> n;

    int **a = new int*[n];
    for (int i=0; i < n; ++i)
        a[i] = new int[n];

    for (int i=0; i < n; ++i)
        for (int j=0; j < n; ++j)
            a[i][j] = 0;

    int row = 0;
    int col = n / 2;
    int i = row;
    int j = col;

    for (int count=1; count <= n * n; ++count) {
        a[row][col] = count;
        if (i == 0)
            i = n - 1;
        else
            --i;
        j = (j + n - 1) % n;
        if (a[i][j] || row == 0 && col == 0) {
            i = row + 1;
            j = col;
        }
        row = i;
        col = j;
    }

    for (int i=0; i < n; ++i) {
        for (int j=0; j < n; ++j)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
}