// by roger && taifar
inherit ROOM;
#include <ansi.h>
#include "wind-rain.h"
void create () {
set ("short","�ߵ�");
set ("long",@LONG
�ɺ�ձë���أ�����ɢ��һ��һ���ɫ�ҷ���������������������
���Ŵ���������ƿ����ͷ�����ŵĹ����ݣ����������߲�����ɻ�
���ƣ�ǽ�Ϲҵģ����ƴ�ɽˮ������ī�� 
LONG);



  set("exits", ([
            "east" :  __DIR__"a11",
            "north" : __DIR__"a19",
                ]));

        setup();
}