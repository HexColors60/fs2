//copy from cage,re-edit from ccat

#include <ansi.h>
inherit NPC;

void create()
{
        set("title",RED"嗜血剑"NOR);
        set_name("赵高", ({"chou-kau","kau","chou"}));
        set("age",55);
        set("long","曾为仙剑高手之一,后因杀人过多,而被郑士欣逐出仙剑.\n");
        set("gender","男姓");
		set("str",30);
        set("con",30);
        set("max_kee",50000);
        set("max_gin",50000);
        set("max_sen",50000);
        set("kee",50000);
        set("gin",50000);
        set("sen",50000);
        set("combat_exp",500000);
        set("max_force",10000);
        set("force",100000);
        set("force_factor",15);
        set_skill("dodge",120);
        set_skill("parry",120);
        set_skill("move",120);
        set_skill("force",250);
        set_skill("sha-steps",120);
        set_skill("sword",120);
        set_skill("shasword",100);
        set("inquiry",([
            "郑士欣" : "哼! 那自大的死老头,只教剑不问仙,不知误了仙剑多少人材.\n",
            "仙剑剑术":"仙剑剑术乃包含<仙术>与剑术,只有仙术与剑术并重,"
                      +"才算真正学成仙剑武功.\n",
            "仙术":"仙剑仙术以失传多时,不过却在我手中光复,就是我手中这把<火龙剑>!!",
            "火龙剑":"呵呵...试试便之...来过几招吧!\n",
            ]));
        set("chat_chance",5);
        set("chat_msg",({
            "赵高说:有朝一日,我必杀回仙剑,以报今日之耻.\n",
            "赵高说:<郑士欣>那老猴子,以为<仙剑剑术>就是如此吗?\n没有 仙,只有 剑,"
            +"何言仙剑? 可笑啊...\n",
            }));
//        set("chat_chance_combat",20);
//        set("chat_msg_combat",({
//           (: perform_action,"sword.sha_kee" :)
//             }));
        map_skill("dodge","sha-steps");
        map_skill("move","sha-steps");
        map_skill("sword","shasword");
        map_skill("parry","shasword");
        set_temp("apply/armor",100);
        set_temp("apply/damage",80);
        set_temp("apply/defense",90);
        set_temp("apply/dodge", 20);
        set_temp("apply/parry", 50);

        setup();
        carry_object("/open/common/obj/pill2")->set_amount(10);
        carry_object("/open/ping/obj/poison_pill")->set_amount(3);  
        add_money("gold",25);
}

int accept_kill(object me)
{
    call_out("change",1,me);
    return 1;
}
int accept_fight(object me)
{
      command("say 我从来都不接受比试的，去找别人吧。");
        return 0;
}

void change(object ob)
{
	object mob,obj;
    int exp;
	mob=this_object();
    exp =ob->query("combat_exp",1);
    if( exp > 150000)
    {
      exp = exp * 1.5;
      set("combat_exp",exp);
    }
    if(!query("change"))
    {
      obj=new("/open/main/obj/firesword");
      obj->move(this_object());
      obj->set("material","crimsonsteel");     
      command("wield sword");
      set("wield",1);
      set("change",1);
	  set("max_kee",50000);
	  set("max_gin",50000);
	  set("max_sen",50000);
	  set("kee",50000);
	  set("gin",50000);
	  set("sen",50000);
      set("family/family_name","仙剑派");
      set("class","swordsman");
      set("functions/sha_kee/level",100);
      set("functions/swordkee/level",100);
	  command("say 实在太小看我的本领了，今天就拿出我的真本事让你看看吧!!");
	}
    return;
}

void heart_beat()
{
 object env,mob,*enemy,target;
 int i,kee;
 mapping exit;
 string *exit_name;

 mob = this_object();
 env = environment(mob);
 
 if(mob->is_fighting() && random(100) < 12)
 {
   command("sword_fire");
 }
 
 if(mob->is_fighting() && random(10) > 3 && mob->query("change") )
 {
 command("perform sword.sha_kee");
 }

 if((mob->query("kee")<mob->query("max_kee")*0.3) && (random(100) < 25) )
 {
   command("large pill"); 
 }

 if((mob->query("kee")<mob->query("max_kee")*0.2) && (random(100) < 20) )   
 {
   exit = env->query("exits");
   exit_name = keys(exit);
   i = random(sizeof(exit_name));
   command(exit_name[i]);
   i = random(sizeof(exit_name));
   command(exit_name[i]);
 }
   
   set_heart_beat(1);
   ::heart_beat();
   
}

void die()                                                                 
{    
	object winner = query_temp("last_damage_from");
	object obj = query_temp("weapon");
	int j;
        if(obj)
          obj->set("material","steal"); 
        if(!winner)
	{
	::die();
	return ;
        }
        winner->set_temp("kill_kau",1);
	if ( winner->query_temp("bless")==1 )
	{
	j=random(6000);
	  if( j==7 || j==77 || j== 777 || j==1111 || j==55 || j==555 || j==1000 || j==4000 || j==3333 || j==5555 )
	  {      
	  new("/open/sky/obj4/wish_shells")->move(environment(winner));
	  message_vision(HIM"\n从赵高的身上掉下了一件奇怪的东西!!\n"NOR,winner);
          write_file("/log/sky/wish_shells",sprintf("%s(%s) 让赵高掉下了希望之贝壳于 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}else{
	j=random(12000);
	  if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 ) 
	  {      
	  new("/open/sky/obj4/wish_shells")->move(environment(winner));
	  message_vision(HIM"\n从赵高的身上掉下了一件奇怪的东西!!\n"NOR,winner);
          write_file("/log/sky/wish_shells",sprintf("%s(%s) 让赵高掉下了希望之贝壳于 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}
	::die();                                                           
}