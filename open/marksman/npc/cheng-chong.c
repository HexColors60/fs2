#include <ansi.h>
#include "/open/open.h"
inherit F_VENDOR;
void create()
{
        set_name("陈总",({"cheng chong","cheng","chong"}));        set("gender", "男性" );
        set("age",40);
        set("long", "天龙客栈的掌柜 , 整天在那里数着不完的银票 .\n");
        set("attitude", "friendly");
        set("combat_exp",20000);
        set("nickname",HIG"财迷心窍"NOR);
        set("dodge",50);
        set("parry",50);
        set("unarmed",50);
        set("chat_chance",20);
        set("chat_msg",({
        "陈总惊慌的说：我可是没有什么钱喔，你去找别人吧。\n",
        }));

        setup();
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
say("陈总说道: 这位"+RANK_D->query_respect(ob)+"你好 , 来吃点东西吧 !\n");
return;
}
int accept_kill(object ob)
{
 command("say 天呀!救命呀!有人要抢劫呀!");
 command("kill"+ob->query("id"));
return 1;
}
int accept_fight(object ob)
{
command("say 你好烦喔!!我忙着数钱都来不急了，走开走开别烦我数钱。");
return 0;
}
