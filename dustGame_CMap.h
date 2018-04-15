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
		cout<<"���������ͼ"<<endl;
		loadMap(map);
	}
	bool displayMap(int row,int col);
	void loadMap(int map[MAP_LEN][MAP_LEN]);
    void changeMap(int row,int col,int blockID);

};
/** \brief C_Map ::  ��ʾ��ͼ����
 *
 * \param �����������������
 * \param
 �������current_map��ʾ
 * \return ���Ƿ���سɹ�
 *
 */

bool C_Map :: displayMap(int row,int col)
{
    if(current_map[row][col] == 1)
    {
        cout<<"��ͼ����ʧ��"<<endl;
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
/** \brief  C_Map :: ���ص�ͼ����
 *
 * \param �����������ͼ�Ķ�άint����
 * \param
 * \return ��
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
/** \brief  C_Map :: �ı��ͼ����
 *
 * \param ��������Ҫ�ı�ķ���������Լ��ı��ķ���ID
 * \param
 * \return
 *
 */

void C_Map :: changeMap(int row,int col,int blockID)
{
    current_map[row][col]=blockID;
}



#endif // DUSTGAME_MAP_H_INCLUDED
