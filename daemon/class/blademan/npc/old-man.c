#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;
void create()
{
        seteuid(getuid());
   set("score",10000000);
        set("long","神秘老者\n");
        set("gender","男性");
        set_name("神秘老者",({"old man","man"}));
        set("combat_exp",5000000);
        set("attitude","heroism");
        set("bellicosity",3000);
        set("age",70);
        set("max_force",35000);
        set("force",35000);        
     set("max_kee",50000);
        set("max_gin",10000);
        set("max_sen",10000);
        set("str", 35);
        set("cor", 35);
        set("cps", 30);
        set("per", 30);
        set("int", 30);
        set("force_factor",40);
        set_skill("dodge",150);
        set_skill("force",150);
        set("clan_kill",1);     //不能派杀手追杀
    set("mpower",1);
        set_skill("move",150);
        set_skill("parry",150);
        set_skill("mogi-steps",150);
        set_skill("firestrike",150);
        set_skill("unarmed",150);
        set_skill("literate",150);
        set_skill("fireforce",150);
        map_skill("force","fireforce");
        map_skill("unarmed","firestrike");
        map_skill("dodge","mogi-steps");
        map_skill("move","mogi-steps");
        map_skill("parry","firestrike");
        set("functions/gold-fire/level",100);
        set("quest/gold-fire",1);
        set("quest/new_gold_fire",1);
        set_temp("apply/defense",100);
        set_temp("apply/armor",100);
        setup();
        carry_object("/open/snow/obj/figring")->wield();
        add_money("gold",50);
}


void greeting(object me)
{
 write(HIY"
 神秘老者发出慑人心神声音：「来者是谁!?”
「能来到这里，真不简单！不过刀冢进入方法，我是不会跟你说的！”
"NOR); 
}
int accept_fight(object who)
{
 write(HIY"神秘老者冷冷的说：「要命的话就快走吧！”\n"NOR);
 return 0;
}

int accept_kill(object who)
{
 who = this_player();
 command("say 刀冢进入方法！打败我再说吧！");
 command("perform fireforce.gold-fire");
 kill_ob(who);
 return 1;
}


void die()
{
   object winner = query_temp("last_damage_from");
   string name = winner->query("name");
log_file("mblade/KILL_OLD_MAN", sprintf("%s(%s) 打败 神秘老者 on %s\n"
,name,winner->query("id"), ctime(time()) ));
   tell_object(winner,HIG"\n
神秘老者说：好吧...既然你已经赢了我了，我就把进入刀冢
的方法交给你了，反正这么多年来我虽知方法却没有六行石
也是无功于返，其入刀冢方法就是在此处(to-jump hole)。
\n"NOR);
   winner->set_temp("can_jump",1);
  :: die();
}                    
void heart_beat()
{
object me,room,*target;
int i,j;
me=this_object();
room=environment(me);
target=me->query_enemy(room);
if(i=sizeof(target)) {
if(random(100) > 30)
{
if(random(9) >= 4)
{
message_vision(HIY"神秘老者仰天长啸，顿时你被强力的音波一扫脑门！\n"NOR,me);
for(j=0;j < i;j++) {
target[j]->start_busy(1);
target[j]->add("kee",-1500); }
   }
   else
   {
message_vision(HIC"神秘老者仰天一笑，瞬时内息稳固。\n"NOR,me);
me->receive_curing("kee",2500);
me->receive_heal("kee",2500);
    me->delete_busy();
    me->clear_condition();
   }
  }
}
  ::heart_beat();
  }

