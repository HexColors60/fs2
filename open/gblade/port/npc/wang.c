// /open/center/npc/vendor.c
#include "/open/open.h"
inherit F_VENDOR;
void create()
{
	set_name("刀疤王五", ({ "wang" }) );
	set("gender", "男性" );
	set("age", 42);
	set("long", @LONG
看他脸上一条条令人怵目惊心的刀疤 , 你可以想见他年轻
时一定也是条铁铮铮的好汉 .
LONG);
	set("attitude", "friendly");
	set("combat_exp",20000);
	set_skill("dodge",50);
	set_skill("blade",50);
	set_skill("parry",50);
	set_skill("gold-blade",30);
	set_skill("fly-steps",30);
	map_skill("blade","gold-blade");
	map_skill("dodge","fly-steps");
	set("vendor_goods", ({
            GS_OBJ"woodblade",
	    "/open/gblade/obj/blade",
            "/open/gblade/obj/knife",	
	"/open/badman/obj/blade",
	"/open/gblade/port/obj/steel_blade",
	"/open/gblade/port/obj/knife",
	"/open/gsword/obj/blade",
	"/open/gblade/obj/oldblade",

	}) );
	set("chat_chance_combat",20);
	set("chat_msg_combat",({
	"刀疤王五喝到 : 不自量力的小子 , 我杀死的人比你看过还多勒 !\n",
	"刀疤王五怒道 : 可恶 , 我让你看看什么叫做功夫 !\n",
	}));
	
	set("greeting_msg", ({
 	    "刀疤王五说道: 年轻人 , 买把武器防身吧!\n",
	    	}) );
	setup();
        add_money("silver",10);
	carry_object("/open/gblade/port/obj/ghost_blade")->wield();
}
