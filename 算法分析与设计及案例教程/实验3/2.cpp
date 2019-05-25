#include <iostream>

using namespace std;

void KnapSack(int v[], int w[], int c, int n, int **m) {
    for (int j=0; j <= c; ++j)
        m[0][j] = w[0] <= j ? v[0] : 0;
    for (int i=1; i < n; ++i)
        for (int j=0; j <= c; ++j) {
            m[i][j] = m[i-1][j];
            if (w[i] <= j)
                m[i][j] = max(m[i][j], m[i-1][j-w[i]] + v[i]);
        }
}

void Traceback(int **m, int w[], int c, int n, int x[]) {
    cout << "装入总价值:" << m[n-1][c] << endl;
    for (int i=n-1; i > 0; --i)
        if (m[i][c] == m[i-1][c])
            x[i] = 0;
        else {
            x[i] = 1;
            c = c - w[i];
        }
    x[0] = (m[0][c]) ? 1 : 0;
    cout << "最优解:";
    for (int i=0; i < n; ++i)
        if (x[i])
            cout << i+1 << ' ';
    cout << endl;
}

int main() {
    int n, c;
    cout << "物品数量:";
    cin >> n;
    cout << "背包容量:";
    cin >> c;

    int *w = new int[n];
    int *v = new int[n];
    for (int i=0; i < n; ++i) {
        cout << "物品" << i+1 << "的重量及其价值:";
        cin >> w[i] >> v[i];
    }

    int **m = new int*[n];
    for (int i=0; i < n; ++i)
        m[i] = new int[c+1];

    KnapSack(v, w, c, n, m);

    int *x = new int[n];
    Traceback(m, w, c, n, x);
    return 0;
}