#include <weapon.h>
#include <ansi.h>
inherit DAGGER;
void create()
{
        seteuid(getuid());
        set_name(HIC"白虎匕首"NOR,({"bihu"}));
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else 
        {
                set("unit", "把");
               set("long","匕首上刻有白虎之图腾，仿佛要吃了人似的感觉．\n");
                set("value",10000);
                set("material", "steel");
                set("no_sell",1);
                set("no_auc",1);
                set("wield_msg",HIC"$N将$n握在手上，感到全身似乎充满劲道。\n"NOR);
                set("unwield_msg",HIC"$N画出一道银花，将$n放回身边小袋中。\n"NOR);
        }
        init_dagger(63);
        setup();
}

mixed hit_ob(object me)
{
  object user=this_player();
  object *enemy=user->query_enemy();
  int i=random(sizeof(enemy));
  int be = user->query("bellicosity")/10;
  int inn = user->query_skill("shadow-kill",1);
  int sp = user->query_skill("magic",1);
  int bb = user->query_skill("dodge",1);

 if (this_player()->query("class") != "killer")
	return 0;

 if( user->is_fighting() && query("equipped") )
  {//下一行是检查有多少机会驱动特攻，约50％
   //因为使以自己的乱数，如自己的杀气是1000点
   //乱数介于 0-1000点之间，所以一定不大于 1000
   //所以把乱数出来的值*2，造成如果乱数出来的值大于500，就可以大于1000
    if( random(100) > 50 )
    {
       if( random(bb*2)  > enemy[i]->query_skill("dodge",1) )
     {//注意，为了要强调dodge的效用，（现在FS根本不重视）
      //所以，故意以dodge来决定命中度，如果你的dodge大于对方一倍，命中度几乎100％
      //相对的，如果对方的dodge大于你两倍的话，命中度几乎就是0％
      message_vision(HIC"白虎图腾化成白虎幻影,包围$N令其动作迟缓!!"NOR,enemy[i]);
      enemy[i]->start_busy(1);
     }
      else
      	message_vision(HIW"由白虎匕首唤出的幻影，被$N识破根本无效\n"NOR,enemy[i]);
    }
  }
  return;
}
