//room:/u/e/eva/village/room/room-29.c        made by eva
#include <room.h>
#include <ansi.h>
#include <village.h>

inherit ROOM;

void create()
{
    set("short","ħ����·");
    set("long","
    ������ħ������Χ��·, ��·������ʯ���̳ɵ�, �������ڳ�
��ʹ�õĽ��, ·��ʮ�ֵ�ƽ̹, ���������м����˼�ֻħ��, ����
���һ��, ����ħ���ɺ�ƽ�ദ!\n\n");
    set("exits",([
        "east" : __DIR__"room-30",
        "west" : __DIR__"room-28",
        ]));
    set("objects",([
        V_NPC"sprite" : 2,
        ]));
    set("no_fight",1);
    set("no_magic",1);
    set("outdoors",1);
    set("no_auc",1);
    set("no_transmit",1);
    set("evil",1);
    setup();
}