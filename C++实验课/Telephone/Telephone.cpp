#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;
const int length=80;

class CData {
	public:
		CData(){};
		virtual ~CData(){};
		virtual int Compare(CData &)=0;
		virtual void Show()=0;
};

class CNode {
	private:
		CData *pData;
		CNode *pNext;
	public:
		friend class CList;
		CNode() {
			pData=NULL;
			pNext=NULL;
		}
		CData *GetData() {
			return pData;
		}
		void InputData(CData *pData) {
			this->pData = pData;
		}
		void ShowNode() {
			pData->Show();
		}
};

class CList {
	private:
		CNode *pHead;
	public:
		CList() {
			pHead = new CNode;
		}
		~CList() {
			DeleteList();
		}
		CNode *GetListHead() {
			return pHead;
		}
		void AddNode(CNode *pNode) {
			pNode->pNext = pHead->pNext;
			pHead->pNext = pNode;
		}
		CNode *GetListNextNode(CNode *pNode) {
			return pNode->pNext;
		}
		CNode *LookUp(CData &data) {
			CNode *pNode = pHead;

			while (pNode = pNode->pNext)
				if (!pNode->pData->Compare(data))
					return pNode;
				return NULL;
		}
		CNode *DeleteNode(CNode *pNode) {
			CNode *pre=pHead, *p;

			while (p = pre->pNext)
				if (p == pNode) {
					pre->pNext = p->pNext;
					cout << "successfully deleted" << endl;
					return pNode;
				} else
					pre = p;
			cout << "failed to delete" << endl;
			return NULL;
		}
		void ShowList() {
			CNode *pNode=pHead;
			int line=0;

			while (pNode = pNode->pNext)
				if (++line <= 20) {
					cout << line << ":";
					pNode->ShowNode();
				} else {
					cout << "press anykey to show more info" << endl;
					system("cls");
					line = 0;
				}
		}
		void DeleteList() {
			CNode *pNode=pHead, *pTemp;

			while (pNode) {
				delete pNode->pData;
				pTemp = pNode;
				pNode = pNode->pNext;
				delete pTemp;
			}
		}
		void InsertSort();
};

void CList::InsertSort() {
	CNode *head, *tail, *p, *pre, *after;

	head = tail = pHead->pNext;
	while (p = tail->pNext)
		if (p->pData->Compare(*(head->pData)) < 0) {
			tail->pNext = p->pNext;
			p->pNext = head;
			head = p;
		} else if (p->pData->Compare(*(tail->pData)) > 0)
			tail = p;
		else {
			tail->pNext = p->pNext;
			pre = head;
			while (after = pre->pNext)
				if (p->pData->Compare(*(after->pData)) < 0) {
					pre->pNext = p;
					p->pNext = after;
					break;
				} else
					pre = after;
		}
	pHead->pNext = head;
}

class CTelRecord: public CData {
	private:
		char name[length];
		char phone[length];
	public:
		CTelRecord() {
			strcpy(name, "\0");
			strcpy(phone, "\0");
		}
		CTelRecord(char *n, char *p) {
			strcpy(name, n);
			strcpy(phone, p);
		}
		void SetRecord(char *n, char *p) {
			strcpy(name, n);
			strcpy(phone, p);
		}
		int Compare(CData &data) {
			CTelRecord &cTel=(CTelRecord &) data;

			return strcmp(name, cTel.name);
		}
		void Show() {
			cout << name << '\t';
			cout << phone << endl;
		}
};

void AddRecord(CList &TelList) {
	char name[length], phone[length];

	cout << "name(enter 0 to end):";
	cin.getline(name, length);
	while (strcmp(name, "0")) {
		CNode *pNode=new CNode;
		CTelRecord *pTel=new CTelRecord;

		cout << "phone:";
		cin.getline(phone, length);
		pTel->SetRecord(name, phone);
		pNode->InputData(pTel);
		TelList.AddNode(pNode);
		cout << "name(enter 0 to end):";
		cin.getline(name, length);
	}
}

void DisplayRecord(CList &TelList) {
	cout << "name" << '\t' << "phone" << endl;
	TelList.ShowList();
}

void LookUpRecord(CList &TelList) {
	char sname[length];

	cout << "input lookup name(enter 0 to end):";
	cin.getline(sname, length);
	while (strcmp(sname, "0")) {
		CTelRecord cTel(sname, "0");
		CNode *pNode = TelList.LookUp(cTel);
		if (pNode) {
			cout << "found " << sname << ":" << endl;
			pNode->ShowNode();
		} else
			cout << "name not found" << endl;
		cout << "input lookup name(enter 0 to end):";
		cin.getline(sname, length);
	}
}

void DeleteRecord(CList &TelList) {
	char sname[length], yn;

	cout << "input delete name(enter 0 to end):";
	cin.getline(sname, length);
	while (strcmp(sname, "0")) {
		CTelRecord cTel(sname, "0");
		CNode *pNode=TelList.LookUp(cTel);
		if (pNode) {
			cout << "found " << sname << ":" << endl;
			pNode->ShowNode();
			cout << "sure to delete?(y/n):";
			cin >> yn;
			if (yn == 'y')
				TelList.DeleteNode(pNode);
		} else
			cout << "name not found" << endl;
		cout << "input delete name(enter 0 to end):";
		cin.getline(sname, length);
	}
}

void StoreFile(CList &TelList) {
	CNode *pNode=TelList.GetListHead();
	ofstream outfile("TELEPHONE.DAT", ios::binary);

	if (!outfile) {
		cout << endl << "\t数据文件打开错误" << endl;
		return;
	}
	if (TelList.GetListNextNode(pNode) == NULL)
		cout << "not exist" << endl;
	while (pNode = TelList.GetListNextNode(pNode)) {
		CTelRecord *pTel=(CTelRecord*) pNode->GetData();
		outfile.write((char *)pTel, sizeof(CTelRecord));
	}
	outfile.close();
}

void Operate(char &strChoice, CList &TelList) {
	if (strChoice == '1') {
		AddRecord(TelList);
		TelList.InsertSort();
	}
	else if (strChoice == '2')
		DisplayRecord(TelList);
	else if (strChoice == '3')
		LookUpRecord(TelList);
	else if (strChoice == '4')
		DeleteRecord(TelList);
	else if (strChoice == '0')
		StoreFile(TelList);
	else
		cout << "unrecognized command" << endl;
}

void LoadFile(CList &TelList) {
	ifstream infile("TELEPHONE.DAT", ios::binary);

	if (!infile) {
		cout << endl << "\t数据文件不存在" << endl;
		return;
	}	
	while (!infile.eof()) {
		CTelRecord *pTel=new CTelRecord;
		infile.read((char *)pTel, sizeof(CTelRecord));
		CNode *pNode=new CNode;
		pNode->InputData(pTel);
		TelList.AddNode(pNode);
	}
	infile.close();
}

int main() {
	CList TelList;
	char strChoice;

	system("cls");
	cout << "\t欢迎进入电话簿管理程序" << endl;
	LoadFile(TelList);
	do {
		cout << "\t1、添加电话簿" << endl;
		cout << "\t2、显示电话簿内容" << endl;
		cout << "\t3、根据姓名查询电话簿数据" << endl;
		cout << "\t4、根据姓名删除电话簿数据" << endl;
		cout << "\t0、退出程序" << endl << endl;
		cout << "请输入您的选择:";
		cin >> strChoice;
		Operate(strChoice, TelList);
	} while (strChoice != '0');
	cout << endl << "\t欢迎再次使用！" << endl << endl;
	return 0;
}