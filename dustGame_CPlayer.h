#ifndef DUSTGAME_CPLAYER_H_INCLUDED
#define DUSTGAME_CPLAYER_H_INCLUDED

#include <iostream>
#include "dustGame_Const.h"
#include "dustGame_Texture.h"
using namespace std;
class C_Player
{

    int row,col;
    int keyNum;
public:
    C_Player(int r=0,int c=0)
    {
        row=r;
        col=c;
        keyNum=0;
    }
    int getRow(){return row;}
    int getCol(){return col;}
    void movePlayer(char direction);
    int judgeBlock(char direction,int map[MAP_LEN][MAP_LEN]);
};


/** 移动玩家 函数
 *
 * 参数：移动方向
 * 返回：无
 *
 *
 */
void C_Player :: movePlayer(char direction)
{
      switch(direction)
      {
      case 'a':case 'A':
          col --;
          break;
      case 'w':case 'W':
          row --;
          break;
      case 's':case 'S':
          row ++;
          break;
      case 'd':case 'D':
          col ++;
          break;
      }
}
/** 检测方块 函数
 *
 * 参数：检测的方向，检测的地图
 * 返回：检测方向上第一个方块的方块id
 *
 *
 */
int C_Player :: judgeBlock(char direction,int map[MAP_LEN][MAP_LEN])
{
    switch(direction)
    {
    case 'a':case 'A':
        if(col<=0) return -1;//如果在边界
        return map[row][col-1];
        break;
    case 'w':case 'W':
        if(row<=0) return -1;
        return map[row-1][col];
        break;
    case 's':case 'S':
        if(row>=MAP_LEN-1) return -1;
        return map[row+1][col];
        break;
    case 'd':case 'D':
        if(col>=MAP_LEN-1) return -1;
        return map[row][col+1];
        break;

    }
}



#endif // DUSTGAME_CPLAYER_H_INCLUDED
