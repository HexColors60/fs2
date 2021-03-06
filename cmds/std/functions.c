#include <ansi.h>
inherit F_CLEAN_UP;

string *status = ({
        BLU "初学乍练" NOR,
        HIB "粗通皮毛" NOR,
        HIB "半生不熟" NOR,
        HIB "马马虎虎" NOR,
        HIB "驾轻就熟" NOR,
        CYN "出类拔萃" NOR,
        CYN "神乎其技" NOR,
        CYN "出神入化" NOR,
        HIC "登峰造极" NOR,
        HIC "一代宗师" NOR,
        HIW "深不可测" NOR
	});
string get_status(int value);

varargs int main( object me, string arg, int mode )
{
	string msg;
	string *name;
	object ob;
	int i;
        if(!arg)
                ob = me;
        else{
		if(!wizardp(me))
			return notify_fail("只有巫师才能查看玩者的特殊功能状况。\n");
                ob = present(arg, environment(me));
                if (!ob) ob = find_player(arg);
                if (!ob) ob = find_living(arg);
		if (!ob) return notify_fail("你要察看谁的关系状态 ?\n");
        }

	if( mode==1 )
		ob = me->query_temp("pal");

	if(!ob->query("functions"))
		return notify_fail((ob==me ? "你" : ob->name())+"目前并没有任何特殊功能。\n");
	name=keys(ob->query("functions"));
	msg=(ob==me ? "你" : ob->name())+"目前的特殊功能：\n\n";
	for(i=0;i<sizeof(name);i++)
		msg+=sprintf("  %-40s- %10s - %4d/%5d\n",
	to_chinese(name[i])+"("+name[i]+")",
	get_status(ob->query("functions/"+name[i]+"/level")),
	ob->query("functions/"+name[i]+"/level"),
	ob->query("functions/"+name[i]+"/learned"));
	msg+="\n";
	write(msg);
	return 1;
}
string get_status(int value)
{
        if(value > 100) return status[10];
        return status[value/10];
}
int help()
{
write(@LONG
指令格式 : functions
指令说明 :
           这个指令用来查询你的特殊功能。
LONG);
	return 1;
}
