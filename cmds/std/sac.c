// sac.c  可以将不需要的 物品 和 尸体奉献给天神 不过似乎战斗中也可以使用
// 以后有机会再来修         By Anmy    97/11/22
// 二版修正 战斗中及 昏迷的mob 无法 sac 已设定好  By Anmy  98/5/22
// 三版修正能 sac all by swy
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object tp, string str)
{
   object ob, *inv;
	int val,i;
	tp = this_player();
	if(!str) return notify_fail("你想奉献什么？\n");
seteuid(getuid());
if(str=="all") {
inv = all_inventory(environment(tp));
	for(i=0;i<sizeof(inv);i++)
	{
		if(living(inv[i])) continue;
		if(inv[i]->is_fighting()) continue;
if(in_edit(inv[i])||in_input(inv[i])||inv[i]->query_temp("netdead")) continue;
if(inv[i]->query("no_sac")) continue;
if(userp(inv[i])) continue;
if(inv[i]->query("capacity")) continue;
    message_vision(HIC"$N将"+inv[i]->short()+"奉献给大神。\n"NOR, tp);
	destruct(inv[i]);
	}
	return 1;
        }
	ob = present(str, environment(tp));
	if(!ob) return notify_fail("你找不到这样东西！\n");
        if (tp->is_fighting()) return notify_fail("你上个动作还没完成。\n");
   if(living(ob)) return notify_fail("你不能奉献活的生物！\n");
   if(ob->query("no_sac",1)) return notify_fail("你不能把这个奉献掉！\n");
   if(ob->is_fighting()) return notify_fail("你正在战斗中！无法分心去奉献\n");
   if(userp(ob)) return notify_fail("你不能奉献玩家!!\n");
   if(ob->query("capacity") > 1) //板子用的
   return notify_fail("留言板不能奉献!!!!\n");
        if (in_edit(ob) || in_input(ob) || ob->query_temp("netdead"))
          return notify_fail (ob->name() +"正在忙呢..\n");
message_vision(HIC"$N以很遗憾的心情将"+ob->short()+"归入尘土风逝。\n"NOR,tp);
//修正sac的人可以拿到潜能...一点.以提高sac的情形
	write(tp->name()+"的善心, 大神给你一文钱做为赏赐。\n");
	destruct(ob);
	new("/obj/money/coin")->move(tp);
	return 1;
}

void help() {
  write(" 技能用法 : sac <地上物品> \n\n");
  write(" 将不用的东西奉献给大神, 大神会给予报酬。\n\n");
  return;
} 
