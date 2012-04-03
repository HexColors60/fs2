
#include <ansi.h>
inherit F_VENDOR;
void create()
{
	set_name("面店老板", ({"shop keeper","keeper"}) );
	set("long","
这间面店的主人，他看起来似乎十分好客，他正急促的催促你赶快坐下品
尝一下他的拿手绝活。\n");
	set("age",35);
	set("no_kill", 1);
	set("gender","男性");
	set("vendor_goods",({
	"/open/poison/obj/no1.c",
	"/open/poison/obj/no2.c",
	"/open/poison/obj/no3.c",
}) );
	setup();
	carry_object("/obj/cloth.c")->wear();
}
void greeting(object me)
{
	if(!me || environment(me) != environment()) return;
{
	command("smile "+me->query("id"));
	command("say 你好...要来碗面吗?");
 }
}
