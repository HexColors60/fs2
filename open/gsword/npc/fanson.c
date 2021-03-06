inherit NPC;
inherit F_MASTER;
void create()
{
	set_name("范松", ({"fan son","son"}));
	set("long","郑士欣三弟子,平时负责教导第五代弟子太极剑法,由于郑士欣年岁
已高,对于徒子徒孙不再亲自教导,除非是极具慧根之人,亦或有缘
之人,郑士欣才会略加指点.\n");
	set("gender","男性");
	set("combat_exp",500000);
        set("attitude","heroism");
	set("age",38);
	set("class","swordsman");
	set("title","仙剑派第四代三弟子");
	create_family("仙剑派",4,"弟子");
	set("score",100000);
	set("force",1000);
	set("max_force",1000);
	set("force_factor",10);
	set_skill("sword",90);
	set_skill("dodge",70);
       set_skill("shasword",70);
      set_skill("shaforce",100);
	set_skill("parry",100);
	set_skill("literate",40);
	set_skill("move",50);
	set_skill("force",60);
	set_skill("array",90);
	set_skill("blade",90);
	set_skill("unarmed",50);
        map_skill("sword","shasword");
        map_skill("force","shaforce");
	set_skill("dagger",40);
        set("str", 30);
        set("cor", 30);
	set("per", 25);
	set("int", 30);
	set("cps",20);
	set("con", 30);
	set("spi", 15);
	set("kar", 30);
	setup();
	carry_object("/open/gsword/obj/sword-3.c")->wield();
}
 int accept_fight(object me)
  {
  if((int)me->query("combat_exp")<=60000)
  {
  command("say 不是我不跟你打,我怕出手太重会取你性命");
  return 0;
  }
 command("say 好,我也很久没跟人家过招了,拔剑吧!");
  return 1;
  }
         
void attempt_apprentice(object ob)
{
	if(!ob->query_temp("allow_3"))
	{
	command("say 师父说过,要收徒必需他的同意!");
	return 0;
	}
	command("hmm");
	command("say 好,我就收你为徒!");
	command("recruit "+ob->query("id"));
	ob->set("marks/仙剑七侠",1);
	}
