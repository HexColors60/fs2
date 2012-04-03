//更改玩家密码的指令by bss
inherit F_CLEAN_UP;

private void check1(string str,object me,object ob);

void create()
{
        seteuid(getuid());
}
int main(object me, string arg)
{
        string name;
        object ob;

        if( !arg || arg=="" )
                return notify_fail("指令格式：chpw 玩家id \n");

        name=arg;
        ob = new(LOGIN_OB);
        ob->set("id",arg);
        if(!ob->restore())
        {
                write("没有这个使用者!!!\n");
                destruct(ob);
                return 1;
        }
//        if(wizhood(ob)=="(admin)"||wizhood(ob)=="(manager)")
//        {
//                printf("%s\n",SECURITY_D->get_status(name));
//                printf("你没有更改%s(%s)密码的权力!!!\n",ob->query("name"),ob->query("id"));
//                return 1;
//        }
        printf("你确定要更改%s(%s)的密码吗??(y/n)\n",ob->query("name"),ob->query("id"));
        input_to("check1",me,ob);
        return 1;
}
private void check1(string str,object me,object ob)
{
        string pass;

        if( str=="" ) {
        printf("你确定要更改%s(%s)的密码吗??(y/n)\n",ob->query("name"),ob->query("id"));
        input_to("check1",me,ob);
        return ;
        }

        if( str[0]!='y' && str[0]!='Y' ) {
                write("你放弃了更改密码。\n");
                return ;
        }
        else {
                write("依据规定,该玩家的密码将被设为12345 !!!\n");
                pass="12345";
                ob->set("password",crypt(pass,0));
                ob->save();
                log_file( "CHANGEPW", sprintf("%s(%s) 更换 %s(%s) 的密码在 (%s)\n",
                  me->query("name"),me->query("id"),
                  ob->query("name"), ob->query("id"),
                   ctime(time()) ) );
                write("密码更改完毕!!!\n");
                destruct(ob);
                return ;
        }
}


int help()
{
        write(@TEXT
指令格式：chpw 玩家id

这是因为总是有些玩家会把密码忘了,所以才设的指令
指令中内定该玩家的密码将被设为12345....

TEXT
        );
        return 1;
}
