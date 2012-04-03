inherit NPC;
#include <ansi.h>
void create()
{
        set_name("五爪金龙", ({ "npc05" }) );
        set("long",
                "这是一只生长在璃山的五爪金龙，牠身上的鳞片闪闪发着耀眼的光芒。\n");

        set("race", "野兽");
        set("age", 600);
        set("attitude", "friendly");

        set("max_gin", 4000);
        set("max_kee", 6000);
        set("max_sen", 3000);

        set("str", 80);
        set("cor", 50);
        set("spi", 70);
        set("int", 40);

        set("limbs", ({ "头部", "身体", "前爪", "后爪", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );

        set_temp("apply/attack", 100);
        set_temp("apply/damage", 130);
        set_temp("apply/armor", 60);

        set("combat_exp", 1000000);
        setup();
        carry_object("/u/u/unfinished/ss.c");
}

int heal_up()
{
        if (!is_fighting() ) {
             message_vision (HIW"系统：战斗停止，$N回收中，。\n"NOR, this_object ());
             destruct(this_object());
             return 1;
        }
        return ::heal_up() + 1;
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
if(me->query("quest/start_game")< 6)
       {
        tell_object(users(),HIY"
恭喜"HIW+me->query("name")+HIY"挑战"HIG"‘"HIR"第五层试炼□塔"HIG"’"HIY"通过！！

"HIW"希望"+me->query("name")+"能不负众望，勇闯"HIG"‘"HIY"第六层试炼□塔"HIG"’"HIW"。
	"NOR);
	me->set("quest/start_game",6);
        destruct (this_object ());
       }
{
        :: unconcious();
	tell_object(me,HIW"系统：你已经通过测试，系统不做任何更改。\n"NOR);
	destruct(this_object());
}
}