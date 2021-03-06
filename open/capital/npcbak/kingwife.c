// Tnpc.c
// 修改ES2's liu npc 
#include <ansi.h>

inherit NPC;

string ask_me(object who);

void create()
{
        set_name("钟妃", ({ "King girl", "girl" }) );
        set("title", "当今皇后");
        set("gender", "女性" );
        set("age", 22);
        set("str", 22);
        set("cor", 30);
        set("cps", 21);
        set("int", 25);
        set("per", 29);
        set("long",
                "钟妃就是当今圣上的正室, 乃为凤仪天下之皇后\n" );
        set("combat_exp", 30000);
        set("attitude", "heroism");
        set("chat_chance", 15);
        set("chat_msg_combat", ({
                "钟妃说道：大胆狂徒, 竟敢来皇城撒野？\n",
                "钟妃说道：来人啊..有刺客!!\n",
           }) );
        set("inquiry", ([
                "钟离魅": (: ask_me :),
                "魔教之徒": (: ask_me :)
        ]) );

        set_skill("unarmed", 30);
        set_skill("parry", 30);
        set_skill("dodge",30);

        setup();
  
        carry_object("/obj/cloth")->wear();
}

string ask_me(object who)
{
        int i;
        object *ob;

        if( query("revealed") ) {
                if( is_killing(who) ) return "你既然知道了我的身分，今日休想活命
！\n";
                else {
                        kill_ob(who);
                        who->fight_ob(this_object());
                        return "好个不知死活的家伙, 竟敢在我魔教左使头上撒野！纳命来！\n
";
                }
        }

        if( (random(10) < 5)
        ||      !is_fighting() )
                return "你..你..别乱说话！\n";
        set_temp("apply/attack", 80);
        set_temp("apply/dodge", 50);
        set_temp("apply/parry", 60);
        set_temp("apply/damage", 30);
        set("title", "魔教左使");
        set("nickname", HIR "钟离魅" NOR);
        message("vision",
                HIY "钟妃发出摄人的光芒，颤声说道：看来...你都知道了？
\n\n"
                "钟妃大喝一声，叫道：既然如此，老娘今天豁出去了，纳命来！\n" NOR
                "钟妃使出魔教的招术, 招数精奇，沈猛狠辣，和刚才简直判若两人！\n",
                environment(), this_object() );
        set("attitude", "aggressive");
        set("chat_msg_combat", ({
                (: this_object(), "random_move" :)
        }) );
        set("chat_msg", ({
                (: this_object(), "random_move" :)
        }) );
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
                if( !ob[i]->is_character() || ob[i]==this_object() ) continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        }
        carry_object(__DIR__"obj/blade_book");
        set("revealed", 1);
        return 0;
}

int follow_me(object ob, string dir)
{
        if( is_killing(ob) ) {
                remove_all_enemy();
                message("vision", "钟离魅大喝：你们一个也不许走！\n",
                        environment(), this_object() );
                command("go " + dir);
        }
}
