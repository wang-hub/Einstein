#include<iostream>
#include"_chess.h"
#include"math.h"
#include"time.h"
#include"windows.h"
#include"stdio.h"
#include"stdlib.h"
using namespace std;
_stone::_stone(int x0=0,int y0=0,int n=0)  //初始棋子
{
    num=n;
    bl=1;
    x=x0;
    y=y0;
    if(n>0&&n<7)                //我方棋子，老巢棋盘左上
   {
       if(x<y)
        distance=4-x;
       else
        distance=4-y;
   }
   else                    //敌方棋子，老巢右下
   {
       if(x>y)
        distance=x;
       else
        distance=y;
   }
  if(n>0&&n<7)                      //我方棋子
 {
     if(x==0&&y==0)               //原点
         value=0;
     else                                 //其他
         value=pow(2,4-distance);
 }
 else                            //对面棋子
 {
     if(x==4&&y==4)                //在老巢
        value=0;
     else                              //其他地方
         value=pow(2,4-distance);
 }
}
void _stone::getdistance()   //计算棋子居对面老巢位置
{
   if(num>0&&num<7)                //我方棋子，老巢棋盘左上
   {
       if(x<y)
        distance=4-x;
       else
        distance=4-y;
   }
   else                    //敌方棋子，老巢右下
   {
       if(x>y)
        distance=x;
       else
        distance=y;
   }
}

void _stone::getnowvalue()        //计算棋子价值
{
  if(num>0&&num<7)                      //我方棋子
 {
     if(x==0&&y==0)               //原点
         value=0;
     else if((x==4&&y!=4)||(y==4&&x!=4))   //在边界
         value=5*pow(2.0,2-distance);
     else if(x==4&&y==4)                    //在对面老巢
         value=100;
     else                                 //其他
         value=pow(2.0,4-distance);
 }
 else                            //对面棋子
 {
     if(x==4&&y==4)                //在老巢
        value=0;
     else if((x==0&&y!=0)||(y==0&&x!=0))  //在边界
         value=5*(float)pow(2.0,2-distance);
     else if(x==0&&y==0)              //在我方老巢
         value=100;
     else                              //其他地方
         value=(float)pow(2.0,4-distance);
 }
}
_chesspan::_chesspan()             //创建开局
{
    int i,j,c,k=1;
    int q[4][6]={6,2,4,1,5,3,
                 6,5,2,1,4,3,
                 1,5,4,6,2,3,
                 1,6,3,5,2,4};    //开局初始值
    int kj;
    srand((unsigned)time(NULL));
    kj=rand()%4;
    cout<<"请输入你的棋子排布（从上往下，从左往右）："<<endl;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            if(i==0&&j==0)
            {
                chess[q[kj][0]]=_stone(i,j,q[kj][0]);
                nowchess[i][j]=q[kj][0];
            }
                else if(i==0&&j==1)
                {
                chess[q[kj][1]]=_stone(i,j,q[kj][1]);
                nowchess[i][j]=q[kj][1];
                }
                else if(i==0&&j==2)
                {
                chess[q[kj][2]]=_stone(i,j,q[kj][2]);
                nowchess[i][j]=q[kj][2];
                }
                else if(i==1&&j==0)
                {
                nowchess[i][j]=q[kj][3];
                chess[q[kj][3]]=_stone(i,j,q[kj][3]);
                }
                else if(i==1&&j==1)
                {
                nowchess[i][j]=q[kj][4];
                chess[q[kj][4]]=_stone(i,j,q[kj][4]);
                }
                else if(i==2&&j==0)
                {
                nowchess[i][j]=q[kj][5];
                chess[q[kj][5]]=_stone(i,j,q[kj][5]);
                }
                else if(i==2&&j==4)
                {
                    cout<<"第"<<k<<"颗：";
                    cin>>c;
                    while(c>7||c<0)
                    {
                        cout<<"棋子有误，重新输入:";
                        cin>>c;
                    }
                    cout<<endl;
                    chess[c+6]=*(new _stone(i,j,c+6));
                    nowchess[i][j]=c+6;
                    k++;
                }
                else if(i==3&&j==3)
                {
                    cout<<"第"<<k<<"颗：";
                    cin>>c;
                    while(c>7||c<0)
                    {
                        cout<<"棋子有误，重新输入:";
                        cin>>c;
                    }
                    cout<<endl;
                    chess[c+6]=*(new _stone(i,j,c+6));
                    nowchess[i][j]=c+6;
                    k++;
                }
                else if(i==3&&j==4)
                {
                   cout<<"第"<<k<<"颗：";
                    cin>>c;
                    while(c>7||c<0)
                    {
                        cout<<"棋子有误，重新输入:";
                        cin>>c;
                    }
                    cout<<endl;
                    chess[c+6]=*(new _stone(i,j,c+6));
                    nowchess[i][j]=c+6;
                    k++;
                }
                else if(i==4&&j==2)
                {
                    cout<<"第"<<k<<"颗：";
                    cin>>c;
                    while(c>7||c<0)
                    {
                        cout<<"棋子有误，重新输入:";
                        cin>>c;
                    }
                    cout<<endl;
                    chess[c+6]=*(new _stone(i,j,c+6));
                    nowchess[i][j]=c+6;
                    k++;
                }
                else if(i==4&&j==3)
                {
                    cout<<"第"<<k<<"颗：";
                    cin>>c;
                    while(c>7||c<0)
                    {
                        cout<<"棋子有误，重新输入:";
                        cin>>c;
                    }
                    cout<<endl;
                    chess[c+6]=*(new _stone(i,j,c+6));
                    nowchess[i][j]=c+6;
                    k++;
                }
                else if(i==4&&j==4)
                {
                    cout<<"第"<<k<<"颗：";
                    cin>>c;
                    while(c>7||c<0)
                    {
                        cout<<"棋子有误，重新输入:";
                        cin>>c;
                    }
                    cout<<endl;
                    chess[c+6]=*(new _stone(i,j,c+6));
                    nowchess[i][j]=c+6;
                    k++;
                }
                else
                nowchess[i][j]=0;
        }
    }
    for(i=0;i<13;i++)
        p[i]=1;
 }
 int _chesspan::getsaizi()
 {
     int s;
     srand((unsigned)time(NULL));
     s=(int)(rand()%6+1);
     return s;
 }
