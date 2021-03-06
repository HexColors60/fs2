#include <ansi.h>
#include <weapon.h>
inherit SWORD;
object user;
int sp,max;
void create()
{
     set_name( HIR"血咒"NOR,({"blood_sword","sword"}) );
     set_weight(7500);
     if( clonep() )
               set_default_object(__FILE__);
     else {
            set("long","血魔的专用配剑，在战斗中可利用其血气压制对手.\n"
                      +"释放血气: sword_blood,检查威力:sword_check\n"
                      +"会于战斗中自动集气,集气越久,威力越强.");
            set("unit", "件");
            set("value",20000);
            set("material","steal");
            set("wield_msg", HIR"$N从将$n"+HIR"由画满符咒的剑鞘中抽出.\n");
            set("unwield_msg", "$N把$n插回剑鞘里.\n");
           }
        init_sword(99);
        setup();
}

void init()
{
     add_action("do_wield","wield");
     add_action("do_check","sword_check");
     add_action("do_fire","sword_blood");
}

int do_wield(string str)
{
     ::wield();
     if( query("equipped") )
     {
        user = this_player();     // 取得使用者
        sp = 0;
        max = user->query_skill("blood_sword",1);
        set_heart_beat(1);
     }
}
int do_check()
{

 if( query("equipped") )
   write(HIR"血咒储存的血气有 "+sp+" .\n"NOR);


 return 1;
}
void heart_beat()
{
  if( user->is_fighting() && query("equipped") && sp < max )
  {
   sp++;
  }
     return;
}

int do_fire()
{
  object *enemy;
  int i,pp;

  if( max < 80)
  {
    write("你的剑术太低,无法控制血咒.\n");
    return 1;
  }

  if( user->is_fighting() && query("equipped") )
  {
    enemy=user->query_enemy();
    i=random(sizeof(enemy));
    if( environment(user) == environment(enemy[i]) )
    {
           if( random(250)+max > enemy[i]->query_skill("dodge") )
      {
        if( sp < 2)
        {
          message_vision("一小道血气由血咒串出，但由于血气不足，未到"
                            +"$n身边时已经消失!!!\n",user,enemy[i]);
          sp=0;
          return 1;
        }else if( sp < 10 )
        {
          message_vision(HIR+"一道血气由血咒射出,射向$n!!!\n"
                         +NOR,user,enemy[i]);
          pp = sp;
        }else if( sp < 20 )
        {
          message_vision(HIR+"$N手中血咒天一划,数道血气由血咒直奔上天，并朝向"
                         +"$n射去!!!\n"+NOR,user,enemy[i]);
          pp=sp*2;
//          enemy[i]->apply_condition("burn",(int)sp*1.5);
        }else if( sp < 30)
        {
          message_vision(HIR+"$N手中长剑一挥,只见天上地上,到处血红一片,"
                      +"$n陷入了血海中中!!!\n"+NOR,user,enemy[i]);
          pp=sp*3;
          enemy[i]->apply_condition("hellfire",1);
        }else if( sp < 40)
        {
          message_vision(HIR+"$N祭起血咒,只见四周景物开始淡去,无数血气从朦胧"
                            +"中突然透出,一招血雾刃直接袭击$n!!\n"
                            +NOR,user,enemy[i]);
          pp=sp*4;
          enemy[i]->apply_condition("hellfire",2);
        }else{
          message_vision(HIR+"$N陷入疯狂，将手中血剑刺进另一只手中，只见血咒"
                            +"在吸收$N的鲜血后，散发出耀眼光芒，并释放出无数"
                            +"血气包围$n!!!\n"NOR,user,enemy[i]);
          user->receive_damage("kee",300);
          pp=sp*7;
          enemy[i]->start_busy(1);
          enemy[i]->apply_condition("hellfire",3);
        }
        sp=0;
        enemy[i]->receive_wound("kee",pp,user);
        COMBAT_D->report_status(enemy[i], 0);
      }else
      {
        message_vision(HIR+"$N尝试使用血咒..但血咒里都不理他..\n"+NOR,user);
        sp=sp*0.7;
      }
     }
   }
  return 1;
}

