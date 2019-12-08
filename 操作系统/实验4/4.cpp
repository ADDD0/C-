#include <iostream>
#include <iomanip>

using namespace std;

class pageTable {
    private:
        int pageNumber;
        bool existFlag;
        int blockNumberOnMemory;
        bool modifyFlag;
        int blockNumberOnDisk;

    public:
        pageTable() {}

        pageTable(int p, bool e, int bm, bool m, int bd): pageNumber(p),
        existFlag(e), blockNumberOnMemory(bm), modifyFlag(m), blockNumberOnDisk(bd) {}

        void changeExistFlag() {
            existFlag = 1-existFlag;
        }

        int getPageNumber() {
            return pageNumber;
        }

        int getBlockNumberOnMemory() {
            return blockNumberOnMemory;
        }

        int getBlockNumberOnDisk() {
            return blockNumberOnDisk;
        }

        void setBlockNumberOnMemory(int bm) {
            blockNumberOnMemory = bm;
        }

        void swapBlockNumberOnMemory(pageTable &pt) {
            int temp;

            temp = pt.blockNumberOnMemory;
            pt.setBlockNumberOnMemory(blockNumberOnMemory);
            setBlockNumberOnMemory(temp);
        }

        void print() {
            cout << setw(12) << pageNumber;
            cout << setw(12) << existFlag;
            cout << setw(12) << blockNumberOnMemory;
            cout << setw(12) << modifyFlag;
            cout << setw(12) << blockNumberOnDisk << endl;
        }
};

int blockSize = 1024;
pageTable *pt = new pageTable[8];
pageTable *FIFO = new pageTable[3];

void init() {
    FIFO[0] = pt[0] = pageTable(0, true, 0, false, 2);
    FIFO[1] = pt[1] = pageTable(1, true, 1, false, 3);
    FIFO[2] = pt[2] = pageTable(2, true, 2, false, 5);
    pt[3] = pageTable(3, false, -1, false, 7);
    pt[4] = pageTable(4, false, -1, false, 11);
    pt[5] = pageTable(5, false, -1, false, 13);
    pt[6] = pageTable(6, false, -1, false, 17);
    pt[7] = pageTable(7, false, -1, false, 19);

}

void printPageTable() {
    cout << setw(12) << "页号";
    cout << setw(12) << "存在标志";
    cout << setw(12) << "主存块号";
    cout << setw(12) << "修改标志";
    cout << setw(12) << "外部块号" << endl;
    for (int i=0; i < 8; ++i)
        pt[i].print();
}

void pageFaultHandling(int addPage) {
    static int removePage=0;

    cout << "移出页面" << FIFO[removePage].getPageNumber() << "并移入页面"
    << pt[addPage].getPageNumber() << endl;
    FIFO[removePage].changeExistFlag();
    pt[addPage].changeExistFlag();
    FIFO[removePage].swapBlockNumberOnMemory(pt[addPage]);
    pt[FIFO[removePage].getPageNumber()] = FIFO[removePage];
    FIFO[removePage] = pt[addPage];

    removePage = (removePage+1) % 3;
}

int main() {
    init();

    int addr=0;
    int pageNumber, pageAddress;
    while (true) {
        printPageTable();
        cout << "请输入逻辑地址(0结束):";
        cin >> addr;
        if (!addr)
            break;
        else if (addr < 1 || addr > blockSize*8-1) {
            cout << "地址非法,请重新输入!!" << endl;
            continue;
        } else {
            pageNumber = addr / blockSize;
            pageAddress = addr % blockSize;
            cout << "该逻辑地址对应的页号和页内地址分别为" << pageNumber << " "
            << pageAddress << endl;
        }
        for (int i=0; i < 3; ++i)
            if (pageNumber == FIFO[i].getPageNumber()) {
                cout << "第" << pageNumber << "页在内存中" << endl;
                cout << "该逻辑地址对应物理地址为" << FIFO[i].getBlockNumberOnDisk()
                << "*" << blockSize << "+" << pageAddress << "=" <<
                FIFO[i].getBlockNumberOnDisk()*blockSize + pageAddress << endl;
                break;
            } else if (i == 2) {
                cout << "第" << pageNumber << "页不在内存中" << endl;
                cout << "采用FIFO页面置换算法进行缺页中断处理" << endl;
                pageFaultHandling(pageNumber);
            }
    };
    return 0;
}