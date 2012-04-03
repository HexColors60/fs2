// gather.c

#include <ansi.h>

inherit SSERVER;
inherit F_GUILDCMDS;

int main(object me)
{
	if(me->query_temp("spe")==1)
		return notify_fail("你现在正在使用灵气，不能修练。\n");
       if(!me->query("sec_kee"))
              return notify_fail("你的身上没有任何灵气。\n");
	if(me->query("atman")<10)
		return notify_fail("你的灵力不够，无法修练灵气。\n");
      message_vision(
          HIG + "$N体内真力贯入护身灵气之中，使$N灵气增强。\n" NOR,me);
	me->add("s_kee",me->query("spi")/10);
	me->add("atman",-10);
	if(me->query("s_kee")>me->query("max_s_kee")*2)
	{
//99/5/2加入杀意魔气MAX的成长限制
                if (me->query("sec_kee") == "mkill")
                {//杀意魔气以胆识为锻炼条件 胆识30*9＝270 MAX
	  if ( me->query("max_s_kee") >= (me->query("cor")*9))
	  {
	      tell_object(me,"你突然感到全身酸麻，似乎体内的灵气已到极限。\n");
                        me->set("s_kee",me->query("max_s_kee"));
                        return 1;
                    }
	  me->add("max_s_kee",1);
                    me->set("s_kee",me->query("max_s_kee"));
                    tell_object(me,HIY "你的灵气增强了！\n" NOR);
	  return 1;
                }
		if(me->query("max_s_kee")>=me->query("spi")*2+me->query("max_atman")/20)
		{
			tell_object(me,"你突然感到全身酸麻，似乎体内的灵气已到极限。\n");
			me->set("max_s_kee",me->query("spi")*2+me->query("max_atman")/20);
			me->set("s_kee",me->query("max_s_kee"));
			return 1;
		}
		me->add("max_s_kee",1);
		me->set("s_kee",me->query("max_s_kee"));
		tell_object(me,HIY "你的灵气增强了！\n" NOR);
	}
	return 1;
}
int help(object me)
{
  write( @HELP
 
这个指令是用来修练灵气的，每次修练会减少实战经验。
 
HELP);
  return 1;
}
