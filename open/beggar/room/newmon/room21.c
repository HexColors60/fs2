inherit ROOM;

void create()
{
 set("short","雷居");
 set("long",@LONG
此房间是雷护法休息的地方，他常在房间练功，为的就是
要保护帮主的安危，这也就是他的房间在帮主的附近。

LONG);
 set("exits",([
 "east" : __DIR__"room09.c"
 ]));

 
setup();
}
