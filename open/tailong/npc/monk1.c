inherit NPC;
void create()
{
        set_name("小僧",({"monk"}));
        set("gender","男性");
        set("class","scholar");
        set("combat_exp", 1000);
        set("attitude","peaceful");
        set("age",15);
        set("chat_chance", 50);
        set("chat_msg", ({
        "小僧说道: 施主您好,这里是崇圣寺。\n",
        "小僧说道: 施主,如果您有事要找方丈,可以入内请问接待师兄。\n",
        }));
        set("inquiry", ([
        "崇圣寺" : "这里就是崇圣寺,不过一般人都称这里为天龙寺",
"天龙寺" : "这里就是了!",
        ]));
        set("force",150);
        set("max_force",150);
        set("max_kee",300);
        set("kee",300);
        set("force_factor", 1);
        set_skill("force",20);
        set_skill("unarmed",30);
        set_temp("apply/dodge",30);
        setup();
      add_money("silver",1);
}
