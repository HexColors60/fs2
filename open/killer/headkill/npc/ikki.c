//ikki.c
#include <ansi.h>
inherit NPC;
void do_special();

mapping *action = ({
([     "action"     :   "$N大叫：‘凤  凰  幻  魔  拳’，刹那间$N的身影已在$n的身后了",
                "dodge"      :   -35,
                "parry"      :   -35,
                "damage"     :    150,
                "force"      :    150,
                "damage_type":   "内伤",
           ]),
([    "action"     :   "$N用从沙迦那领悟到的第六感，集中全身的小宇宙，对$n使出了‘凤  翼
天  翔’！！！",
                "dodge"      :    40,
                "parry"      :   -50,
                "damage"     :    250,
                "force"      :    200,
                "damage_type":   "烧伤",
            ]),
   });

void create()
{
        set_name("一辉", ({"ikki"}));
        set("age",16);
        set("long","他是属于青铜级的圣斗士，在三大圣战中一直是护卫着雅典娜女神。\n"
        "而现在的实力是远超过黄金圣斗士，是雅典娜忠心的护卫。\n");
        set("title",HIR"凤凰座"NOR+ HIG"圣斗士"NOR);
        set("gender","男性");
        set("class","圣斗士");
        set("str",30);
        set("cps",30);
        set("kar",30);
        set("spi",30);
        set("int",30);
        set("cor",30);
        set("attitude","herosim");
	set("potential",49999);
        set("max_gin",1000);
        set("max_kee",3000);
        set("max_sen",1000);
        set("gin",1000);
        set("kee",2000);
        set("sen",1000);
        set("combat_exp",1450000);
        set("max_force",10000);
        set("force",10000);
        set("max_atman",5000);
        set("max_mana",5000);
        set("atman",5000);
        set("mana",5000);
        set("force_factor",35);
        set_skill("dodge",200);
        set_skill("unarmed",200);
        set("chat_chance_combat",40);
        set("chat_msg_combat",({
        (: do_special :)
        }));
        set_temp("apply/armor",430);
        set_temp("apply/damage",110);
        setup();
        set("default_actions", (: call_other, __FILE__,"query_action" :));
        reset_action();
}

mapping query_action()
{
        return action[random(sizeof(action))];
}
void do_special()
  {
    object *enemy,target;
    int i;

        enemy=this_object()->query_enemy();
        i=sizeof(enemy);
        target=enemy[random(i)];

                message_vision(
HIR "\n一辉燃烧了全身的小宇宙，大喝：看我的‘凤  翼  天  翔’～～～\n",target);
                message_vision(
HIW "\n一辉的身影突然变成一只火凤凰，快速的由$N的身边飞过！！$N感觉到一股强大的火焰从$N身边经过，等$N回过身来时，一辉已在$N身后等着了！！！\n"NOR,target);
                target->receive_wound("kee",random(210+270));
                COMBAT_D->report_status(target);

  }
