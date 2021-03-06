//master_yua.c //cgy
#include <ansi.h>
#include "/open/open.h"
string magic();
string ask_get_dan_sp();
string ask_get_meteor();
string ask_ribbon();
inherit NPC;
inherit F_MASTER;
void create()
{
            object ob;
            set_name("月牙儿",({"master yua","yua"}));
            set("long","她是镜月岛二位美丽的岛主之一，擅长舞蹈，据说
她的舞蹈之美会令人以为仙女下凡身处仙境。\n");
            set("gender","女性");
            set("class","dancer");
            set("nickname","霓裳仙子");
            set("combat_exp",5000000);
            set("attitude","heroism");
            set("age",20);
            set("str", 34);
            set("cor", 30);
            set("cps", 50);
            set("per", 24);
            set("int", 40);
          set("kee",30000);
          set("max_kee",30000);
          set("gin",1600);
          set("max_gin",1600);
          set("atman",2000);
          set("max_atman",2000);
          set("mana",400);
          set("max_mana",400);
          set("force",2000);
          set("max_force",2000);
            set_skill("array",60);
            set_skill("parry",60);
            set_skill("spells",50);
            set_skill("magic",120);
            set_skill("cure",60);
            set_skill("force",60);
            set_skill("literate",70);
            set_skill("move",90);
            set_skill("dodge",100);
            set_skill("sword",50);
            set_skill("unarmed",70);
            set_skill("paull-steps",130);
            set_skill("dremagic",100);
            set_skill("dreamforce",90);
            set_skill("dreamdance",100);
        map_skill("magic","dremagic");
        map_skill("dodge","paull-steps");
        map_skill("force","dreamforce");
        map_skill("move","paull-steps");
        map_skill("unarmed","dreamdance");
        set_temp("apply/armor",70);
		set("get_dan_sp",1);
		set("/spells/reflection/level",100);
		set("/spells/confuse/level",100);
        set("/spells/fireball/level",100);
        set("/spells/thunder/level",100);
        set("/spells/firedance/level",100);
        set("/spells/dreamwings/level",1);
		
        set("force_factor",30);
        setup();
        create_family("夜梦小筑",3,"宫主");
        carry_object("/open/dancer/obj/yuaboots.c")->wear();
		carry_object("/open/dancer/obj/maple_ribbon.c")->wield();
        carry_object("/open/dancer/obj/yuawaist.c")->wear();
		add_money("diamond",1);
//      ob->set_amount(50);
        set("inquiry", ([
            "傅剑寒"  : "你说的是神龙山庄庄主傅剑寒吗??他是我倾慕的偶像耶!!",
			"后三式" :  (: ask_get_dan_sp :),
			"流星雨" :  (: ask_get_meteor :),
			"ribbon" : (: ask_ribbon :)
        ]));
        set("chat_chance_combat",60);
        set("chat_msg_combat",({
         (: magic :),
        }));
}
void init()
{       object ob;
        add_action("do_join","join");
        set_heart_beat(1);
}
void heart_beat()
{
        if( is_fighting() ){
		      if(query_temp("ref_shield")!=1)
		      command("conjure reflection");
                if( query("kee") < query("eff_kee") )
                        command("exert recover");
        }
        else{
                if( query("eff_kee") < query("max_kee") )
                        command("conjure dreamcure");
        }
        :: heart_beat();
}
  void attempt_apprentice(object ob)
{
        command("l "+ob->query("id"));
      if(this_player()->query("class")!="dancer")
      {
          command("hammer"+ob->query("id"));
          command("say 先去加入舞者公会再来吧\n");
          return;
      }
        command("smile");
        command("nod");
        command("chat 这个世界上又多了一个美丽的舞者了，希望各位多多爱护他..\n");
         ob->query("no_recruit");
        command("recruit "+ob->query("id"));
		new("/open/dancer/obj/ribbon")->move(ob);
        message_vision("月牙儿给了$N一条七彩缎带 .\n",ob);
        command("say 这是咱们夜梦小筑的信物 ,务必妥善保存 !");
}
string ask_ribbon()
{
        if(present("ribbon",this_player()))
		   return "妳不是有了吗？";
		if(this_player()->query("class")!="dancer")
		   return "妳不是舞者要那个做什？？";
        else
		{
        command("say 唉 , 怎么那样不小心呢 !");
        new("/open/dancer/obj/ribbon")->move(this_player());
        return "希望妳能好好保管 , 别再弄不见啦 !\n";
        }
           
}
string ask_get_dan_sp()
{ 
 if(this_player()->query("get_dan_sp")==1)
  return "妳不是学过了？？";
 if(this_player()->query("class")!="dancer")
      {
          command("stare"+this_player()->query("id"));
          return "妳问那么多干嘛？";
      }
 if((int)this_player()->query("combat_exp") < 500000)
	   return "等妳经验值高些再来吧！";
 else
  {
 command("say 很好.....我就将后三式传授于妳...\n");
 this_player()->set("get_dan_sp",1);
  return "希望妳努力将舞者绝学发扬光大";
 }
}
string ask_get_meteor()
{ 
 if(this_player()->query("spells/meteor/level")==1)
  return "妳不是学过了？？";
 if(this_player()->query("class")!="dancer")
      {
          command("stare"+this_player()->query("id"));
          return "妳问那么多干嘛？";
      }
 if((int)this_player()->query_temp("allow_learn")!= 1)
	   return "先通过我师妹的考验再说吧！";
 else
  {
 command("say 很好.....我就将终极火焰术流星雨传授于妳...\n");
 this_player()->set("spells/meteor/level",1);
 message("system",HIW"月牙儿开心的说道:有了"+this_player()->name()+"的帮助定能使舞者更加发扬光大.\n"NOR,users());
 return "今后要更加努力喔";

 }
}
string magic()
{       
        command("conjure confuse");
        command("conjure fireball");
		command("conjure reflection");
        command("conjure firedance");
        command("conjure thunder");
        command("conjure dreamwings");
        return "\n";
}
 
int accept_fight(object ob)
{
        command("say 小女子怎是您的对手呢??\n");
		command("conjure reflection");
		command("conjure dreamwings");
		command("conjure confuse");
        message_vision( this_object()->name()+"一付弱不禁风的样子。\n",ob);
        return 1;
}
int accept_kill(object ob)
{
        command("say 没想到你忍心欺负弱小女子，那我就不客气了!!!\n");
		command("conjure reflection");
		command("conjure dreamwings");
		command("conjure confuse");
        return 1;
}
int do_join()
{
        object ob=this_player();
        command("shake"+ob->query("id"));
        return notify_fail("想当舞者要去找我师妹水灵儿才行喔!!\n");
}
