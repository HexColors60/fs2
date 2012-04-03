//神秘药水供玩家饮用,属于特殊的道具......           made by eva  
inherit COMBINED_ITEM;
void create()
{
        set_name("蓝色神秘药水", ({"blue potion","potion"}) );
	set("long","蓝色的液体反射出诡异的光芒, 完全不知如何制造的药水.
听说喝了会使伤口迅速复元, 但是却不会回复生命力.\n");
        set("unit", "罐");
        set("base_unit", "罐");
        set("value",100000);
        set("base_weight", 150);
	set_amount(1);
	setup();
}

void init()
{
	if( this_player()==environment() )
	{
		add_action("drink_potion", "drink");
	}	
}

int drink_potion(string arg)
{      

        object ob,me=this_player();
	int max_kee,eff_kee;
        if( !arg )                      return 0;
        arg=lower_case(arg);
        if( !ob = present(arg,me) )     return 0;
        if( ob != this_object() )       return 0;
	message_vision("$N喝下一罐蓝色神秘药水.\n", me);
        max_kee = me->query("max_kee");
        eff_kee = me->query("eff_kee");
        eff_kee = eff_kee + 200;
        if( eff_kee > max_kee )
            eff_kee = max_kee;
	me->set("eff_kee",eff_kee);
	add_amount(-1);
        return 1;
}

              
                           
