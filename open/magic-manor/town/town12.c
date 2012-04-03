inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "东镇道");
        set ("long", @LONG
云风镇的东边道路，道路的两旁边种满了各式花花草草，让你走
在此路上觉得格外愉快，镇上的居民也是很亲切，看见了你还不时的
向你打招呼，往北边是丸山镇的镇长住家，南边接着东镇道，西边是
接着北边道。
LONG);  
        set("exits", ([ /* sizeof() == 4 */
        "north"  : __DIR__"town06",
        "south"  : __DIR__"town18",
        "west"   : __DIR__"town11",
]));
        setup();
}
