//room:/u/e/eva/village/room/room-38.c        made by eva
#include <room.h>
#include <ansi.h>
#include <village.h>

inherit ROOM;

void create()
{
    set("short","ħ�����");
    set("long","
    һ����ש�����ɵ���ͨ��, ���ڷ���һЩ�򵥵ļҾ߰�\��, ��
ħ����е�һ����, ���ھ���һ����¯, ���ܰ�\���˹���, ����ס
��һ����һ������ʦ!\n\n");
    set("objects",([
        V_NPC"lee" : 1,
        ]));
    set("exits",([
        "east" : __DIR__"room-03",
        ]));
    set("no_fight",1);
    set("no_magic",1);
    set("light_up",1);
    set("no_auc",1);
    set("no_transmit",1);
    set("evil",1);
    setup();
}