inherit ROOM;
#include <ansi.h>

void create()
{
	set("short",BBLU+YEL"震邪道"NOR);
	set("long",@LONG
沉长的通道, 由你所站立的位置, 螺旋状的阶梯, 直值得往下延
伸, 你集中精神的注视着最底端, 只能看到火红的一点, [ 那里
可能就是火墙所结成的〔幻结界〕了...] 你心理这么盘算着。
LONG);
	set("exits",([
"down":__DIR__"e07",
]));
	setup();
}