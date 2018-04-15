#include <iostream>
#include <conio.h>
#include <windows.h>

#include "dustGameHeader/dustGame_CMap.h"
#include "dustGameHeader/dustGame_CPlayer.h"
#include "dustGameHeader/dustGame_Const.h"
#include "dustGameHeader/dustGame_Texture.h"
using namespace std;

/*做新方块的步骤：
1.在dustGame_Const.h文件里的枚举enum MAP_BLOCK中加入新方块的英文ID；
2.在dustGame_Texture.h文件里定义一个前缀TEXTURE_的全局字符数组常量作为新方块材质；
3.在dustGame_Cmap.h文件里将加载地图函数新增加载此方块的语句;
4.在blockReact()中定义方块触发动作；*/


char command='0';//用于接收玩家指令
bool judgeVar=false;//用于接收判断函数返回值
int mapBlockVar=B_BLANK;//用于接收函数返回的地图方块id

C_Map map1(test_map);
C_Player p1;

void blockReact(int blockID);
int main()
{
    while(1)
    {
        /**< 显示地图 */
        system("cls");
        map1.displayMap(p1.getRow(),p1.getCol());
        /**< 接受指令 */
        command=getch();
        /**< 方块触发 */
        mapBlockVar=p1.judgeBlock(command,test_map);//检测方块id
        blockReact(mapBlockVar);//触发方块
    }
    return 0;
}
/** 方块响应函数（方块ID）
 *  决定方块被触发后的响应事件
 *
 *
 *
 *
 */

void blockReact(int blockID)
{
    switch(mapBlockVar)
    {
    case B_BLANK:/**< 空地 */
        //可通行
        p1.movePlayer(command);
        break;

    case B_TRIGGER:/**< 触发器 */
        p1.movePlayer(command);

        system("cls");
        map1.displayMap(p1.getRow(),p1.getCol());

        cout<<"你踩到了触发器"<<endl;
        system("pause");
        break;
    case B_TP_DOOR:/**< 传送门 */
        p1.movePlayer(command);

        system("cls");
        map1.displayMap(p1.getRow(),p1.getCol());

        cout<<"正在传送到地图2"<<endl;
        map1.loadMap(test_map2);


        system("pause");
        break;
    }
}
