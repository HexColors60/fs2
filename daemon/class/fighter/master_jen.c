// master_jen.c
// Chan 22/5重新设计
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string test();
string kee_god();
string ask_yan();
string super_fighter();
void create()
  {
        set("class", "fighter");
        set_name("任正晴", ({ "master jen", "master", "jen" }) );
        set("title","泷山派第七代掌门人");
        set("nickname", "泷山奇侠");
        set("gender", "男性");
        set("age", 45);
        set("del_delay",1);
        set("attitude", "hero");
        set("long",
        "任正晴自幼生长于武学名门中，受其父「任博文”英才式的教育，薰\n"
        "陶出其严肃而谦逊的人格，身为泷山派掌门的他，以发扬泷山为己任\n"
        "，对于违反派规的弟子毫不留情，如此就可看出其严肃的个性\n");
        set("str", 48);
        set("cps", 40);
        set("per", 34);
        set("int", 38);
        set("kar", 16);
        set("fire_strike",1);
        set("super_fire",1);
        set("combat_exp",5000000);
        set("max_kee",30000);
        set("kee",30000);
        set("max_gin",15000);
        set("gin",15000);
        set("max_sen",15000);
        set("sen",15000);
        set("force"       , 15000);
        set("max_force"   , 15000);
	set("atman"       , 15000);
        set("max_atman"   , 15000);
	set("mana"       , 15000);
        set("max_mana"   , 15000);
        set("force_factor", 40);
        set("score"       , 200000);
        set("s_kee",1000);
        set("env/泷山连击","YES");
        set("max_s_kee",1000);
        set("sec_kee","tiger");
        set("inquiry",([
                 "泷山拳法":   "此为任家传承的绝学，分为「素招”、「禁断”、「奥义”三种。 ",
                 "素招":       "是泷山拳法中较易学、威力较小的招式。\n",
                 "禁断":       "泷山禁断共有「山水之气”、「吼啸山林”二招。\n"
                               "只有泷山拳法至登峰造极之际才能接受考验传授\n",
                 "奥义":       "是上任掌门任溥文将泷山拳结合浩日真气所创出的绝招。\n"
                               "称之为‘赤焰神掌’共三式\n"
                               "只有泷山绝学传人且有特别贡献才能传授\n",
                 "禁断考验":   (: test :),
                 "风青云" : (: ask_yan :),
                 "仙云之气":   (: kee_god :),
                 "玄天圣地":   (: super_fighter :),
                 "叶狂":       "三十年前横行江湖无恶不做的大魔头，被上代掌门囚禁在监牢中\n",
                 "监牢":       "在泷山的禁地中\n",
          ]));
        set("functions/kang_kee/level",100);
        set_temp("roared", 1 );
		set_temp("kang-power", 1 );
        set_skill("cure",40);
        set_skill("move",50);
        set_skill("unarmed", 120);
        set_skill("force",120);
        set_skill("parry",50);
        set_skill("dodge",50);
        set_skill("fire-kee",100);
        set_skill("literate",40);
        set_skill("henma-steps",100);
	set_skill("literate",30);
        set_skill("lungshan",100);
	set_skill("haoforce",100);

        map_skill("force", "haoforce");
        map_skill("unarmed", "lungshan");
        map_skill("dodge", "henma-steps");
        map_skill("parry", "fire-kee");
        set("chat_chance_combat",20);
        set("chat_msg_combat",({
            (: perform_action, "force.kang_kee"   :),
        }));
        create_family("泷山派", 7, "掌门人");
        setup();
            carry_object(__DIR__"ywleg")->wear();
            carry_object(__DIR__"ywboots")->wear();
            carry_object(__DIR__"ywcloth")->wear();
            carry_object(__DIR__"ywgem")->wear();
            carry_object(__DIR__"ywhelme")->wear();
            carry_object(__DIR__"ywhand")->wear();
            carry_object(__DIR__"ywsu")->wear();
            carry_object(__DIR__"armband")->wear();
               carry_object(__DIR__"star");
                carry_object(__DIR__"figring")->wield();
        add_money("gold",40);
}

