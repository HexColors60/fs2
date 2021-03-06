// food.c

#include <dbase.h>
#include <name.h>

void init()
{
	add_action("do_eat", "eat");
}
/*
varargs string long(int raw)
{
	int amount, max;
	string str;

	if( amount = query("food_remaining") ) {
		str = ::long(raw);
		max = query("food_maximum");
		if( amount == max )
			;
		else if( amount > max/2 )
			str += "里面装了七、八分满的" + query("liquid_name") + "\n";
		else if( amount >= max/3 )
			str += "里面装了五、六分满的" + query("liquid_name") + "\n";
		else if( amount > max/2 )
			str += "里面装了少许的" + query("liquid_name") + "\n";
		return str;
	}
	else return ::long(raw);
}
*/

int do_eat(string arg)
{
	object	me, ob;
	int	max_food;

	me = this_player();
	max_food = (int)this_player()->max_food_capacity();

	if (!ob = present (arg, me)) return 0;
	if( ob != this_object() ) return 0;
	if( me->is_busy() )
		return notify_fail("你上一个动作还没有完成。\n");
	if( !query("food_remaining") )
		return notify_fail( name() + "已经没什么好吃的了。\n");
	if( (int)me->query("food") >= max_food )
		return notify_fail("你已经吃太饱了，再也塞不下任何东西了。\n");

	me->add("food", query("food_supply"));
	if ((int)me->query("food") >= max_food)
	  me->set("food", max_food);
	if( me->is_fighting() ) me->start_busy(2);

	// This allows customization of drinking effect.
	if( query("eat_func") ) return 1;

	set("value", 0);
	if(this_object()->query("get_poison"))
	{
		tell_object(this_player(),"糟了 ! 食物里有毒 !\n");
		me->apply_condition(this_object()->query("get_poison"),
		                    this_object()->query("poison_power"));
	}
	add("food_remaining", -1);
	if( !query("food_remaining") ) {
		message_vision("$N将剩下的" + name() + "吃得干干净净。\n", me);
		if( !this_object()->finish_eat() )
			destruct(this_object());
	} else 
message_vision("$N端起" +name() + "，喝了一口汤，吃了一口面。\n",me);

	return 1;
}
