#include "PCB.h"
#include <iostream>

using namespace std;

void create() {
    PCB *p=new PCB();
    int i;

    p->init();
    addPCB(p, pr);
}

void block() {
    string processNameOfBlock;
    cout << "请输入您要阻塞的进程名:";
    cin >> processNameOfBlock;

    if (PCB *p=search(processNameOfBlock))
        if (p->status < 0)
            cout << "该进程已在阻塞队列中" << endl;
        else if (p->status > 0) {
            trans(p->name, pw, pb);
            p->status = -1;
            cout << "已将该进程从运行队列转移至阻塞队列" << endl;
        } else {
            trans(p->name, pr, pb);
            p->status = -1;
            cout << "已将该进程从就绪队列转移至阻塞队列" << endl;
        }
}

void wake() {
    string processNameOfWake;
    cout << "请输入您要唤醒的进程名:";
    cin >> processNameOfWake;

    if (PCB *p=search(processNameOfWake))
        if (p->status < 0) {
            trans(p->name, pb, pr);
            p->status = 0;
            cout << "已将该进程从阻塞队列中唤醒" << endl;
        } else if (p->status > 0)
            cout << "该进程正在运行,无需唤醒" << endl;
        else
            cout << "该进程已在就绪队列中,无需唤醒" << endl;
}

void stop() {
    string processNameOfStop;
    cout << "请输入您要终止的进程名:";
    cin >> processNameOfStop;

    if (PCB *p=search(processNameOfStop)) {
        if (p->status < 0)
            deletePCB(processNameOfStop, pb);
        else if (p->status > 0)
            deletePCB(processNameOfStop, pw);
        else
            deletePCB(processNameOfStop, pr);
        cout << "已将该进程终止" << endl;
        delete p;
    }
}

void show() {
    cout << "就绪队列:";
    print(pr);
    cout << endl << "运行队列:";
    print(pw);
    cout << endl << "阻塞队列:";
    print(pb);
    cout << endl;
}

int main() {
    int num;
    pr = new PCB();
    pw = new PCB();
    pb = new PCB();

    do {
        cout << endl << "系统主菜单" << endl;
        cout << "1...创建" << endl;
        cout << "2...阻塞" << endl;
        cout << "3...唤醒" << endl;
        cout << "4...终止" << endl;
        cout << "5...显示" << endl;
        cout << "0...退出" << endl;
        cout << "请输入您需要的功能(0-5):";
        cin >> num;

        switch(num) {
            case 1: create(); break;
            case 2: block(); break;
            case 3: wake(); break;
            case 4: stop(); break;
            case 5: show(); break;
            default: break;
        }
    } while (num);
    return 0;
}