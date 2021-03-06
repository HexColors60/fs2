// chfn.c

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object link;

	if( link = me->link() ) {
		write("您的 Email address [" + link->query("email") + "]: ");
		input_to("get_email", link);
		return 1;
	}
	return 0;
}

void get_email(string new_email, object link)
{
	if( new_email != "" )
		link->set("email", new_email);

	write("您的自我介绍: (finger时显示)\n");
	link->body()->edit((: call_other, __FILE__, "get_profile", link :));
}

void get_profile(object link, string str)
{
	link->set("profile", str);
	write("您的签名格式: (post时用)\n");
	link->body()->edit((: call_other, __FILE__, "get_signature", link :));
}

void get_signature(object link, string str)
{
	if( strlen(str) > 400 )
		write("签名格式太长！请重新设定。\n");
	else
		link->set("signature", str);
	write("请记得用 save 储存您所作的修改。\n");
}

int help(object me)
{
write(@HELP
指令格式 : chfn

用途 : 用来修改 email address , 编辑自我介绍(finger 时看到)
       及签名(post 时用)。
HELP
     );
     return 1;
}
