#include <ansi.h>

object env,target;
string owner;
int feed_time,live_age,gin,kee,sen;

int update_condition(object ob, int duration)
{
	env = environment(ob);
	owner = ob->query("insect_owner");
	feed_time = (int)ob->query("feed_time");
	live_age = (int)ob->query("live_age");
	gin = (int)ob->query("gin_damage");
	kee = (int)ob->query("kee_damage");
	sen = (int)ob->query("sen_damage");

	if( duration >= 1)
	{
		if( !owner )
			ob->die();

		target = find_player(owner);
		if( env != environment(target) )
		{
			message_vision("\n$N由于缺乏人照顾，渐渐地化成一摊黑色的血水～\n\n"NOR,ob);
			ob->die();
		}
		if( (int)ob->query("age") > live_age )
		{
			message_vision("\n$N由于老化死去了。\n",ob);
			ob->die();
		}
		if( (int)ob->query_temp("can_feed") > 10 )
		{
			message_vision("\n$N由于缺乏喂食蛊毒而死去了。\n",ob);
			ob->die();
		}

		if( random(100) < feed_time )
		{
		        message_vision("\n$N不断的扭动着，并且不断的吸食着$n的气血～\n\n",ob,target);
			target->receive_damage("gin",gin);
			target->receive_damage("kee",kee);
			target->receive_damage("sen",sen);
        		COMBAT_D->report_status(target,1);
			ob->add_temp("can_feed",1);
			ob->set("title",HIR"( 嗜血 )"NOR);
                }
		else
			message_vision("\n$N正处于熟睡的状态～\n\n"NOR,ob);

		if( !ob->query_temp("can_feed") )
			ob->set("title",YEL"( 熟睡 )"NOR);

		ob->add("age",1);
		return 1;
	}

	if( duration < 1)
		return 0;
return 1;
}
