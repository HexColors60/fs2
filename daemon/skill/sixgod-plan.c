// security.c

inherit SKILL;

int valid_enable(string usage) { return usage=="plan"; }

int valid_learn(object me)
{
            if( me->query("max_force") < 4000 ) {
            tell_object(me, "你的内力修为不够，最少要有四千点。\n");
            return 0;
        }
            if( me->query("force") < 600 ) {
            tell_object(me, "你目前的内力不到六百点，无法练此计谋。\n");
            return 0;
        }
            if( me->query_skill("god-plan", 1) < 100 ) {
            tell_object(me,"你的诸葛神算不够纯熟，最少需要一百级。\n");        
            return 0;
        }
            if( !me->query("mark/sixgod-plan",1) ) {
            tell_object(me, "你还没拿到六韬奇略这本书吧?\n");
            return 0;
        }
            if( (me->query("potential") - me->query("learned_points")) < 5 ) {
            tell_object(me, "你的潜能不到五点，无法练此计谋。\n");
            return 0;
        }
      tell_object(me, "学此计谋需扣潜能五点。\n");
            me->add("potential", -5);
            return 1;
}

int practice_skill(object me)
{
    return notify_fail("六韬奇略只能用学的。\n");
}


string perform_action_file( string action )
{
if( this_player()->query("race") !="人类" )


   {
      tell_object( this_player(), "你不是儒门,怎么用六韬奇略???\n");
      action= "null_plan";
   }
      return CLASS_D("scholar") + "/sixgod-plan/" + action;
}

