// room7.c by konn
inherit ROOM;
#include <ansi.h>
void create () {
set ("short","һ¥�ײ�");
        set ("long","
���ܶ�����ɭɭ�Ĺ���,ʹ��Խ��Խ�����Ļš��������ƺ�
������һ����΢���ĵƹ⡣
");

        set("evil", 1);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([
            
            "southwest"  : __DIR__"room18",
            "west"  :__DIR__"room10",
      ]));

       

        setup();
}