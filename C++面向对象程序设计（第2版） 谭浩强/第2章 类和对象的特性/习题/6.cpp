/**
 * ��Ҫ��3������������������дһ�����ڶ���ĳ������ݳ�Ա����length��������
 * width������height���ߣ���Ҫ���ó�Ա����ʵ�����¹��ܣ�
 * ��1���ɼ��̷ֱ�����3���������ĳ������ߣ�
 * ��2�����㳤�����������
 * ��3�����3���������������
 * �������ϻ����Բ����С�
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