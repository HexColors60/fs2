#include <ansi.h>
inherit NPC;
string ask_oldman();
void create ()
{
        set_name("老人",({"old man","man","old"}) );
        set("gender","男性");
        set("age",74);
        set("long","一个身处于岩壁地窖内的神秘人, 除了脸上长满怪异的(狼斑)外, 
似乎也看不出来他与路上的乞丐有何两样!!\n");
	set("inquiry",([
	"狼斑":"这是(死灵骨魔)的杰作, 狼斑会让我的\功力全部尽失...",
	"死灵骨魔":(:ask_oldman:),
	]));
	set("chat_chance",1);
	set("chat_msg",({
	HIY"老人突然激动的喊着:天煞的死灵骨魔!! 谁能帮我报仇啊...哎哎..\n"NOR,
	HIW"老人似哭似笑的表情, 情绪十分的失控...\n"NOR,
	}));
	setup();
}

string ask_oldman()
{
object me;
me=this_player();
if(me->query_temp("ghost-hole/agree-kill-ghost",1))
return "老人高兴的笑着:太好了,我期待你带回来的好消息!!";
me->set_temp("ghost-hole/ask_oldman",1);
return "老人说着:他是掌管此地的魔神, 十分的强大, 你愿意帮我报仇吗?";
}

void init()
{
add_action("do_nod","nod");
}

int do_nod(string arg)
{
object me=this_player();
if(!arg||arg!="man")
return 0;
if(me->query_temp("ghost-hole/ask_oldman")!=1)
{
message_vision(HIY"$N对老人点头, 老人投以怀疑的眼光看着$N\n"NOR,me);
return notify_fail("你对我点头做什么?");
}
message_vision(HIY"$N点头答应了老人的要求!!\n"NOR,me);
message_vision(HIY"老人笑道:太好了, 让我利用我最后一点\功力把你送出这里!!\n"NOR,me);
me->move("/open/ghost-hole/g-h04");
message_vision(HIW"空间突然出现了一个裂缝, $N从裂缝掉了下来...\n"NOR,me);
return 1;
}
