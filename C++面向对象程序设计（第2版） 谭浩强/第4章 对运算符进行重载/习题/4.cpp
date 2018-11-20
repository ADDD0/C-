/**
 * 有两个矩阵a和b，均为2行3列。求两个矩阵之和。
 * 重载运算符“+”，使之能用于矩阵相加。如c=a+b。
 */
#include <iostream>

using namespace std;

class Matrix {
    public:
        Matrix(int r=1, int c=1): row(r), column(c) {
            data = new double[r * c];
        }
        void setMatrix();
        void display();
        friend Matrix operator + (Matrix &, Matrix &);
    private:
        int row, column;
        double *data;
};

void Matrix::setMatrix() {
    cout << "Input " << row * column << " data:" << endl;
    for (int i=0; i < row; ++i)
        for (int j=0; j < column; ++j)
            cin >> data[i * column + j];
}

void Matrix::display() {
    for (int i=0; i < row; ++i) {
        for (int j=0; j < column; ++j)
            cout << ' ' << data[i * column + j];
        cout << endl;
    }
}

Matrix operator + (Matrix &x, Matrix &y) {
    if (x.row != y.row || x.column != y.column) {
        cout << "Both matrices must have the same numbers of rows and columns." << endl;
        return Matrix(0, 0);
    }
    for (int i=0; i < x.row; ++i)
        for (int j=0; j < x.column; ++j)
            x.data[i * x.column + j] += y.data[i * y.column + j];
    return x;
}

int main() {
    Matrix a(2, 3);
    Matrix b(2, 3);

    a.setMatrix();
    b.setMatrix();
    a = a + b;
    a.display();
    return 0;
}