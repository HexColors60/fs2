inherit ROOM;

void create()
{
 set("short","长老休息室");
 set("long",@LONG
  这里是长老的房间，他们专管帮派弟子生活上的锁事，包
  括传授武功、清除叛徒及扰乱帮派安宁的家伙，你想叛帮
  吗？劝你最好三思.....

LONG);
 set("exits",([
 "south" : __DIR__"room21.c"
 ]));
 

 setup();
}
