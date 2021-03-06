//by roger
//极火掌;魔界之王专属skill
inherit SKILL;
inherit SSERVER;
#include <ansi.h>
#include <combat.h>
void burn(object me, object victim, object  weapon, int damage);
mapping *action = ({
([	"action": "$N左掌火劲一吐，身形顿时向右平飘三尺，$n见此怪招不禁愕然!!$N趁机劲运右臂鼓起极火功八成功力将火劲悍然灌入$n的体内，正是"HIR"‘五内具焚’"NOR"，$n被烧的哀嚎连连，鲜血狂吐",
		"dodge":		-60,
		"parry":		-60,
		"force":		350,
		"damage":               360,
                "post_action":               (: burn :),
		"damage_type":	"内脏灼伤"
	]),
([	"action": "$N劲运双臂，双手成爪状不停地急旋下，使出霸道的"HIR"‘风车火轮’"NOR"，$n被绞的防守尽失下，$N趁势中宫直入，其急旋的气势几乎将$n的手臂绞断!!",
		"dodge":		-60,
		"parry":		-60,
		"force":		350,
		"damage":               360,
                "post_action":               (: burn :),
		"damage_type":	"火爪灼伤"
	]),
([	"action": "$N运起极火真气,天灵聚起一片炙火,身形一旋,双掌内拢,使出"HIR"‘极火燎天崖’"+NOR",一圈,一吐,催起一股凌厉的气焰,扫向$n!!",
		"dodge":		-60,
		"parry":		-60,
		"force":		350,
		"damage":               360,
                "post_action":               (: burn:),
		"damage_type":  "烧伤"
	]),
([	"action": "$N全身火劲暴吐之下，纵身在高空一式"HIR"‘焚天极火’"NOR"从空中悍然以双掌向$n直压而下，刹那间$n的四周全部笼罩在强烈无匹的雄浑火劲中，铺天盖\地，无法闪避",
		"dodge":		-60,
		"parry":		-60,
		"force":		350,
		"damage":               360,
                "post_action":               (: burn :),
		"damage_type":	"极火内伤"
	]),
([	"action": "$N揉身而上,飘然滑行,顺势使出"HIR"‘极火刀’"+NOR",双掌火劲暴吐成刀,挥动之际,泛起一片红光,有如电光之势,$n顿时眼前罩上一片炙光,一阵昏眩,光刀迅速的朝$n各部位砍去!!",
                "dodge":                -60,
		"parry":		-60,
  		"force":		350,
		"damage":               360,
                "post_action":               (: burn :),
		"damage_type":	"极火刀伤"
	]),        
});

void burn(object me, object victim, object  weapon, int damage)
{
         int burn;
         burn=victim->query_condition("burn");
message_vision("$N的极火劲在$n的体内乱窜，使$n受到了严重的烧伤，兼且内息严重紊乱\n",me,victim);
         victim->apply_condition("burn",burn+3);
         victim->add("kee",-30);
         victim->add("force",-30);
         COMBAT_D->report_status(victim, 1);
 }
int valid_enable(string usage) { return ( usage=="unarmed" || usage=="parry"); }

mapping query_action(object me,object weapon)
{
 int i,force,kee,burn;
 object victim,*enemy;
 enemy = me->query_enemy();
 i=sizeof(enemy);
 victim = enemy[random(i)];
 burn=victim->query_condition("burn");
 force=victim->query("force",1);
 kee=140;
        if( random(100) < 10){    
             message_vision(HIY"
$N狂笑说：「死在极火三掌下，你也不枉此生了！”


"HIR"                       看，极 火 三 掌 ！"NOR"


"HIM"第一掌
"HIR"---天罗火网---"NOR"
"HIR"$N稳稳地站在原地，双手在胸前交叉画了个圆，瞬间熊熊烈火
卷成一道漩涡般的火柱，其势磅礴威猛，直卷向$n的面门！
"NOR"结果$n被极火柱当胸贯穿，鲜血狂吐，全身陷入熊熊烈火中！\n",me,victim);
             victim->receive_damage("kee",(int)kee,me);
             COMBAT_D->report_status(victim);
             message_vision("


"HIG"第二掌
"HIR"---极火双摧---"NOR"
"HIR"$N运起极火功，双掌翻飞下火舌暴吐急冲往$n的上中盘，一
瞬间$n的面门以被极火掌印中，嗤嗤声中夹杂着焦肉味和$n的惨叫声...
"NOR"结果$n更被极火掌透胸而过，眼看是不活了\n",me,victim);
             victim->receive_damage("kee",(int)kee,me);
             COMBAT_D->report_status(victim);     
             message_vision(HIY"

$N大吼：「死吧！”

"HIW"第三掌
"HIR"---极火焚尽九重天---
$N狂吼一声，豁尽所能将浑身炽热极火以铺天盖\地之势向
$n笼罩而下顿时天地全部都笼罩在火海中，烧得$n皮开
肉绽，哀嚎不断！
\n"NOR,me,victim);
             victim->receive_damage("kee",190,me);
             victim->apply_condition("burn",burn+18);
             me->start_busy(2);
            COMBAT_D->report_status(victim);
                             }

    return action[random(sizeof(action))];
}

string *parry_msg = ({
HIR"\n但$n运起极火真气硬架，$N只觉得一股非比寻常的热气从手中的$w传来，不得不撤招防御\n"NOR,
            });
string query_parry_msg(string limb)
{
   return parry_msg[random(sizeof(parry_msg))] ;
}
             
