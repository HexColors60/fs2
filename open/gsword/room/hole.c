#include <room.h>

 inherit ROOM;

 void create()
{
      
        set("short", "岩穴");
        set("long", @LONG
一个黑戚戚的洞穴，里头有着各式各样千奇百怪的的奇岩，无数的蝙蝠倒挂在
岩石上，构成一幅令人畏惧的景象。仔细的观察一下四周，除了一些野鸟在此
筑巢外，赫然发现岩壁上，似乎有几个拳印，但年代已久，并不是很清楚。
LONG
        );

       set("objects",([
	"/open/gsword/mob/bat.c": 3,
       ]));
        set("exits", ([
"down":__DIR__"rroad2",
"west":__DIR__"whole",
"east":__DIR__"ehole",
"north":__DIR__"nhole"
        ]) );
setup();

}
