
#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIG"极杀雷凤凰"NOR,
        ({"lighting-phoenix","lighting","phoenix",}));
        set("mount_id","lighting-phoenix");
        set("age",12);
        set("race","野兽");
        set("score",1000000);
        set("gender","女性");
set("level",1);
        set("rider","phoenix");
        setup();
}
string *dodge_msg = ({
HIG"$n"HIG"的绿色陆行鸟佯装要逃走"GRN"，"HIG"趁$N"HIG"不注意的"GRN"，"
HIG"一个瞬间$n"HIG"已躲过$N"HIG"的攻击"GRN"。\n"NOR,
HIG"$n"HIG"往上一跳"GRN"，"HIG"在此瞬间白色陆行鸟往前冲"GRN"，"HIG"攻其不意"GRN"。\n"NOR,
});
string query_dodge_msg()
{
        return dodge_msg[random(sizeof(dodge_msg))];
}
