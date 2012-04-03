#include <ansi.h>
#include <armor.h>
inherit CLOTH;
object user;
int kar;
void create()
{
   set_name("[1;37m□[0;37mg[1;37m□[0;37m□[1;37m□[0;37m□[1;37m□[0;37m□[0m",({"wind armor","armor"}));
   set_weight(20000);
   if( clonep() )
        set_default_object(__FILE__);
   else {
   set("no_sell",1);
   set("no_auc",1);
   set("no_drop",1);
   set("unit","件");
   set("value",150000);
   set("material", "cloth");
   set("long","这是一件由天上诸神使用风岩石所打造的神奇盔甲。\n");
   set("unequip_msg", "$N将$n脱掉，"HIW"狂风盔甲"NOR"的力量随之逝去。\n");
   set("armor_prop/armor",22);
   set("armor_prop/stabber",10);
}
        setup();
}
int query_autoload()
{
 return 1;
}
int init()
{
    add_action("do_wear","wear");
}
int do_wear(string str)
{
::wear();
 if( query("equipped") )
 {
   user = this_player();
message_vision("$N将[1;37m□[0;37mg[1;37m□[0;37m□[1;37m□[0;37m□[1;37m□[0;37m□[0m穿上，"HIW"狂风盔甲"NOR"的力量贯注在$N身中。\n",user);
   kar=user->query("kar");
   set_heart_beat(1);
 }
}
void heart_beat()
{
  object *enemy,who;
  int i,dodge;
  if( !objectp(user) )
  { set_heart_beat(0);
     return;
  }
  if( user->is_fighting() && query("equipped") )
  {
    if( random(kar+70) > 70)  // 运气高,机率高
    {
     enemy=user->query_enemy();
     i=random(sizeof(enemy));
     dodge = enemy[i]->query_skill("dodge");
     if( random(180) > dodge)
     {
message_vision(HIW+"忽然间狂风急起此时,此时无数的旋风从[1;37m□[0;37mg[1;37m□[0;37m□[1;37m□[0;37m□[1;37m□[0;37m□[0m"HIW"中发出,瞬间将$N卷住无法动弹!!!\n"+NOR,enemy[i]);
      enemy[i]->start_busy(1);
     }else{
message_vision(HIW+"忽然间狂风急起此时,此时无数的旋风从[1;37m□[0;37mg[1;37m□[0;37m□[1;37m□[0;37m□[1;37m□[0;37m□[0m"HIW",$N瞬间看出风的纹路,避了过去..\n"+NOR,enemy[i]);
  }
    }
  }
  return;
}
