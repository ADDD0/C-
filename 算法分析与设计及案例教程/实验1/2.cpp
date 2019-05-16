/**
 * m个小朋友手拉手站成一个圆圈,从第k个小朋友开始报数,报到n的那个小朋友退到圈外,
 * 然后他的下一位重新报"1".这样继续下去,直到最后只剩下一个小朋友,求解这个小朋友
 * 原来站在什么位置上呢?
 */
#include <iostream>

using namespace std;

int main() {
    int m, k, n;

    cin >> m >> k >> n;

    int *p = new int[m];

    for (int i=0; i < m; ++i)
        p[i] = 1;

    int const TOTAL=m;
    int flag=0;

    while (m - 1)
        for (int i=0; i < TOTAL; ++i)
            if (p[i])
                if (flag == n) {
                    p[i] = 0;
                    --m;
                    flag = 1;
                } else
                    ++flag;
    for (int i=0; i < TOTAL; ++i)
        if (p[i]) {
            int offset = (i + k - 1) % TOTAL;
            offset = offset ? offset : TOTAL;
            cout << offset << endl;
        }

    return 0;
}