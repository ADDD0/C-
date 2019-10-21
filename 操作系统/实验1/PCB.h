#include <iostream>
#include <string>

using namespace std;

class PCB {
    public:
        string name;
        int prior;
        int time;
        int status;  // 0Ϊ���� 1Ϊ���� -1Ϊ����
        PCB* next;
		
        void init() {
            cout << "�����������:";
            cin >> name;
            cout << "���������ȼ�:";
            cin >> prior;
            cout << "����������ʱ��:";
            cin >> time;
            status = 0;
            next = NULL;
        }
};

PCB *pr, *pw, *pb;  //��������  ���ж���  ��������
PCB *pall;  //���н��̶��ڴ˶��е���

PCB *check(string name) {
    for (PCB *p=pall->next; p; p=p->next)
        if (name == p->name)
            return p;
    cout << "�ý�����������,���ȴ���" << endl;
    return NULL;
}

PCB *deletePCB(string name, PCB *pq) {
    PCB *pre=pq, *p;

    do {
        p = pre->next;
        if (p->name == name) {
            if (!p->next) {
                pre->next = NULL;
                return p;
            }
            p = p->next;
            pre->next = p;
            return p;
        }
        pre = p;
    } while (pre->next);
    return NULL;
}

void addPCB(PCB *p, PCB *pq) {
    PCB *pre=pq;

    if (p == NULL)
        return;
    while (pre = pre->next)
        ;
    pre->next = p;
    p->next = NULL;
}

void trans(string name, PCB *pq1, PCB *pq2) {
    PCB *pd=deletePCB(name, pq1);
    addPCB(pd, pq2);
}

void print(PCB *pq) {
    PCB *p=pq;

    for (p=p->next; p; p=p->next)
        cout << p->name << "  ";
}