int accept_object(object who, object ob)
{
  object mid;
  if( ob->query("id") == "ya-head")
  {
    destruct(ob);
    say("任正晴仔细对叶狂的头审视,说道:这竟然是‘血魔’叶狂的头。\n");
    who->set("quests/ya",1);
    if( who->query("family/family_name")=="泷山派"&&who->query_skill("lungshan",1) < 70)
	{
	 say("任正晴怒道:泷山派的武学都没有学好了,还想学什么禁技!!!\n");
	 return 0;
    }
    else if( who->query("family/family_name")=="泷山派")
     {
	 
      if(!who->query("fire_strike",1))
       {
        say("你为武林除去这万恶魔头，立下如此大的功劳!\n"
            "嗯!!好吧!!我便将泷山的终极奥义‘赤焰神掌’传授给你\n");
        who->set("fire_strike",1);
        who->set("title","泷山奥义传人");
       }
      else
       {
        say("你为武林除去这万恶魔头，立下如此大的功劳!!\n"
            "这些是我多年来收集的雪莲丹及灵芝仙丹都给你吧\n");
        mid=new("/open/gsword/obj/ff_pill");
        mid->add_amount( who->query("per")+100 );
        mid->move(who);
        mid=new("/open/gsword/obj/f_pill");
        mid->add_amount( who->query("per")+100 );
        mid->move(who);
       }
     }
     else
     {
      if(!who->query("get_force",1))
       {
        say("你为武林除去这万恶魔头，立下如此大的功劳!!\n"
            "嗯!!好吧!!我将部份内力传授给你吧!!\n");
        message_vision(HIC"任正晴将双手按住$N檀中穴，真气瞬时间打通$N的任督二脉\n",who);
        who->add("max_force",200);
        who->set("get_force",1);
       }
      else
       {
        say("你为武林除去这万恶魔头，立下如此大的功劳!!\n"
            "这些是我多年来收集的雪莲丹及灵芝仙丹都给你吧\n");
        mid=new("/open/gsword/obj/ff_pill");
        mid->add_amount( who->query("per")+100 );
        mid->move(who);
        mid=new("/open/gsword/obj/f_pill");
        mid->add_amount( who->query("per")+100 );
        mid->move(who);
       }
     }
} else
  if( ob->query("id") == "tiger-head")
  {
    destruct(ob);
    if((who->query("family/family_name") == "泷山派") && (who->query("lungshan_test") != 1))
     {
      say("任正晴仔细的看了看!!,说:这不是独角虎的头!!。\n");
      return 0;
     }
    if((who->query("family/family_name") != "泷山派") || who->query("super_fire"))
     {
      say("任正晴仔细的看了看!!,说道:果然是恶兽的头!!感谢你为武林除此大害。\n");
      who->set("go_ya",1);
      return 0;
     }
    say("任正晴仔细的看了看!!说道:这果然是残害无数百姓恶兽--独角虎--的头。\n");
    if(!who->query("super_fire",1))
     {
     say("任正晴道:你果然不负我所期望，完成这艰难的任务!!\n"
         "好!!这是泷山拳禁断技的奥密就传授给你吧!!,望你更上一层楼。\n");
     who->set("super_fire",1);
     who->set("title","泷山绝学传人");
      who->set("go_ya",1);
     }
  }
}

int accept_fight(object who)
{
 command("say 果然英雄出少年。\n");
 who=this_player();
 fight_ob(who);
 command("cmd usekee "+who->query("id"));
 command("charge "+who->query("id"));
// command("perform force.kang-power");
  return 1;
}

int accept_kill(object who)
{
 command("say 找死!!!\n");
 who=this_player();
 kill_ob(who);
 command("cmd usekee "+who->query("id"));
 command("charge "+who->query("id"));
// command("perform force.kang-power");
  return 1;
}
  void attempt_apprentice(object ob)
{
        if(this_player()->query("class")!="fighter")
        {
                command("sigh");
                command("say 你不是武者，我不能收你。\n");
                return;
        }
      if((int)ob->query("cps") <20 )
{
          command("sigh");
          command("say 学泷山拳法必须有恒心，敝人观之"+ RANK_D->query_respect(ob) + "的资质似乎不宜！\n");

return;
        }

      command("hmm");
      command("pat" + ob->query("id"));
      command("recruit "+ob->query("id"));
}

// by babe
void heart_beat()
{
        if( !is_fighting() ) {
                if( query("sen") < query("eff_sen") ) // 125
                        command( "exert refresh" );
                if( query("force") < query("max_force") ) // 1 -> 5.035
                        command( "ex 160" );
                if( query("eff_kee") < query("max_kee") ) // 35
                        command( "10 exert heal" );
                if( query("gin") < query("eff_gin") ) // 125
                        command( "exert regenerate" );
                if( query("kee") < query("eff_kee") ) // 125 -> 300
                        command( "3 exert recover" );
        
        }
		if(is_busy() ){
		if(30>random(100)){
		message_vision(HIW"\n只见$N暴起所有"HIY"真气内劲"HIW"，$N全身陇罩在一股"HIC"绽蓝气劲"HIW"中，赫然已解开身上被封的穴道。\n"NOR,this_object());
        delete_busy();
		}
		}
		::heart_beat();
}

