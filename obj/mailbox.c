// mailbox.c
// Fix 显示画面, "from" 命令
// by wade@Fantasy.Spaace 87/7/31

#include <ansi.h>

inherit ITEM;
inherit F_SAVE;

mapping *mails;

void get_mail_text(mapping mail, string str);

void create()
{
	set_name("文书业务说明书", ({ "mailbox","box" }) );
	set("long",
		"你可以用以下指令来处理你的邮件：\n\n"
		"mail <某人>               寄信给别人。\n"
		"forward <信件编号> <某人> 将某封信转寄给别人。\n"
		"from                      查看信箱中的信件。\n"
		"read <信件编号>           阅\读一封信件。\n"
		"discard <信件编号>        丢弃一封信件。\n"
	);
	set("unit", "张");
	set("no_drop", 1);
	set("no_insert", 1);
	setup();
}

int set_owner(string id)
{
	set("owner_id", id);
	return restore();
}

void init()
{
	object ob;

	if( this_player() && environment()==this_player() ) {
		set_owner( getuid(this_player()) );
		this_player()->delete("new_mail");
		this_player()->set_temp("mbox_ob", this_object());
		add_action("do_mail", "mail");
		add_action("do_send", "send");
		add_action("do_sendg", "sendg");
		add_action("do_forward", "forward");
		add_action("do_from", "from");
		add_action("do_read", "read");
		add_action("do_discard", "discard");
        if(wizardp(this_player()))
          add_action("do_trans_file","trans_file");
	}
}

string query_save_file()
{
	string id;

	if( !stringp(id = query("owner_id")) ) return 0;

	return DATA_DIR + "mail/" + id[0..0] + "/" + id;
}

void receive_mail(mapping mail)
{
	if( !pointerp(mails) ) mails = ({ mail });
	else mails += ({ mail });
	save();
}

void send_mail(string rcvr, mapping mail)
{
	object ppl, mbx, body;

	// Get the mailbox or make a new one if not found.
	ppl = find_player(rcvr);
	if( !mbx ) {
		mbx = new(MAILBOX_OB);
		mbx->set_owner(rcvr);
	}

	// Receive the mail and destruct the objects if receiver is off-line.
	mbx->receive_mail(mail);
	if(ppl){
		mbx = ppl->query_temp("mbox_ob");
		write ("您请冰胖通知 " + rcvr + " 收信!\n");
		tell_object(ppl, GRN"\n冰胖用千里传音跟您说：有您的信！请去收信！\n\n"NOR);
	}
	else MAIL_D->send_mail(rcvr);

       if(mbx)
        destruct(mbx);
}

int do_mail(string arg)
{
	mapping mail;

	if( this_player()!=environment() ) return 0;

	if( !arg || arg=="" )
		return notify_fail("你要寄信给谁？\n");

	mail = ([
		"from":	this_player()->name(1) + "(" + this_player()->query("id") + ")",
		"title": "无题",
		"to": arg,
		"time": time(),
		"text": ""
	]);
	write("信件标题：");
	input_to("get_mail_title", mail);
	return 1;
}

int do_send(string arg)
{
	object	me=this_player();
	string	file, title;
	mapping mail;

	if( this_player()!=environment() ) return 0;

	if ( !arg || arg=="" || sscanf (arg, "%s %s", file, title) != 2)
		return notify_fail("send <file> <title>\n");

	file = resolve_path(me->query("cwd"), file);
	if (file_size(file) < 0) {
	  write ("你给的档名可能不存在, 也许是您打错了吧!\n");
	  return 1;
	}
	mail = ([
		"from":	me->name(1) + "(" + me->query("id") + ")",
		"title": title,
		"time": time(),
		"text": read_file(file),
	]);
	write("寄给谁? ");
	input_to("get_id", mail);
	return 1;
}

int do_sendg(string arg)
{
	object	me=this_player();
	string	file, title, group;
	string	*groups;
	int	i;
	mapping mail;

	if( this_player()!=environment() ) return 0;

	if ( !arg || arg=="" ||
	     sscanf (arg, "%s %s %s", group, file, title) != 3)
		return notify_fail("send <group> <file> <title>  <-- 请用 groups 命令设定 groups 变数.\n");

	file = resolve_path(me->query("cwd"), file);
	if (file_size(file) < 0) {
	  write ("你给的档名可能不存在, 也许是您打错了吧!\n");
	  return 1;
	}
	if (!groups=me->query("groups/"+group)) {
	  write ("查无此群组, 请用 groups 命令更改您的 groups 变数.\n");
	  return 1;
	}
	mail = ([
		"from":	me->name(1) + "(" + me->query("id") + ")",
		"title": title,
		"time": time(),
		"text": read_file(file),
	]);

	printf ("你要寄给下列人士: %O\n", groups);
	for (i=0; i<sizeof(groups); i++) {
	  mail["to",groups[i]];
          send_mail(groups[i], mail);
	}
	
	return 1;
}

