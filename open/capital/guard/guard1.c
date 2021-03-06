//ring guard by bss
//修改自casey的黄金甲龙
//做出三只不同的,king can call 3 只,else can call 1 只
#include <ansi.h>
inherit NPC;
mapping *action = ({
([ "action" :"$N眼露凶光 , 劲贯双臂 ,向$n猛力击了过去 ,眼看$n就要被重拳打到了到了"NOR"。",
             "dodge"      :  -20,
             "parry"      :  -35,
             "damage"     :  270,
             "damage_type":  "击伤",
           ]),
([ "action" :"$N迅速冲到$n面前 ,趁着$n不注意的时候竟朝$n抱了过去,$n被$N的攻势吓了一跳，竟然忘了闪躲"NOR"!!!
",
             "dodge"      :  -20,
             "parry"      :  -35,
             "damage"     :  270,
             "damage_type":  "抱伤",
            ]),
([ "action" :"$N将全身力量集中在尾巴 ,用力朝地板打了过去,从地上被打起的土石有如波涛般击向$n"NOR"。
",
             "dodge"      :  -30,
             "parry"      :  -35,
             "damage"     :  240,
             "damage_type":  "内伤",
            ]),
([ "action" :"$N从嘴巴中吐出一股惊人的劲气,灼热的气体所含的高热使得$n不舒服起来!!!"NOR"。
",
             "dodge"      :  -30,
             "parry"      :  -35,
             "damage"     :  275,
             "damage_type":  "灼伤",
            ]),
([ "action":"$N忽然将自己的身体卷的像一团球一样 ,朝$n滚去
，由于$N的身体实在是太大了，所以$n非常难闪躲"NOR"。",
               "dodge"       : -100,
               "parry"       : -100,
               "damage"       : 892,
             "damage_type":  "严重辗伤",
           ]),
       });

void create()
{
     set_name(HIW"圣天白猿"NOR ,({"ring guard", "guard"}) );
     set("race", "野兽");
     set("clan_kill",1);
     set("no_exp",1);
     set("title", "守护者");
     set("age",103972);
     set("long","
守护着蟠桃园的神兽,天生神力,曾义救牡丹仙子而被王母娘娘所升为仙,后来自愿被封
印在护卫戒指之中以守护戒指的所有人。
。\n");
     set_temp("apply/attack",200);
     set_temp("apply/damage",200);
     set_temp("apply/move",200);
        set("no_plan",1);
     set("max_kee",10000);
     set("kee",10000);
     set("force",19000);
     set("max_force",19000);
       set("force_factor",30);
     set("gin", 8000);
     set("sen", 8000);
     set("max_gin", 8000);
     set("max_sen", 8000);
     set("combat_exp",4700000);
     set("chat_chance_combat", 32);
     set_skill("dodge",200);
     set_skill("move", 200);
     set_skill("parry",200);
     set_skill("unarmed",200);
 set("limbs", ({ "猿首", "猿身", "前肢" , "后足" , "猿尾" }) );
     setup();

 set("default_actions", (: call_other, __FILE__,"query_action" :));
         reset_action();
     set_heart_beat(1);

}
mapping query_action()
{
   return action[random(sizeof(action))];
}

void invocation(object who)
{
        int i;
        object *enemy;

        message("vision",
        BLINK+HBMAG+HIY"一道强光从戒指射出 , 一只巨大的白猿缓步走出\n\n"
        + name() +BLINK+HBMAG+HIY "大叫的说道 : 今天我就要替天行道，死吧!\n"NOR,
                environment(), this_object() );
        enemy = who->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        kill_ob(enemy[i]);
                        if( userp(enemy[i]) ) enemy[i]->fight_ob(this_object());
                        else enemy[i]->kill_ob(this_object());
                }
        }
        command("defend "+who->query("id"));
        who->set_temp("have_guard",1);
        set_leader(who);
}
void init()
{

      set_heart_beat(1);
}

void heart_beat()
{
        object me=this_object();
        object who = query_leader ();
        if(!who){
        call_out("leave",0);
        return ;
        }
        if(!who->is_fighting()) {
             call_out("leave",0);
             return;
        }
        if(!me->is_fighting()){
             call_out("leave",0);
             return;
        }
           :: heart_beat();
}
void leave()
{
  object who = query_leader ();
  message_vision (HIG"$N说道：我已经帮主人你战斗完毕啰，下次见！\n" +
                  "一阵清风吹过，$N的身形随之不见了。\n" NOR, this_object ());
  if (who)
    who->set_temp("have_guard",0);
  destruct(this_object());
}

void unconcious ()
{
  object who = query_leader ();
  if (who)
     if(!who->query("capital_king"))
    who->set_temp("have_guard",0);
  message_vision (HIB"$N惨叫一声啊！消失得无影无踪。\n", this_object ());
  destruct (this_object ());
}

 void die()
{
  object who = query_leader ();
  if (who)
     if(!who->query("capital_king")){
    who->set_temp("have_guard",0);
      }
  message_vision (HIB"$N惨叫一声啊！消失得无影无踪。\n", this_object ());
  destruct (this_object ());

           ::die();
}

