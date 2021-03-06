// 1998/9/29  wataru 改编自雷虎之气
//由于这是杀手的第三段转职才可以学到的气
//所以基本上，会比较强大，可以算是进阶的技巧，请QC的大神多加斟酌
//学到这一个气的玩家EXP大约必须在 80万以上，并不是每个人都可以学到的
//主要是利用杀气与灵气，配合bellup使用出来的一种杀意魔气
//因为花费的是杀气，（杀气并不会自动回复），所以威力自然也强大
//效果主要是以强大的杀意去消灭对手的精，神，并且使对手动作迟缓
//但因为规定只可以busy 1 ，所以，牵制的回数会增加，希望qcer可以通融
//牵制的回数会与所花费的杀气有关，所可花的杀气与玩家的magic lv有关
//杀手的master yar magic lv 是20，所以请qcer列入考虑
//1998/12/11 再次修正，修正有关因为magic lv 不易控制
//1999/4/29   再次修正，修正有关没有心跳的问题，并改善讯息的输出
//1999/5/19   再次修正，修正有关吃下绝世丹药后的威力增幅
//2000/1/24   再次修正，为适应目前fs的强度，修正杀意魔气
#include <combat.h>
#include <ansi.h>
inherit SSERVER;
int kee_out(object me,object target)
{
    int mkilluse,cor,maxskee;
    int magic_lv,makee_lv;
    int sha_lv,rain_lv;
    int mix_power;
    int ext_power=0;

    if (me->query("quest/worldpill") == 1)
        ext_power=120;  //吃下绝世丹药后的威力增幅
    cor=me->query("cor");
    maxskee   =me->query("max_s_kee");
    magic_lv  =me->query_skill("magic",1);
    sha_lv    =me->query_skill("shadow-kill",1)*2;         //max lv 90
    rain_lv   =me->query_skill("rain-throwing",1);       //max lv 100
    makee_lv  =me->query("/functions/manakee/level")*2;    //max lv 150
    mix_power=sha_lv+rain_lv+makee_lv+ext_power;

    //如果magic lv 80的话，最多可以使用10单位的杀气
    //加1是避免出现零次的机会
    //用于控制持续回数
    if (magic_lv > 80)
        magic_lv=80;
    mkilluse=random(magic_lv /8)+1;

        if(me->query("class") != "killer")
        {
         tell_object(me,"自从你离开杀手后，就发现心中的魔气逐渐消失...\n");
                return 1;
        }
        if(me->query("quest/head-kill") != 1)
        {
                tell_object(me,"ㄟ......你想用什么气呀？要用？自己放屁会快一点\n");
                return 1;
        }
        if(me->query("s_kee")< 20)
        {
                tell_object(me,"你的杀意魔气修练不够精深，多练一下再用吧！\n");
                return 1;
        }

      if( !target   ||   !target->is_character()   ||      !me->is_fighting(target) )
                return notify_fail("‘杀意魔气’只能对战斗中的对手使用。\n");

        if(target->query_temp("mkill")==1)
        {
                tell_object(me,"敌人目前被杀意魔气纠缠着，先攻击等会再放杀气\n");
                return 1;
        }
        if (me->query("bellup") != 1)
        {
                tell_object(me, "感觉起来你还不够想杀人嘛！怎么不用杀意升这一招\n");
                return 1;
        }
        if (me->query("bellicosity") < 500)
        {
                tell_object(me, "杀气不够啦！那要怎么用杀气来威吓对手呢？\n");
                return 1;
        }
        if (me->query_skill("magic") < 10)
        {
                tell_object(me, "连点法术也不学，那怎么会有足够的灵力来控制杀气\n");
                return 1;
        }
        if (me->query("atman") < 30)
        {
                tell_object(me, "灵力不够啦，这样你会自灭哦！？\n");
                return 1;
        }
    //以下是花费
    me->add("bellicosity",-(mkilluse*5));  //因为使用杀气恫吓对方
    me->add("atman",-30);                      //使用灵力来结合杀气与灵气
    me->add("s_kee",-20);                      //所需花去的灵气量


//持续回数最高mkilluse可能到10，威力以最大灵气量来分等级
//这根本是变态，把灵气练到lv 250以上，由lv200->lv 250最少需要230000的atman值
//所以给予一击必杀的威力，但把灵气等级降30，使玩家不能练比lv 250更高
 if (maxskee > 250)
 {
   me->add("max_s_kee",-30);                   //所需花去的灵气等级
   message_vision(HIM"  杀      意      魔      气\n\n"NOR,me);
   message_vision(HIM"超顶级威力        **紫**级**魔**气**      \n\n"NOR,me);
   message_vision(HIM"超精纯的杀意魔气化成真元由$N体内射出，这是具有无比威力的魔气\n"NOR,me);
   message_vision(HIM"$N的魔气真元在瞬间射入$n体内，无比的威力在其体内爆发！\n"NOR,me,target);
   target->start_busy(2);
   target->receive_damage("gin",random(mix_power*2));
   target->receive_damage("sen",random(cor*40));   //胆识30*40=1200 一般是一击必杀，重要NPC不会有问题
   //且杀手的胆识大约在20-25之间, 20*20＝400，也就是只要胆识低一些，威力就降很多
 }
 else if (maxskee > 200)
 {
   message_vision(HIM"  杀      意      魔      气\n\n"NOR,me);
   message_vision(HIG"顶级威力          *绿*级*魔*气*   \n\n"NOR,me);
   message_vision(HIG"$N由自身爆出强烈的杀气，这是一种带有魔力的杀气\n"NOR,me);
   message_vision(HIG"$N地狱般的魔气瞬间笼罩$n，令其感到剧烈的恐惧感！\n"NOR,me,target);
   target->start_busy(2);
   target->receive_damage("gin",random(mix_power));
   target->receive_damage("sen",random(cor*20));                  //胆识30*20=600
 }
 else if (maxskee > 150)
 {
   message_vision(HIM"  杀      意      魔      气\n\n"NOR,me);
   message_vision(HIR"超上级威力        *红*级*魔*气*   \n\n"NOR,me);
   message_vision(HIR"$N由自身爆出强烈的杀气，这是一种带有魔力的杀气\n"NOR,me);
   message_vision(HIR"$N地狱般的魔气瞬间笼罩$n，令其感到剧烈的恐惧感！\n"NOR,me,target);
   target->start_busy(2);
   target->receive_damage("gin",random(mix_power));
   target->receive_damage("sen",random(cor*10));                          //胆识30*10=300
 }
 else if (maxskee > 100)
 {
   message_vision(HIM"  杀      意      魔      气\n\n"NOR,me);
   message_vision(HIY"上级威力          *黄*级*魔*气*   \n\n"NOR,me);
   message_vision(HIY"$N由自身爆出强烈的杀气，这是一种带有魔力的杀气\n"NOR,me);
   message_vision(HIY"$N地狱般的魔气瞬间笼罩$n，令其感到剧烈的恐惧感！\n"NOR,me,target);
   target->start_busy(2);
   target->receive_damage("gin",random(mix_power*0.9)); //max 249
   target->receive_damage("sen",random(cor*8));                         //胆识30*8=240
 }
 else if (maxskee > 70)
 {
   message_vision(HIM"  杀      意      魔      气\n\n"NOR,me);
   message_vision(HIB"中级威力          *蓝*级*魔*气*   \n\n"NOR,me);
   message_vision(HIB"$N由自身爆出强烈的杀气，这是一种带有魔力的杀气\n"NOR,me);
   message_vision(HIB"$N地狱般的魔气瞬间笼罩$n，令其感到剧烈的恐惧感！\n"NOR,me,target);
   target->start_busy(1);                                     //busy 1
   target->receive_damage("gin",random(mix_power*0.8)); //max 249
   target->receive_damage("sen",random(cor*7));                         //胆识30*6=180
 }
 else if (maxskee > 40)
 {
   message_vision(HIM"  杀      意      魔      气\n\n"NOR,me);
   message_vision(RED"          *泛*级*魔*气*   \n\n"NOR,me);
   message_vision(RED"$N由自身爆出强烈的杀气，这是一种带有魔力的杀气\n"NOR,me);
   message_vision(RED"$N地狱般的魔气瞬间笼罩$n，令其感到剧烈的恐惧感！\n"NOR,me,target);
   target->start_busy(1);                                     //busy 1
   target->receive_damage("gin",random(mix_power*0.7)); //max 150
   target->receive_damage("sen",random(cor*6));                         //胆识30*6=180
 }
 else if (maxskee > 10)
 {
   message_vision(HIM"  杀      意      魔      气\n\n"NOR,me);
   message_vision(MAG"          *初*级*魔*气*   \n\n"NOR,me);
   message_vision(MAG"$N由自身爆出强烈的杀气，这是一种带有魔力的杀气\n"NOR,me);
   message_vision(MAG"$N地狱般的魔气瞬间笼罩$n，令其感到剧烈的恐惧感！\n"NOR,me,target);
   target->start_busy(1);                                     //busy 1
   target->receive_damage("gin",random(mix_power*0.5)); //max 120
   target->receive_damage("sen",random(cor*4));                         //胆识30*5=120
 }
   target->set_temp("mkill",1);
   target->apply_condition("mkill_out",mkilluse);
   return 1;
}

