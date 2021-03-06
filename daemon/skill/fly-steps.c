//fly-steps.c

inherit SKILL;

string *dodge_msg = ({
	"$n使出一个「蜉蝣戏水”的身法 ,左脚一扫 ,倏地一个旋身 ,腾出一丈以外 !\n",
	"$n运起全身真力 ,一个「风卷落花”之势 ,拔起三丈多高 !\n",
	"$n双臂一振 ,便以「海燕掠波”之势 ,「嘶”的掠风声中 ,身形拔起三丈多高 .\n",
	"$n不慌不忙 ,长啸一声 ,一招「东风洗柳” ,跃了开去 .\n",
});

int valid_enable(string usage) {
	return (usage=="dodge")||(usage=="move");
}

int valid_learn(object me)
{
	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if((int)me->query("kee")<30)
		return notify_fail("你的气不够，不能练飞云纵。\n");
	me->receive_damage("kee",30);
	return 1;
}
string perform_action_file(string action)
{
	return CLASS_D("blademan")+ "/fly-steps/" +action;
}
