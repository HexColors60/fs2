inherit NPC;
#include <ansi.h>
inherit F_MASTER;
void create()
{
        set_name("莫无乐", ({ "run mou", "run", "mou" }));
        set("title","魔龙魔刀");
        set("nickname", "尸死无涯");
        set("gender", "男性");
        set("age", 40);
        set("attitude", "aggressive");
        set("long","莫无乐是莫无愁的同门，但想篡夺门主之位，而与独孤嵊合作。\n");
        set("str", 45);
        set("cps", 45);
        set("cor", 45);
        set("have_book",1);
        set("mpower",1);
        set("env/魔性六斩","YES");
        set("bellicosity",3000);
        set("combat_exp",5000000);
        set("max_force", 10000);
        set("force", 10000);
        set("max_kee",15000);
        set("max_gin",10000);
        set("max_sen",10000);
        set("force_factor", 30);
        set_skill("force", 120);
        set_skill("parry",120);
        set_skill("dodge",120);
        set("functions/mdragon-dest/level",100);
        set_skill("blade",120);
        set_skill("dragon-blade",120);
        set_skill("powerforce",120);
        map_skill("force", "powerforce");
        map_skill("blade", "dragon-blade");
        map_skill("parry", "dragon-blade");
        set("chat_chance_combat",90);
        set("chat_msg_combat",({
            (: perform_action, "blade.mdragon-dest"   :)
        }));
        set_temp("apply/armor",100);
        set_temp("apply/defense",100);
        setup();
        carry_object("/daemon/class/blademan/obj/mar-blade")->wield();
        carry_object("/open/gblade/obj/dragon_book");
        add_money("gold",10);
}
void heart_beat()
{
 object env,mob,*enemy,target;
 int i;
 mob = this_object();
 env = environment(mob);
if( random(100) > 40)
 {
    enemy=mob->query_enemy();
    if(i=sizeof(enemy)) {
target=enemy[random(i)];
    if( env == environment(target) )
    {
message_vision(HIC"
莫无乐表情狰狞，施展出魔龙魔刀‘屠人千万～血流遍野’\n"+
"$N闪避不及，被打中要害，血流满地\n"NOR,target);
      target->receive_damage("kee",600,mob);
      COMBAT_D->report_status(target,1);
    }
 }
}
   ::heart_beat();
}
