#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;
object ob1=this_object();
int have_say;

string ask_study()
{
    object ob2=this_player();
    if( ob2->query("family/master_name") =="司徒荣" && (int)ob2->query("combat_exp") >= 300000 )
    {
    ob2->set("can_study",1);
    return("这是我传家绝艺!!你首先要好好地练习基本技巧才行......\n");
    }
    else
    {
    return("[36m我不能让你学习这套掌法!![0m");
    }
}

string ask_test1()
{
    object ob2=this_player();
    if( ob2->query("family/master_name") =="司徒荣" && ob2->query("can_study",1) )
    {
    ob2->set("can_test1",1);
    ob2->set_skill("test1",1);
    return("基本技巧--插铁沙, 是要练此掌法之人先锻练自己的双掌强度, \n
    然后才能力保攻敌之时, 掌劲能透敌之体, 伤敌之脉!!先将等级提高吧!!\n");
    }
    else
    {
    return("[36m我不能让你学习这套掌法!![0m");
    }
}

string ask_test2()
{
    object ob2=this_player();
    if( ob2->query("family/master_name") =="司徒荣" && ob2->query_skill("test1",1) >=30 )
    {
    ob2->set("can_test2",1);
    ob2->set_skill("test2",1);
    return("基本技巧--拍石碑, 是要练此掌法之人在锻练自己的双掌强度后, \n
    掌握出掌时的劲道, 才能对于掌劲做到收发自如的境界!!继续加油!!\n");
    }
    else
    {
    return("[36m我不能让你学习这套掌法!![0m");
    }
}

string ask_test3()
{
    object ob2=this_player();
    if( ob2->query("family/master_name") =="司徒荣" && ob2->query_skill("test2",1) >= 30 )
    {
    ob2->set("can_test3",1);
    return("测验所指的, 乃是进入练功房中, 针对特制的石人进行对打, 只要能够击败石人
,便可以通过测试, 习得铁沙掌的入门武学!!\n");
    }
    else
    {
    return("[36m我不能让你学习这套掌法!![0m");
    }
}

string ask_test4()
{
    object ob2=this_player();
    if( ob2->query_temp("win_stone",1) && ob2->query("can_test2",1) )
    {
    ob2->set_skill("ironhand",10);
    ob2->delete("can_test1");
    ob2->delete("can_test2");
    ob2->delete_skill("test1");
    ob2->delete_skill("test2");
    ob2->set("study/ironhand",1);
    ob2->set("quests/ironhand",1);
    return("很好, 你通过了测试, 我这就传你基本的铁沙掌法!!\n");
    }
}

string ask_book()
{
    object ob2=this_player();
    object ob3=new("/open/prayer/obj/ironbook");
    if( ob2->query("quests/ironhand",1) && !present("ironbook",ob2) )
    {
    ob3->move(this_player());
    return "你务必要好好的学习我家传的绝艺!!\n";
    }
    else
    {
    return("[36m我不能让你学习这套掌法!![0m");
    }
}   

void create()
{
        set_name("司徒荣", ({"se-tu rong","se-tu","rong"}));
        set("long",@LONG

        天权门的门主！与其妻司徒知华两人分别成为圣火教八天门
        的门主．鹅鲽情深，山盟海誓．司徒荣本身所修练的武学为
        外家兵器，不过他的先天乾坤功与教主所学却也相差无几!

LONG);
        set("gender","男性");
        set("class","prayer");
        set("family/master_name","林宏升");
        set("combat_exp",1000000);
        set("attitude","heroism");
        set("age",45);
        set("title","天权门主");
        set("kee",4700);
        set("max_kee",4700);
        set("force",9000);
        set("max_force",9000);
        set("force_factor",5);
        set("max_gin",2700);
        set("max_sen",2700);
        set_skill("superforce", 80);
        set_skill("holy-force", 50);
        set_skill("cure", 40);
        set_skill("dodge", 60);
        set_skill("force",50);
        set_skill("move", 50);
        set_skill("parry", 90);
        set_skill("canon",80);
        set_skill("unarmed",60);
        set_skill("literate",40);
        set_skill("shift-steps",60);
        set_skill("universe",80);
        map_skill("force","superforce");
        map_skill("dodge","shift-steps");
        map_skill("move","shift-steps");
        map_skill("parry","universe");
        map_skill("unarmed","universe");
        set("functions/black/level",50);
        set("inquiry",([
        "铁沙掌法":"这是我家传武学, 一共分成八式!!你想要学习吗??\n",
        "学习":(: ask_study :),
        "基本技巧":"基本技巧分别是[插沙]与[拍石], 最后再通过[测验]就可以练成!!\n",
        "插沙":(: ask_test1 :),
        "拍石":(: ask_test2 :),
        "测验":(: ask_test3 :),
        "通过":(: ask_test4 :),
        "拳谱":(: ask_book :),
        ]));
        set("chat_chance",10);
        set("chat_msg", ({
        HIC+"司徒荣吟道:以无为有～以退为进～以空为乐～以众为我～!!\n"+NOR,
        }) );
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
        (: exert_function("black") :),
        }));
        setup();
    carry_object("/open/prayer/obj/emery-robe")->wear();
    carry_object("/open/prayer/obj/emery-armband")->wear();
    carry_object("/open/prayer/obj/emery-firer")->wield();
    carry_object("/open/prayer/obj/speed-ring")->wear();
    carry_object("/open/prayer/obj/hat")->wear();
    create_family("天权门",5,"门主");
    add_money("gold",5);
}

int accept_kill(object ob2)
{
        ob2->set_temp("杀夫之仇",1);
        command("say 哼!!"+ob2->name()+"我妻子会替我报仇的。");
        return 1;
}

void attempt_apprentice(object ob2)
{
        if(!ob2->query_temp("allow_3"))
        {
        command("say 没有教主的同意,我不敢擅自做主让你进门!");
        return 0;
        }
        command("smile");
        command("say 既然是教主的意思,以后你就用心地好好跟我学武吧!!");
        command("recruit "+ob2->query("id"));
        ob2->set("marks/圣火八天门",1);
        this_player()->set("title","圣火教天权门俗家弟子");
        }

void greeting(object ob2)
{
    if( ob2->query("family/master_name") =="司徒荣" && (int)ob2->query("combat_exp") > 300000 )
    {
    command("pat "+getuid(ob2));
    command("say 我看你的资质颇佳, 我有意传授你我家传的[铁沙掌法]!!\n");
    return;
    }

    if(ob2->query_temp("杀妻之仇",1))
    {
    command("angry "+getuid(ob2));
    command("say 还我贤妻[司徒知华]的命来!!!!");
    kill_ob(ob2);
    return;
    }

    if (ob2->query_skill("coldpoison", 1))
//      if ((present("five poison", ob2)) || (present("dark poison", ob2)) || (present("faint poison", ob)) || (present("rose poison", ob)) )
    {
    command("say 教主有令！！凡是学有毒术之人，杀无敕！！");
    kill_ob(ob2);
    return;
    }
    if( ob2->query("class")=="dancer")
    {
    command("say 教主有令，见到舞者-----格杀勿论！！");
    kill_ob(ob2);
    return;
    }
    return ;
}


