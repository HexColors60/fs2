// perform.c
inherit F_CLEAN_UP;
inherit F_FUNCTION;
int main(object me, string arg)
{
        object weapon;
        string martial, skill;
        int result;
        seteuid(getuid());
        if( !arg ) 
                return notify_fail("你要用外功做什么？\n");
        if( me->query("force") < 0 )
     {
     me->set("force",0);
   tell_object(me,"没内力了用什呀?\n"); 
   return 1;
     }
        if(me->query_temp("is_busy"))
                return notify_fail("你的内息翻滚不定,暂时无法使用外功!!!\n");
        if(me->query_temp("is_busy")||me->is_busy() )
        return notify_fail("你一运气用力，发觉丹田中毫无内息。\n");

//sun_fire_sword 特殊功能

        if( me->query_temp("no_power") )
                return notify_fail("炫目的剑光还残留在你眼底，使你无法全力运气。\n");

        if( me->query_temp("no_power_f") )
                return notify_fail("你被身旁的龙卷气劲所阻，因此你无法以自由使用绝招\n");

        if( me->query_temp("arrayp") )
                return notify_fail("阵法刚开始运转，你没办法分心使用绝招\n");
        
        if( environment(me)->query("no_fight") )
             return notify_fail("这里不准战斗。\n");

        if( sscanf(arg, "%s.%s", martial, arg)!=2 ) {
                if( weapon = me->query_temp("weapon") )
                        martial = weapon->query("skill_type");
                else
                        martial = "unarmed";
        }
//add by bss 因为有perform不能用的现像,故检查一下
/*
        if(!(TEMP_D->update_perform(me,martial,arg)))
                return 0;
*/

        if( stringp(skill = me->query_skill_mapped(martial)) )
        {
                if( SKILL_D(skill)->perform_action(me, arg) ) 
                {

			
                      	 	 me->set_temp("is_busy",1);
                        call_out("del_busy",4,me);
                 		return 1;
	
                }
        }
        if(!find_object(SKILL_D(martial)))
          if(!load_object(SKILL_D(martial)))
            return 0;
        if( SKILL_D(martial)->perform_action(me, arg) ) {

                me->set_temp("is_busy",1);
             call_out("del_busy",4,me);
                return 1;
        }
        return 0;
}

void del_busy(object me) {

        if( me )        // 使用 call_out 一定要检查 player 是否在吗
                me->delete_temp("is_busy");
        return;
}

int help(object me)
{
        write(@HELP
指令格式 : perfrom [<武功种类>.]<招式名称> [<施用对象>]
指令说明 :
           如果你所学的外功(拳脚、剑法、刀法....)有一些特殊的攻击
     方式或招式，可以用这个指令来使用，你必须先用 enable 指令指定
     你使用的武功，不指定武功种类时，空手的外功是指你的拳脚功夫，
     使用武器时则是兵刃的武功。
           若是你的外功中有种类不同，但是招式名称相同的，或者不属
     于拳脚跟武器技能的武功(如轻功)，可以用 <武功>.<招式>  的方式
     指定，如：
        perform sword.powerfocus 
        perform move.reflexion
           换句话说，只要是 enable 中的武功有特殊招式的，都可以用
     这个指令使用。

□ 附录 基本技能的外功
        以下是基本技能中含有外功功能的部份

基本技能   外功名称   用法                                附注
基本剑法   剑气       perform sword.swordkee [<target>]   剑士、刀客、武者
读书识字   教诲训示   perform literate.preach [<target>]  书生
HELP
        );
        return 1;
}
