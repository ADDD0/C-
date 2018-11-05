#include <iostream>

using namespace std;

template<typename T>
void sort(T a[], int n) {
    T temp;

    for (int j=0; j < n; ++j)
        for (int k=0; k < n - 1 - j; ++k)
            if (a[k] > a[k + 1])
                temp = a[k], a[k] = a[k + 1], a[k + 1] = temp;
    for (int j=0; j < n; ++j)
        cout << a[j] << " ";
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