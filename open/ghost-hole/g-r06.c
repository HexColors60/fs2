#include <ansi.h>
inherit ROOM;
void create ()
{
        set("short",YEL"幽冥道"NOR"杂货店");
        set("long",@LONG
这里是一间竹制的竹屋, 竹墙上挂满了许许多多奇
怪的东西, 有些东西似乎看起来是可以食用的, 但是形
状却十分的古怪, 又有些看似防具之类的东西, 不过都
长的奇形怪状, 让你不由的怀疑, 这里面的东西到底能
不能用...
LONG);
        set("exits",([
        "east":__DIR__"g-r04",
        ]));
        set("no_transmit",1);
        setup();
}
