//room:/u/e/eva/village/room/room-54.c        made by eva
#include <room.h>
#include <ansi.h>
#include <village.h>

inherit ROOM;

void create()
{
    set("short","魔界村武器店");
    set("long","
    这里是魔界村中的武器店, 身处魔界的险境之中, 如果没有武器
防身, 相信一踏出魔界村的大门, 就会死无全尸了, 如果你手上没有
武器, 这里的武器会是不错的选择!\n\n");
    set("exits",([
        "out" : __DIR__"room-13",
        ]));
    set("objects",([
        V_NPC"w_boss" : 1 ,
        ]));
    set("no_fight",1);
    set("no_magic",1);
    set("light_up",1);
    set("no_auc",1);
    set("no_transmit",1);
    set("evil",1);
    setup();
}
