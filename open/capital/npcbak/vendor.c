// /open/center/npc/vendor.c
#include </open/capital/capital.h>
					
inherit F_VENDOR;

void create()
{
	set_name("小贩", ({ "vendor"}) );
	set("gender", "男性" );
	set("age", 37);
	set("long", @LONG
一个贩卖杂货的小贩，浓眉大眼，看起来像是关外的胡人。
LONG);
	set("attitude", "friendly");
	set("combat_exp",170);
	set("no_kill",1);

	set("vendor_goods", ({
	    "/obj/torch",
	    CAP_OBJ"map",
	}) );
						
	set("greeting_msg", ({
 	    "小贩说道: 大爷小姐们，有木头卖喔!\n",
	    "小贩说道: 大爷小姐们，有地图卖喔!\n",	
	}) );
	setup();
}

				
