// pklist.c
// 使用于pk大赛时,用来看共杀了几人的指令 by Chan

#include <command.h>
inherit F_CLEAN_UP;
int main(object me)
{
 object *user;
 string desc = "";
 int i, sam = 0;
 user = users();
 desc += "    狂    想  　杀    戮    大    会    成    绩    一    览    表\n\n";
 for(i=0; i<sizeof(user); i++) {
  if( !wizardp(user[i]) ) {
        desc += sprintf("  %10s%6s共杀死:%-3d名玩家",
                        user[i]->name(), "("+user[i]->query("id")+")",
                        user[i]->query("pkgame"));
        if( sam % 2 == 1 ) desc += "\n";
        sam += 1;
    }
 }
 desc += "\n";
 me->start_more(desc);
 return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : pklist
指令说明 :
           这是用来观看你在PK大赛时共杀了多少人的指令。
HELP);
        return 1;
}
