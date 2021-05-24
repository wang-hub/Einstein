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
    cout<<"欢迎进入游戏！"<<endl;
    int win,i,j,p,q;
    _chesspan A;
    A.printchess();
    cout<<"**********************************"<<endl
        <<"游戏开始！"<<endl
        <<"请猜色子奇偶，猜中可获得先手(1,奇;2,偶)："<<endl;
    cin>>i;
    while(i!=1&&i!=2)
    {
      cout<<"输入有误哦，请仔细看规则，亲QAQ"<<endl
          <<"重新输入:";
      cin>>i;
    }
    p=A.getsaizi();
    cout<<"色子数为:"<<p<<endl;
    if(p%2==i)
    {
        cout<<"恭喜你猜对啦，获得先手！"<<endl
            <<"***********************************"<<endl;
        q=0;
        system("pause");
    }
    else
    {
        cout<<"很遗憾，运气好像不太好，不过问题不大，实力才是关键！"<<endl;
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
                <<"蓝棋回合:"<<endl
                <<"        此次色子数为："<<p<<endl
                <<"        此次能选择的棋子有:";
            for(i=1;i<7;i++)
                if(A.canmove(p,i+6))
                    cout<<i<<" ";
           cout<<endl
               <<"请输入要移动的棋子：";
           cin>>i;
           cout<<"请输入要移动的方向（1,左;2,左上;3,上）：";
           cin>>j;
           while(!A.onemove(i+6,j))
           {
               cout<<"这次你的走法好像有点问题QAQ"<<endl
                   <<"请重新输入要移动棋子:";
               cin>>i;
               cout<<"请重新输入要移动的方向（1,左;2,左上;3,上）：";
               cin>>j;
           }
           win=A.judgewin();
           q=1;
        }
        else
        {
            p=A.getsaizi();
            cout<<"**************************"<<endl
                <<"红方回合:"<<endl
                <<"此次色子数为："<<p<<endl;
            A.findway(p);
            cout<<"红棋选的棋子是:"<<_next[0]<<endl
                <<"    选的方向是:";
            switch(_next[1])
            {
            case 1:
                cout<<"右"<<endl;
                break;
            case 2:
                cout<<"右下"<<endl;
                break;
            default:
                cout<<"下"<<endl;
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
    cout<<"如果想再开始一局游戏请输入1，退出输入0"<<endl;
    cin>>qt;}
    cout<<"thanks for your using!"<<endl;
}
