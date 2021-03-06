// lys-skill
//QC..OK..by Chan 8/29/98

inherit SKILL;


string *parry_msg=
    ({
      "$n回身抽鞭，使出冥蛇鞭法防御式，将$N的攻势一一化去\n",
      "只见$n身形一转，轻抖手中$l，圈出一个鞭花，往$N的$w卷去\n",
      "$n气运$l，将$l舞成一个圈圈，护住身周五尺内\n",
      "$n急忙之际，使出一招‘围魏救赵’，进身直攻，逼的$N收势防守\n",
    });
mapping *action = ({
([ "action":"$N手中$w一挥，使出一招[33m‘金蛇出洞’[0m，气势惊人，直扑$n而去",
        "dodge": -20,
        "parry": 25,
        "damage": 50,
        "damage_type":  "鞭伤",
]),

([ "action":"$N使出一招[35m‘灵蛇八方’[0m，$w似灵蛇般由四面八方打向$n",
        "dodge": -15,
        "parry": 35,
        "damage": 45,
        "damage_type":  "鞭伤",
]),

([ "action":"$N使出一招[1;34m‘灵蛇乍现’[0m，$w忽隐忽现，忽东忽西，令$n无法捉摸$N的鞭路",
        "dodge": 10,
        "parry": 40,
        "damage": 40,
        "damage_type":  "鞭伤",
]),

([ "action":"$N蓄势一挥，使出一招[31m‘赤龙翻江’[0m，呼的一声，手中$w向$n横扫而去",
        "dodge": -15,
        "parry": 25,
        "damage": 55,
        "damage_type":  "鞭伤",
]),

([ "action":"$N挥动$w，使出一招[1;33m‘金蛇万道’[0m，如有千百条金蛇同时打出，直扑$n各大穴",
        "dodge": -10,
        "parry": 35,
        "damage": 60,
        "damage_type":  "鞭伤",
]),

([ "action":"$N手中$w一抖，圈起一圈圈鞭花，一招[1;32m‘金蛇缠身’[0m，向$n卷去",
	"dodge": 35,
        "parry": 50,
    "damage": 70,
        "damage_type":  "鞭伤",
]),

([ "action":"$N身形一斜，使出一招[1;31m‘万蛊蚀心’[0m，顿时满天鞭影，鞭势挟带一股腥风向$n扑至",
        "dodge": 20,
        "parry": 45,
     "damage": 80,
        "damage_type":  "鞭伤",
]),

([ "action":"[1;35m$N$w微挥，使出一招[1;36m‘幽冥幻化’[1;35m，
使鞭之快不见鞭影，只闻呼呼声响，邪风阴煞，围绕$n四周[0m",
        "dodge": 25,
        "parry": 50,
    "damage":80,
        "damage_type":  "鞭伤",
]),

});

int valid_enable(string usage)
{
        return usage=="whip" || usage=="parry";
}
string query_parry_msg(string limb)
{
  int parry_pow;
  object me;
  me=this_player();
  if(!me) return parry_msg[random(sizeof(parry_msg))];
        parry_pow = (int)( me->query_skill("ming-snake", 1)/10);
          if ( parry_pow < 3)
                return parry_msg[random(2)];
            else

                return parry_msg[random(sizeof(parry_msg))];
}
mapping query_action(object me, object weapon)
{
	int skill_level, limit;
	skill_level = (int)(me->query_skill("ming-snake",1));
	limit = (int)(skill_level/10);
	if(limit < 4)
		return action[random(3)];
	if(limit < 8)
		return action[random(limit)];
	else
		return action[random(sizeof(action))];
}
int vaid_learn(object me)
{
	object ob;
	if(!(ob=me->query_temp("weapon")) || (string)ob->query("skill_type")!="whip")
                return notify_fail("不拿鞭怎么学呀!你有没有搞错。\n");
	return 1;
}
int practice_skill(object me)
{
	object ob;
	if(!(ob=me->query_temp("weapon")) || (string)ob->query("skill_type")!="whip")
		return notify_fail("不拿鞭如何练习鞭法。\n");
	if( (int)me->query("kee")< 40)
		return notify_fail("不会累吗? 你的体力不够了，还是休息一下再练吧。\n");
	if( (int)me->query("force")< 5 )
                return notify_fail("你的内力不够了，我看你还是休息一下再练吧。\n");
	me->receive_damage("kee", 40);
	me->add("force",-5);
	return 1;
}
	
string perform_action_file(string action)
{
        return CLASS_D("poisoner")+"/ming-snake/"+action;
 }

