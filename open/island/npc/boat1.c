// open/island/npc/boat1.c
#include "/open/open.h"
inherit NPC;
int time=0;
void create()
{
        set_name("小木筏", ({ "boat" }) );

        set("long", @LONG
用木材扎起来的筏子 ,古朴的样子令人感到
无比的亲切 ,风大舟轻 ,大概很快就能够到
达想去的地方...

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
 say("前往东津港的渡船到啰 , 请赶快搭(board)船 !\n");
 }
 if(time==11)
 {
 say("出航啰 , 没搭上的人下次请早 !\n");
 destruct(this_object());
 }
} 

int do_look(string str)
{
        if(str=="boat")
        {
        write("用木材扎起来的筏子 ,古朴的样子令人感到
无比的亲切 ,风大舟轻 ,大概很快就能够到
达想去的地方...

\n");
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




