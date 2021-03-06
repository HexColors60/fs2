
//dumpquest.c

#include <ansi.h>

inherit F_CLEAN_UP;
inherit F_SAVE;

mapping quests_list = ([ ]);
mapping quest_long = ([ ]);
string have_finish(object me, string arg);

int main(object ob , string arg)
{
	object	who;
	string *k;
	int i;

	seteuid(getuid());
	restore();
	if( !arg ) {
	  k = keys(quests_list);
	  tell_object(ob, "目前狂想空间的任务如下表。\n");
	  for(i = 0;i < sizeof(quests_list);i++) {
	    tell_object(ob, sprintf("%4d.%3d %-30s",
		i+1,
		have_finish(ob, quests_list[k[i]]), k[i]));
	    if (i%2) printf ("\n");
	    else printf ("\t");
	  }
	  if (i%2) printf ("\n");
	    return 1;
	}
	else if (wizardp(ob) && (who=find_player(arg))) {
	  k = keys(quests_list);
	  tell_object(ob, "目前狂想空间的任务如下表。\n");
	  for(i = 0;i < sizeof(quests_list);i++) {
	    tell_object(ob, sprintf("%4d.%3d %-30s",
		i+1,
		have_finish(who, quests_list[k[i]]), k[i]));
	    if (i%2) tell_object(ob,"\n");
	  }
	  if (i%2) tell_object(ob,"\n");
	  return 1;
	}
	else {
	  if( sscanf(arg,"%d",i) != 1)
	    return notify_fail("请输入要查询之quest编号\n");
	  k = keys(quests_list);
	  if( i >= (sizeof(k) + 1) || i <= 0 )
	    return notify_fail("好像没有这个编号吧？\n");
	  printf("%3d %s：%s\n",i,k[i-1],quest_long[k[i-1]]);
	  return 1;
	}
}

string query_save_file()
{ return "/data/questlist" ; }

mapping query_quests()
{
  return quests_list;
}

string have_finish(object me, string arg)
{
	return (me->query(arg));
}

int help(object me)
{
	write(@HELP
指令格式 : quests [数字]
指令说明 :
           quests      : 这指令让你看自己完成的任务。
           quests 数字 : 这指令用来查数字所指定的任务说明。
HELP );
	return 1;
}
