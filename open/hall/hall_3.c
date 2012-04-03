// Room: /u/r/rose/room/hall_3.c

inherit ROOM;

void create()
{
        set("short", "总衙大堂");
        set("long", @LONG
这里是总衙升堂的地方，你可以看到无尘大人高坐堂上，正等候着
升堂。而在他身旁，站着贴身四大护卫。在这里你的言行举止要很小心
，否则轻则苔杖之刑，重则杀身之祸!!
LONG);
        set("exits",([
  "northeast" : __DIR__"h_room4",
  "south" : __DIR__"hall_2",
  "northwest" : __DIR__"h_room3",
  "east" : __DIR__"h_room5",
  "west":__DIR__"h_room10",
]));
        set("objects", ([ /* sizeof() == 1 */
  "/open/hall/npc/cheng" : 1,
]));

        setup();
}
