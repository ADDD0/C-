/* 编一个程序，用同一个函数名对n个数据进行从小到大排序，
数据类型可以是整型、单精度型、双精度型。用重载函数实现。 */
#include <iostream>
using namespace std;

void sort(int i[], int n)
{
    int j, k, temp;

    for (j = 0; j < n; ++j)
        for (k = 0; k < n - 1 - j; ++k)
            if (i[k] > i[k + 1])
                temp = i[k], i[k] = i[k + 1], i[k + 1] = temp;
    for (j = 0; j < n; ++j)
        cout << i[j] << " ";
    cout << endl;
}

void sort(float f[], int n)
{
    int j, k;
    float temp;

    for (j = 0; j < n; ++j)
        for (k = 0; k < n - 1 - j; ++k)
            if (f[k] > f[k + 1])
                temp = f[k], f[k] = f[k + 1], f[k + 1] = temp;
    for (j = 0; j < n; ++j)
        cout << f[j] << " ";
    cout << endl;
}

void sort(double d[], int n)
{
    int j, k;
    double temp;

    for (j = 0; j < n; ++j)
        for (k = 0; k < n - 1 - j; ++k)
            if (d[k] > d[k + 1])
                temp = d[k], d[k] = d[k + 1], d[k + 1] = temp;
    for (j = 0; j < n; ++j)
        cout << d[j] << " ";
    cout << endl;
}

int main()
{
    int i[] = {3, 2, 1};
    float f[] = {6, 13.5, 9, 3.14};
    double d[] = {3.1415926, 2.718e-10};

    sort(i, sizeof(i) / sizeof(int));
    sort(f, sizeof(f) / sizeof(float));
    sort(d, sizeof(d) / sizeof(double));
    return 0;
}