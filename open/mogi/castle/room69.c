
inherit ROOM;
#include <ansi.h>
void create () {
set ("short","魔之左翼");
        set ("long","随着你走过每一步, 灼烫的魔气愈是升高, 相映墙上的火蠋鬼影, 令人神
智不清, 精神上承受着无比的压力. 此地墙石均是由魔界深处的漆黑墨石
所拼, 邪气郁郁, 石性极阳, 呼应着焚天魔王的魔气荡荡. 而妖魅之影散
乱, 孰不知人间黑夜之阴翳, 无丝无竹, 兽号魔哭回转绕光不曾歇止.  
");

        set("evil", 1);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([
            "east" :  __DIR__"room68",
            "north"  : __DIR__"room70",
      ]));
        setup();
}
