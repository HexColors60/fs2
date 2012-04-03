// Room: /u/t/tide/room/tide1.c

inherit ROOM;

void create()
{
        set("short", "小巷道");
        set("long", @LONG
幽暗僻静的小巷道中，迎面袭来的是股刺鼻薰人的霉臭味；而　　
地上所布满的坑坑洞洞，则是积满了无处可流的死水。垃圾遍布的
此地，偶而几只老鼠穿梭其中；除此之外，大概也没啥生物了。
        正南方传来几声的声响，好像有人在那儿。

LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                "south" : __DIR__"tide2",
        ]) );

        set("outdoors",1);
        setup();
}
