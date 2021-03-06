// copy from 天地云龙
#include <ansi.h>
#include <combat.h>
inherit NPC;
int spatt();
void create()
{
        seteuid(getuid());
        ::create();
        set_name("试炼武者", ({ "man", "man" }) );
        set("long", "仙剑试炼谷的护法武者。\n");
	set("class","swordsman");
        set("family/family_name","仙剑派");
        set("combat_exp",1000000);
        set("attitude","heroism");
        set("bellicosity", 1000);
        set("max_gin", 5000);
        set("max_sen", 5000);
        set("max_kee", 7500);
        set("max_atman", 100);
        set("atman", 100);
        set("max_mana", 100);
        set("mana", 100);
        set("max_force", 2000);
        set("force", 1000);
        set("force_factor",10);
        set("str", 30);
        set("cor", 30);
        set("cps", 25);
        set("get_sha_sp",1);
        set_skill("shasword",90);
        set_skill("shaforce",80);
        set_skill("sha-steps",100);
        set_skill("force",70);
	set_skill("dodge",80);
	set_skill("parry",120);
	set_skill("sword",120);
        map_skill("dodge","sha-steps");
        map_skill("force","shaforce");
        map_skill("sword","shasword");
        map_skill("parry","shasword");
        set ("chat_msg_combat", ({(: spatt :)}));
        setup();
    carry_object("/open/gsword/obj/spsword-2.c")->wield();

}
int heal_up()
{
        if (!is_fighting() ) {
             message_vision (HIC"凶暴的$N渐渐平息下来，再度变为云雾。\n"NOR, this_object ());
             destruct(this_object());
             return 1;
        }
        return ::heal_up() + 1;
}
void unconcious ()
{
   object winner = query_temp("last_damage_from");
    if(!winner) :: unconcious();
    {
        winner->add("quests/test",1);
        message_vision (HIC"$N咻的一声，消失的无影无踪。\n"NOR, this_object ());

    }
  destruct (this_object ());
 }

int spatt()
{
        object me = this_object(), victim, *enemy = query_enemy();
        int i;
        if( !i = sizeof(enemy) )
                return 0;
        victim = enemy[random(i)];
        message_vision (HIB"$N一声怒吼，一道闪电向$n直劈而来。\n"NOR,me,victim);
        victim->receive_damage("kee",100);
        COMBAT_D->report_status(victim);
        return 1;
}