string ask_yan()
{
  object me;
  me=this_player();
  if( me->query("fyan")==5)
{
command("say 您说风青云前辈ㄚ,昨天他曾来找我商量欲借我陇山与刘全书雪苍之力,以对付血魔庞大的势力,谈完后..他就往雪苍去了。\n ");
me->set("fyan",6);
}
  else
    {
   command("say 我不清处呦~。\n");
    }
}

string test()
{
 object me;
 me=this_player();
 if(me->query("family/family_name") != "泷山派")
  {

   return "任正晴怒道:不是泷山弟子问那怎么多做什么!!!!\n";
  }
 if(me->query_skill("lungshan",1)   < 70)
  {
   return "任正晴怒道:泷山派的武学都没有学好了,还想学什么禁技!!!\n";
  }
 say("任正晴沈吟一下!!!\n");
 say("任正晴道:最近中央译站往平南城的方向,听说有一只独角虎横行,危害许无数的百姓!!\n");
 say("任正晴续道:只要你除此大害!!我就将禁技传授给你!!!\n");
 me->set("lungshan_test",1);
}
string kee_god()
{
 object me;
 me=this_player();
 if(!me->query("ask_god_kee"))
  {
   return "任正晴道:此事是武林中重大秘传!!恕难奉告!!!!\n";
  }
 say("任正晴沈思了一下!!!\n");
 say("任正晴道:独孤云既然都跟你说了..我就告诉你吧!!\n");
 say("任正晴续道:仙云之气在天灵谷之中,但要进天灵谷必须要有青龙之气及天灵石才能进!!\n");
 say("任正晴又道:至于天灵谷的位置的话!!在雪苍山之中自己找吧!!\n");
 me->set("ask_god_kee",2);
}
string super_fighter()
{
 object me;
 me=this_player();
 if((me->query("class") != "fighter") || (!me->query("ask_super_fighter")) )
  {
   return "任正晴道:此地为武者传说圣地,恕难奉告!!!!\n";
  }
 if((me->query("family/family_name") == "泷山派") && (me->query("title") != "泷山奥义传人"))
  {
   return "任正晴怒道:连自己门派的秘奥义都没有学会了,问那么多做什么!!!\n";
  }
 if((me->query("family/family_name") == "雪苍派") && (me->query("title") != "雪苍绝学传人"))
  {
   return "任正晴怒道:连自己门派的绝学都没有学会了,问那么多做什么!!!\n";
  }
 say("任正晴沈思了一下!!!\n");
 say("任正晴吟诗道:------雪~山~深~岭~中、苍~天~一~柱~峰-----\n");
 say("任正晴续道:下二句你就去问刘全书吧。!!\n");
 say("任正晴最后道:句中的涵意就自己体会吧。!!\n");
 me->set("ask_super_fighter",1);
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
	tell_object(users(),"\n\t[1;37m～～[36m长江后浪推前浪 前浪死在沙滩上[1;37m～～[0m\n"+
	"\n\t[1;37m想不到泷山掌门[36m任正晴[37m竟被击败,看来武林将以[33m"+winner->query("name")+"[1;37m为[1;31m至尊[1;37m了!![0m\n");

	if ( winner->query_temp("bless")==1 )
	{
	j=random(6000);
	  if( j==7 || j==77 || j== 777 || j==1111 || j==55 || j==555 || j==1000 || j==4000 || j==3333 || j==5555 )
	  {      
	  new("/open/sky/obj3/fire_feather")->move(environment(winner));
	  message_vision(HIM"\n从任正晴的身上掉下了一件奇怪的东西!!\n"NOR,winner);
          write_file("/log/sky/fire_feather",sprintf("%s(%s) 让任正晴掉下了火之焰羽于 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}else{
	j=random(12000);
	  if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 ) 
	  {      
	  new("/open/sky/obj3/fire_feather")->move(environment(winner));
	  message_vision(HIM"\n从任正晴的身上掉下了一件奇怪的东西!!\n"NOR,winner);
          write_file("/log/sky/fire_feather",sprintf("%s(%s) 让任正晴掉下了火之焰羽于 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}
 :: die();
}
