/*
 * 稀疏矩阵的快速转置算法
 */
#include <iostream>
#include <string.h>

using namespace std;

class Triple {
    public:
        int row;
        int column;
        int value;
};

class TSMatrix {
    public:
        init() {
            cout << "input row and column:" << endl;
            cin >> mu >> nu;
            setData();
        }

        setData() {
            cout << "input matrix:" << endl;
            for (int i=0; i < mu; ++i)
                for (int j=0; j < nu; ++j) {
                    cin >> data[tu].value;
                    if (data[tu].value) {
                        data[tu].row = i;
                        data[tu].column = j;
                        ++tu;
                    }
                }
        }

        print() {
            int **a = new int*[mu];
            for (int i=0; i < mu; ++i) {
                a[i] = new int[nu];
                memset(a[i], 0, sizeof(int) * nu);
            }

            for (int x=0; x < tu; ++x) {
                int i=data[x].row;
                int j=data[x].column;
                a[i][j] = data[x].value;
            }

            for (int i=0; i < mu; ++i) {
                for (int j=0; j < nu; ++j)
                    cout << a[i][j] << ' ';
                cout << endl;
            }
        }

        Triple data[100];
        int mu;
        int nu;
        int tu=0;
};

void FastTransposeSMatrix(TSMatrix M, TSMatrix &T) {
    T.mu = M.nu;
    T.nu = M.mu;
    T.tu = M.tu;
    if(T.tu) {
        int col;
        int num[100], cpot[100];

        for (col = 0; col < M.nu; ++col)
            num[col] = 0;
        for (int t = 0; t < M.tu; ++t)
            ++num[M.data[t].column];
        cpot[0] = 0;
        for (col = 1; col < M.nu; ++col)
            cpot[col] = cpot[col-1] + num[col-1];

        for (int p=0; p < M.tu; ++p) {
            int q = cpot[col];
            col = M.data[p].column;
            T.data[q].row = M.data[p].column;
            T.data[q].column = M.data[p].row;
            T.data[q].value = M.data[p].value;
            ++cpot[col];
        }
    }
}

int main() {
    TSMatrix M;
    TSMatrix T;

    M.init();

    FastTransposeSMatrix(M, T);

    T.print();

    return 0;
}