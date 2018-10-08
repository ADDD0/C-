/**
 * 需要求3个长方柱的体积，请编写一个基于对象的程序。数据成员包括length（长）、
 * width（宽）、height（高）。要求用成员函数实现以下功能：
 * （1）由键盘分别输入3个长方柱的长、宽、高；
 * （2）计算长方柱的体积；
 * （3）输出3个长方柱的体积。
 * 请编程序，上机调试并运行。
 */
#include <iostream>

using namespace std;

class cylinder {
    public:
        void set_value();
        int get_volume();
    private:
        int length;
        int width;
        int height;
};

void cylinder::set_value() {
    cin >> length >> width >> height;
}

int cylinder::get_volume() {
    return length * width * height;
}

int main() {
    cylinder c[3];

    cout << "input 3 data\n(length:width:height)" << endl;
    for (int i=0; i < 3; ++i) {
        cout << i + 1 << ":";
        c[i].set_value();
    }
    for (int i=0; i < 3; ++i) {
        cout << "volumn" << i + 1 << ":";
        cout << c[i].get_volume() << endl;
    }
}