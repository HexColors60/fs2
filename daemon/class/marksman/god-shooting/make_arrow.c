#include <ansi.h>
inherit F_FUNCTION;
int do_make_arrow(object me,int lv);
inherit SSERVER;
int perform(object me,object target)
{
int lv;
object ob;
me=this_player();
if(me->query("functions/ten_kee/level") < 50)return notify_fail("等级不够!!\n");
lv = me->query("functions/make_arrow/level");
if(me->query("force") < (lv * 3))return notify_fail("你的气不够,休息一下再用吧!!\n");
        if(objectp(ob = present("force arrow", me)))
                return notify_fail("你的箭已经够了!!\n");
        if(me->is_busy()) return notify_fail("你正在忙喔!!\n");
        if(me->is_fighting()) me->start_busy(1);
message_vision(HIW"$N紧握着双手，运气一发劲，渐渐的手中出现了一道白烟!!\n"NOR,me
);
me->start_call_out((:call_other,__FILE__,"do_make_arrow",me,lv:),2);
         me->start_busy(1);
me->add("force",-(lv * 3));
if(me->query("force") < 0 ) me->set("force",0);
        return 1;
}
int do_make_arrow(object me,int lv)
{
object obj;
message_vision(HIY"一瞬间，"+chinese_number(1+(lv*3))+"道箭气从$N手中飞越而出
\n"NOR,me);
obj=new("/daemon/class/marksman/iceforce/forcearrow.c");
obj->set("name",HIY"云气箭"NOR);
obj->set_amount(1+(lv*3));
obj->move(me);
if(query_function("make_arrow") < 100)
              {
function_improved("make_arrow",random(500));
              }
return 1;
}

