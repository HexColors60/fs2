//新浑天宝鉴
//修正 by swy
#include <ansi.h>
inherit F_FUNCTION;
inherit F_CLEAN_UP; 
void remove_effect(object me, int skill);
int perform(object me, object target)
{
        string env;
        int skill,fun1;
        skill=me->query_skill("superforce",1);
        env=me->query("env/superforce");
        if(me->query("class")!="prayer"&&me->query("id")!="swy")
        return notify_fail("非圣火不能用。\n");   
        if(env=="YES"||(env!="white"&&env!="gen"&&env!="ice"&&env!="purple"&&env!="nine"
           &&env!="black"&&env!="bluesea"&&env!="goldsun"&&env!="blood"&&env!="green"))
        return notify_fail("你要运哪一种心法呢。\n");   
        if( (string)me->query_skill_mapped("force")!= "superforce" )
        return notify_fail("浑天心法气劲要用浑天心法来运作。\n");    
        if( skill<20 )
        return notify_fail("你浑天心法等级不够最少要 20。\n");    
        if (me->query("force") < 300)
        return notify_fail("你的内力不够，不能运起浑天心法。\n");
        if(me->query_temp("mixforce")==1)
        return notify_fail("你已经在使用浑天心法。\n");
        if( skill>=250 ) skill=250;
        me->add("force",-250);
if (skill >= 20 && env=="white") {
        fun1=me->query("functions/white/level");
        if(!fun1) me->set("functions/white/level",1);
        skill=(int)skill/5;
        message_vision(
        HIC "$N运起浑天心法第一层的"HIW"白云烟"HIC"，身上涌出如云气般的内劲形成无数的气旋!!\n" NOR,me);
        me->set_temp("superforce",1);
        me->set_temp("mixforce",1);
        me->add_temp("apply/force",   skill);
        me->add_temp("apply/move",    skill);
        me->add_temp("apply/dodge",   skill);
        me->add_temp("apply/unarmed", skill);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill*2);
        if( me->is_fighting() ) me->start_busy(1); 
        } else 
if (skill >=30 && env=="nine") {
        fun1=me->query("functions/nine/level");
        if(!fun1) me->set("functions/nine/level",1);
        skill=(int)skill/5;
        message_vision(
        HIC "$N运起浑天心法第二层的"CYN"玫荡霞"HIC"，身上发出如晚霞般的光茫形成无数的气流!!\n" NOR,me);       
        me->set_temp("superforce",2);
        me->set_temp("mixforce",1);
        me->add_temp("apply/force",   skill);
        me->add_temp("apply/move",    skill);
        me->add_temp("apply/dodge",   skill);
        me->add_temp("apply/unarmed", skill);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill*2);
        if( me->is_fighting() ) me->start_busy(1);
        } else 
if (skill >= 40 && env=="gen") {
        fun1=me->query("functions/gen/level");
        if(!fun1) me->set("functions/gen/level",1);
        skill=(int)skill/5;
        message_vision(
        HIC "$N运起浑天心法第三层的"YEL"土昆仑"HIC"，身上发出如大地般的迫力,形成无数的气流!!\n" NOR,me);
        me->set_temp("superforce",3);
        me->set_temp("mixforce",1);
        me->add_temp("apply/force",   skill);
        me->add_temp("apply/move",    skill);
        me->add_temp("apply/dodge",   skill);
        me->add_temp("apply/unarmed", skill);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill*2);
        if( me->is_fighting() ) me->start_busy(1);
        } else 
if (skill >=50 && env=="ice") {
        fun1=me->query("functions/ice/level");
        if(!fun1) me->set("functions/ice/level",1);
        skill=(int)skill/5;
        message_vision(
        HIC "$N运起浑天心法第四层的"HIW"碧雪冰"HIC"，身上发出如寒霜般的寒劲,四周的空气似乎也为之冻结!!\n" NOR,me);
        me->set_temp("superforce",4);
        me->set_temp("mixforce",1);
        me->add_temp("apply/force",   skill);
        me->add_temp("apply/move",    skill);
        me->add_temp("apply/dodge",   skill);
        me->add_temp("apply/unarmed", skill);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill*2);
        if( me->is_fighting() ) me->start_busy(1);
        } else 
if (skill >=60 && env=="purple") {
        fun1=me->query("functions/purple/level");
        if(!fun1) me->set("functions/purple/level",1);
        skill=(int)skill/5;
        message_vision(
        HIC "$N运起浑天心法第五层的"MAG"紫星河"HIC"，脸色紫气大盛!!全身涌出如星河般的内劲!!\n" NOR,me);
        me->set_temp("superforce",5);
        me->set_temp("mixforce",1);
        me->add_temp("apply/force",   skill);
        me->add_temp("apply/move",    skill);
        me->add_temp("apply/dodge",   skill);
        me->add_temp("apply/unarmed", skill);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill*2);
        if( me->is_fighting() ) me->start_busy(1);
        } else 
