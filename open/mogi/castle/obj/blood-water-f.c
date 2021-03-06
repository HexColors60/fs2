// made by roger

inherit COMBINED_ITEM;
#include <ansi.h>
void create()
{
        set_name("千坟之水", ({"blood water","water"}) );
	set("long",
	"一颗藏黑的心脏仍在不断的跳动着, 青黑色的血液被冻化而封在心脏里, 
看起来似乎可以吸干(suck)里面的血\n");
	set("unit", "颗");
	set("base_unit", "颗");
        set("value", 100000);
        set("base_weight", 50);
	set_amount(1);
	setup();
}
void init()
{
	if( this_player()==environment() )
		add_action("suck_water", "suck");
}
int suck_water(string arg)
{
        object ob,me=this_player();

        if( !arg )                      return 0;
        arg=lower_case(arg);
        if( !ob = present(arg,me) )     return 0;
  	if( ob != this_object() )       return 0;

        if (me->query_condition("mogi") > 30){
        message_vision(
"$N割开心脏吸干了其中黑色的血水之后, 发出了一声凄厉的惨嚎, 身子慢慢倒了下去...\n", me);
        me->die();
 log_file("mogi/poison", sprintf("%s(%s) 二次误食千坟之水葛屁 on %s\n"
,me->query("name"),me->query("id"), ctime(time()) ));
	add_amount(-1);
	return 1;
                                       }

       else if (me->query_condition("mogi") > 0){
        message_vision(
"$N割开心脏吸干了其中黑色的血水, 突然觉得脑中一阵剧痛, 随即七窍喷出黑血, 入灭之毒猛然发作！\n", me);
        me->apply_condition("mogi",35);
 log_file("mogi/poison", sprintf("%s(%s) 误食假千坟之水 on %s\n"
,me->query("name"),me->query("id"), ctime(time()) ));
	add_amount(-1);
	return 1;
                                       }
       else {
        message_vision(
"$N割开心脏吸干了其中黑色的血水, 忽然头痛欲裂, 脸上霎时全无血色！\n", me);
        me->add("force",-1000);
        me->receive_wound("kee",90);
        me->apply_condition("mogi",5);
 log_file("mogi/poison", sprintf("%s(%s) 中入灭之毒(误食) on %s\n"
,me->query("name"),me->query("id"), ctime(time()) ));
	add_amount(-1);
	return 1;
        }    	
}
