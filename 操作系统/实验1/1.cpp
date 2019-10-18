#include "PCB.h"
#include <iostream>
#include <list>

using namespace std;

PCB *pr, *pw, *pb;  //就绪队列  运行队列  阻塞队列
PCB *pall;  //所有进程都在此队列当中

void create() {
    PCB *p=new PCB();

    addPCB(p, pall);
    addPCB(p, pr);
}

void block() {
    string processNameOfBlock;
    cout << "请输入您要阻塞的进程名:";
    cin >> processNameOfBlock;

    if (PCB *p=check(processNameOfBlock))
        if (p->status < 0)
            cout << "该进程已在阻塞队列中" << endl;
        else if (p->status > 0) {
            trans(p, pw, pb)
            p->status = -1;
            cout << "已将该进程从运行队列移至阻塞队列中" << endl;
        } else {
            trans(p, pr, pb)
            p->status = -1;
            cout << "已将该进程从就绪队列移至阻塞队列中" << endl;
        }
}

void wake() {
    string processNameOfWake;
    cout << "请输入您要唤醒的进程名:";
    cin >> processNameOfWake;

    if (PCB *p=check(processNameOfWake))
        if (p->status < 0) {
            trans(p, pb, pr);
            p->status = 0;
            cout << "已将该进程从阻塞队列中唤醒" << endl;
        } else if (p->status > 0)
            cout << "该进程正在运行,无须唤醒" << endl;
        else
            cout << "该进程已在就绪队列中,无须唤醒" << endl;
}

void stop() {
    string processNameOfStop;
    cout << "请输入您要终止的进程名:";
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
    cout << "就绪队列:";
    print(pr);
    cout << endl << "运行队列:";
    print(pw);
    cout << endl << "阻塞队列:";
    print(pb);
}

int main() {
    int num;

    do {
        cout << "系统主菜单" << endl;
        cout << "1...创建" << endl;
        cout << "2...阻塞" << endl;
        cout << "3...唤醒" << endl;
        cout << "4...终止" << endl;
        cout << "5...显示" << endl;
        cout << "0...退出" << endl;
        cout << "请输入您需要的功能(0-5):" << endl;
        cin >> num;

        switch(num) {
            case 1: create(); break;
            case 2: block(); break;
            case 3: wake(); break;
            case 4: stop(); break;
            case 5: show(); break;
            default: continue;
        }
    } while (num);
    return 0;
}