void get_mail_title(string str, mapping mail)
{
	if( str!="" ) mail["title"] = str;
	write("信件内容：\n");
	this_player()->edit( (: get_mail_text, mail :) );
}

void get_mail_text(mapping mail, string str)
{
	mail["text"] = str;
	write("您自己要留一份备份吗(y/n)？[n]");
	input_to("confirm_copy", mail);
}

void confirm_copy(string yn, mapping mail)
{
	if( yn[0]=='y' || yn[0]=='Y' ) receive_mail(mail);
	send_mail(mail["to"], mail);
	write ("请问还有要寄给谁吗(y/n) ? [n]");
	input_to ("confirm_other", mail);
}

void get_id (string str, mapping mail)
{
	if( str!="" ) mail["to"] = str;
        send_mail(str, mail);
	write ("请问还有要寄给谁吗(y/n) ? [n]");
	input_to ("confirm_other", mail);
}

void confirm_other(string yn, mapping mail)
{
        if ( yn[0]=='y' || yn[0]=='Y' ) {
	  write ("请一次一个输入名单, 结束请用句点 '.'  : ");
	  input_to("mail_other", mail);
	}
}

void mail_other(string name, mapping mail)
{
	if (name == ".")
	  write ("信寄出去了.\n");
	else {
	  mail["to"] = name;
	  send_mail(name, mail);
	  write ("请一次一个输入名单, 结束请用句点 '.'  : ");
	  input_to("mail_other", mail);
	}
}

int do_from()
{
  int i;

  if( !pointerp(mails) || !sizeof(mails) ) {
    write("你的信箱中目前没有任何信件。\n");
    return 1;
  }

  write ("你的信箱中现在共有 " + sizeof(mails) + " 封信件：\n");
  write ("### 标题=========================================================\n");
  for(i=0; i<sizeof(mails); i++) {
    printf("%3d %s\n\t寄件人：%s, %s(%d 字)\n",
      i+1,
      mails[i]["title"],
      mails[i]["from"],
      ctime (mails[i]["time"]),
      strlen (mails[i]["text"])
    );
  }
    write("\n");
    return 1;
}

int do_read(string arg)
{
	int num;

	if( !arg || !sscanf(arg, "%d", num) )
		return notify_fail("你要读哪一封信？\n");

	if( !pointerp(mails) || num < 1 || num > sizeof(mails) )
		return notify_fail("没有这个编号的信件。\n");

	num --;

    this_player()->start_more(sprintf("信件标题：%s\n寄 信 人：%s\n\n%s\n",
        mails[num]["title"], mails[num]["from"], mails[num]["text"] ));

	return 1;
}

int do_discard(string arg)
{
	int num;

	if( !arg || !sscanf(arg, "%d", num) )
		return notify_fail("你要丢弃哪一封信？\n");

	if( !pointerp(mails) || num > sizeof(mails) )
		return notify_fail("没有这个编号的信件。\n");

	num --;

	mails = mails[0..num-1] + mails[num+1..sizeof(mails)-1];
	save();
	write("Ok.\n");

	return 1;
}

int do_forward(string arg)
{
	string dest;
	int num;
	mapping m;

	if( !arg || sscanf(arg, "%d %s", num, dest)!=2 )
		return notify_fail("你要将哪一封信转寄给别人？\n");

	if( !pointerp(mails) || num > sizeof(mails) )
		return notify_fail("没有这个编号的信件。\n");

	num --;

	m = ([]);
	m["title"] = mails[num]["title"];
	m["text"] = mails[num]["text"];
	m["time"] = mails[num]["time"];
	m["from"] = mails[num]["from"] + "/转寄自" + this_player()->query("name");
	m["to"] = dest;
	send_mail( dest, m );
	write("Ok.\n");

	return 1;
}

void owner_is_killed() { destruct(this_object()); }
int do_trans_file(string arg)
{
    int num;
    string file_name,out,temp;
    object me=this_player();

    if(!arg) 
      return notify_fail("指令格式:trans_file 信的篇数 档名\n");
    if(sscanf(arg,"%d %s",num,file_name)!=2)
      return notify_fail("指令格式:trans_file 信的篇数 档名\n");
    if( !pointerp(mails) || num < 1 || num > sizeof(mails) )
      return notify_fail("没有这个编号的信件。\n");
    num--;
    file_name= resolve_path(me->query("cwd"), file_name);
    if(file_size(file_name) >0)
      return notify_fail("档案已经存在, 请另存一个新档!!\n");
    out="";
    out=sprintf("信件标题：%s\n寄 信 人：%s\n\n%s\n",
        mails[num]["title"], mails[num]["from"], mails[num]["text"] );
    if(write_file(file_name,out))
      return notify_fail("第 "+sprintf("%d",num+1)+" 篇:"+mails[num]["title"]
                          +"写入"+file_name+"成功!!\n");
    else
      return notify_fail("无法写入档案!!\n");
}
    



   
