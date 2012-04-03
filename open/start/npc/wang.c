// wang.c by oda

#include <ansi.h>
#include <../start.h>

inherit NPC;

void create()
{
	set_name("王老板", ({ "wang" }) );
	set("gender", "男性");
	set("combat_exp",8);
	set("long", "你看到一个中年男子正站在柜台里高兴的算钱。\n");

	setup();
}

int accept_object(object who , object item)
{
	int letter;
	letter = who->query_temp("letter");

	if( item->query("id") == "sheik's letter" ) {
		if( letter==1 || letter==3 ) {
			tell_object(who,"王老板小声的对你说：喔！是凌云村村长叫你送来的吗？\n真是谢谢你，麻烦再你回去告诉(report)他我已经收到了。\n");
			if( letter==1 )
				who->set_temp("letter", 2);
			else
				who->set_temp("letter", 4);
		}
	}
	return 1;
}
