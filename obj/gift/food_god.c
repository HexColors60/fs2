// story:food_god.c

#include <ansi.h>

string give_gift();

private mixed *story = ({
    "太白金星：唉！肚子好饿阿，食神阿，你有没有东西可以给我吃阿？",
    "食神：真是不巧，厨房里面的东西都被斗战胜佛拿去吃了，只剩下一颗鸡蛋。",
    "太白金星：鸡蛋有啥好吃的阿？？？",
    "食神：开玩笑，我可是食神耶，看我的，喝～～～",
    "太白金星：哇！少林绝学！火～～云～～掌！！！",
    "转眼间，生鸡蛋已经变成了一片香喷喷的荷包蛋。",
    "忽然间，食神的手一阵抽筋，已经煎好的荷包蛋也跟着往下掉。",
    (: give_gift :),
    "食神：哎呀！我忘记这招只能在刚上完厕所才可以使用．．．",
    "太白金星：．．．．．．",
});

void create()
{
        seteuid(getuid());
}

mixed query_story_message(int step)
{
        return step < sizeof(story) ? story[step] : 0;
}

string give_gift()
{
        STORY_D->give_gift("/obj/gift/hobowdan", 1,
                           HIM "\n「啪”的一声一片香喷喷的荷包蛋掉在你面前。\n\n" NOR);
        return "太白金星急道：啊～～我的蛋蛋！！";
}
