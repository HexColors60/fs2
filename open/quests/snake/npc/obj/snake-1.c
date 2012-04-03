#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIC"蛇头模组"NOR,({"snake head","head","c-snake-1"}));
	set_weight(100);
	set("long","
这是一个蛇的头部部分，还欠缺蛇身与蛇尾，才能组合(compose)
成一条完整的蛇。\n");
	set("unit","个");
	set("value",100);
setup();
}

void init()
{
add_action("do_compose","compose");
}

int do_compose()
{
object me,obj;

	me = this_player();

	if( !present("c-snake-1",me) || !present("c-snake-2",me) || !present("c-snake-3",me) )
		return 0;

	message_vision(HIY"$N将蛇头接于蛇身，在将蛇尾装上，一条完整的蛇就组装好了～\n"NOR,me);
	obj = new(__DIR__"snake-key-2");
	obj->move(me);
	destruct(present("c-snake-2",me));
	destruct(present("c-snake-3",me));
	destruct(present("c-snake-1",me));
return 1;
}
		
