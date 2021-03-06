// dest.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string option, target;

	object obj;

	if (!arg) return notify_fail("指令格式 : dest <物件之名称或档名>\n" );

	if( sscanf(arg, "%s %s", option, target)!=2 ) target = arg;

	if( option == "-r" &&
		( (string)SECURITY_D->get_status(me)=="(admin)" ||
		  (string)SECURITY_D->get_status(me)=="(manager)" ))
	{
		seteuid(ROOT_UID);
	}
	obj = find_object(target);
	if (!obj) obj = present(target, me);
	if (!obj) obj = present(target, environment(me));
	if (!obj) obj = find_object( resolve_path(me->query("cwd"), target) );
	if (!obj) return notify_fail("没有这样物件....。\n");

	if( environment(me)==environment(obj) )
		message_vision("$N召唤出一个黑洞，尝试将$n吞没。\n", me, obj);

	if (userp(obj)) {
	  log_file("quit", 
                sprintf("%s于 %s 离开游戏。", obj->short(), ctime(time()))
	  );
          CHANNEL_D->do_channel(me, "sys",
                sprintf("%s离开游戏了。", obj->short()) );
	  obj->set("last_on", time());
	  obj->set("last_from", query_ip_name(obj));
	  obj->save();
	  destruct(obj);
	}
	else {
	  seteuid(geteuid(me));
	  destruct(obj);
	}
	if(obj) write("你无法将这个物件摧毁。\n");
	else write("哈哈哈, 好强的黑洞.\n");

	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : dest [-r] <物件之名称或档名>

利用此一指令可将一个物件(object)或物件定义(class)从记忆体中清除，若清除物
件定义(即：指定档名的情况下)则下一次参考到这个物件的时候会重新将它编译。

具有 (admin) 以上身分的巫师可以用 -r 选项以 ROOT_UID 身分来清除被保护的物件如
使用者。

参考资料： destruct(), clone
HELP
    );
    return 1;
}
