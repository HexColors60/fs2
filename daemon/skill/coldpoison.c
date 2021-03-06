// godcure.c
#include <ansi.h>
inherit SKILL;

mapping make = ([
	"rose": ([
	0:"rose flower",
	]),
	"dark":([
	0:"dark heart",
	]),
	"faint":([
	0:"smell",
	]),
	"five":([
	0:"green snake",
	1:"gold bug",
	2:"dragon heart",
	3:"hundred flower",
	4:"poison egg",
	]),
	]);
mapping make_name = ([
	"rose":"火玫瑰毒",
	"dark":"深宫奇毒",
	"faint":"一刻香",
	"five":"五毒",
	]);
mapping make_improve = ([
      	"faint" : 1,
	"rose"  : 2,
	"dark" 	: 4,
	"five"	: 5,
	]);

mapping make_need_lv = ([
	"rose":30,
	"dark":50,
	"faint":10,
	"five":80,
	]);
int valid_enable(string usage)
{
	return (usage=="poison");
}

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
	return notify_fail("天冰奇毒只能用学的。\n");
}

int make(object me,string name)
{
	object medicine;
	int i;
	mapping dict;
	string pstr="";
	if(!make[name])
		return notify_fail("天冰奇毒中没有这种毒。\n");
	if(me->query_skill("coldpoison",1)<make_need_lv[name])
		return  notify_fail("你的天冰奇毒程度不够，无法练制这种毒。\n");
	dict=make[name];
	for(i=0;i<sizeof(dict);i++)
	{
	if(!present(dict[i],me))
		return notify_fail("你的配料不足，无法练制。\n");
		medicine=present(dict[i],me);
		pstr+="("+medicine->name()+")";
	}
	message_vision(
	"$N用"+pstr+"来做"+make_name[name]+"。\n",me);
	for(i=0;i<sizeof(dict);i++)
		present(dict[i],me)->add_amount(-1);
	for(i=0;i<5;i++)
	{
		medicine = new("obj/poison/"+name+"_poison");
		medicine->set("poison_power",me->query_skill("poison")/10);
		medicine->move(me);
	}
        if(me->query_skill("coldpoison",1) < 100)
	  me->improve_skill("coldpoison",random(me->query("int")/2 +make_improve[name]*me->query_skill("poison",1)/10)+4*make_improve[name],1);
	return 1;
}
string perform_action_file(string action)
{
	return CLASS_D("poisoner")+"/coldpoison/"+action;
}
