//by sueplan -五儒2
//因为抓plan的字串怪怪的, so修改bu sueplan
//会放lotch及会抓plan
#include <ansi.h>
#include "/open/open.h"
inherit NPC;
int done=0;


void create() {
        set_name("欧阳之修",({"scholar show","show","scholar"}));
        set("class","scholar");
        set("nickname","$HIR$无可匹敌$NOR$");
        set("title","五儒之尊");
        set("long",
        "\n，为儒门五儒生中欧阳尚礼之师，以武艺高超
闻名，并且欧阳一派古自得儒门孔老夫子之弟子
曾参教之，门风稳建。\n");
        set("inquiry", ([
        "曾参" : "祖师曾参为我一族之尊师, 并且为虚兵, 铁索, 奇袭之计之祖。",
        ]));
        set("str",40);
        set("cor",40);
        set("cps",40);
        set("gender","男性");
        set("attitude","heroism");
        set("family/family_name","儒门");
        set("quests/lotch","1");
        set("max_gin",13000);
        set("max_kee",10000);
        set("max_sen",13000);
        set("max_force",8000);
        set("age",93);
        set("force",10000);
        set("force_factor",20);
        set("combat_exp",8000000);
        set("score",9000000);
        set_skill("stabber",150);
        set_skill("dodge",150);
        set_skill("move",120);
        set_skill("parry",120);
        set_skill("knowpen",100);
        set_skill("god-plan",100);
        set_skill("plan",120);
        set_skill("force",200);
        set_skill("poetforce",150);
        set_skill("winter-steps",100);
        map_skill("plan","god-plan");
        map_skill("dodge","winter-steps");
        map_skill("move","winter-steps");
        map_skill("force","poetforce");
        map_skill("stabber","knowpen");
        map_skill("parry","knowpen");
        set_temp("apply/armor",100);
        set_temp("apply/defense",100);
        set_temp("apply/damage",100);
        set_temp("apply/attack",100);

        set("functions/movedown/level",100);
        set("functions/finger/level",100);
set("chat_chance_combat", 100);
set("chat_msg_combat",({
(: perform_action("stabber.movedown") :),
(: perform_action("stabber.finger") :),
(: perform_action("plan.false") :),
(: perform_action("plan.lock-link") :),
}));
        set("chat_chance",50);
        set("chat_msg",({
        }));
setup();
        carry_object("/open/scholar/room/newplan/obj/test");
        carry_object("/open/scholar/room/newplan/obj/pen")->wield();
        add_money("gold",50);
 }
void init()
{
add_action("do_action","",1);
        set_heart_beat(1);
}
int do_action(string str)
  {
        object who=this_player();
        if(str)
        {
        if(strsrch(str,"plan.speed")!=-1)
        {
          command("say 愚蠢呀!!难到你不知道奇袭之计是我所创的吗?!\n");
          write("\n你见欧阳之修态自若, 就破解了眼前的计谋!!!\n");
          kill_ob(who);
          command("perform stabber.finger");
          who->start_busy(5);
          return 1;
        }
        if(strsrch(str,"plan.flase")!=-1)
        {
          command("say 虚兵之计是最基本的计谋, 我会有不懂之理??\n");
          write("\n你见欧阳之修态自若, 就破解了眼前的计谋!!!\n");
          kill_ob(who);
          command("perform stabber.finger");
          who->start_busy(5);
          return 1;
        }
        if(strsrch(str,"plan.lock-link")!=-1)
        {
          command("say 铁锁连环我研究的方法可比你多着呢!!敢对我用?\n");
          write("\n你见欧阳之修态自若, 就破解了眼前的计谋!!!\n");
          kill_ob(who);
          command("perform stabber.finger");
          who->start_busy(5);
          return 1;
        }
        }
return 0;
}
int accept_kill(object who,object me)
{
        who=this_player();
        me=this_object();
        command("wield pen");
        command("say 愚蠢!!你以为我会一个人对付你吗?");
        command("kill "+who->query("id"));
        command("use lotch");
        command("use lotch");
        command("use lotch");
        me->add("sen",200);
        command("perform stabber.movedown");
        return 1;
}

int accept_fight(object who)
{
        who=this_player();
        command("say 如果不敢和我较量, 那就别来这边送死!!");
          return 0;
}
void die()
{
object winner = query_temp("last_damage_from");
winner->set_temp("ko_show",1);
:: die();
}
