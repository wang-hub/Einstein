#ifndef _CHESS_H_INCLUDED
#define _CHESS_H_INCLUDED
#define _depth 5
#define factor 5
extern int _next[2];
extern int ccount;
extern int bijiao;
extern float ved[_depth/2+1][6];
class _stone
{
public:
      _stone(int,int,int);
      int num;                   //棋子号码
      int bl;                     //棋子是否存在
      int x;                      //棋子坐标
      int y;
      float value;                  //棋子当前价值
      int distance;                //棋子距离对方老巢距离
    void getnowvalue();            //计算当前棋子价值
    void getdistance();           //计算当前棋子距离
};
float movesearch();
class _chesspan
{
public:
    _chesspan();
    _stone chess[13];             //棋子数组
    int p[13];                    //每个棋子会被走的概率
    int nowchess[5][5];           //现在的棋盘局面
    void getp();                  //获得当前局面的各棋子概率
    int getsaizi();                 //掷色子
    float getnowvalue();          //获得当前局面棋盘总价值
    int onemove(int i,int j);    //i表示移动棋子，j表示怎样移动
    int canmove(int,int);          //判断在该色子下该棋子是否能移动
    int judgewin();                //判断赢棋（0没赢，1红方赢，-1蓝方赢）
    void findway(int p);           //怎样走棋
    void printchess();             //输出当前局面
};
//float movesearch(_chesspan A,int p,int chose,int dep,int side,float a,float b);
float movesearch(_chesspan A,int p,int chose,int dep,int side);
#endif // _CHESS_H_INCLUDED