void _chesspan::getp()       //计算当前局面下各棋子概率
{
    int i,j,k=1;
    for(i=1;i<7;i++)
    {
        if(chess[i].bl==0)          //棋子已死，概率为0
            p[i]=0;
        else
        {
            j=i-1;
            while(j>0)              //找小于该棋子应属于它的概率
            {
                if(chess[j].bl==0)
                {
                    k++;
                    j--;
                }
                else
                    break;
            }
            if(j==0)
            {
                p[i]=k;
                k=0;
            }
            else
            {
                if(chess[i].value<chess[j].value)
                {
                    p[i]=1;
                    k=0;
                }
                else
                {
                    p[i]=k;
                    k=0;
                }
            }
            j=i+1;
            while(j<7)                //找大于该棋子的应属于它的概率
            {
                if(chess[j].bl==0)
                {
                    k++;
                    j++;
                }
                else
                    break;
            }
            if(j==7)
            {
                p[i]=p[i]+k;
                k=1;
            }
            else
            {
                if(chess[i].value<chess[j].value)
                {
                    p[i]=p[i];
                    k=1;
                }
                else
                {
                    p[i]=p[i]+k;
                    k=1;
                }
            }
        }
    }
    for(i=7;i<13;i++)                  //计算对方棋子概率
    {
        if(chess[i].bl==0)
            p[i]=0;
        else
        {
            j=i-1;
            while(j>7)              //找小于该棋子应属于它的概率
            {
                if(chess[j].bl==0)
                {
                    k++;
                    j--;
                }
                else
                    break;
            }
            if(j==7)
            {
                p[i]=k;
                k=0;
            }
            else
            {
                if(chess[i].value<chess[j].value)
                {
                    p[i]=1;
                    k=0;
                }
                else
                {
                    p[i]=k;
                    k=0;
                }
            }
            j=i+1;
            while(j<13)                //找大于该棋子的应属于它的概率
            {
                if(chess[j].bl==0)
                {
                    k++;
                    j++;
                }
                else
                    break;
            }
            if(j==13)
            {
                p[i]=p[i]+k;
                k=1;
            }
            else
            {
                if(chess[i].value<chess[j].value)
                {
                    p[i]=p[i];
                    k=1;
                }
                else
                {
                    p[i]=p[i]+k;
                    k=1;
                }
            }
        }
    }
}
float _chesspan::getnowvalue()     //计算当前局面下价值
{
   int i,xx,yy;
   float tt=0,totalvalue;
   float exp1=0,exp2=0,thread=0;
   for(i=1;i<7;i++)                      //计算进攻值
      if(chess[i].bl!=0)
       exp1=p[i]/6.0*chess[i].value+exp1;
   for(i=7;i<13;i++)
       if(chess[i].bl!=0){
       exp2=p[i]/6.0*chess[i].value+exp2;    //计算防守值
       exp2=-exp2;}
   for(i=7;i<13;i++)                       //计算威胁值
   {
       if(chess[i].bl!=0)                 //如果该棋子存在的话
       {
       xx=chess[i].x;
       yy=chess[i].y;
       if(xx==0&&yy>0)
       {
           if(nowchess[xx][yy-1]<7&&nowchess[xx][yy-1]>0)
               tt=chess[nowchess[xx][yy-1]].value;
       }
       else if(yy==0&&xx>0)
       {
           if(nowchess[xx-1][yy]>0&&nowchess[xx-1][yy]<7)
            tt=chess[nowchess[xx-1][yy]].value;
       }
       else if(xx>0&&yy>0)
       {
           if(nowchess[xx-1][yy]>0&&nowchess[xx-1][yy]<7)
            if(tt<chess[nowchess[xx-1][yy]].value)
            tt=chess[nowchess[xx-1][yy]].value;
           if(nowchess[xx][yy-1]>0&&nowchess[xx][yy-1]<7)
            if(tt<chess[nowchess[xx][yy-1]].value)
            tt=chess[nowchess[xx-1][yy]].value;
           if(nowchess[xx-1][yy-1]>0&&nowchess[xx-1][yy-1]<7)
            if(tt<chess[nowchess[xx-1][yy-1]].value)
            tt=chess[nowchess[xx-1][yy-1]].value;
       }
       else;
       thread=p[i]/6.0*tt+thread;
       }
   }
       //cout<<"exp1:"<<exp1<<"exp2"<<exp2<<"thread"<<thread<<endl;
       totalvalue=2.5*factor*exp1+factor*exp2-0.05*factor*thread;
       return totalvalue;
}
int _chesspan::onemove(int i,int j)        //移动棋子
{
    int xx,yy;
    if(i<7)
    {
        if(chess[i].bl!=0)          //该棋子存在
        {
        xx=chess[i].x;
        yy=chess[i].y;
        if(j==1)                //向右移动
        {
            if(yy<4)                  //右边有空位
            {
            if(nowchess[xx][yy+1]!=0)    //右边有棋子
            {
                chess[nowchess[xx][yy+1]].bl=0;   //右边棋子被吃掉
                chess[i].y=yy+1;
                nowchess[xx][yy+1]=i;
                nowchess[xx][yy]=0;               //棋子右移
                chess[i].getdistance();
                chess[i].getnowvalue();
                getp();

                return 1;
            }
            else
            {
                chess[i].y=yy+1;
                nowchess[xx][yy+1]=i;
                nowchess[xx][yy]=0;               //棋子右移
                chess[i].getdistance();
                chess[i].getnowvalue();
                getp();
                return 1;
            }
            }
            else
                return 0;
        }
        else if(j==2)                  //向右下移动
        {
            if(yy<4&&xx<4)                  //右下边有空位
            {
            if(nowchess[xx+1][yy+1]!=0)    //右下边有棋子
            {
                chess[nowchess[xx+1][yy+1]].bl=0;   //右边棋子被吃掉
                chess[i].y=yy+1;
                chess[i].x=xx+1;
                nowchess[xx+1][yy+1]=i;
                nowchess[xx][yy]=0;                //棋子移动
                chess[i].getdistance();
                chess[i].getnowvalue();
                getp();
                return 1;
            }
            else
            {
                chess[i].y=yy+1;
                chess[i].x=xx+1;
                nowchess[xx+1][yy+1]=i;
                nowchess[xx][yy]=0;                //棋子移动
                chess[i].getdistance();
                chess[i].getnowvalue();
                getp();
                return 1;
            }
            }
            else
                return 0;
        }
        else if(j==3)                    //向下移动
        {
            if(xx<4)                  //下边有空位
            {
            if(nowchess[xx+1][yy]!=0)    //下边有棋子
            {
                chess[nowchess[xx+1][yy]].bl=0;   //下边棋子被吃掉
                chess[i].x=xx+1;
                nowchess[xx+1][yy]=i;
                nowchess[xx][yy]=0;               //棋子移动
                chess[i].getdistance();
                chess[i].getnowvalue();
                getp();
                return 1;
            }
            else
            {
                chess[i].x=xx+1;
                nowchess[xx+1][yy]=i;
                nowchess[xx][yy]=0;               //棋子移动
                chess[i].getdistance();
                chess[i].getnowvalue();
                getp();
                return 1;
            }
            }
            else
                return 0;
        }
        return 0;      //移动不是三个方向数之一
    }   return 0;      //棋子不存在
    }
    else                            //移动敌方棋子
    {
        if(chess[i].bl!=0)          //该棋子存在
        {
        xx=chess[i].x;
        yy=chess[i].y;
        if(j==1)                //向左移动
        {
            if(yy>0)                  //左边有空位
            {
            if(nowchess[xx][yy-1]!=0)    //左边有棋子
            {
                chess[nowchess[xx][yy-1]].bl=0;   //左边棋子被吃掉
                chess[i].y=yy-1;
                nowchess[xx][yy-1]=i;
                nowchess[xx][yy]=0;               //棋子移
                chess[i].getdistance();
                chess[i].getnowvalue();
                getp();
                return 1;
            }
            else
            {
                chess[i].y=yy-1;
                nowchess[xx][yy-1]=i;
                nowchess[xx][yy]=0;               //棋子移
                chess[i].getdistance();
                chess[i].getnowvalue();
                getp();
                return 1;
            }
            }
            else
                return 0;
        }
        else if(j==2)                  //向左上移动
        {
            if(yy>0&&xx>0)                  //左上边有空位
            {
            if(nowchess[xx-1][yy-1]!=0)    //左上边有棋子
            {
                chess[nowchess[xx-1][yy-1]].bl=0;   //左上边棋子被吃掉
                chess[i].y=yy-1;
                chess[i].x=xx-1;
                nowchess[xx-1][yy-1]=i;
                nowchess[xx][yy]=0;                //棋子移动
                chess[i].getdistance();
                chess[i].getnowvalue();
                getp();
                return 1;
            }
            else
            {
                chess[i].y=yy-1;
                chess[i].x=xx-1;
                nowchess[xx-1][yy-1]=i;
                nowchess[xx][yy]=0;                //棋子移动
                chess[i].getdistance();
                chess[i].getnowvalue();
                getp();
                return 1;
            }
            }
            else
              return 0;
        }
        else if(j==3)                    //向上移动
        {
            if(xx>0)                  //上边有空位
            {
            if(nowchess[xx-1][yy]!=0)    //上边有棋子
            {
                chess[nowchess[xx-1][yy]].bl=0;   //上边棋子被吃掉
                chess[i].x=xx-1;
                nowchess[xx-1][yy]=i;
                nowchess[xx][yy]=0;               //棋子移动
                chess[i].getdistance();
                chess[i].getnowvalue();
                getp();
                return 1;
            }
            else
            {
                 chess[i].x=xx-1;
                nowchess[xx-1][yy]=i;
                nowchess[xx][yy]=0;               //棋子移动
                chess[i].getdistance();
                chess[i].getnowvalue();
                getp();
                return 1;
            }
            }
            else
                return 0;
        }
        else
            return 0;}
        else
            return 0;}
    return 0;
}

