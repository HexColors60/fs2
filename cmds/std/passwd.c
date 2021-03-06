// passwd.c

inherit F_CLEAN_UP;

int check_passwd (string);
void create() { seteuid(getuid());}

int main(object me, string arg)
{
  object ob;

  if( me != this_player(1) ) return 0;

  ob = me->query_temp("link_ob");
  if( !ob ) return 0;
  while( ob && ob->is_character() ) ob = ob->query_temp("link_ob");

  write("为了安全起见，请先输入您原来的密码：");
  input_to("get_old_pass", 1, ob);
  return 1;
}
void get_old_pass(string pass, object ob)
{
  string old_pass;

  write("\n");
  old_pass = ob->query("password");
  if( crypt(pass, old_pass)!=old_pass ) {
    write("密码错误！\n");
    return;
  }
  write("请输入新的密码：");
  input_to("get_new_pass", 1, ob );
}

void get_new_pass(string pass, object ob)
{
  if (!check_passwd (pass)) {
    write ("密码必须至少含有一个普通英文字母跟一个非普通英文字母.\n");
    write("\n请再输入一次新的密码：");
    input_to("get_new_pass", 1, ob );
  }
  else {

    write("\n请再输入一次刚刚的密码，以资确认：");
    input_to("confirm_new_pass", 1, ob, crypt(pass,0));
  }
}

void confirm_new_pass(string pass, object ob, string new_pass)
{
  write("\n");
  if( crypt(pass, new_pass)!=new_pass ) {
    write("对不起，您输入的密码并不相同，继续使用原来的密码。\n");
    return;
  }
  if( !ob->set("password", new_pass) ) {
    write("密码变更失败！\n");
    return;
  }
  ob->save();
  write("密码变更成功。\n");
}
//修改by bss
//我只会用笨方法
int check_passwd (string passwd)
{
  int   i, n, word,cnt;
  string txt;
  if ((n = strlen (passwd)) < 5) return 0;

  cnt=0;
  for(i=0;i<sizeof(passwd);i++)
  {
    txt=sprintf("%d",passwd[i]);
    sscanf(txt,"%d",word);
    if((word <= 122 && word >= 97) ||
       (word <= 90 && word >= 65))
      cnt++;
  }
  if(!cnt) return 0;
  else if(cnt==sizeof(passwd)-1) return 0;
  else return 1;

}
int help(object me)
{
  write(@HELP
指令格式 : passwd
指令说明 :
           这个指令可以修改你的人物密码。
         密码的目的是在保护自己的人物不被他人任意使用，因此，
         必须适当的设定密码。通常密码不得过于简单。系统基本上
         会要求你不能使用下列情形当密码：
             1.  太短，目前设定是不能比五个字元短。

             2.  全部都是英文字，至少必须包括数字或特殊符号。
             3.  全部都是特殊符号，如全部都是数字。
HELP
    );
    return 1;
}
