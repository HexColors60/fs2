//多加一个御蜂术...by firedancer ...11/3 2000//
//加入学习hellfire的设限,2000.10.16   firedancer //
//master_yua.c //cgy
#include <ansi.h>
#include "/open/open.h"
string magic();
string ask_get_dan_sp();
string ask_get_meteor();
string ask_ribbon();
string ask_set_allow_hellfire();
string ask_orderbee();
string ask_mirror();
string ask_title();
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
			set("allow_hellfire",1);
            set("age",20);
            set("str", 34);
            set("cor", 30);
            set("cps", 50);
            set("per", 24);
            set("int", 40);
			set("adv_dancer",1);
	set("kee",16000);
	set("max_kee",16000);
	set("gin",16000);
	set("max_gin",16000);
	set("max_sen",16000);
	set("sen",16000);
	set("atman",20000);
	set("max_atman",20000);
	set("mana",14000);
	set("max_mana",14000);
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
            set_skill("order-bee",120);
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
		set("/spells/hellfire/level",75);
        set("/spells/thunder/level",100);
         set("spells/mirror/level",100);
        set("/spells/firedance/level",100);
        set("/spells/dreamwings/level",1);
                
        set("force_factor",30);
        setup();
        create_family("夜梦小筑",3,"宫主");
        carry_object("/open/dancer/obj/yuaboots.c")->wear();
                carry_object("/open/dancer/obj/maple_ribbon.c")->wield();
        carry_object("/open/dancer/obj/yuawaist.c")->wear();
//                add_money("diamond",1);
//      ob->set_amount(50);
        set("inquiry", ([
            "傅剑寒"  : "你说的是神龙山庄庄主傅剑寒吗??他是我倾慕的偶像耶!!",
                        "后三式" :  (: ask_get_dan_sp :),
                        "流星雨" :  (: ask_get_meteor :),
                        "ribbon" : (: ask_ribbon :),
             "蜂笛":(: ask_orderbee :),
//             "mirror":(: ask_mirror :),
        "hellfire":(: ask_set_allow_hellfire :),
        "地狱雷火术":(: ask_set_allow_hellfire :),
		"古舞使":(: ask_title :),
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
						if(random(100)>85)
		              command("conjure hellfire");
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

string ask_set_allow_hellfire()
{
object me=this_player();
int i;
i=random(2);
        if(me->query("class")!="dancer")
                return "抱歉了, 这是舞者的不传之秘, 我是不会告诉外人的...";
        if(me->query("allow_hellfire"))
                return "你不是会了吗?";
        if(me->query("combat_exp") < 4000000 )
                return "你的经验还太浅薄了, 多加磨练后再来找我吧...";
        if(me->query("spells/fireball/level")<100)
                return "你的火球术还不够强, 不能学地狱雷火术";
        if(me->query("spells/thunder/level")<100)
                return "你的天雷术还不够强, 不能学地狱雷火术";
        if(me->query("spells/firedance/level")<100)
                return "你的火凤飞翔还不够强, 不能学地狱雷火术";
        message_vision("月牙儿笑着说:看来$N已经有资格学习了, 我现在就把雷火真元传到你身上!!\n",me);
		message("system",HIW"月牙儿开心的说道:恭喜"HIC+this_player()->name()+HIG"历尽磨练终于成为古舞者传人.\n"NOR,users());
        me->set("allow_hellfire",1);
        me->set("adv_dancer",1);
        message_vision(HIW"一股"HIB"地狱"HIC"雷"HIR"火"HIW"真元缓缓流入$N的体内\n"NOR,me);
        if(i>0)
                me->set("title",HIG"∮"HIM"古 舞"HIG"∮"HIC"谕 雷 使"NOR) ;
        else
                me->set("title",HIG"∮"HIM"古 舞"HIG"∮"HIR"幻 火 使"NOR) ;
                me->set("spells/hellfire/level",1);
                
                return "恭喜你, 你已经学会了地狱雷火术了!!";
}

string ask_title()
{
object me=this_player();
int i;
i=random(2);
        if(me->query("class")!="dancer")
                return "妳不是舞者问这干么...???";
        if(!me->query("allow_hellfire"))
                return "妳还不够资格吧先去学学地狱雷火术吧?";
        if(me->query("title")==HIG"∮"HIM"古 舞"HIG"∮"HIC"谕 雷 使"NOR)
                return "妳已经是古舞使了吧";
        if(me->query("title")==HIG"∮"HIM"古 舞"HIG"∮"HIR"幻 火 使"NOR)
                return "妳已经是古舞使了吧";
        
		message_vision("月牙儿笑着说:好吧...我帮妳恢复妳的称号!!\n",me);
		
        
        if(i>0)
                me->set("title",HIG"∮"HIM"古 舞"HIG"∮"HIC"谕 雷 使"NOR) ;
        else
                me->set("title",HIG"∮"HIM"古 舞"HIG"∮"HIR"幻 火 使"NOR) ;
				return"妳的称号改好啰.....";
                
}


string ask_orderbee()
{
object me=this_player();
        if(!me->query_skill("order-bee"))
                return "你连御蜂术都不会, 给你蜂笛也没用\n";
        if(me->query_temp("give-order-bee"))
                return "蜂笛只能给一次, 下次再来跟我要吧。\n";
        me->set_temp("give-order-bee",1);
    new("/daemon/class/dancer/bee_flute")->move(me);
        message_vision("月牙儿拿了一只蜂笛给$N。\n",me);
                return "拿去吧, 好好保管!!可不要弄丢了!!\n";
}

string ask_mirror()
{
object me=this_player();
        if(me->query("spells/mirror"))
                return "妳不是已经学会了吗??\n";
                me->set("spells/mirror/level",1);
                return "好吧，那我就传授你‘镜月知术’!!";
}

void die()                                                                 
{    
	object winner = query_temp("last_damage_from");
	int j;

	if(!winner)
	{
	::die();
	return ;
	}
	tell_object(users(),HIW"\n‘"HIC"叶 舞 春 怜 生 "HIM"～ 似悲又喜
\t  "HIC"雷 舞 夏 吟 颂 "HIM"～ 娱也乐乎
\t\t  "HIC"枫 舞 秋 别 恨 "HIM"～ 既多也愁
\t\t\t  "HIC"雪 舞 冬 悲 降 "HIM"～ 暗藏永久"HIW"’
\n"HIG"生在这四季的轮回总是如梦一场 ～ 空也!!
\t想我"HIY"月牙儿"HIG"美丽的生命也逃不过这命运!!
\t\t而"HIR+winner->query("name")+HIG"也终将踏上这轮回之道 ～ 永无止境!!\n"NOR);

	if ( winner->query_temp("bless")==1 )
	{
	j=random(6000);
	  if( j==7 || j==77 || j== 777 || j==1111 || j==55 || j==555 || j==1000 || j==4000 || j==3333 || j==5555 )
	  {      
	  new("/open/sky/obj1/water_emblem")->move(environment(winner));
	  message_vision(HIM"\n从月牙儿的身上掉下了一件奇怪的东西!!\n"NOR,winner);
          write_file("/log/sky/water_emblem",sprintf("%s(%s) 让月牙儿掉下了水之纹章于 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}else{
	j=random(12000);
	  if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 ) 
	  {      
	  new("/open/sky/obj1/water_emblem")->move(environment(winner));
	  message_vision(HIM"\n从月牙儿的身上掉下了一件奇怪的东西!!\n"NOR,winner);
          write_file("/log/sky/water_emblem",sprintf("%s(%s) 让月牙儿掉下了水之纹章于 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}
	::die();                                                           
}