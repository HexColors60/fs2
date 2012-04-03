#include <ansi.h>                                                               
inherit F_FUNCTION;                                                             
inherit SSERVER;                                                                

int perform(object me, object target)                                           
{
    object ob;
    int age=me->query("age",1);
    int lv1=me->query("functions/goldsun/level");
    int lv=me->query_skill("superforce",1);
    int hurt_value=lv1*age/4+lv*age/10;
	if(me->query("class")!="prayer")
          return notify_fail("你的职业无法使用此技能。\n");
    if( hurt_value > 900) hurt_value=900;
                                                                                
        if( !target ) target = offensive_target(me);                            
        if(!target) return notify_fail("你找不到敌人!!\n");
                                                                                
        if( lv1 < 60  )
            return notify_fail("你的[33m金晨曦[0m练的不够纯熟，无法催运出[33m金晨曦[0m的霸气，须60级。\n");
        if( me->query_skill("superforce",1) < 170 )             
            return notify_fail("你浑天宝鉴心法的火侯尚未足够，须170级。\n");
                                                                                
        if(!(ob=me->query_temp("weapon")))
        {
            if(me->query_temp("secondary_weapon"))
            return notify_fail("你不空手是无法使用[33m双星赶月[0m的！！\n");
        }
        if(ob=me->query_temp("weapon"))                                         
        {                                                                       
            if((string)ob->query("skill_type") != "unarmed")
            return notify_fail("你不空手是无法使用[33m双星赶月[0m的!\n");
        }
        if(me->query("force")<400)                                            
            return notify_fail("你的内力不够。\n");
        if(me->query("kee")<140)                                      
            return notify_fail("你的气不够。\n");
                                                                                
        if(!me->is_fighting(target))        
        {                                                                       
            tell_object(me,"[33m双星赶月[0m唯在战斗中才能使用。\n");
            return 1;
        }                                                                       
        message_vision("\t$N全身[33m金光闪闪[0m，光华夺目，[33m金色的真气[0m在身旁旋绕，\n\t$N整个人飞升在数丈高的半空中!!光芒四射宛若骄阳!!\n\n",me,target);
        message_vision("$N双拳一握，两团[33m耀眼金光[0m汇聚成球，呼啸而出！此招有如双龙出海，金光刺目，直逼敌人上下两路！\n",me,target);
                                                                                
        me->add("kee",-(hurt_value/20));
        me->add("force",-(hurt_value/4));
        if(80>random(100))
        {                                                                       
        message_vision("$n竭力抵挡，仍被这两团气劲轰中，顿时身首无存，尸骸遍地！！\n",me,target); 
        message_vision( NOR,me);                                        
        target->receive_damage("kee",hurt_value);
        target->add("force",-hurt_value/4);
        COMBAT_D->report_status(target);                                
        }                                                                       
        else                                                                    
        {                                                                         
        message_vision("$n竭力闪避，避开了[33m双星赶月[0m正面的攻击，两团[33m金光[0m轰向地面将地面炸了开来。\n",me,target);
        message_vision( NOR,me);                                        
        target->receive_damage("kee",hurt_value/12);
        target->add("force",-hurt_value/14);
        COMBAT_D->report_status(target);                                
        }                                                                        
        message_vision("[33m「双星赶月”[0m使出后，$N面露笑容，似乎很满意此招的攻击能力",me,target); 
        me->start_busy(1);
        if(lv1 < 150) function_improved("goldsun",random(500));
        message_vision( NOR,me);                                                
        return 1;                                                               
}
                                                                             
