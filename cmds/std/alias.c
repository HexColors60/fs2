// alias.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    int i,flag;
	mapping alias;
    object ob;
    string verb, replace, name, *vrbs;

    flag=0;
    if(wizardp(me)){
     if(arg){
      if(find_player(arg)){
        ob=find_player(arg);
        arg=0;
      }
       else if(FINGER_D->acquire_login_ob(arg)){
         ob = FINGER_D->acquire_login_ob(arg);
         arg=0;
       }
      else ob=me;
      alias=ob->query_all_alias();
      flag=1;
     }
    }
    if(!flag)
	alias = me->query_all_alias();
	if( !arg ) {
		if( !sizeof(alias) ) {
			write("你目前并没有设定任何 alias。\n");
			return 1;
		} else  {
			write("你目前设定的所有命令替代如下：\n");
			vrbs = keys(alias);
			for(i=0; i<sizeof(vrbs); i++)
				printf("%-15s = %s\n", vrbs[i], alias[vrbs[i]]);
			return 1;
		}
	}

	if (strlen(arg) > 79) arg = arg[0..78];
	if( sscanf(arg, "%s %s", verb, replace)!=2 )
	  if (stringp(alias[arg]))
		printf("你设定命令 %s 替换成 :\n%s\n", arg, alias[arg]);
	  else if (alias[arg])
		printf("你设定命令替换有问题，请删除或重新设定。\n");
	  else
		printf("你没有设定命令替换 "+arg+"\n");
	else if( verb=="alias" || verb == "go" || verb == "do" )
		return notify_fail("你不能将 "+verb+" 指令设定其他用途。\n");
	else if (verb == "-d") {
		printf("你删除命令替换 %s:\n%s\n", replace, alias[replace]);
		me->set_alias(replace, 0);
	}
	else if( verb=="" )
		return notify_fail("你要设什么 alias？\n");
	else {
		if (stringp(me->find_commands(verb))) return
		  notify_fail ("你会取代掉现有的命令, 请换个命令再来.\n");
		if (strsrch(replace, "$*") == -1) replace += " $*";
		printf("你设定命令替换 %s:\n%s\n", verb, replace);
		return me->set_alias(verb, replace);
	}

	return 1;
}

int help (object me)
{
	write(@HELP
指令格式 : alias [-d] <欲设定之指令> <系统提供之指令>
指令说明 :
           有时系统所提供之指令需要输入很长的字串, 在使用时
        (尤其是经常用到的) 或许会感觉不方便, 此时你(妳)可以
        用此一指令设定并替代原有之指令。 
范例:
	'alias sc score' 会以 sc 取代 score 指令。
	'alias' 后不加参数则列出你所有的替代指令。
	'alias sc' 会显示 sc 这个替代指令。 (如果你有设的话)
	'alias -d sc' 会删除你原先对 sc 的设定
 
其中可以用 $1, $2, $3 .... 来取代第一、第二、第三个参数，或是 $* 取代
所有的参数，如：
	'alias pb put $1 in $2'

则每当你(妳)打：
	pb bandage bag

就会取代成：
	put bandage in bag
	
HELP
);
        return 1;
}
