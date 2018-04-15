#ifndef DUSTGAME_CMAP_H_INCLUDED
#define DUSTGAME_CMAP_H_INCLUDED

#include <iostream>
#include "dustGame_Const.h"
#include "dustGame_Texture.h"
using namespace std;
class C_Map
{
	int current_map[MAP_LEN][MAP_LEN];
	public:
	C_Map(int map[MAP_LEN][MAP_LEN])
	{
		cout<<"正在载入地图"<<endl;
		loadMap(map);
	}
	bool displayMap(int row,int col);
	void loadMap(int map[MAP_LEN][MAP_LEN]);
    void changeMap(int row,int col,int blockID);

};
/** \brief C_Map ::  显示地图函数
 *
 * \param 参数：玩家所在坐标
 * \param
 输出：将current_map显示
 * \return ：是否加载成功
 *
 */

bool C_Map :: displayMap(int row,int col)
{
    if(current_map[row][col] == 1)
    {
        cout<<"地图加载失败"<<endl;
        return false;
    }

    for(int i=0;i<MAP_LEN;i++)
    {
        for(int j=0;j<MAP_LEN;j++)
        {
            if(i==row && j==col)
            {
                cout<<TEXTURE_PLAYER;
            }
            else
            {
                switch(current_map[i][j])
               {
               case B_WALL:
                   cout<<TEXTURE_WALL;
                   break;
               case B_WATER:
                   cout<<TEXTURE_WATER;
                   break;
               case B_TREE:
                   cout<<TEXTURE_TREE;
                   break;
               case B_TRIGGER:
                   cout<<TEXTURE_TRIGGER;
                   break;
               case B_TP_DOOR:
                    cout<<TEXTURE_TP_DOOR;
                    break;
               default:
                   cout<<TEXTURE_BLANK;
                   break;
                }
            }
        }
        cout<<endl;
    }
    return true;
}
/** \brief  C_Map :: 加载地图函数
 *
 * \param 参数：代表地图的二维int数组
 * \param
 * \return 无
 *
 */

void C_Map :: loadMap(int map[MAP_LEN][MAP_LEN])
{
	for(int i=0;i<MAP_LEN;i++)
	{
		for(int j=0;j<MAP_LEN;j++)
		{
			current_map[i][j]=map[i][j];
		}
	}
}
/** \brief  C_Map :: 改变地图函数
 *
 * \param 参数：需要改变的方块的坐标以及改变后的方块ID
 * \param
 * \return
 *
 */

void C_Map :: changeMap(int row,int col,int blockID)
{
    current_map[row][col]=blockID;
}



#endif // DUSTGAME_MAP_H_INCLUDED
