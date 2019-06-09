/**
 * 使用动态规划求解给定图的最短路径问题
 * 示例输入:
 *      0 3 4 0 0 0 0 0 0
 *      0 0 0 5 3 6 0 0 0
 *      0 0 0 0 7 8 0 0 0
 *      0 0 0 0 0 0 9 5 0
 *      0 0 0 0 0 0 7 5 0
 *      0 0 0 0 0 0 0 3 0
 *      0 0 0 0 0 0 0 0 4
 *      0 0 0 0 0 0 0 0 5
 *      0 0 0 0 0 0 0 0 0
 */
#include <iostream>

using namespace std;

#define INF 0x3f3f3f3f

int main() {
    int n, a[105][105], c[105]={0};
    cin >> n;

    for (int i=1; i <=n; ++i)
        for (int j=1; j <= n; ++j)
            cin >> a[i][j];

    int f[105]={INF};
    f[n] = 0;
    for (int i=n-1; i >= 1; --i) {
        int mins=INF, k=0;
        for (int j=1; j <= n; ++j)
            if (a[i][j] && a[i][j] != INF) {
                f[i] = f[j] + a[i][j];
                if (f[i] < mins)
                    k = j;
                c[i] = k;
                mins = min(f[i], mins);
            }
        f[i]=mins;
    }
    cout << "minlong = " << f[1] << endl;
    int x=c[1];
    while (x) {
        cout << x << ' ';
        x = c[x];
    }
    cout << endl;

    return 0;
}