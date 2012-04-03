// fund, 你写程式都不写 help 的啊

inherit F_CLEAN_UP;
int main(object me,string arg)
{
	string cmds,str;
	string file;

	seteuid(getuid());
	if (!arg) return notify_fail ("啊? 你要什么命令?\n");
	if(sscanf(arg,"%s %s",cmds,str)!=2)
		cmds=arg;
	file="/daemon/class/normal/cmds/"+cmds;
	if(file_size(file+".c")>0)
		return file->main(me,str);
	file="/daemon/class/"+me->query("class")+"/cmds/"+cmds;
	if(file_size(file+".c")<=0)
		return notify_fail("没有这样指令。\n");
	return file->main(me,str);
}

int help (object me)
{
        write(@HELP
指令格式 : cmd <工会门派专用指令>
指令说明 :
           这个指令可以让你使用门派专用指令。
HELP);
}
