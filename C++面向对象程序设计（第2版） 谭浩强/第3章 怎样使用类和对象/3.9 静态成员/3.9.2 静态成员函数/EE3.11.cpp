//ͳ��ѧ��ƽ���ɼ���ʹ�þ�̬��Ա������
#include<iostream>
using namespace std;
class Student                 //����Student��
  {public:
     Student(int n,int a,float s):num(n),age(a),score(s){}  //���幹�캯��
     void total();            //������Ա����
     static float average();  //������̬��Ա����
   private:
     int num;
     int age;
     float score;
     static float sum;        //��̬���ݳ�Աsum(�ܷ�)
     static int count;        //��̬���ݳ�Աcount(����)
  };

void Student::total()         //����Ǿ�̬��Ա����
  {sum+=score;                //�ۼ��ܷ�
   count++;                   //�ۼ���ͳ�Ƶ�����
  }

float Student::average()      //���徲̬��Ա����
  {return(sum/count);
  }

float Student::sum=0;         //�Ծ�̬���ݳ�Ա��ʼ��
int Student::count=0;         //�Ծ�̬���ݳ�Ա��ʼ��

int main()
  {Student stud[3]={          //����������鲢��ʼ��
      Student(1001,18,70),
      Student(1002,19,78),
      Student(1005,20,98),
    };
   int n;
   cout<<"please input the number of students:";
   cin>>n;                    //������Ҫ��ǰ�������ѧ����ƽ���ɼ�
   for(int i=0;i<n;i++)       //����3��total����
     stud[i].total();
   cout<<"the average score of "<<n<<" students is "<<Student::average()<<endl;
                              //���þ�̬��Ա����
   return 0;
}