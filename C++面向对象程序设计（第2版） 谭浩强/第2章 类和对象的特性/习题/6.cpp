/* ��Ҫ��3������������������дһ�����ڶ���ĳ���
���ݳ�Ա����length��������width������height���ߣ���
Ҫ���ó�Ա����ʵ�����¹��ܣ�
��1���ɼ��̷ֱ�����3���������ĳ������ߣ�
��2�����㳤�����������
��3�����3���������������
�������ϻ����Բ����� */
#include <iostream>
using namespace std;

class cylinder
{
    public:
        void set_value();
        int get_volume();
    private:
        int length;
        int width;
        int height;
};

int main()
{
    cylinder c[3];
    int i;

    for (i = 0; i < 3; ++i)
        c[i].set_value();
    for (i = 0; i < 3; ++i)
        cout << c[i].get_volume() << endl;
}

void cylinder::set_value()
{
    cin >> length >> width >> height;
}

int cylinder::get_volume()
{
    return length * width * height;
}