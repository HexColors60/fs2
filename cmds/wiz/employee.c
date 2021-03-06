// employee.c

#include <ansi.h>
#define SYNTAX	"指令格式：employee [巫师姓名]\n"

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string *list, name, str;
	int i, count;

	if( !arg ) name = me->query("id");
	else if( sscanf(arg, "%s", name)!=1 )
                return notify_fail(SYNTAX);

	count = 0;
	write(name + " 的手下有：\n");
	list = sort_array(SECURITY_D->query_wizlist(), 1);
        for(i=0; i<sizeof(list); i++)
	{
		if((str=SECURITY_D->get_boss(list[i]))== name)
		{
			count ++;
			printf("%-12s ： %-10s\n", list[i], SECURITY_D->get_status(list[i]));
		}
	}
	write("总共有 "+ count + " 个人。\n");	

	return 1;
}

int help()
{
	write(SYNTAX + @TEXT

找出某位巫师的手下工作人员。
TEXT
	);
}
