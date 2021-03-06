#include <ansi.h>
inherit F_CLEAN_UP;
inherit F_GUILDCMDS;
int exert(object me, object target)
{
        mapping poison_type = ([
                        "snake" : "snake_poison",
                   "firefinger" : "fire_poison",
                        "rose"  : "rose_poison",
                        "dark"  : "dark_poison",
                        "five"  : "five_poison",
                        "lyssa" : "lyssa",
                        ]);
        mapping poison_name = ([
                        "snake" : "蛇毒",
                   "firefinger" : "火云邪毒",
                        "rose"  : "火玫瑰毒",
                        "dark"  : "深宫奇毒",
                        "five"  : "五毒神掌",
                        "lyssa" : "狂犬病",
                        ]);
        mapping need_lv = ([
                        "snake" : 10,
                   "firefinger" : 20,
                        "rose"  : 30,
                        "dark"  : 50,
                        "five"  : 60,
                        "lyssa" : 60,
                        ]);
        mapping fp_cost = ([
                        "snake" : 1,
                   "firefinger" : 1,
                        "rose"  : 3,
                        "dark"  : 4,
                        "five"  : 6,
                        "lyssa" : 6,
                        ]);
        string type;
        int my_lv = me->query_skill("shinnoforce", 1);
        int factor, need, total, my_force = me->query("force");
        if(!type=me->query("env/cure_poison"))
        return notify_fail("请先设定欲解何种毒素(set sure_poison +poisoname)。\n");
        if(undefinedp(poison_type[type]) || my_lv < need_lv[type])
        return notify_fail("你并不会解这种毒。\n");
        if(my_force < 50 )
        return notify_fail("你内力不够，无法逼毒。\n");
        if( me->is_fighting() )
        return notify_fail("战斗中不能逼毒。\n");
        me == target ? factor = 3 : factor = 2 ;
        total = target->query_condition(poison_type[type]);
        if((need=total*fp_cost[type])!=0)
{
need = need / factor;
if(my_force < need) {
message_vision(HIW"$N运起"HIY"琉璃心诀"HIW"，费尽内力帮$n逼出一些"+poison_name[type]+"。\n",me,target);
me->set("force",0);
target->apply_condition(poison_type[type],total-(int)my_force*factor/fp_cost[type]);
                        }
                else {
message_vision(HIW"$N席地盘腿而坐,运起心法中的奥义"HIY"琉璃心诀"HIW"把"+poison_name[type]+"给逼出体外。\n"NOR, me);
       me->add("force", -need);
       target->apply_condition(poison_type[type], 0);
                    }
                return 1;
        }
    if(me==target)
        return notify_fail("你并没有中这种毒。\n");
    else
        return notify_fail("他并没有中这种毒。\n");
}


