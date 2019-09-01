/**
 * 使用贪婪算法解决背包问题
 * 给定一个载重量为C的背包,以及n个重量为wi,价值为pi的物体(物体可以分割),
 * 要求把物体装满背包,且使背包内的物体价值最大
 * 具体实例:背包容量C=50
 * 物品   重量   价值  价值/重量
 *   1     20     60       3
 *   2     30    120       4
 *   3     10     50       5
 */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

float v[101];   //物品价值
float w[101];   //物品重量
float x[101];   //问题的解
float a[101];   //存放vi/wi
int in[101];    //存放vi/wi从大到小的下标
float v1[101];  //按照vi/wi排序好的物品价值
float w1[101];  //按照vi/wi排序好的物品重量

int cmp(int a, int b) {
    if (a > b)
        return 1;
    return 0;
}

float knapsack(int n, float M, float v[], float w[], float x[]) {
    int i=0;
    float total=0;      //背包的价值

    memset(x, 0, sizeof(x));
    while (w[i] < M) {  //判断当前物品的重量是否能装入背包
        x[i] = 1;
        total += v[i];
        M -= w[i];
        i++;
    }
    x[i] = M / w[i];    //这是最后装入背包的物品
    total += x[i] * v[i];
    return total;
}

int main() {
    int n;
    float C;

    cout << "input n:";
    cin >> n;
    cout << "input C:";
    cin >> C;
    cout << "input numbergroup(w, v):" << endl;
    for (int i=0; i < n; ++i) {
        cin >> w[i] >> v[i];
        a[i] = v[i] / w[i];
    }

    int temp=0, index=0;
    //对数组a即vi/wi进行冒泡降序排序,并且记录下标到in[]数组
    for (int i=0; i < n; ++i) {
        for (int j=0; j < n - i; ++j)
            if (a[j] > a[j+1]) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                index = j;
            }
        in[i] = index;
    }
    //将原来输入的w[i],v[i]数组按照v[i]/w[i]的顺序进行排列
    for (int i=0; i < n; ++i) {
        v1[i] = v[in[i]];
        w1[i] = w[in[i]];
    }

    cout << knapsack(n, C, v1, w1, x) << endl;
    return 0;
}