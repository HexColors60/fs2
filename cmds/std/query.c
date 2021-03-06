#include <ansi.h>
inherit F_CLEAN_UP;
inherit F_MORE;

int help ();

int main(object me, string arg)
{
	mapping dict=([]);
	int i,j;
	string *name;
	string msg="";
	object *list;
	seteuid(getuid());

	if (!arg) return help ();

	switch(arg)
	{
	case "skills":
	{
	msg+="目前狂想空间合法的技能有：\n";
		msg+="\n";
		msg+=sprintf("  %-30s%-20s\n","技能名称","所属门派");
		msg+="--------------------------------------------------\n";
		dict=F_SKILL_D->query_translate();
		name=keys(dict);
		for(i=0;i<sizeof(name);i++)
			msg+=sprintf("  %-30s%-20s\n",to_chinese(name[i])+"("+name[i]+")",dict[name[i]]);
		msg+="\n"+sprintf("目前狂想空间共有 %d 个合法技能。\n\n",sizeof(name));
		start_more(msg);
		return 1;
	}
	case "guild":
	{
		msg+="目前狂想空间的门派分布状况：\n";
		msg+="------------------------------------------------------------\n";
		list=users();
		for(i=0;i<sizeof(list);i++)
		if(!wizardp(list[i]))
			if(!dict[list[i]->query("family/family_name")])
				dict[list[i]->query("family/family_name")]=1;
			else
				dict[list[i]->query("family/family_name")]=dict[list[i]->query("family/family_name")]+1;
		name=keys(dict);
		for(i=0;i<sizeof(name);i++)
		{
		if(name[i])
		msg+=sprintf("%-10s：",name[i]);
		else
		msg+=sprintf("%-10s：","其它");
		for(j=0;j<dict[name[i]];j++)
			msg+=HIC+"□";
		msg+="\n" NOR;
		}
		write(msg);
		return 1;
	}
	case "class":
	{
		msg+="目前狂想空间的职业分布状况：\n\n";
		list=users();
		for(i=0;i<sizeof(list);i++)
		if(!wizardp(list[i]))
		if(!dict[list[i]->query("class")])
			dict[list[i]->query("class")]=1;
		else
			dict[list[i]->query("class")]=dict[list[i]->query("class")]+1;
		name=keys(dict);
		for(i=0;i<sizeof(name);i++)
		{
		if(name[i])
		msg+=sprintf("%-10s：",to_chinese(name[i]));
		else
		msg+=sprintf("%-10s：","【 平  民 】");
		for(j=0;j<dict[name[i]];j++)
			msg+=HIC+"□";
		msg+="\n" NOR;
		}
		write(msg);
		return 1;
	}
	}

	return help();
}

int help()
{
	write ( @HELP
指令格式 : query <查询的项目>
指令说明 :
           目前可查的有 :
		skills
	        guild
	        class
HELP
	);
	return 1 ;
}
