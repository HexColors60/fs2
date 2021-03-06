// copy from 天地云龙
#include <ansi.h>
#include <combat.h>
inherit NPC;
int spatt();
void create()
{
        seteuid(getuid());
        ::create();
        set_name("护法战龙", ({ "tesin dragon", "dragon" }) );
        set("long", "传说中..由天地破魔阵所衍生出的护法战龙，当阵中有任何生物杀气过高时便会出现杀敌。\n");
        set("race","野兽");
        set("gender","雄性");
        set("attitude", "friendly");
        set("max_gin", 4000);
        set("max_sen", 8000);
        set("max_kee", 4000);
        set("max_atman", 100);
        set("atman", 100);
        set("max_mana", 100);
        set("mana", 100);
        set("max_force", 6000);
        set("force", 6000);
        set("force_factor",22);
        set("str", 30);
        set("cor", 30);
        set("cps", 25);
        set("limbs",({"头部","胸部","腹部","前爪","后爪","尾巴"}));
        set("verbs",({"bite","claw"}));
        set ("chat_chance_combat",30);
        set ("chat_msg_combat", ({(: spatt :)}));
        setup();
}
void callset(object who)
{
        int pp;
        object me = this_object();
        pp=who->query("combat_exp");
        set("combat_exp",pp*3+1000);
        set_temp("apply/defend",pp/50);
        set_temp("apply/attack",pp/50);
        set("max_kee",pp/600);
        set("kee",pp/600);
}
int heal_up()
{
        if (!is_fighting() ) {
             message_vision (HIB"凶暴的$N渐渐平息下来，再度变为云雾。\n"NOR, this_object ());
             destruct(this_object());
             return 1;
        }
        return ::heal_up() + 1;
}
void unconcious ()
{
        message_vision (HIB"$N长嚎一声，消失的无影无踪。\n"NOR, this_object ());
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
