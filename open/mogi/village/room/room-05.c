//room:/u/e/eva/village/room/room-05.c        made by eva
#include <room.h>
#include <ansi.h>
#include <village.h>

inherit ROOM;

void create()
{
    set("short","魔界村土祭坛");
    set("long","
    这里是魔界村的正中央, 也是魔界村五阵之一, 相传是自古以来
先人设下的, 正因为五阵的魔力, 才使得魔界村得以安保于魔界中,
祭坛四周布满了符咒, 符咒间散发出强大的魔力, 也许是因为有符咒
压制, 才使得祭坛中散发的魔力, 不至于伤害到人.\n\n");
    set("exits",([
        "north" : __DIR__"room-04",
        "east" : __DIR__"room-14",
        "south" : __DIR__"room-06",
        "west" : __DIR__"room-13",
        ]));
    set("objects",([
        V_NPC"old_man" : 1,
        ]));
    set("no_fight",1);
    set("no_magic",1);
    set("outdoors",1);
    set("no_auc",1);
    set("no_transmit",1);
    set("evil",1);
    setup();
}
