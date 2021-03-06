inherit NPC;
inherit F_MASTER;
void create()
{
	set_name("张乘云", ({"chen un","un"}));
	set("long","郑士欣二第子,与其兄乘风同时进入仙剑派,乘云在剑法上虽已明显
落后于乘风,但说到内力深厚,仙剑派中除了掌门人郑士欣,无人能及
乘云项背,兄弟两因行侠于江湖,而并称风云双侠.乘云平时负责看管
藏经阁.\n");
	set("gender","男性");
	set("guild_master",1);
	set("combat_exp",500000);
        set("attitude","heroism");
	set("age",43);
	set("class","swordsman");
	set("nickname","风云双侠");
	set("title","仙剑派第四代二弟子");
	create_family("仙剑派",4,"弟子");
	set("score",100000);
	set("force",1800);
	set("max_force",1800);
	set("force_factor",10);
	set_skill("sword",80);
	set_skill("dodge",80);
	set_skill("move",40);
	set_skill("parry",80);
	set_skill("literate",60);
	set_skill("force",100);
	set_skill("array",90);
	set_skill("blade",40);
	set_skill("unarmed",90);
	set_skill("staff",40);
	set_skill("throwing",40);
	set_skill("cure",40);
        set("str", 30);
        set("cor", 30);
	set("per", 25);
	set("int", 30);
	set("cps",20);
	set("con", 30);
	set("spi", 15);
	set("kar", 30);
	setup();
	carry_object("/u/w/wugi/obj/sword-2")->wield();
	add_money("gold",5);
}

 int accept_fight(object me)
 {
 if((int)me->query("combat_exp")<=80000)
  {
  command("say 刀剑无眼,伤了你就不好了");
  return 0;
  }
  command("say 出招吧!");
  return 1;
  }
void attempt_apprentice(object ob)
{
	if(!ob->query_temp("allow_2"))
	{
	command("say 没有师父的同意,我不敢擅自收徒!");
	return 0;
	}
	command("smile");
	command("say 既然是师父的意思,以后你就跟我好好学吧!");
	command("recruit "+ob->query("id"));
	ob->set("marks/仙剑七侠",1);
	}
