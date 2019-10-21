#include <iostream>
#include <string>

using namespace std;

class PCB {
    public:
        string name;
        int prior;
        int time;
        int status;  // 0为就绪 1为运行 -1为阻塞
        PCB *next;

        PCB() {
            next = NULL;
        }
        void init() {
            cout << "请输入进程名:";
            cin >> name;
            cout << "请输入优先级:";
            cin >> prior;
            cout << "请输入运行时间:";
            cin >> time;
            status = 0;
        }
};

PCB *pr, *pw, *pb;  //就绪队列  运行队列  阻塞队列

void print(PCB *pq) {
    PCB *p=pq;

    while (p = p->next)
        cout << p->name << " ";
}

PCB *check(string name, PCB *pq) {
    for (PCB *p=pq->next; p; p=p->next)
        if (name == p->name)
            return p;
    return NULL;
}

PCB *search(string name) {
    PCB *p;

    if (p = check(name, pr))
        return p;
    else if (p = check(name, pw))
        return p;
    else if (p = check(name, pb))
        return p;
    cout << "该进程不存在,请先创建" << endl;
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
            pre->next = p->next;
            p->next = NULL;
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
    if (pre->next == NULL) {
        pre->next = p;
        return;
    }
    while (pre->next)
        pre = pre->next;
    pre->next = p;
}

void trans(string name, PCB *pq1, PCB *pq2) {
    PCB *pd=deletePCB(name, pq1);
    addPCB(pd, pq2);
}