/**
 * ʱ�䰲������
 * ��n���,ÿ����ֱ���Si��ʼ,Ti����.��ÿ���,�㶼����ѡ��μ����,
 * ��ѡ��μ�,�������ʼ���ղμ�ȫ�̲���,�Ҳ��빤����ʱ��β������ص�
 * ����S={1,2,4,6,8},T={3,5,7,8,10}
 */
#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

#define Max_N 1000

int main() {
    int n;
    pair<int,int> p[Max_N];

    cin >> n;
    for (int i=0; i < n; ++i) {
        int start, end;
        cin >> start >> end;
        p[i] = make_pair(end, start);
    }                //��������,�����pair�Ա�����������
    sort(p, p + n);  //����pair�е�һ���ؼ��ʽ�����������

    int last=0, ans=0;
    cout << "ѡ��Ĺ�������ʼʱ����:" << endl;
    for(int i=0; i < n; ++i) {
        //����Ѱ�ҵ���һ�������Ŀ�ʼʱ�������һ�ι����Ľ���ʱ��,��ѡ��ôι���
        if(p[i].second > last) {
            last = p[i].first;
            ans++;
            cout << p[i].second << "--" << p[i].first << endl;
        }
    }
    cout << "��ѡ����" << ans << "������" << endl;
    return 0;
}