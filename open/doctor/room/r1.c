inherit ROOM;
void create()
{
        set("short", "药圃");
        set("long", @LONG

    你一进入这里，发觉这里雾气四散，景色模糊不以，靠的微弱的灯光
，依稀可以辨别的出这里是个园子，低头一看，哇～原来这里是一个种植
药物的场所，抬头往前看，里面似乎还种着更名贵的药草。

LONG
        );
  set("can_search",1);
  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"r2",
  "east" :__DIR__"r",
  "enter" :__DIR__"1",
]));
        set("no_clean_up", 0);

        setup();
}



