#include <ansi.h>
inherit NPC;
void do_special();

mapping *action = ({
([     "action"     :   "$N轻声说道：‘我正在snoop $n喔’，刹那间$N的身影已在$n的身后了",
                "dodge"      :   -35,
                "parry"      :   -35,
                "damage"     :    150,
                "force"      :    150,
                "damage_type":   "内伤",
           ]),
([    "action"     :   "$N轻声说道：‘给我3秒钟，我给你smash’，一道落雷击向$n。",
                "dodge"      :    40,
                "parry"      :   -50,
                "damage"     :    250,
                "force"      :    200,
                "damage_type":   "烧伤",
            ]),
   });

void create()
{
        set_name("懒人舞", ({"lazy dancer","dancer","lazy"}));
        set("age",16);
        set("long","他是所有的巫师当中最懒的一位，整天无所事事，
最近才去找到一份‘可以偷懒’的工作。\n");
        set("title",HIR"懒惰成性"NOR+ HIG"巫师"NOR);
        set("gender","男性");
        set("class","巫师");
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
        set("combat_exp",100000);
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
HIR "\n懒人舞懒懒的叫了一声："+target->query("name")+"再不回应～～～，我要purge "+target->query("id")+"啰。\n",target);
                message_vision(
HIW "\n懒人舞躺了下来，手指挥挥，出现了purge "+target->query("id")+" 的讯息...\n"NOR,target);
                target->receive_wound("kee",random(210+270));
        COMBAT_D->report_status(target, 1);

  }


void unconcious ()
{
 object me=query_temp("last_damage_from");
if(!present("fight_card",me))
{
tell_object(me,"\n\n系统：由于你没携带晶片，所以无法记录战绩。\n");
destruct (this_object ());
}
else
if(!me->query("quest/start_game"))
{
tell_object(me,"\n\n系统：由于你没有正式登记，资料无法传输。\n");
destruct (this_object ());
}
else
if(me->query("quest/start_game")< 12)
       {
        message_vision(HIY"
恭喜"HIW+me->query("name")+HIY"挑战"HIG"‘"HIR"第十一层试炼□塔"HIG"’"HIY"通过！！

"HIW"希望"+me->query("name")+"能不负众望，勇闯"HIG"‘"HIY"第十二层试炼□塔"HIG"’"HIW"。
	"NOR,me);
	me->set("quest/start_game",12);
        destruct (this_object ());
       }
{
        :: unconcious();
	tell_object(me,HIW"系统：你已经通过测试，系统不做任何更改。\n"NOR);
	destruct(this_object());
}
}


