//written by wataru...../open/killer/mon/room/g2.c
inherit ROOM;

void create()
{
        set("short", "绿云组内部");
        set("long", @LONG
	你逐渐地怀疑你是否在绿云组之内了，因为整个绿云组，
	根本就与这一棵树合为一体，要不是有绿云组的人员在此。
	你真的很难以想像你是身在神秘的绿云组中，
	看来传说中，绿云组是天才机关手诸冈渡所做，这一点是错不了了。

LONG
        );
   set("exits", ([ /* sizeof() == 1 */
       "west" : __DIR__"g1.c",
       "south" : __DIR__"g3.c",
   ]));
        setup();
}
