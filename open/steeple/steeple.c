inherit ROOM;
void create ()
{
set("short", "试炼之塔--入口");
set("long",@LONG

眼前伫立了一座高大的圆柱形砖塔，乳白色的外观看起来十分的
高雅与塔内不时的传出打斗跟哀嚎声十分的不搭调，路旁有个标
示牌(sign)。

LONG);
set("exits", ([
"enter" : __DIR__"ticket",
"west":"/open/main/room/gosteeple",
]));
set("item_desc",([
"sign":"试炼塔开放至50楼\n",
]));
set("outdoors", 1);
set("objects",([
__DIR__"leftman": 1,
__DIR__"rightman":1,
]));
setup();
}
