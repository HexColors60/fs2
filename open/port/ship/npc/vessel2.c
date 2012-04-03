// /open/center/npc/vendor.c
#include "/open/open.h"
inherit NPC;
int time=0;
void create()
{
	set_name("幽冥魔船",({"vessel"}));
	
	set("long", @LONG
船头一个大骷颅头 , 整騪船阴森森的 , 甚为恐怖 !
LONG);
	set("attitude", "friendly");
	
	setup();
	set_heart_beat(1);	
}
void init()
{
	add_action("do_look","look");
	add_action("do_look","l");
}

void heart_beat()
{
 time++;
 if(time==1)
 {
	say("前往枫林港的船到啰 , 请赶快搭(board)船 !\n");
 }
 if(time==11)
 {
 say("开船啰 , 没搭上的人等下一班吧 !\n");
 destruct(this_object());
 }
} 

int do_look(string str)
{
	if(str=="vessel")
	{
	write("一騪阴气森森的魔船 , 有胆的就坐上去吧 !\n");
	return 1;
	}
return 0;
}
int accept_fight(object me)
{
	return notify_fail("看清楚 , 那并不是生物 !\n");
}
int accept_kill(object me)
{
	return notify_fail("看清楚 , 那并不是生物 !\n");
}
