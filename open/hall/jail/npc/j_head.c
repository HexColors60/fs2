
//j_master.c
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("筱孰落", ({"jail master","master"}));
        set("title", "牢房统领");
        set("nickname", "[36m一钱一命[0m");
        set("long",@LONG
    一个身着短衫的彪形巨汉，身上配着一把亮闪闪的钢刀，好像
会两下子的样子!!他是牢房的头头，你可以问问看赎人的消息。
LONG);
        set("gender", "男性");

        set("age", 35);
        set("attitude", "peaceful");
        set("score", 200000);
        set("combat_exp", 70000);

        set("str", 30);
        set("max_gin", 2000);
        set("max_kee", 2000);
        set("max_sen", 2000);
        set("int", 30);
        set("cor", 30);
        set("cps", 30);
        set("con", 30);
        set("inquiry", ([
            "赎人" : "要赎人!!??没问题...除了死牢里的我没办法...其他一律一百两!!不二价!!嘿嘿..",
        ]) );

        setup();

        set("chat_chance", 5);
        set("chat_msg", ({
            "没啥事就快滚!!老子很忙....没空跟你们这些龟儿子瞎扯!!\n",
            "啥事!!快说!!\n",
        }));
}

