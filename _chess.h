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
      int num;                   //���Ӻ���
      int bl;                     //�����Ƿ����
      int x;                      //��������
      int y;
      float value;                  //���ӵ�ǰ��ֵ
      int distance;                //���Ӿ���Է��ϳ�����
    void getnowvalue();            //���㵱ǰ���Ӽ�ֵ
    void getdistance();           //���㵱ǰ���Ӿ���
};
float movesearch();
class _chesspan
{
public:
    _chesspan();
    _stone chess[13];             //��������
    int p[13];                    //ÿ�����ӻᱻ�ߵĸ���
    int nowchess[5][5];           //���ڵ����̾���
    void getp();                  //��õ�ǰ����ĸ����Ӹ���
    int getsaizi();                 //��ɫ��
    float getnowvalue();          //��õ�ǰ���������ܼ�ֵ
    int onemove(int i,int j);    //i��ʾ�ƶ����ӣ�j��ʾ�����ƶ�
    int canmove(int,int);          //�ж��ڸ�ɫ���¸������Ƿ����ƶ�
    int judgewin();                //�ж�Ӯ�壨0ûӮ��1�췽Ӯ��-1����Ӯ��
    void findway(int p);           //��������
    void printchess();             //�����ǰ����
};
//float movesearch(_chesspan A,int p,int chose,int dep,int side,float a,float b);
float movesearch(_chesspan A,int p,int chose,int dep,int side);
#endif // _CHESS_H_INCLUDED
