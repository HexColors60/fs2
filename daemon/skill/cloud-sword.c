// cloud-sword for 云龙天宫 by nike...02/03/2002
#include <combat.h>
#include <ansi.h>
inherit SSERVER;
inherit SKILL;

void super(object me,object target,object weapon,int damage);
void busy(object me,object target,object weapon,int damage);
void delbusy(object me,object target,object weapon,int damage);
void attack(object me,object target,object weapon,int damage);
void damage(object me,object target,object weapon,int damage);
void recover(object me, object target, object weapon, int damage);
void att1(object me, object target, object weapon, int damage);

mapping *action = ({
    ([
        "action"     : HIC"$N祭出"HBBLU+HIW"ζ云龙剑诀ζ"NOR+HIG"◎ 起手式 ◎"HIY"《 云雨苍茫 》"HIC"，$N手中$w"HIC"猛抖，
脚踏奇步，$w"HIC"登时涌起凛冽剑气，遥指向$n，一招攻去，似攻非守，似守非攻。"NOR,
        "damage"     : 105,
        "dodge"      : -45,
        "parry"      : -45,
        "force"      :  25,
        "post_action": (: att1 :),
    ]),
    ([
        "action"     : HIG"$N使出"HBBLU+HIW"ζ云龙剑诀ζ"NOR+HIC"◎ 奔跃式 ◎"HIB"《 风起云涌 》"HIG"，只见$N舞起$w"HIG"，
时而满场剑光，时而劲气收敛，$N一时身随剑走，剑劲化作长虹，直朝$n射去。\n"NOR,
        "damage"     : 70,
        "dodge"      : -32,
        "parry"      : -32,
        "force"      : 30,
        "post_action": (: attack :),
    ]),
    ([
        "action"     : HIW"$N使来"HBBLU+HIW"ζ云龙剑诀ζ"NOR+HIR"◎ 急攻式 ◎"NOR+WHT"《 八方云动 》"HIW"，$N首将己身处于地利之中，
再以$w"HIW"舞起八方幻影，将剑影化成无形剑阵，并将$n困于剑阵之中。\n"NOR,
        "damage"     : 50,
        "dodge"      : -27,
        "parry"      : -27,
        "force"      : 30,
        "post_action": (: busy :),
    ]),
    ([
        "action"     : HIY"$N狂舞$w"HIY"，只见满场$w"HIY"剑芒气劲，虚则实之，实则虚之，令$n眼花撩乱，
并将$n笼罩在剑影之中，此招正是"HBBLU+HIW"ζ云龙剑诀ζ"NOR+HIW"◎ 气吞式 ◎"HIC"《 云游百山 》"HIY"。\n",
        "damage"     : 80,
        "dodge"      : -18,
        "parry"      : -18,
        "force"      : 20,
        "post_action": (: att1 :),
    ]),
    ([
        "action"     : HIC"忽然一阵剑光闪耀，原是$N积聚剑锋之气劲，如山洪般一泄而出，形成一
波又一波的剑浪，直向$n涌去，正为"HBBLU+HIW"ζ云龙剑诀ζ"NOR+HIG"◎ 惊涛式 ◎"HIM"《 覆雨翻云 》"HIC"。\n"NOR,
        "damage"     : 115,
        "dodge"      : -9,
        "parry"      : -9,
        "force"      : 15,
        "post_action": (: att1 :),
    ]),
    ([
        "action"     : HIW"突然$N剑锋一转，使来"HBBLU+HIW"ζ云龙剑诀ζ"NOR+HIY"◎ 虚藏式 ◎"HIG"《 云出无心 》"NOR"，似以剑气为
守，实以剑劲为攻，突然一道剑气突然从$w"HIW"剑锋急奔而出，直冲向$n。\n"NOR,
        "damage"     : 230,
        "dodge"      : 0,
        "parry"      : 0,
        "force"      : 25,
        "post_action": (: delbusy :),
    ]),
    ([
        "action"     : HIG"$N手中之$w"HIG"忽然黯淡无光，似若气劲已虚，而$n正待抢攻，却被$N以一招
"HBBLU+HIW"ζ云龙剑诀ζ"NOR+HIM"◎ 奇袭式 ◎"HIR"《 伏云暗蛰 》"HIG"抢出，正是攻其不备，占得先机。\n"NOR,
        "damage"     : 150,
        "dodge"      : 8,
        "parry"      : 8,
        "force"      : 10,
        "post_action": (: damage :),
    ]),
    ([
        "action"     : HIY"$N将真气化为阴阳两劲，并贯劲于剑锋，顺而使出"HBBLU+HIW"ζ云龙剑诀ζ"NOR+HIC"◎ 破空式 ◎
"HIG"《 松柏浮云 》"HIY"，只见剑气化为松柏两柱形自剑锋破出，以不同方向击向$n。\n"NOR,
        "damage"     : 170,
        "dodge"      : 18,
        "parry"      : 18,
        "force"      : 20,
        "post_action": (: att1 :),
    ]),
    ([
        "action"     : HIC"$N真气游走全身，使出"HBBLU+HIW"ζ云龙剑诀ζ"NOR+YEL"◎ 护体式 ◎"HIW"《 天地云龙 》"HIC"，将真气化为
无形剑网在周身产生绵密的保护层，使得$n无法接近，甚而眼花撩乱之。\n"NOR,
        "damage"     : 90,
        "dodge"      : 25,
        "parry"      : 25,
        "force"      : 20,
        "post_action": (: att1 :),
    ]),
    ([
        "action"     : HIY"$N劲透剑尖，使出一招"HBBLU+HIW"ζ云龙剑诀ζ"NOR+HIB"◎ 轰天式 ◎"HIR"《 云破山河 》"HIY"，一道雄浑剑
气直取$n咽喉，其破空之势中夹带孅柔飘朔之劲，威力足以震破名山巨岳。\n"NOR,
        "damage"     : 210,
        "dodge"      : 31,
        "parry"      : 31,
        "force"      : 20,
        "post_action": (: super :),
    ]),
    ([
        "action"     : HIG"只见$N双足一跨，体内真气流转，随即使上"HBBLU+HIW"ζ云龙剑诀ζ"NOR+HIB"◎ 诡谲式 ◎"HIC"《 重云深锁 》
"HIG"，招式中蕴含流云万化的神奇态势，只见$N飞来一剑，$n一时无法招架。\n"NOR,
     "damage"    : 230,
     "dodge"     : 38,
     "parry"     : 38,
     "force"     : 30,
        "post_action": (: super :),
    ]),
    ([
        "action"     : HIC"
\t\t  ═══╦═══      ╦═╩╦ ╠══╯    ══╩═╰═╬═╮
\t\t╭═══╬═══╮    ╩══╩ ╰══╮     ═══     ║  ║
\t\t║╰═╮║╭═╯║    ╔══╗ ╭══╯     ═══ ══╬═╩
\t\t   ══════       ╠══╣ ╠══╯    ╭══╮╭═╯═╮
\t\t ═╦══════     ╠══╣ ╠══╯    ║    ║║      ║
\t\t   ╰════╣       ╯    ╯ ╰══╮    ╰══╯╯      ╰\n\n
"HIW"$N一招"HBBLU+HIW"ζ云龙剑诀ζ"NOR+HIB"◎ 总诀式 ◎"HIG"《 云龙无际 》"HIW"使出，真有如百人舞剑般，
急手快剑，绝妙无匹，恰似有意若无意，既趣态横生，却又是凶险至极。\n"NOR,
        "damage"     : 250,
        "dodge"      : 45,
        "parry"      : 45,
        "force"      : 25,
        "post_action": (: recover :),
    ]),
});
void recover(object me, object target, object weapon, int damage)
{
    int bell, recover, sklv = me->query_skill("cloud-sword",1);
    bell = me->query("bellicosity")/10;
    if(bell > 250) bell = 250;
    recover = sklv*2-bell;
    if(sklv < bell) recover = 0;

    if(me->query("family/family_name") != "云龙天宫") return 0;
    if( !me->query_temp("berserk") && me->query("kee") < me->query("max_kee") && random(100) > sklv*2/3) {
        message_vision(HIY"\n$N体内的真气爆发，自剑锋闪出一道黄芒，并将$N完全笼罩！\n
"HIW"$N突然感到自己的气力似乎已经回复了不少！\n"NOR,me,target);
        me->receive_curing("kee",recover);
        me->receive_heal("kee",recover);
        me->add("force",sklv);
    } else return 0;
}
void busy(object me, object target, object weapon, int damage)
{
    int sklv = me->query_skill("cloud-sword",1);

    if(me->query("family/family_name") != "云龙天宫") return 0;
    if(me->query("force") < sklv/2) return 0;
    if(me->query("force") < 200 || target->is_busy() >= 3) return 0;
        message_vision(HIM"\n\t$N气贯丹田，马步站稳，顺势使上一招...\n
\t\t"HIY"～～～"HIC"《 "HIW"云踪无现"HIC"～"HIR"龙飞焰"HIC" 》"HIY"～～～\n
\t    "HIR"自剑身散发出一股熊熊火光，狠狠地朝$n"HIR"刺去！！\n\n"NOR,me,target);
    if(!me->query_temp("berserk") && random(75) > 60-me->query("cps")) {
        message_vision(HIB"$N的一剑刺中$n的要害罩门，一股灼热之感，自剑端漫向$n体内，
$n登时面无血色，一脸目瞪口呆，仿佛自以惊骇无比...\n"NOR,me,target);
        target->receive_damage("kee",sklv*2);
        target->apply_condition("burn",random(sklv)+sklv/3);
        target->start_busy(random(2)+1);
        me->add("force",-sklv);
    } else {
        message_vision(HIR"$N的一剑刺偏，只轻扫过$n的双肩，$n肩头登时血如泉涌，但并无大碍...\n"NOR,me,target);
        target->receive_damage("kee",sklv*2);
        me->add("force",-sklv/2);
    }
}
void delbusy(object me, object target, object weapon, int damage)
{
    int sklv = me->query_skill("cloud-sword",1);

    if(me->query("family/family_name") != "云龙天宫") return 0;
    if(sklv < 40 || me->query("force") < sklv*3/2) return 0;
    if(!me->query_temp("berserk") && random(100) > 50) {
        message_vision(HIG"\n$N被$n逼得喘不过气，却突然狂吼一声，如疯狂般开始舞起手中之剑，并吟道：\n\n
\t\t"HIW"‘"HIC"孤亭突兀插飞流"HIW"，"HIC"气压元龙百尺楼"HIW"’\n
\t\t\t"HIW"‘"HIY"万里风涛按瀛海"HIW"，"HIY"千年豪杰壮山丘"HIW"’\n
\t\t"HIW"‘"HIG"疏星澹月鱼龙夜"HIW"，"HIG"老木清霜鸿雁秋"HIW"’\n
\t\t\t"HIW"‘"HIR"倚剑长歌一杯酒"HIW"，"HIR"浮云西北是神州"HIW"’\n\n
        "NOR,me,target);
        message_vision(HIY"  须臾...$N终于摆\脱了$n的绵密攻势，并且以强势快剑反将$n逼至绝境...\n"NOR,me,target);
        target->receive_damage("kee",sklv*2);
        me->add("force",-sklv*3/2);
    } return 0;
}
void damage(object me, object target, object weapon, int damage)
{
    int bell, sklv = me->query_skill("cloud-sword",1);

    if(me->query("family/family_name") != "云龙天宫") return 0;
    if(sklv < 90 || me->query("force") < sklv*2/3) return 0;
        message_vision(HIR"\n
    $N手捏剑诀，暗自运行真气入体，有如九珠一般，行遍周身大穴，\n
\t又随即舞起手中之剑，似已幻化无数剑圈，接着纵身跃\n
    起丈余，一个旋身，由半空中自向$n疾攻而至，口中并缓缓吟道：\n
\t  "HIW"--== "HBRED+HIY"云"NOR+HIW" == "HBRED+HIC"起"NOR+HIW" == "HBRED+HIC"山"NOR+HIW" == "HBRED+HIC"河"NOR+HIW" == "HBRED+HIC"动"NOR+HIW" == "HBRED+HIC"九"NOR+HIW" == "HBRED+HIC"天 "NOR+HIW" ==--\n
\t      "HIW"--== "HBRED+HIY"龙"NOR+HIW" == "HBRED+HIC"游"NOR+HIW" == "HBRED+HIC"干"NOR+HIW" == "HBRED+HIC"坤"NOR+HIW" == "HBRED+HIC"跃"NOR+HIW" == "HBRED+HIC"古"NOR+HIW" == "HBRED+HIC"渊 "NOR+HIW" ==--\n
\t\t  "HIW"--== "HBRED+HIY"剑"NOR+HIW" == "HBRED+HIC"傲"NOR+HIW" == "HBRED+HIC"孤"NOR+HIW" == "HBRED+HIC"独"NOR+HIW" == "HBRED+HIC"孰"NOR+HIW" == "HBRED+HIC"为"NOR+HIW" == "HBRED+HIC"敌 "NOR+HIW" ==--\n
\t\t      "HIW"--== "HBRED+HIY"诀"NOR+HIW" == "HBRED+HIC"霸"NOR+HIW" == "HBRED+HIC"江"NOR+HIW" == "HBRED+HIC"湖"NOR+HIW" == "HBRED+HIC"离"NOR+HIW" == "HBRED+HIC"中"NOR+HIW" == "HBRED+HIC"原 "NOR+HIW" ==--\n
\t    "HIY"此招快意卓绝，妙极无言，须臾之内已出招了二十多剑，剑剑攻向$n"HIY"要害，\n
\t直逼得其毫无退守之余地，只有挺身挡格，却因此而被打乱阵脚，头颈腹背皆以见红。\n\n"NOR,me,target);
    if( !me->query_temp("berserk") && random(sklv) > 45) {
        message_vision(HIR"$N最后使上一剑中冲，直取$n之命门大穴，$n一个闪神而中招，倒地兀自流血不已...\n"NOR,me,target);
        target->receive_wound("kee",sklv*5+random(sklv));
        target->receive_damage("kee",sklv*2+random(sklv));
        target->start_busy(1);
        me->add("force",-sklv*2/3);
    } else {
        message_vision(HIR"$N最后使上一剑中冲，直取$n之命门大穴，$n虽举臂挡驾，却伤及手臂，流血不止...\n"NOR,me,target);
        target->receive_damage("kee",sklv);
        me->add("force",-sklv/3);
    }
}
void attack(object me, object target, object weapon, int damage)
{
    int bell, sklv = me->query_skill("cloud-sword",1)*2;
    bell = me->query("bellicosity")/10;
    if(sklv < 120) sklv = 120;
    if(bell > 100) bell = 100; 
    if(bell < 45) bell = 45;

    if(me->query("family/family_name") != "云龙天宫") return 0;
    if(me->query("force") < sklv) return 0;
        message_vision(HIC"\n
\t$N忽而起手奔跃，转而奇袭急攻，又似虚藏护体，实为气吞总诀，\n
    瞬息万变，有如龙腾凤翔一般的舞起手中之剑，并顺势使上一招......\n
\t      "HIY"《--》"HIW"～"HIC"云"HIW"～"HIC"龙"HIW"～"HIC"剑"HIW"～"HIC"诀"HIW"～"HIY"《--》"HIR"‘奥意之式’"NOR"\n
"HIY"\t    【"HIW"～"HIC"游"HIW"～"HIC"云"HIW"～"HIC"无"HIW"～"HIC"常"HIW"～"HIC"相"HIR"˙"HIC"天"HIW"～"HIC"龙"HIW"～"HIC"舞"HIW"～"HIC"空"HIW"～"HIC"翔"HIW"～"HIY"】\n
    "HIC"一时剑光炽炽，剑芒闪耀，剑气急窜，剑劲突奔，人剑合一，向$n狂攻而去！\n\n"NOR,me,target);
    if(!me->query_temp("berserk") && random(sklv) > bell) {
        message_vision(HIR"$n被剑光所震摄，忽然一个闪神，已经遭$N给痛击了要害！！！\n"NOR,me,target);
        target->receive_damage("gin",sklv+random(sklv/2));
        target->receive_damage("kee",sklv*2+random(sklv));
        target->receive_damage("sen",sklv+random(sklv/2));
        target->receive_wound("gin",sklv/2+random(sklv));
        target->receive_wound("kee",sklv+random(sklv*2));
        target->receive_wound("sen",sklv/2+random(sklv));
        me->add("force",-sklv);
    } else {
        message_vision(HIG"$n脚踩步法，一个回身，竟翩然的闪过这威力不弱的一击...\n"NOR,me,target);
        me->add("force",sklv/3);
        target->start_busy(1);
    }
}
void super(object me, object target, object weapon, int damage)
{
    int sklv,bell = me->query("bellicosity")/10;
    sklv = me->query_skill("cloud-sword",1);
    if(bell < 0) bell = 0;
    if(bell > 60) bell = 60;

    if(me->query("family/family_name") != "云龙天宫") return 0;
    if(sklv < 120) return 0;
    if(!me->query("quests/free_shasword")) return 0;
    if(me->query("force") < 1200) return 0;
    if(me->query_temp("berserk")) return 0;
        message_vision(HIY"\n$N眼绽金光，舞剑如轮，大喝一声：「纳命来！！！”，一招使上...\n
\t\t"HBRED+HIW"-= "HIY"云龙霸剑意"HIW"－"HIC"十二式齐出 "HIW"=-"NOR+HIY"\n\n"NOR,me,target);
    if(random(100) > 30) {
    sklv = sklv - bell;
        message_vision(HIR"\n$N狂暴剑意，劲贯剑锋，使出"HIY"《起手式》"HIW"◤"NOR+GRN"云雨苍茫"HIW"◢"HIR"，一招虎虎生风，去势汹汹的攻向$n的招子。\n"NOR,me,target);
        target->receive_damage("kee",sklv/2);
        COMBAT_D->report_status(target);
        message_vision(HIR"\n$N狂暴剑意，劲贯剑锋，使出"HIY"《奔跃式》"HIW"◤"NOR+MAG"风起云涌"HIW"◢"HIR"，一招虎虎生风，去势汹汹攻向$n的颈项。\n"NOR,me,target);
        target->receive_damage("kee",sklv/2);
        COMBAT_D->report_status(target);
        message_vision(HIR"\n$N狂暴剑意，劲贯剑锋，使出"HIY"《急攻式》"HIW"◤"HIB"八方云动"HIW"◢"HIR"，一招虎虎生风，去势汹汹攻向$n的双臂。\n"NOR,me,target);
        target->receive_damage("kee",sklv/2);
        COMBAT_D->report_status(target);
        message_vision(HIR"\n$N狂暴剑意，劲贯剑锋，使出"HIY"《气吞式》"HIW"◤"NOR+CYN"云游百山"HIW"◢"HIR"，一招虎虎生风，去势汹汹攻向$n的手腕。\n"NOR,me,target);
        target->receive_damage("kee",sklv*2/3);
        COMBAT_D->report_status(target);
        message_vision(HIR"\n$N狂暴剑意，劲贯剑锋，使出"HIY"《惊涛式》"HIW"◤"HIM"覆雨翻云"HIW"◢"HIR"，一招虎虎生风，去势汹汹攻向$n的胸口。\n"NOR,me,target);
        target->receive_damage("kee",sklv*2/3);
        COMBAT_D->report_status(target);
        message_vision(HIR"\n$N狂暴剑意，劲贯剑锋，使出"HIY"《虚藏式》"HIW"◤"NOR+WHT"云出无心"HIW"◢"HIR"，一招虎虎生风，去势汹汹攻向$n的肚皮。\n"NOR,me,target);
        target->receive_damage("kee",sklv+random(sklv));
        COMBAT_D->report_status(target);
        message_vision(HIR"\n$N狂暴剑意，劲贯剑锋，使出"HIY"《奇袭式》"HIW"◤"NOR+YEL"伏云暗蛰"HIW"◢"HIR"，一招虎虎生风，去势汹汹攻向$n的腰际。\n"NOR,me,target);
        target->receive_damage("kee",sklv*2);
        COMBAT_D->report_status(target);
        message_vision(HIR"\n$N狂暴剑意，劲贯剑锋，使出"HIY"《破空式》"HIW"◤"HIG"松柏浮云"HIW"◢"HIR"，一招虎虎生风，去势汹汹攻向$n的鼠奚。\n"NOR,me,target);
        target->receive_damage("kee",sklv*2+random(sklv/2));
        COMBAT_D->report_status(target);
        message_vision(HIR"\n$N狂暴剑意，劲贯剑锋，使出"HIY"《护体式》"HIW"◤"HIC"天地云龙"HIW"◢"HIR"，一招虎虎生风，去势汹汹攻向$n的大腿。\n"NOR,me,target);
        target->receive_damage("kee",sklv*2+random(sklv));
        COMBAT_D->report_status(target);
        message_vision(HIR"\n$N狂暴剑意，劲贯剑锋，使出"HIY"《诡谲式》"HIW"◤"HIY"重云深锁"HIW"◢"HIR"，一招虎虎生风，去势汹汹攻向$n的膝头\n。"NOR,me,target);
        target->receive_damage("kee",sklv*3);
        COMBAT_D->report_status(target);
        message_vision(HIR"\n$N狂暴剑意，劲贯剑锋，使出"HIY"《轰天式》"HIW"◤"HIR"云破山河"HIW"◢"HIR"，一招虎虎生风，去势汹汹攻向$n的小腿。\n"NOR,me,target);
        target->receive_damage("kee",sklv*3+random(sklv/2));
        COMBAT_D->report_status(target);
        message_vision(HIR"\n$N狂暴剑意，劲贯剑锋，使出"HIY"《总诀式》"HIW"◤"HIW"云龙无际"HIW"◢"HIR"，一招虎虎生风，去势汹汹攻向$n的足踝。\n"NOR,me,target);
        target->receive_damage("kee",sklv*4+random(sklv));
        COMBAT_D->report_status(target);
        COMBAT_D->report_status(target);
        COMBAT_D->report_status(target);
        target->start_busy(2);
        me->add("force",-1200);
        me->start_busy(1);
    } else {
        message_vision(HIB"没料到居然被$n"HIB"突如其来的一招给攻破剑势，而$N只伤到$n"HIB"的一点皮毛，
并无给予重击，反而$N自身顿时失去重心，自空中重摔于地...\n"NOR,me,target);
        me->add("force",-200);
        target->receive_damage("kee",sklv*2);
    }
}
// 从 gold-blade 直接偷过来改的喔...by nike
void att1(object me, object victim, object weapon, int damage)
{
    int lose, i, bell = me->query("bellicosity")/100;
    if(bell < 1) bell = 1;
    if(bell > 15) bell = 15;
    lose = (int)me->query_skill("cloud-sword",1)/20-random(bell)+1;

    if(me->query_temp("berserk")) return 0;
    if(me->query("force") < 120) return 0;
    if(lose < 1) lose = 1;
    if(lose > 20) lose = 20;
    for(i = 0;i < lose; i++) {
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
        me->set_temp("berserk",1);
        me->add("force",-120);
        if(me->query("force") < 0) me->set("force",0);
    }
        me->delete_temp("berserk");
}
int valid_learn()
{
    object me = this_player();
    object ob = me->query_temp("weapon");

    if(me->query("max_force") < 60)
        return notify_fail("你的内功根基不足，无法学习《云龙剑诀》。\n");
    if(!ob) return notify_fail("你手中无剑，如何学习《云龙剑诀》？\n");
        return 1;
}
int valid_enable(string usage) { return (usage=="sword"); }
mapping query_action(object me, object weapon)
{
    object target = offensive_target(me);
    int sk = me->query_skill("cloud-sword",1);
    int da = sk*(random(2)+5);
    da = random(da)+da/2;
    weapon = me->query_temp("weapon");

    if(weapon) {
    if(me->query("force") >= 450 && me->query("bellicosity") <= 50) {
    if(me->query("family/family_name") == "云龙天宫"
    && weapon->query("id") == "cloud-dragon sword"
    && sk >= 80 && random(100) > 85 && target) {
message_vision(HIC"$N手中的"+weapon->name()+"在体内浮云劲气的导引之下，竟幻化为一尾翔空云龙，朝$n腾飞而去！\n"NOR,me,target);
message_vision(@LONG

[0;1;36m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m/[1m|[1m [1m [1m/[1m|[1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m,[1m^[1m^[1m^[1m-[1m-[1m_[1m/[1m|[0m
[0;1;36m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m_[1m-[1m^[1m^[1m^[1m^[1m^[1m^[1m-[1m_[1m/[1m|[1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m.[1m_[1m-[1m-[1m-[1m;[1m/[1m^[1m [1m^[1m [1m [1m [1m`[1m.[1m/[1m|[0m
[0;1;36m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1mv[1m [1m [1m [1m [1m [1m/[1m^[1m^[1m [1mv[1m [1m [1m^[1m^[1m [1m [1m^[1m/[1m|[1m [1m [1m [1m [1m [1m [1m [1m [1m [1m([1m([1m [1m)[1m;[1m/[1m^[1m [1m [1m [1m [1m [1m>[1m [1m>[1m [1m`[1m/[1m|[0m
[0;1;36m [1m [1m [1m\[1m [1m [1m [1m [1m [1m([1m:[1m)[1m [1m [1m [1m/[1m^[1m [1m^[1m([1m:[1m)[1m [1m [1m^[1m [1m [1m>[1m>[1m`[1m/[1m|[1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m,[1m/[1m [1m^[1m^[1m [1m [1m>[1m [1m [1m [1m [1m>[1m [1m>[1m`[1m/[1m|[0m
[0;1;36m [1m [1m [1m [1m [1m\[1m [1m [1m [1m [1m([1m:[1m:[1m)[1m [1m/[1m [1m [1m [1m([1m:[1m:[1m)[1m [1m;[1m>[1m [1m/[1m [1m>[1m>[1m`[1m/[1m|[1m [1m [1m [1m [1m [1m [1m [1m [1m,[1m/[1m^[1m^[1m^[1m [1m [1m [1m,[1m-[1m.[1m [1m [1m [1m>[1m [1m>[1m>[1m`[1m/[1m|[0m
[0;1;36m [1m [1m [1m [1m [1m [1m\[1m [1m [1m [1m([1m:[1m:[1m)[1m,[1m^[1m^[1m^[1m.[1m([1m:[1m:[1m)[1m/[1m`[1m/[1m [1m [1m [1m>[1m>[1m>[1m`[1m/[1m|[1m [1m [1m [1m [1m [1m [1m,[1m/[1m^[1m^[1m [1m [1m [1m^[1m;[1m [1m [1m [1m`[1m.[1m [1m [1m [1m>[1m [1m>[1m`[1m/[1m|[0m
[0;1;36m [1m [1m [1m [1m [1m [1m [1m [1m\[1m [1m [1m<[1m_[1m)[1m:[1m:[1m:[1m:[1m:[1m([1m_[1m>[1m/[1m [1m/[1m`[1m.[1m_[1m-[1m-[1m.[1m [1m [1m`[1m/[1m|[1m [1m [1m [1m [1m [1m;[1m/[1m^[1m [1m [1m^[1m [1m [1m;[1m-[1m_[1m.[1m [1m [1m`[1m.[1m.[1m [1m>[1m [1m [1m>[1m`[1m/[1m|[0m
[0;1;36m [1m [1m [1m [1m [1m [1m [1m [1m [1m\[1m [1m\[1m|[1m:[1m:[1m:[1m|[1m:[1m:[1m:[1m|[1m/[1m [1m/[1m [1m [1m [1m([1m [1m)[1m)[1m [1m [1m>[1m`[1m/[1m|[1m [1m [1m [1m,[1m/[1m^[1m [1m^[1m [1m [1m [1m;[1m([1m [1m)[1m)[1m [1m [1m [1m [1m [1m;[1m [1m [1m>[1m>[1m [1m`[1m/[0m
[0;1;36m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m\[1m [1m [1m\[1m_[1m:[1m|[1m:[1m_[1m/[1m [1m [1m/[1m [1m [1m [1m [1m`[1m.[1m [1m [1m [1m [1m [1m>[1m`[1m/[1m|[1m [1m,[1m/[1m^[1m^[1m [1m [1m [1m^[1m [1m;[1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m;[1m>[1m [1m [1m>[1m [1m/[1m;[0m
[0;1;36m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m\[1m [1m\[0;1;5;31m@[0;1;36m,[1m [1m.[0;1;5;31m@[0;1;36m/[1m [1m/[1m [1m [1m [1m [1m [1m [1m`[1m.[1m [1m [1m>[1m [1m>[1m [1m`[1m-[1m-[1m [1m^[1m^[1m [1m^[1m [1m^[1m [1m;[1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m;[1m [1m>[1m [1m>[1m [1m/[0m
[0;1;36m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m\[1m [1m\[1m=[1m:[1m=[1m/[1m [1m/[1m [1m [1m [1m [1m [1m [1m [1m_[1m`[1m.[1m [1m [1m [1m [1m>[1m [1m [1m>[1m [1m>[1m [1m [1m>[1m [1m [1m;[1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m,[1m`[1m [1m>[1m [1m [1m/[1m;[0m
[0;1;36m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m\[1m\[1m=[1m:[1m=[1m/[1m/[1m [1m [1m [1m [1m [1m [1m [1m([1m([1m,[1m`[1m.[1m>[1m [1m>[1m [1m [1m [1m [1m>[1m [1m>[1m [1m_[1m/[1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m,[1m'[1m [1m>[1m [1m>[1m [1m/[1m,[0m
[0;1;36m [1m [1m [1m [1m [1m [1m [1m [1;33m [1m_[1;36m [1m [1m [1m [1m<[1mo[1m_[1mo[1m>[1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m^[1m`[1m-[1m_[1m_[1m [1m>[1m [1m_[1m_[1m_[1m-[1m^[1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m_[1m,[1m'[1m [1m>[1m>[1m [1m [1m/[1m;[0m
[0;1m [1m [1;33m^[1m^[1m-[1m_[1m_[1m [1;31m/[1m^[1m^[1m\[1;33m [1m_[1m-[1;37m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1;36m^[1m^[1m^[1m^[1m^[1m_[1m-[1m^[1m=[1m-[1m-[1m^[1m^[1m.[1m.[1m.[1m_[1m'[1m [1m>[1m>[1m [1m [1m/[0m
[0;1m [1m [1m [1m [1;33m^[1m^[1m-[1;31m|[1m [1m [1m'[1m;[1m|[1;33m_[1m_[1m-[1m^[1m^[1m^[1m-[1m_[1m_[1m_[1m [1;37m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1;36m_[1m^[1m_[1m^[1m-[1m-[1m.[1m.[1m.[1m.[1m_[1m_[1m.[1m.[1m.[1m/[0m
[0;1m [1m [1m [1;33m_[1m_[1m_[1m-[1m_[1;31m\[1m_[1m_[1m/[1;33m-[1m-[1m^[1m^[1m^[1m [1m [1;37m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1;36m^[1m^[1m^[0m

LONG+NOR,me,target);
        message_vision(HIW"云龙腾飞于空，忽口吐赤红火珠，随即朝$n俯冲直下，狂劲似雷，迅疾如电！\n"NOR,me,target);
        message_vision(HIY"\n云龙旋舞长啸一声，声若旱天洪雷，震得$n七昏八素，脑子里嗡嗡乱叫！\n"NOR,me,target);
        COMBAT_D->report_status(target);
        message_vision(HIR"云龙挥舞着锐爪展开疯狂攻击，$n一时闪躲不及，而导致全身皮绽肉裂！\n"NOR,me,target);
        COMBAT_D->report_status(target);
        message_vision(RED"云龙口中的火珠突然朝$n驰飞而去，由于来得突然，$n惨遭火珠灼身，痛苦不已！\n"NOR,me,target);
        COMBAT_D->report_status(target);
        target->start_busy(1);
        target->receive_damage("kee",da);
        target->receive_damage("gin",da/5);
        target->receive_damage("sen",da/5);
        me->add("force",-(random(150)+300));
        message_vision(HIB"\n云龙在完成使命之后，又幻化为剑形，落回$N的手中。\n"NOR,me,target);
        }
    }
  }
    sk = sk/10;
    if(sk < 2) return action[random(3)];
    else if(sk < 4) return action[random(6)];
    else if(sk < 8) return action[random(9)];
    else return action[random(sizeof(action))];
}
string perform_action_file(string action)
{
        return CLASS_D("swordsman")+"/cloud-sword/"+action;
}