int _chesspan::judgewin()
{
    if(nowchess[4][4]>0&&nowchess[4][4]<7)            //红方到对面老巢
        return 1;
    if(nowchess[0][0]>6)                                //蓝方到对面老巢
        return -1;
    int i,j,redcount=0,bluecount=0;
    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
    {
        if(nowchess[i][j]>0&&nowchess[i][j]<7)
            redcount++;                                 //计算红棋棋子个数
        else if(nowchess[i][j]>6)
            bluecount++;                                //计算蓝棋棋子个数
    }
    if(redcount==0&&bluecount!=0)                       //蓝棋被吃光
        return -1;
    if(redcount!=0&&bluecount==0)
        return 1;                                       //红棋被 吃光
    return 0;                                            //还未有一方赢棋
}

int _chesspan::canmove(int p,int n)
{
    if(chess[n].bl==0)
        return 0;
    int i,k;
    if(n<7)
    {
    i=n;
    if(i==p)
        return 1;
    k=i-1;
    while(k>=p)
    {
        if(chess[k].bl!=0)
            return 0;
        k--;
    }
    k=i+1;
    while(k<=p)
    {
        if(chess[k].bl!=0)
            return 0;
        k++;
    }
    }
    else
    {
       i=n;
    if(i-6==p)
        return 1;
    k=i-1;
    while(k>=p+6)
    {
        if(chess[k].bl!=0)
            return 0;
        k--;
    }
    k=i+1;
    while(k<=p+6)
    {
        if(chess[k].bl!=0)
            return 0;
        k++;
    }
    }
    return 1;
}
void _chesspan::findway(int p)
{
    int aa=bijiao;
    //movesearch(*(this),p,0,0,0,-100000000,10000000);
    for(int i=0;i<=(_depth/2+1);i++)
        for(int j=0;j<6;j++)
           ved[i][j]=0;
    movesearch(*(this),p,0,0,0);
    cout<<"比较次数："<<bijiao-aa<<endl;
    cout<<"走法是:"<<_next[0]<<" "<<_next[1]<<endl;
    onemove(_next[0],_next[1]);
}
void _chesspan::printchess()
{
    system("CLS");
    int i,j;
    HANDLE hout;
    hout=GetStdHandle(STD_OUTPUT_HANDLE);
    for(i=0;i<6;i++)
        cout<<i<<" ";
    cout<<endl;
    for(i=0;i<5;i++)
    {
        cout<<i+1<<" ";
        for(j=0;j<5;j++)
        {
            SetConsoleTextAttribute(hout,BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED);
            if(nowchess[i][j]!=0)
            {
                if(nowchess[i][j]>6)
                {
                    SetConsoleTextAttribute(hout,FOREGROUND_BLUE|FOREGROUND_INTENSITY|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED);
                    cout<<nowchess[i][j]-6<<" ";
                    SetConsoleTextAttribute(hout,FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED);
                }
                else
                {
                    SetConsoleTextAttribute(hout,FOREGROUND_RED|FOREGROUND_INTENSITY|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED);
                    cout<<nowchess[i][j]<<" ";
                    SetConsoleTextAttribute(hout,FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED);
                }
            }
            else
                printf("%c%c",'\xA1','\xF6');
        }
        SetConsoleTextAttribute(hout,FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED);
        cout<<endl;
    }
}
//极大极小算法
/*float  movesearch(_chesspan A,int p,int chose,int deep,int side)    //chose=1为色子层
{
    bijiao++;
    float value;
    if(deep==_depth)
           value=A.getnowvalue();
    else
    {
    if(chose==0)                     //红方
        {
         ccount++;
          value=-1000000;
          for(int i=1;i<7;i++)
          {
            if(A.canmove(p,i)){
                for(int j=1;j<=3;j++)
                 {
                     _chesspan S(A);
                  if(S.onemove(i,j))
                  {
                      if(S.judgewin()==1)
                      {
                          if(value<pow(10,(float)(_depth+1)/2-(float)deep/2+2))
                          {
                              value=pow(10,(float)(_depth+1)/2-(float)deep/2+2);
                              if(ccount==1)
                              {_next[0]=i;_next[1]=j;}}}
                      else
                      {
                          //if(value<movesearch(S,p,1,deep+1,1))
                          float aa=movesearch(S,p,1,deep+1,1);
                          if(value<aa)
                          {
                              //value=movesearch(S,p,1,deep+1,1);
                              value=aa;
                              if(ccount==1)
                              {_next[0]=i;
                              _next[1]=j;}}}}}}}
    ccount--;}
    else if(chose==1&&side==1)                      //蓝方色子层
    {
        value=0;
        float valued;
        for(int dice=1;dice<7;dice++){
                     valued=movesearch(A,dice,2,deep+1,1);
                     value+=valued/6.0;}
    }
    else if(chose==1&&side==0)                   //红方色子层
    {
        value=0;
        float valued;
        for(int dice=1;dice<7;dice++){
            valued=movesearch(A,dice,0,deep+1,1);
            value+=valued/6.0;}
    }
    else                                        //蓝色
    {
        value=1000000;
        for(int i=7;i<13;i++){
            if(A.canmove(p,i)){
                for(int j=1;j<=3;j++){
                _chesspan S(A);
                  if(S.onemove(i,j))
                  {
                      if(S.judgewin()==-1){
                          if(value>-pow(10,(float)(_depth+1)/2-(float)deep/2+2))
                              value=-pow(10,(float)(_depth+1)/2-(float)deep/2+2);}
                      else{
                            float bb=movesearch(S,p,1,deep+1,0);
                          if(value>bb)
                            value=bb;}}}}}
    }
    }
    return value;
}*/

