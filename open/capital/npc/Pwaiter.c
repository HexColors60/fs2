//vendor.c
#include "/open/open.h"
inherit F_VENDOR;

void create()
{
	set_name("药铺伙计",({"medicine waiter","waiter"}));
	set("gender", "男性" );
	set("age", 27);
	set("long", @LONG
他是药铺里的店员, 专门负责招待上门的顾客, 因此嗓门特别大。
LONG
	);
	set("combat_exp",116);
        set("attitude", "friendly");
        set("score",1000000);
        set_skill("dodge", 40);
        set_skill("unarmed", 20);
	set("vendor_goods", ({
        COMMON_OBJ"bandage",
        COMMON_OBJ"pill",
"/open/doctor/pill/ff_pill",
"/open/doctor/pill/ice_pill",
"open/doctor/pill/f_pill",
        COMMON_OBJ"pill1",
        COMMON_OBJ"pill2",
        COMMON_OBJ"plaster",
        COMMON_OBJ"plaster1",
        COMMON_OBJ"plaster2",
        COMMON_OBJ"plaster3",
	}) );
	set("no_kill",1);
	setup();
	add_money("coin",35);
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(3) ) {
		case 0:
		say("店员靠近你说: 这位"+RANK_D->query_respect(ob)
		    +"来买些特制补品吧!\n");
		break;
		case 1:
                say("店员客气的道: 这儿什么药材都有 "+RANK_D->query_respect(ob)
                    +"要过来看看吗!?\n");
		break;
		case 2:
		say("店员高声喊道: 来来来, "+RANK_D->query_respect(ob)
		    +"要的话，我可以算便宜一点喔!\n");
		break;
	}
}
