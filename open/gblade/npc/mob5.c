inherit NPC;

void create()
{
        set_name("遁地巨鼠", ({ "big rat","rat" }) );
        set("race", "野兽");
        set("age", 600);
        set("long", "
宛若小山的巨鼠站在你面前，顿时你觉得自己好渺小，看牠的体积，估
量一下牠的吨位，如果真的打了起来你绝对是吃亏的一方。
你看了看遁地巨鼠挖地的速度，你猜想这个地道是不是就是他挖的。
");
        set("str", 60);
        set("con", 55);
        set("kee",7000);
        set("max_kee",7000);
        set("verbs", ({ "bite","claw"}));
        set("limbs", ({ "头部", "利爪","尾巴"  }) );
        set("attitude","peacful");
	 set("combat_exp",400000);
	 set_temp("apply/attack",100);
	set_temp("apply/dodge",100);
        set("chat_chance",10);
        set("chat_msg", ({
        "遁地巨鼠用牠的利爪挖了挖地面，片刻把地上挖出了一个大洞。\n",
        }) );
       setup();
}
void init()
{
        object ob;
        ::init();
        if(interactive(ob=this_player()) && !is_fighting())
        {
        remove_call_out("greeting");
        call_out("greeting",2,ob);
        }
}
void greeting(object ob)
{
if(ob->query("pass_gblade")<5)
        this_object()->kill_ob(ob);
}
void die()
{
        object ob;
        ob= this_object()->query_temp("last_damage_from");
	if(ob&&userp(ob)&&ob->query("pass_gblade")<5)
	ob->set("pass_gblade",5);
::die();
}