if (skill >=80 && env=="black") {
        fun1=me->query("functions/black/level");
        if(!fun1) me->set("functions/black/level",1);
        skill=(int)skill/5;
        message_vision(
        HIC "$N运起浑天心法第六层玄混沌，面泛黑气，全身的内劲增加了有数倍之多!!\n" NOR,me);
        me->set_temp("superforce",6);
        me->set_temp("mixforce",1);
        me->add_temp("apply/force",   skill);
        me->add_temp("apply/move",    skill);
        me->add_temp("apply/dodge",   skill);
        me->add_temp("apply/unarmed", skill);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill*2);
        if( me->is_fighting() ) me->start_busy(1);
        } else 
if (skill >=110 && env=="bluesea") {
        fun1=me->query("functions/bluesea/level");
        if(!fun1) me->set("functions/bluesea/level",1);
        skill=(int)skill/5;
        message_vision(
        HIC "$N运起浑天心法第七层"HIB"[靛沧海]"HIC"，真气流窜，暮地周围出现"HIB"海啸般的内劲"HIB"!!\n" NOR,me);
        me->set_temp("superforce",7);
        me->set_temp("mixforce",1);
        me->add_temp("apply/force",   skill);
        me->add_temp("apply/move",    skill);
        me->add_temp("apply/dodge",   skill);
        me->add_temp("apply/unarmed", skill);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill*2);
        if( me->is_fighting() ) me->start_busy(1);
        } else 
if (skill >=150 && env=="goldsun") {
        fun1=me->query("functions/goldsun/level");
        if(!fun1) me->set("functions/goldsun/level",1);
        skill=(int)skill/5;
        message_vision(
        HIC "$N运起浑天心法第八层"HIY"[金晨曦]"HIC"，真气鼓涨，刹时全身爆出"HIY"万道金色的光芒"NOR"!!\n" NOR,me);
        me->set_temp("superforce",8);
        me->set_temp("mixforce",1);
        me->add_temp("apply/force",   skill);
        me->add_temp("apply/move",    skill);
        me->add_temp("apply/dodge",   skill);
        me->add_temp("apply/unarmed", skill);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill*2);
        if( me->is_fighting() ) me->start_busy(1);
        } else 
if (skill >=200 && env=="blood") {
        fun1=me->query("functions/blood/level");
        if(!fun1) me->set("functions/blood/level",1);
        skill=(int)skill/5;
        message_vision(
        HIC "$N运起浑天心法第九层"HIR"[血穹苍]"HIC"，将真气运布全身，刹时全身冒出血红色的蒸气!!\n" NOR,me);
        me->set_temp("superforce",9);
        me->set_temp("mixforce",1);
        me->add_temp("apply/force",   skill);
        me->add_temp("apply/move",    skill);
        me->add_temp("apply/dodge",   skill);
        me->add_temp("apply/unarmed", skill);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill*2);
        if( me->is_fighting() ) me->start_busy(1);
        } else {
if (skill >=250 && env=="green") {
        fun1=me->query("functions/green/level");
        if(!fun1) me->set("functions/green/level",1);
        skill=(int)skill/5;
        message_vision(
        HIC "$N运起浑天心法第十层"HIG"[玄宇宙]"HIC"，刹时天空昏暗，万星繁动，全身各条经脉均充满了星晨所付予的气劲!!\n" NOR,me);
        me->set_temp("superforce",10);
        me->set_temp("mixforce",1);
        me->add_temp("apply/force",   skill);
        me->add_temp("apply/move",    skill);
        me->add_temp("apply/dodge",   skill);
        me->add_temp("apply/unarmed", skill);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill*2);
        if( me->is_fighting() ) me->start_busy(1);
        }
        }
        if(!me->query_temp("mixforce")) {
        message_vision(HIW"$N浑天心法等级不够再运也没有用!\n"NOR,me); }        
        return 1;
}
 
void remove_effect(object me, int skill)
{
        int fun,lv;
        lv=me->query_temp("superforce");
if(lv==1) {
fun=me->query("functions/white/level");
if(fun<50)
function_improved("white",1000);
} else if(lv==2) {
fun=me->query("functions/nine/level");
if(fun<50)
function_improved("nine",1000);
} else if(lv==3) {
fun=me->query("functions/gen/level");
if(fun<50)
function_improved("gen",1000);
} else if(lv==4) {
fun=me->query("functions/ice/level");
if(fun<50)
function_improved("ice",1000);
} else if(lv==5) {
fun=me->query("functions/purple/level");
if(fun<50)
function_improved("purple",1000);
} else if(lv==6) {
fun=me->query("functions/black/level");
if(fun<100)
function_improved("black",900);
} else if(lv==7) {
fun=me->query("functions/bluesea/level");
if(fun<100)
function_improved("bluesea",800);
} else if(lv==8) {
fun=me->query("functions/goldsun/level");
if(fun<150)
function_improved("goldsun",700);
} else if(lv==9) {
fun=me->query("functions/blood/level");
if(fun<150)
function_improved("blood",600);
} else {
fun=me->query("functions/green/level");
if(fun<150)
function_improved("green",500);
}
        me->add_temp("apply/force",    -skill);
        me->add_temp("apply/unarmed",  -skill);
        me->add_temp("apply/move",     -skill);
        me->add_temp("apply/dodge",    -skill);
        me->delete_temp("mixforce");
        me->delete_temp("superforce");
        message_vision(HIW"$N的浑天心法气劲开始涣散了。\n"NOR,me);
}
