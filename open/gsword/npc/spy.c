inherit NPC;
void create()
{
	set_name("媮学嵨", ({"Shie wu","媮学嵨","wu"}));
	set("long","媮学嵨,看起来像江湖中某一落漠门派的弟子,偷偷摸摸的,不晓得\n"
"在搞什么花样,从他的一举一动看来,好像是在偷学仙剑派的武功.\n");
	set("gender","男性");
	set("combat_exp",3000);
	set("age",30);
	set("title","某派弟子");
	set("score",2000);
	set("force",50);
	set("max_force",50);
	set_skill("force",20);
	set_skill("sword",30);
	set_skill("dodge",50);
	set_skill("parry",30);
	set_skill("move",30);
	set_skill("unarmed",60);
	set_skill("blade",40);
	set_skill("staff",40);
	set_skill("dagger",40);
        set("str", 20);
        set("cor", 25);
	set("per", 15);
	set("int", 20);
	set("cps", 15);
	set("con", 30);
	set("spi", 15);
	set("kar", 20);
	setup();
	carry_object("/open/gsword/obj/sword.c")->wield();
	add_money("silver",3);
}
 
void init()
{ 
 add_action("look_mob","look");
}

 int look_mob(string me)
{ 
  if(me=="媮学嵨" ||  me == "wu" )
 {
  command("fear");
  command("flee");
  return 1; }
  return 0; 

}

 int accept_fight(object ob)
{ ob ->query("id");
  command("fool");
  command("hammer "+ob->query("id"));
  command("flee");
  return 1;
}  
