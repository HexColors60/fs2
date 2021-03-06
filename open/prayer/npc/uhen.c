#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;
object ob1=this_object();
int have_say;
void create()
{
        set_name("葛梁青", ({"ka lian-gin","ka","lian-gin"}));
        set("long",@LONG

        玉衡门的门主！西域土生土长的人士，是西域第一大美人, 可
        是却跑来加入圣火教, 并且对于轻功异常喜爱, 一双快腿倒也
        不输给天上的飞禽!!

LONG);
        set("gender","女性");
        set("class","prayer");
        set("family/master_name","林宏升");
        set("combat_exp",1000000);
        set("attitude","heroism");
        set("age",28);
        set("title","玉衡门主");
        set("kee",5850);
        set("max_kee",5850);
        set("force",9000);
        set("max_force",9000);
        set("max_gin",3800);
        set("max_sen",3800);
        set("force_factor",5);
        set_skill("holy-force", 40);
        set_skill("superforce", 80);
        set_skill("cure", 30);
        set_skill("dodge", 90);
        set_skill("force",60);
        set_skill("move", 90);
        set_skill("canon", 80);
        set_skill("parry",60);
        set_skill("unarmed",50);
        set_skill("literate",20);
        set_skill("shift-steps",90);
        set_skill("universe",60);
        map_skill("force","superforce");
        map_skill("dodge","shift-steps");
        map_skill("move","shift-steps");
        map_skill("parry","universe");
        map_skill("unarmed","universe");
        set("functions/white/level",40);
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
        (: perform_action("force.white1") :),
        (: exert_function("white") :),
        }));
        setup();
    add_money("gold",5);
    carry_object("/open/prayer/obj/emery-robe")->wear();
    carry_object("/open/prayer/obj/speed-ring")->wear();
    carry_object("/open/prayer/obj/emery-armband")->wear();
    carry_object("/open/prayer/obj/emery-belt")->wear();
    add_money("gold",5);
        create_family("玉衡门",5,"门主");
}

void attempt_apprentice(object ob)
{
        if(!ob->query_temp("allow_5"))
        {
        command("say 没有教主的同意,我不敢擅自做主让你进门!");
        return 0;
        }
        command("smile");
        command("say 既然是教主的意思,那你就进入我玉衡门吧!");
        command("say 圣火教的绝学博大精深,可不是那么好学的!");
        command("say 想学得绝顶轻功就得好好修习腿部的功力!");
        command("recruit "+ob->query("id"));
        ob->set("marks/圣火八天门",1);
        this_player()->set("title","圣火教玉衡门俗家弟子");
        }
void greeting(object ob)
{
        if (ob->query_skill("coldpoison", 1))
//      if ((present("five poison", ob)) || (present("dark poison", ob)) || (present("faint poison", ob)) || (present("rose poison", ob)) )
      {
       command("say 教主有令！！凡是学有毒术之人，杀无敕！！");
        kill_ob(ob);
     }
       if( ob->query("class")=="dancer")
        {
        command("say 教主有令，见到舞者-----格杀勿论！！");
        kill_ob(ob);
     }
    return;
}
