//绛雪步法 by bss
#include <ansi.h>
inherit SKILL;

string *dodge_msg = ({

        "\n只见$n跃至空中，忽地一闪，消失了身影，竟然是失传已久的轻功绝技 "HIY"「凌空逝影”"NOR"，使得$N的攻击完全无效。\n",

        "\n$n的脚下忽然加快，左右晃动下，居然出现了七个你的身影，正是忍术中的"HIB"「忍者七分身法”"NOR"\n，$N在震惊之余，完全分不出那一个是真的$n。\n",

        "\n$n脚踩八卦，忽左忽右地绕到了对手的身后，正是"HIG"「八卦游龙步法”"NOR"中的精华"HIC"「扭转乾坤”"NOR"，面对这突如其来的举动，使得$N完全无法招架。\n",

"\n忽然$n眼放精光，大喝一声"HIR"「幻魔身法”"NOR"，身形展开$n就像一缕\轻烟般从$N眼前消失，使得\n$N失去了攻击目标。\n",

        "\n$n运起"HIB"忘"HIW"情"HIY"天"HIR"书"NOR"中的绝技"HIC"「天意”"NOR"，天意一出，人如天意，天意不可夺，面对这强大的招式，使$N收回所有的攻击。\n",

        "\n$n运起"HIB"忘"HIW"情"HIY"天"HIR"书"NOR"中的绝技"HIM"「木顽”"NOR"，$n的身体忽然变得跟朽木一般，使得$N得招式完全失去了效用。\n",

        "\n$n运起"HIB"忘"HIW"情"HIY"天"HIR"书"NOR"中的绝技"HIG"「地势”"NOR"，$n的身形忽高忽低，随着地势的起伏而移动，$N被地势所阻，无法进攻。\n",

        "\n$n运起"HIB"忘"HIW"情"HIY"天"HIR"书"NOR"中的绝技"HIY"「君王”"NOR"，气势有如君王驾到，锐不可档，使$N完全不敢对$n攻击。\n",

        "\n$n运起"HIB"忘"HIW"情"HIY"天"HIR"书"NOR"中的绝技"HIB"「水逝”"NOR"，身形有如流水般挪移到了一旁，使得$N招式落空了。\n",

        "\n$n运起"HIB"忘"HIW"情"HIY"天"HIR"书"NOR"中的绝技"HIR"「风流”"NOR"，身形急旋，因旋转造成的气流在$n身旁形成一道气墙，将$N的招式完全阻隔了。\n",

        "\n$n运起"HIB"忘"HIW"情"HIY"天"HIR"书"NOR"中的绝技"MAG"「我无”"NOR"，我即是无，无即是我，$n就像忽然间不见了一般消失在$N的眼前。\n",

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
        if((int)me->query("kee")<5)
                return notify_fail("你的气不够，不能练绛雪步法。\n");
        me->receive_wound("kee",5);
        return 1;
}


