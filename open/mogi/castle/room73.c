
inherit ROOM;
#include <ansi.h>
void create () {
set ("short","ħ֮����");
        set ("long","�������߹�ÿһ��, ���̵�ħ����������, ��ӳǽ�ϵĻ�ώ��Ӱ, ������
�ǲ���, �����ϳ������ޱȵ�ѹ��. �˵�ǽʯ������ħ��������īʯ
��ƴ, а������, ʯ�Լ���, ��Ӧ�ŷ���ħ����ħ������. ������֮Ӱɢ
��, �벻֪�˼��ҹ֮����, ��˿����, �޺�ħ�޻�ת�ƹⲻ��Ъֹ.  
");

        set("evil", 1);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([
            "east" :  __DIR__"room56",
            "west"  : __DIR__"room72",
      ]));
        setup();
}