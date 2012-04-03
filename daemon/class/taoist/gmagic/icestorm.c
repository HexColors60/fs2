//icestorm
#include <ansi.h>
inherit F_SPELL;
inherit SSERVER;
int fun,fun1,fun2,funn;
int fk,tk,k,i,j=0,l=0,r;
int conjure (object me, object target)
{
object *enemy;
enemy=me->query_enemy();
i=sizeof(enemy);
fun=(me->query("spells/icestorm/level")/25)+1;
fun1=me->query("spells/icestorm/level");
fun2=(int)(me->query_skill("gmagic", 1));
funn=(fun1*7/10)+(fun2*3/10);
if(me->query("class")!="taoist")
return notify_fail("这法术只有术士能用!!\n");
if(me->query("get_icestorm")==1)
  return notify_fail("你欲施展此招，但却是从心无力，好像是缺乏了什么一般...\n");
if(me->query("allow_icestorm")!=1)
  return notify_fail("偷学的不能使用喔\n");    
if( !target ) target = offensive_target(me); 
if(!me->is_fighting(target) )
return notify_fail("这法术只能对战斗中的对手使用!!\n");
if(me->query("max_mana") < 2500 )
return notify_fail("你的法力根基不足!!\n");
if(me->query("mana") < 2500 )
return notify_fail("你的法力不足!!\n");
if(me->query_temp("icestorm")==1)
return notify_fail("你施展法术后心思尚未集中!!\n");
message_vision(HIY"
$N高声呐喊道：天地间的奥妙，大自然的力量岂是凡夫俗子所能抗衡的。

"HIC"○。 ．  "HIG"★"HIC"   ．  ☆ ．   "HIB"●"HIC"  ．  "HIM"★  ．"HIC"   ☆   ．  "HIG"★  ．"HIC"  ．   ○
"HIC"○。   ．  ．  "HIB"★"HIC"  ．  ○  ．  ☆   ．  "HIB"○"HIC"   ．  ●    ★    ．  ○
"HIC"○。 "HIG"．  ☆"HIC" ●  "HBRED+HIY"  冰  ˙  雪  ˙  风  ˙  暴  "NOR+HIC"  ☆．"HIG"☆"HIC" ．  ☆    ○
"HIC"○。 ☆  ．  ★  ●．"HIB"○"HIC"  ★ ．．  ○ ．  ☆  ．  "HIM"● ．"HIC"   ． ★   ○
"HIC"○。 "HIB"．"HIC"  ★   "HIM"．  ☆"HIC" ．   "HIG"●  ．"HIC"  ★  ．   "HIB"☆"HIC"   ．  ★  ． "HIM"． 。"HIC" ○

"HIG"此时天地仿佛憾动了起来，凝结的空气如冰雪崩落般的封住$n。
"HIG"$N趁此时机运起紫河星之最高境界 "HIY"‘ "HIC"冰"HIY"．"HIW"雪"HIY"．"HIR"风"HIY"．"HIG"暴 "HIY"’\n
"NOR, me,target);
me->add("mana",-(500*fun));
me->set_temp("icestorm",1);
me->start_busy(1);
call_out("act1",10,me);
for ( l=0 ; l < fun ; l ++)
{
r=random(100);
if (r >= 60) 
{
message_vision(HIM"
$N使出"HIY"‘"HIC"冰"HIW"雪"HIR"风"HIB"暴"HIY"’"HIM"之"HIR"‘"HIW"冰封千里"HIR"’"HIM"，四周的空气瞬间凝结成冰。
"HIM"如同利刃般压力迫使$n无法呼吸，严重缺氧而呆若木鸡。
"HIR"紧接着翩然使出"HIY"‘"HIW"如霜似雪"HIY"’"HIR"利用大自然神秘的力量，促使天降霜雪层
"HIR"层覆盖\着$n，令敌人难以招架如此神秘的强烈攻击。

"HIG"忽然间四周卷起一阵强风将$n卷入空中，$N冷笑数声喝道:
"HIR"太极阴阳变"HIG"，道家禁招"HIW"‘"HIC"风"HIW"～"HIB"起"HIW"～"HIM"云"HIW"～"HIY"涌"HIW"’"HIG"顿然而出，只见天空风云
"HIG"翻滚不停，$N将本身法力藉由"HIM"风的极速力量"HIG"、"HIC"云的变化无穷"HIG"牵引
"HIG"至极高境界，翻手变出数道极光由手中疾驰而出攻击$n。\n
"NOR,me,target);
for ( j=0 ; j < i ; j++ )
{
k=funn*7;
//if (enemy[j]->query_temp("def_fire")==1) k=funn*2;
enemy[j]->receive_damage("kee",k);
//enemy[j]->apply_condition("icewind",random(20));
COMBAT_D->report_status(enemy[j]);
}
}
else if (r>=20)

{
message_vision(HIY"
      "HIC"受到冰封的$N被无情的霜雪覆盖\，紧接着被强烈的飓风卷入空中
        由高空往下急速坠落，碰的一声被摔的血肉模糊不堪入目。\n
"NOR,target);
for ( j=0 ; j < i ; j++ )
{
k=funn*2;
enemy[j]->receive_wound("kee",k);
enemy[j]->apply_condition("ice",random(10));
enemy[j]->start_busy(1);
COMBAT_D->report_status(enemy[j]);
}
}
else 
{
message_vision(HIG"      $N幸运的躲过了冰风暴的攻击\n"NOR,target);
for ( j=0 ; j < i ; j++ )
{
COMBAT_D->report_status(enemy[j]);
}
}
}
return 1;
}
int act1(object me)
{
me->delete_temp("icestorm");
tell_object(me,HIG"霜雪过后大地恢复了原貌!\n"NOR);
if(me->query("spells/icestorm/level")<100) spell_improved("icestorm",random(100));
return 1;
}
