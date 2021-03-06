#include <ansi.h>
inherit F_MORE;
inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
        string *cls,*guild_name;
        mapping master;
        mapping guild;
        int guild_cnt=0;
        int i,j;
        string msg="◎ 狂想空间\n";
        seteuid(getuid());
        guild=GUILD_D->query_translate();
        cls=keys(guild);
        for(i=0;i<sizeof(cls);i++)
        {
                if(cls[i]!="none")
                msg+=sprintf("%s",to_chinese(cls[i]));
                else msg+="【 平  民 】";
                if(sizeof(guild[cls[i]])==0)
                        msg+=sprintf("    目前没有任何派门。\n");
                else
                {
                        guild_name=keys(guild[cls[i]]);
                        master=guild[cls[i]];
                        if(master[arg])
                        {
                                if(file_size("/doc/guild/"+arg)<=0)
                                        return notify_fail("目前没有这个门派的说明。\n");
                                else start_more(read_file("/doc/guild/"+arg));
                                return 1;
                        }
                        for(j=0;j<sizeof(guild_name);j++)
                        {
                                if(j!=0) msg+="            ";
                                msg+=sprintf("    %-16s%-20s\n",guild_name[j],"门派首领："+master[guild_name[j]]);
                                guild_cnt++;
                        }
                }
        }
        msg+="\n ";
        msg+=sprintf("狂想空间目前共有 %d 个门派。\n",guild_cnt);
        msg+=NOR;
        start_more(msg);
        return 1;
}
 
 
int help(object me)
{
        write(@HELP
指令格式 : guild | [门派名称]
指令说明 :
           这个指令让你可以查看目前有几个门派。
           若指定门派名称则可查看门派说明。
HELP
    );
    return 1;
}
