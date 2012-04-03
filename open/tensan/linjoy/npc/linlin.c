#include <ansi.h>
string magic();
inherit NPC;
string ask_master();
string ask_badman();
string ask_linjoy();
string ask_tensan();
void create()
{
            set_name("铃儿",({"lin girl","girl"}));
            set("long","她来自天山，正在到处找人救她的师父，看她着急的模样真是美若天仙!!\n");
            set("gender","女性");
            set("nickname",HIY"小师妹"NOR);
	    set("title",HIW"天山"+BMAG"灵鹫宫"NOR);
            set("combat_exp",1000000);
            set("attitude","heroism");
            set("age",50);
            set("str", 50);
            set("cor", 50);
            set("cps", 50);
            set("per", 50);
            set("int", 50);
          set("kee",100000);
          set("max_kee",100000);
          set("gin",100000);
          set("max_gin",100000);
          set("sen",100000);
          set("max_sen",100000);
          set("atman",30000);
          set("max_atman",30000);
          set("mana",30000);
          set("max_mana",30000);
          set("force",30000);
          set("max_force",30000);
            set_skill("parry",200);     
            set_skill("force",200);
            set_skill("literate",200);
            set_skill("move",200);
            set_skill("dodge",200);
            set_skill("unarmed",150);      
        set_temp("apply/armor",70);     
        set("force_factor",30);
          set("inquiry",([
         "天山"     :  (: ask_tensan :),
         "灵鹫宫"   :  (: ask_linjoy :),
         "师父"     :  (: ask_master :),
         "奸人暗算" :  (: ask_badman :),
         "李秋水"   :  "我也不晓得为何她们师姐妹会如此恨着对方\n",
    ]));

        setup();
      
}

void init()
{ 
  add_action("do_nod","nod");
  add_action("do_shake","shake");
  remove_call_out("check_kill");
  call_out("check_kill",1,this_player()); 
}

void check_kill(object me)
{  
  object mark=new("/open/tensan/obj/tensan-mark");	
  if(me->query_temp("kill_murofu")==1 && me->query_temp("kill_mechoufen")==1
  && me->query_temp("kill_kau")==1 && me->query_temp("kill_shion")==1
  && me->query_temp("kill_poison")==1 && me->query_temp("kill_wind")==1
  && me->query_temp("kill_thunder")==1 && me->query_temp("kill_water")==1
  && me->query_temp("kill_fire")==1
  && me->query("tensan/accept_help")==1 && !present("tensan mark",me))
  {   
     command("say 看来你的实力不差，这是天山通行令，有了这个令牌就可以自由进出天山了。");  
     message_vision("$N交给$n一块「天山通行令”。\n",this_object(),me);    
     mark->move(me); 	
     me->set_temp("tensan/get_enter",1);
     me->delete_temp("kill_murofu",1);
     me->delete_temp("kill_mechoufen",1);
     me->delete_temp("kill_kau",1);
     me->delete_temp("kill_shion",1);
     me->delete_temp("kill_poison",1);
     me->delete_temp("kill_wind",1);
     me->delete_temp("kill_thunder",1);
     me->delete_temp("kill_water",1);
     me->delete_temp("tensan/start_test",1);
  }else if(present("tensan mark",me))
     command("say 找不到天山吗？天山位于大陆西北方，你仔细找找应该就可以找到");   
   else if(me->query_temp("tensan/start_test")==1)
     command("say 怎么这么快就回来了，你好像还没通过我的测试耶？");
   else if(me->query_temp("tensan/get_enter")==1 || me->query("tensan/accept_help")==1)
     {
     	command("say 令牌不见了？那就再接受一次我的测试吧！打败那九个人再来找我");
        me->set_temp("tensan/start_test",1);
     }
}
void heart_beat()
{
	object me=this_player();
        object ob=this_object();
        mixed enemy;
	int i,j;
        enemy=all_inventory(environment(ob));
	i=sizeof(enemy);
       
        :: heart_beat();
}

string ask_master()
{
    object me=this_player();
    if(me->query_temp("tensan/ask_linjoy")==1)
    {   
      command("sigh");
      command("say 我师父就是鼎鼎大名的天山童姥，可是她遭奸人暗算现在下落不明");        
      me->set_temp("tensan/ask_master",1);
      me->delete_temp("tensan/ask_linjoy",1);
    }else command("say 我师承何处，要你管喔！");
    return "";
}

string ask_badman()
{
    object me=this_player();
    if(me->query_temp("tensan/ask_master")==1 && me->query_temp("tensan/start_test")!=1)   
    {
      command("say 师父就是被她师妹李秋水暗算才会丧失功力，大侠你愿意帮我找师父吗？");        
      me->delete_temp("tensan/ask_master",1);
      me->set_temp("tensan/ask_badman",1);
    }else if(me->query_temp("tensan/start_test")==1)
       command("say 你不是已经答应要帮我救师父了，还不赶快通过我的测试。");
     else command("say 你在说什么鬼话连篇阿");
    return "";
}

string ask_linjoy()
{
    object me=this_player(); 
    if(me->query_temp("tensan/ask_tensan")==1)   
    {
      command("say 灵鹫宫是我师父一手创建的，师父的武功可说是天下第一");          
      me->set_temp("tensan/ask_linjoy",1);
      me->delete_temp("tensan/ask_tensan",1);
    }else command("say 你是从那听来的，快说？");
    return "";
}

string ask_tensan()
{
    object me=this_player(); 
    command("say 天山这个地方充满着神奇的传说，我们灵鹫宫就在天山上");          
    me->set_temp("tensan/ask_tensan",1);
    return "";
}
 
int accept_fight(object ob)
{
	object me=this_player();
        command("say 我还忙着找人救师父，大侠还是另寻他人吧！\n");    
        return 0;
}
int accept_kill(object ob)
{
        command("say 如果把我杀了，灵鹫宫的人不会放过你的!!!\n"); 
        return 1;
}

int do_nod()
{
object me = this_player();
if(me->query_temp("tensan/ask_badman") != 1 && me->query_temp("tensan/start_test")==1) 
   return 0;
 me->set("tensan/accept_help",1);
 me->set_temp("tensan/start_test",1);
 me->delete_temp("tensan/ask_badman",1);
 command("jump");
 command("say 终于找到人愿意帮我了，不过不知道你实力如何？");
 command("say 听说武林上有九个人拥有神奇的能力，敌人越强他们也就越强");
 command("hmm");
 command("say 这样好了，如果你能打败这九人，我就告诉你进入天山的方法");
 return 0;
}

int do_shake()
{
  object me = this_player();
  if(me->query("tensan/ask_badman") != 1)
        return 0;
  command("inn");
  command("say 怎么办，再找不到人救师父就惨了");
  return 0;
}

void die()                                                                 
{    
	object winner = query_temp("last_damage_from");
        if(!winner)
	{
	::die();
	return ;
        }
        winner->set("tensan/kill_lin",1);	
        log_file("/tensan/kill_linlin", sprintf("%s(%s) 杀死灵鹫宫铃儿 on %s\n"
        ,winner->query("name"),winner->query("id"), ctime(time()) ));

	::die();                                                           
}