// auc.c

#include <ansi.h>
#include <room.h>
#include "/open/open.h"

inherit F_CLEAN_UP;

int main( object me, string arg )
{
	int	value;
	string	id, *tuned_ch;
	object	ob, boss, *light, env;

	seteuid(getuid());
        tuned_ch = me->query_temp("channels");
        if( !pointerp(tuned_ch) )
          me->set_temp("channels", ({ "mud" }) );
        else if( member_array("mud", tuned_ch)==-1 )
          me->set_temp("channels", tuned_ch + ({ "mud" }) );
	if(!arg)
	  return notify_fail("不知道格式请help auc\n");
	arg = lower_case(arg);
	env = environment(me);

	if (!catch(load_object(AUROOM))) {
          if (!(boss=find_living("auction boss")) &&
              !(boss=find_object("auction boss")))
          return notify_fail ("老板出去玩耍了。\n");
 	}
	else return notify_fail ("黑市倒闭了啦，快找巫师来。\n");

	if( wizardp(me) ) {
		ob = present( arg, me );
		if( !ob ) ob = present( arg, env );
		if( !ob ) return notify_fail( "无此物品。\n" );
		call_other( boss, "do_sell", me, ob );
	}
	else if( sscanf(arg, "%d", value) != 1) {	// 送东西去拍卖
	  if ((ob=present(arg, me)) &&
		!ob->query("no_drop") &&
	!ob->query("no_auc") &&
		!ob->query("secured"))
	  {
	    if (ob->query("had_light")) {
	        ob->delete("had_light");
	        ob->delete("short");
		write (sprintf ("当你把%s送去拍卖时，这%s%s渐渐暗淡下来。\n",
		  ob->name(), ob->query("unit"), ob->name()));
	    }
	    if (ob->query("money_id"))
		return notify_fail ("ㄟ....不能拍卖金钱喔, 对不起啦!\n");
	    call_other(boss, "do_sell", me, ob);
	    message_vision("你看到黑市公司的送货员大老远的跑来拿走$N手中的"+
			   ob->name()+"\n", me);
	    return 1;
	  }
	  else {
	    tell_object (me, "你想欺骗黑市公司的人员啊。\n");
	    return 1;
	  }
	}
	else if (me->can_afford(value)) {	// 抢标
	  call_other(boss, "do_buy", me, value);
	  tell_object (me, "你打电话告诉黑市老板说，你愿意用"+
			   CHINESE_D->cvalue(value)+"抢标。\n");
	  me->pay_money(value);
	}
	else tell_object (me, "喝! 感情是骗吃骗喝的啊!!\n");
	return 1;
}

int help(object me)
{
   write( @HELP
指令格式: auc <物件>|<钱数>
指令说明 :
           本拍卖系统可以一次丢多件上去，由拍卖公司自行决定要
         拍卖哪件。
           对于正在拍卖的当中，也可以使用本命令抢标。
指令范例 :
           要拍卖可以用 auc <物件>，如 auc sword
           要抢标可以用 auc <金钱>，如 auc 100
特别注意 :
           抢标过程的金钱单位是文钱，由系统自行转换金币银币.
         例如你要标一两金子三两银子二十文钱，则 auc 10320
         抢标没有上限，但是每次加的量则跟战斗经验值有关,
         此外，[任何]东西都可以拍卖。
HELP
   );
   return 1;
}
