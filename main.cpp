#include <iostream>
#include <conio.h>
#include <windows.h>

#include "dustGameHeader/dustGame_CMap.h"
#include "dustGameHeader/dustGame_CPlayer.h"
#include "dustGameHeader/dustGame_Const.h"
#include "dustGameHeader/dustGame_Texture.h"
using namespace std;

/*���·���Ĳ��裺
1.��dustGame_Const.h�ļ����ö��enum MAP_BLOCK�м����·����Ӣ��ID��
2.��dustGame_Texture.h�ļ��ﶨ��һ��ǰ׺TEXTURE_��ȫ���ַ����鳣����Ϊ�·�����ʣ�
3.��dustGame_Cmap.h�ļ��ｫ���ص�ͼ�����������ش˷�������;
4.��blockReact()�ж��巽�鴥��������*/


char command='0';//���ڽ������ָ��
bool judgeVar=false;//���ڽ����жϺ�������ֵ
int mapBlockVar=B_BLANK;//���ڽ��պ������صĵ�ͼ����id

C_Map map1(test_map);
C_Player p1;

void blockReact(int blockID);
int main()
{
    while(1)
    {
        /**< ��ʾ��ͼ */
        system("cls");
        map1.displayMap(p1.getRow(),p1.getCol());
        /**< ����ָ�� */
        command=getch();
        /**< ���鴥�� */
        mapBlockVar=p1.judgeBlock(command,test_map);//��ⷽ��id
        blockReact(mapBlockVar);//��������
    }
    return 0;
}
/** ������Ӧ����������ID��
 *  �������鱻���������Ӧ�¼�
 *
 *
 *
 *
 */

void blockReact(int blockID)
{
    switch(mapBlockVar)
    {
    case B_BLANK:/**< �յ� */
        //��ͨ��
        p1.movePlayer(command);
        break;

    case B_TRIGGER:/**< ������ */
        p1.movePlayer(command);

        system("cls");
        map1.displayMap(p1.getRow(),p1.getCol());

        cout<<"��ȵ��˴�����"<<endl;
        system("pause");
        break;
    case B_TP_DOOR:/**< ������ */
        p1.movePlayer(command);

        system("cls");
        map1.displayMap(p1.getRow(),p1.getCol());

        cout<<"���ڴ��͵���ͼ2"<<endl;
        map1.loadMap(test_map2);


        system("pause");
        break;
    }
}
