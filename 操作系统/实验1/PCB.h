#include <iostream>
#include <string.h>

class PCB {
    public:
        string name;
        int prior;
        int time;
        int status;  // 0为就绪 1为运行 -1为阻塞
        PCB* next;
        PCB() {
            cout << "请输入进程名:";
            cin >> name;
            cout << "请输入优先级:";
            cin >> prior;
            cout << "请输入运行时间:";
            cin >> time;
            status = 0;
            next = NULL;
        }
};

PCB *check(string name) {
    for (PCB *p=pall->next; p; p=p->next)
        if (name == p->name)
            return p;
    cout << "该进程名不存在,请先创建" << endl;
    return NULL;
}

PCB deletePCB(string name, PCB *pq) {
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

void addPCB(PCB p, PCB *pq) {
    PCB *pre=pq;

    if (p == NULL)
        return;
    while (pre = pre->next)
        ;
    pre->next = p;
    p->next = NULL;
}

void trans(string name, PCB *pq1, PCB *pq2) {
    PCB pd=deletePCB(name, pq1);
    addPCB(pd, pq2);
}

void print(PCB *pq) {
    PCB *p=pq;

    for (p=p->next; p; p=p->next)
        cout << p->name << "  ";
}