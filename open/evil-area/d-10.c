inherit ROOM;

void create()
{
        set("short","尸骨道");
        set("long",@LONG
脚下的碎骨声，给了你一种很另类的恐惧与罪恶感，一步一步的
踩着一群失败者的尸骨，你的思绪也渐渐地步入了疯狂的地步，你突
然觉得，失败者本来就该如此～大开杀戒吧～....天上一阵巨吼，你
突然回神了起来，反覆思考怎么会突然有这种想法；你重整思绪，再
度的观看四周，在你的北边是沙漠地带，南边则是不断燃烧的熔岩道
，你提起了精神，继续了你的旅途。
LONG);
        set("exits",([
"north":__DIR__"d-12",
"south":__DIR__"d-11",
"west":__DIR__"d-13",
"east":__DIR__"d-07",
]));
        set("objects",([
__DIR__"npc/die-worm":5,
]));
        set("no_transmit",1);
        set("evil-area",1);
        setup();
}
