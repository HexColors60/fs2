inherit NPC;
#include <ansi.h>
string ask();
string do_work();

void create()
{
	set_name("钰萍姊",({"woman"}));
	set("long","
她是在琰扬居服侍水邪将--水柔缠的邪灵之一，一双碧绿色的大
眼，水蓝色的秀发，虽然岁月不断的在她脸上留下了痕迹，可是
却无损她那迷人的脸庞，你看她忙的不可开交的样子，或许你能
帮忙她做一些杂事吧。\n");
	set("age",10291);
	set("gender","女性");
	set("inquiry",([
		"帮忙":(: ask :),
		"水邪将":"唉...别问了...那是一个惨忍的封号...\n",
		"水柔缠":"唉...她是我的主子，你如果想见她，可能很难...除非...\n",
		"除非":"除非你能假装这里的佣人，先帮忙我做厨房的工作...藉机混进主人的房内..\n",
	]));
	set("chat_chance",10);
	set("chat_msg",({
	(: do_work :),
	}));
setup();
}

int accept_object(object me,object ob)
{
int i,j;

	if( !me->query_temp("evil/water/mission") )
		return 0;

	i = (int)me->query_temp("evil/water/mission");

	if( i == 1 )
	{
		if( !me->query_temp("evil/water/f_mission-1") )
			(int)me->set_temp("evil/water/f_mission-1",1);

		j = (int)me->query_temp("evil/water/f_mission-1");

		if( ob->query("id") == "good torch" )
		{
			if( j > 5 )
			{
			command("say 嗯～这样就够多了～应该可以烧出一手好菜出来了～\n");
			command("say 不过...还是有事情需要你的帮忙...^-^\n");
			command("grin "+me->query("id"));
			me->delete_temp("evil/water/f_mission-1");
			(int)me->set_temp("evil/water/mission",2);
			}
			else
			{
			command("say 嗯～辛苦你了～不过木材还不够...\n");
			command("say 请你再多拿点燃木材去砍来给我...拜托了..^-^\n");
			command("rub "+me->query("id"));
			(int)me->add_temp("evil/water/f_mission-1",1);
			me->set_temp("evil/water/ask-mission-1",1);
			}
		}

		if( ob->query("id") == "bad torch" )
		{
			command("say ㄟ...如果可以...我是说...希望你能做好一点。\n");
			command("say 这根无法做出好吃的食物出来...所以..请你再去帮我砍一些好的燃木材。\n");
			me->set_temp("evil/water/ask-mission-1",1);
		}
	}
	call_out("do_dest",1,ob);
return 1;
}

int do_dest(object ob)
{
destruct(ob);
}

string do_work()
{
object ob = this_object();
	
	if( !ob->query_temp("move_action") )
	{
		command("say 唉唉...油锅又过热了...赶紧过去翻动一下锅子..\n");
		command("north");
		message_vision("$N不断的翻动着锅面。\n",ob);
		ob->set_temp("move_action","north");
	}
	else
	{
		if( ob->query_temp("move_action") == "north" )
		{
			command("say 是谁又把炊坎的器具乱放了...真是的...\n");
			command("west");
			ob->set_temp("move_action","west");
			message_vision("$N不断的整理着凌乱的炊坎器具。\n",ob);
		}
		else if( ob->query_temp("move_action") == "west" )
		{
			command("say 是谁将我刚刚刷过的木材又弄脏了...\n");
			command("say 难道没人知道干净的木材烧出来的食物会比较好吃的吗!?\n");
			ob->set_temp("move_action","south");
			command("south");
			message_vision("$N不断的刷洗着地上的木材。\n",ob);
		}
		else if( ob->query_temp("move_action") == "south" )
		{
			command("say 嗯...食物放置于桌上不晓得有没有坏掉的...\n");
			ob->set_temp("move_action","east");
			command("east");
			message_vision("$N品嚐着桌上鲜美的食物。\n",ob);
		}
		else if( ob->query_temp("move_action") == "east" )
		{
			command("say 唉唉...油锅又过热了...赶紧过去翻动一下锅子..\n");
			ob->set_temp("move_action","north");
			command("north");
			message_vision("$N不断的翻动着锅面。\n",ob);
		}
	}
return "真是忙啊...\n";
}

string ask()
{
object me,ob,obj;
int i,j;

	me = this_player();
	ob = this_object();

	if( !me->query_temp("evil/water/mission") )
		(int)me->set_temp("evil/water/mission",1);

	i = (int)me->query_temp("evil/water/mission");
	me->set_temp("evil/water/ask-mission-"+i,1);
	switch(i)
	{
		case 1:	
			{
			command("say 首先你先去厨房内找寻燃木材..将燃木材拿到后厢房那的一块空地上。\n");
			command("say 将其劈开然后再拿来给我。\n");
			break;
			}
		case 2:
			{
			command("say 再来你从厨房内找出一推棉草，拿到后厢房喂食那只凶暴的金锦马。\n");
			command("say 小心别被它踢伤了...除了主人喂它，不然一般魔兽喂食它，都很容易被它踹飞。\n");
			break;
			}
		case 3:
			{
			command("say 奇怪了...我不晓得我将厨房内的千花蜜放到哪去了...\n");
			command("say 如果你找到的话，记得帮我将千花蜜拿去喂食鼓蜂....\n");
			command("say 对了...鼓蜂就在后厢房的那棵大松树上，小心别被螫了。\n");
			break;
			}
		case 4:
			{
			command("say 嗯...好不容易煮好了一些食物，都放在桌上了。\n");
			command("south");
			command("east");
			ob->delete_temp("move_action");
			j = random(5)+1;
			obj = new(__DIR__"obj/food"+j);
			tell_object(me,"你看到钰萍姊走向放置食物的桌子上，从桌上端了一盘"+obj->name(1)+"给你。\n");
			tell_object(me,"钰萍姊告诉你说：请帮我端到后厢房给我的主子，想必她应该已经觉得饿了。\n",ob);
			break;
			}
	}
return "好了，就这样...快去快回吧...厨房很忙的...\n";
}

