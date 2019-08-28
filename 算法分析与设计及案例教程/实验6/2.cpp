/**
 * 使用动态规划解决硬币收集问题:机器人从左上角到右下角对一个格子里面的硬币
 * 进行收集,每个格子最多有一枚硬币,机器人只能往下或往右走,某些格子是不允许
 * 机器人通过的,求机器人最终收集到的硬币数目以及最优的路径数目
 * 例输入:
 *     5 6
 *     0 0 0 0 1 0
 *     0 1 0 1 0 0
 *     0 0 0 1 0 1
 *     0 0 1 0 0 1
 *     1 0 0 0 1 0
 */
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

const int MAXN = 1000;
int arr[MAXN][MAXN];
int f[MAXN][MAXN];
int arr2[MAXN][MAXN];

int main() {
    int n, m;
    cout << "请输入木板的行数(n):";
    cin >> n;
    cout << "请输入木板的列数(m):";
    cin >> m;
    cout << "请输入木板上硬币的放置情况(有硬币为1,没有为0,中间以空格分开):" << endl;
    for (int i=1; i <= n; ++i)
        for (int j=1; j <= m; ++j)
            cin >> arr[i][j];
    for (int i=0; i <= n; ++i) {
        f[i][0] = 0;
        f[0][i] = 0;
    }
    for (int i=1; i <= n; ++i)
        for (int j=1; j <= m; ++j)
            f[i][j] = arr[i][j] + max(f[i - 1][j], f[i][j - 1]);

    //通过回溯得到行走路径
    int i = n;
    int j = m;
    memset(arr2, 0, sizeof(arr2));
    arr2[1][1] = 1;
    arr2[n][m] = 1;
    while (i >= 1 && j >= 1)
        if (f[i - 1][j] > f[i][j - 1]) {
            arr2[i - 1][j] = 1;
            i--;
        } else {
            arr2[i][j - 1] = 1;
            j--;
        }

    cout << "最多可以收集" << f[n][m] << "枚硬币" << endl;
    cout << "硬币的收集路线为:" << endl;
    for (int i=1; i <= n; ++i) {
        for (int j=1; j <= m; ++j)
            cout << arr2[i][j] << " ";
        cout << endl;
    }
    return 0;
}