#include <room.h>
#include <ansi.h>
inherit BANK;

void create()
{
        seteuid(getuid());
        set("short", "云风钱庄");
        set("long", @LONG
这是云风镇内一家颇具信誉的钱庄，你可以放心的在这里存钱和
提钱，也可以将身上的零钱，化零为整，是一个很方便的地方，帮助
你解决一些金钱的问题。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
	"south" : __DIR__"town29",
]));
        set("light_up", 1);
        setup();
}
