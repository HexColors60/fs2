// BLACK1.C 黑风组组长 卫博战
inherit NPC;
void create()
{
  object ob1;
  set_name("卫博战",({"wey fight","fight"}));
  set("title","黑风组组长");
  set("long","黑风组组长卫博战行踪诡密, 他所率领的黑风组正如其名, 来去如风。");
  set("gender","男性");
  set("combat_exp",950000); 
  set("attitude","friendly");
  set("force_factor",15);
  set("age",40);
  set("class","killer");

  set("str", 45);
  set("int", 45);
  set("spi", 45);
  set("cps", 45);
  set("con", 45);
  set("kar", 45);

  set("max_kee",3500);
  set("eff_kee",3500);
  set("kee",3500);
  set("max_gin",2000);
  set("gin",2000);
  set("max_sen",2000);
  set("sen",2000);
  set("force",3700);
  set("max_force",3700);
  set("bellicosity",2000);
  set_skill("throwing",100);
  set_skill("parry",100);
  set_skill("dodge",120);
  set_skill("force",120);
  set_skill("shade-steps",100);
  set_skill("rain-throwing",100);
  set_skill("blackforce",80);
  map_skill("parry","rain-throwing");
  map_skill("throwing","rain-throwing");
  map_skill("dodge","shade-steps");
  map_skill("force","blackforce");
  setup();

  ob1=carry_object("/open/killer/obj/lustar");
  ob1->add_amount(300);
  ob1->wield();
  carry_object("/open/killer/weapon/k_arm2.c")->wear();
  carry_object("/open/killer/weapon/k_belt2.c")->wear();
  carry_object("/open/killer/weapon/k_boot2.c")->wear();
  add_money("gold",8);
}