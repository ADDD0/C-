/**
 * 建立两个磁盘文件f1.dat和f2.dat，编程序实现以下工作：
 * （1）从键盘输入20个整数，分别存放在两个磁盘文件中（每个文件中放10个整数）；
 * （2）从f1.dat读入10个数，然后存放在f2.dat文件原有数据的后面；
 * （3）从f2.dat中读入20个整数，对它们按从小到大的顺序存放到f2.dat
 * （不保留原来的数据）。
 */
#include <iostream>
#include <fstream>

using namespace std;

int amount=20;
int n;

void fun1() {
    ofstream outfile1("f1.dat", ios::binary),
            outfile2("f2.dat", ios::binary);

    cout << "input " << amount << " data:" << endl;
    for (int i=0; i < amount / 2; ++i) {
        cin >> n;
        outfile1.write((char *) &n, sizeof(int));
    }
    for (int i=0; i < amount / 2; ++i) {
        cin >> n;
        outfile2.write((char *) &n, sizeof(int));
    }
    outfile1.close();
    outfile2.close();
}

void fun2() {
    ifstream infile1("f1.dat", ios::binary);
    ofstream outfile2("f2.dat", ios::app | ios::binary);

    for (int i=0; i < amount / 2; ++i) {
        infile1.read((char *) &n, sizeof(int));
        outfile2.write((char *) &n, sizeof(int));
    }
    infile1.close();
    outfile2.close();
}

void fun3() {
    fstream iofile2("f2.dat", ios::in | ios::out | ios::binary);
    int *arr=new int[amount];

    for (int i=0; i < amount; ++i)
        iofile2.read((char *) &arr[i], sizeof(int));
    for (int i=0; i < amount - 1; ++i)
        for (int j=0; j < amount - i - 1; ++j)
            if (arr[j] > arr[j + 1])
                n = arr[j], arr[j] = arr[j + 1], arr[j + 1] = n;
    iofile2.seekg(0, ios::beg);
    for (int i=0; i < amount; ++i)
        iofile2.write((char *) &arr[i], sizeof(int));
    iofile2.close();
}

int main() {
    fun1();
    fun2();
    fun3();

    return 0;
}