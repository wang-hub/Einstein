#include <iostream>
#include"_chess.h"
#include"windows.h"
using namespace std;
int _next[2]={0,0};
int ccount=0;
int bijiao=0;
float ved[_depth/2+1][6]={0};
int main()
{
    int qt=1;
    while(qt){
    system("CLS");
    cout<<"******************"<<endl;
    cout<<"��ӭ������Ϸ��"<<endl;
    int win,i,j,p,q;
    _chesspan A;
    A.printchess();
    cout<<"**********************************"<<endl
        <<"��Ϸ��ʼ��"<<endl
        <<"���ɫ����ż�����пɻ������(1,��;2,ż)��"<<endl;
    cin>>i;
    while(i!=1&&i!=2)
    {
      cout<<"��������Ŷ������ϸ��������QAQ"<<endl
          <<"��������:";
      cin>>i;
    }
    p=A.getsaizi();
    cout<<"ɫ����Ϊ:"<<p<<endl;
    if(p%2==i)
    {
        cout<<"��ϲ��¶�����������֣�"<<endl
            <<"***********************************"<<endl;
        q=0;
        system("pause");
    }
    else
    {
        cout<<"���ź�����������̫�ã��������ⲻ��ʵ�����ǹؼ���"<<endl;
        cout<<"***********************************"<<endl;
        system("pause");
        q=1;
    }
    win=A.judgewin();
    while(win==0)
    {
        A.printchess();
        if(q==0)
        {
            p=A.getsaizi();
            cout<<"*******************************"<<endl
                <<"����غ�:"<<endl
                <<"        �˴�ɫ����Ϊ��"<<p<<endl
                <<"        �˴���ѡ���������:";
            for(i=1;i<7;i++)
                if(A.canmove(p,i+6))
                    cout<<i<<" ";
           cout<<endl
               <<"������Ҫ�ƶ������ӣ�";
           cin>>i;
           cout<<"������Ҫ�ƶ��ķ���1,��;2,����;3,�ϣ���";
           cin>>j;
           while(!A.onemove(i+6,j))
           {
               cout<<"�������߷������е�����QAQ"<<endl
                   <<"����������Ҫ�ƶ�����:";
               cin>>i;
               cout<<"����������Ҫ�ƶ��ķ���1,��;2,����;3,�ϣ���";
               cin>>j;
           }
           win=A.judgewin();
           q=1;
        }
        else
        {
            p=A.getsaizi();
            cout<<"**************************"<<endl
                <<"�췽�غ�:"<<endl
                <<"�˴�ɫ����Ϊ��"<<p<<endl;
            A.findway(p);
            cout<<"����ѡ��������:"<<_next[0]<<endl
                <<"    ѡ�ķ�����:";
            switch(_next[1])
            {
            case 1:
                cout<<"��"<<endl;
                break;
            case 2:
                cout<<"����"<<endl;
                break;
            default:
                cout<<"��"<<endl;
            }
            system("pause");
            win=A.judgewin();
            q=0;
        }
    }
    cout<<"*****************************"<<endl;
    if(win==1)
    {
        A.printchess();
        cout<<"I am sorry,YOU LOSE!"<<endl;
    }
    else if(win==-1)
    {
        A.printchess();
        cout<<"Congruatulation!!!YOU WIN!!"<<endl;
    }
    cout<<"������ٿ�ʼһ����Ϸ������1���˳�����0"<<endl;
    cin>>qt;}
    cout<<"thanks for your using!"<<endl;
}