//α-β剪枝算法
/*float  movesearch(_chesspan A,int p,int chose,int deep,int side,float a,float b)    //chose=1为色子层
{
    bijiao++;
    if(deep==_depth)
           return A.getnowvalue();
    if(chose==0)                     //红方
        {
         ccount++;
          for(int i=1;i<7;i++)
          {
            if(A.canmove(p,i)){
                for(int j=1;j<=3;j++)
                 {
                    _chesspan S(A);
                  if(S.onemove(i,j))
                  {
                      if(S.judgewin()==1)
                      {
                          if(a<pow(10,(float)(_depth+1)/2-(float)deep/2+2))
                          {
                              a=pow(10,(float)(_depth+1)/2-(float)deep/2+2);
                              if(ccount==1)
                              {_next[0]=i;_next[1]=j;}}}
                      else
                      {
                          float aa=movesearch(S,p,1,deep+1,1,a,b);
                          if(a<aa)
                          {
                              a=aa;
                              if(ccount==1){_next[0]=i;_next[1]=j;}
                          }}}
                              if(b<=a) {break;cout<<"a剪子"<<endl; break;}}}}
    ccount--;
    return a;}
    else if(chose==1&&side==1)                      //蓝方色子层
    {
        float value=0;
        float valued;
        for(int dice=1;dice<7;dice++){
                     valued=movesearch(A,dice,2,deep+1,1,a,b);
                     value+=valued/6.0;}
    return value;}
    else if(chose==1&&side==0)                   //红方色子层
    {
        float value=0;
        float valued;
        for(int dice=1;dice<7;dice++){
            valued=movesearch(A,dice,0,deep+1,1,a,b);
            value+=valued/6.0;}
    return value;}
    else                                        //蓝色
    {
        for(int i=7;i<13;i++){
            if(A.canmove(p,i)){
                for(int j=1;j<=3;j++){
                    _chesspan S(A);
                  if(S.onemove(i,j))
                  {
                      if(S.judgewin()==-1){
                          if(b>-pow(10,(float)(_depth+1)/2-(float)deep/2+2))
                              b=-pow(10,(float)(_depth+1)/2-(float)deep/2+2);}
                      else{
                            float bb;
                            bb=movesearch(S,p,1,deep+1,0,a,b);
                          if(b>bb)
                            b=bb;}
                            if(b<=a){break; break;}
                  }}}}
    return b;}
}*/

