
inherit ROOM;
#include <ansi.h>
void create () {
set ("short",HIW"白虎室"NOR);
        set ("long","这里就是白虎密室，墙上雕着一只巨大的白色老虎，散发出慑人
的气势。但房间中央清香四溢，仙光隐隐流转，走近一看是片小
小的叶子，看来这就是传说中的三叶仙兰，百年开花结果一次，
但结果后一刻钟内果实爆裂汁液四散，常人根本无法目睹。
");

        set("evil", 1);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([
            "north" :  __DIR__"room44",
                      ]));
        set("objects",([ /* sizeof() == 1 */
        __DIR__"obj/leave" : 1,
  //      __DIR__"obj/ninepill" : 5,
                      ]));

        setup();
}


