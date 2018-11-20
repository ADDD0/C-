/**
 * 在第4题的基础上，重载流插入运算符“<<”和流提取运算符“>>”，
 * 使之能用于该矩阵的输入和输出。
 */
#include <iostream>

using namespace std;

class Matrix {
    public:
        Matrix(int r=1, int c=1): row(r), column(c) {
            data = new double[r * c];
        }
        friend Matrix operator + (Matrix &, Matrix &);
        friend ostream & operator << (ostream &, Matrix &);
        friend istream & operator >> (istream &, Matrix &);
    private:
        int row;
        int column;
        double *data;
};

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

ostream & operator << (ostream &out, Matrix &m) {
    for (int i=0; i < m.row; ++i) {
        for (int j=0; j < m.column; ++j)
            out << ' ' << m.data[i * m.column + j];
        out << endl;
    }
}

istream & operator >> (istream &in, Matrix &m) {
    cout << "Input " << m.row * m.column << " data:" << endl;
    for (int i=0; i < m.row; ++i)
        for (int j=0; j < m.column; ++j)
            in >> m.data[i * m.column + j];
}

int main() {
    Matrix a(2, 3);
    Matrix b(2, 3);

    cin >> a;
    cin >> b;
    a = a + b;
    cout << a;
    return 0;
}