//存同求异算法
float  movesearch(_chesspan A,int p,int chose,int deep,int side)    //chose=1为色子层
{
    bijiao++;
    float value;
    if(deep==_depth)
           value=A.getnowvalue();
    else
    {
    if(chose==0)                     //红方
        {
         ccount++;
          value=-1000000;
          for(int i=1;i<7;i++)
          {
            if(A.canmove(p,i)){
                    if(ved[(deep+1)/2+1][i-1]!=0){
                      if(ved[(deep+1)/2+1][i-1]>value)
                        value=ved[(deep+1)/2][i-1];}
                      else{
                for(int j=1;j<=3;j++)
                 {
                     _chesspan S(A);
                  if(S.onemove(i,j))
                  {
                      if(S.judgewin()==1)
                      {
                          if(value<pow(10,(float)(_depth+1)/2-(float)deep/2+2))
                          {
                              value=pow(10,(float)(_depth+1)/2-(float)deep/2+2);
                              if(ccount==1)
                              {_next[0]=i;_next[1]=j;}}}
                      else
                      {
                          float aa=movesearch(S,p,1,deep+1,1);
                          if(ved[(deep+1)/2+1][i-1]==0)
                            ved[(deep+1)/2+1][i-1]=aa;
                          else
                          {
                              if(ved[(deep+1)/2+1][i-1]<aa)
                                ved[(deep+1)/2+1][i-1]=aa;
                          }
                          if(value<aa)
                          {
                              value=aa;
                              if(ccount==1)
                              {_next[0]=i;_next[1]=j;}
                          }
                       }
                  }
                }
                             }
                                     }
            }
    ccount--;
    }
    else if(chose==1&&side==1)                      //蓝方色子层
    {
        value=0;
        float valued;
        for(int dice=1;dice<7;dice++){
                     valued=movesearch(A,dice,2,deep+1,1);
                     value+=valued/6.0;}
       for(int i=0;i<6;i++)
        ved[(deep+1)/2+1][i]=0;
    }
    else if(chose==1&&side==0)                   //红方色子层
    {
        value=0;
        float valued;
        for(int dice=1;dice<7;dice++){
            valued=movesearch(A,dice,0,deep+1,1);
            value+=valued/6.0;}
        for(int i=0;i<6;i++)
        ved[(deep+1)/2+1][i]=0;
    }
    else                                        //蓝色
    {
        value=1000000;
        for(int i=7;i<13;i++){
            if(A.canmove(p,i)){
                    if(ved[(deep+1)/2+1][i-1]!=0){
                      if(ved[(deep+1)/2+1][i-1]<value)
                        value=ved[(deep+1)/2][i-1];}
                    else{
                for(int j=1;j<=3;j++){
                _chesspan S(A);
                  if(S.onemove(i,j))
                  {
                      if(S.judgewin()==-1){
                          if(value>-pow(10,(float)(_depth+1)/2-(float)deep/2+2))
                              value=-pow(10,(float)(_depth+1)/2-(float)deep/2+2);}
                      else{
                            float bb=movesearch(S,p,1,deep+1,0);
                            if(ved[(deep+1)/2+1][i-1]==0)
                                ved[(deep+1)/2+1][i-1]=bb;
                            else
                            {
                                if(ved[(deep+1)/2+1][i-1]>bb)
                                    ved[(deep+1)/2+1][i-1]=bb;
                            }
                          if(value>bb)
                            value=bb;
                            }}}}}}}
    }
    return value;
}
