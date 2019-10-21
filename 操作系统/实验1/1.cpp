#include "PCB.h"
#include <iostream>
#include <list>

using namespace std;

void create() {
    PCB *p=new PCB();

	p->init();
    addPCB(p, pall);
    addPCB(p, pr);
}

void block() {
    string processNameOfBlock;
    cout << "��������Ҫ�����Ľ�����:";
    cin >> processNameOfBlock;

    if (PCB *p=check(processNameOfBlock))
        if (p->status < 0)
            cout << "�ý�����������������" << endl;
        else if (p->status > 0) {
            trans(p->name, pw, pb);
            p->status = -1;
            cout << "�ѽ��ý��̴����ж�����������������" << endl;
        } else {
            trans(p->name, pr, pb);
            p->status = -1;
            cout << "�ѽ��ý��̴Ӿ���������������������" << endl;
        }
}

void wake() {
    string processNameOfWake;
    cout << "��������Ҫ���ѵĽ�����:";
    cin >> processNameOfWake;

    if (PCB *p=check(processNameOfWake))
        if (p->status < 0) {
            trans(p->name, pb, pr);
            p->status = 0;
            cout << "�ѽ��ý��̴����������л���" << endl;
        } else if (p->status > 0)
            cout << "�ý�����������,���뻽��" << endl;
        else
            cout << "�ý������ھ���������,���뻽��" << endl;
}

void stop() {
    string processNameOfStop;
    cout << "��������Ҫ��ֹ�Ľ�����:";
    cin >> processNameOfStop;

    if (PCB *p=check(processNameOfStop)) {
        if (p->status < 0)
            p = deletePCB(processNameOfStop, pb);
        else if (p->status > 0)
            p = deletePCB(processNameOfStop, pw);
        else
            p = deletePCB(processNameOfStop, pr);
        delete p;
    }
}

void show() {
    cout << "��������:";
    print(pr);
    cout << endl << "���ж���:";
    print(pw);
    cout << endl << "��������:";
    print(pb);
}

int main() {
    int num;

    do {
        cout << "ϵͳ���˵�" << endl;
        cout << "1...����" << endl;
        cout << "2...����" << endl;
        cout << "3...����" << endl;
        cout << "4...��ֹ" << endl;
        cout << "5...��ʾ" << endl;
        cout << "0...�˳�" << endl;
        cout << "����������Ҫ�Ĺ���(0-5):";
        cin >> num;

        switch(num) {
            case 1: create(),cout<<"!"<<num; break;
            case 2: block(); break;
            case 3: wake(); break;
            case 4: stop(); break;
            case 5: show(); break;
            default: break;
        }
    } while (num != 0);
    return 0;
}