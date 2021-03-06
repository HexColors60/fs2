// oldman.c

inherit NPC;

int give_you( object me )
{
	object obj;
	command("say 你醒了啊 !");
	command("say 幻影娘子雪魂的怨世寒毒的确是十分厉害。");
	if( !present( "cold pill" , this_object() ) ) return 1;
	command("say 这有一颗药丹，可以防止你中毒。");
	message_vision("$N给$n一颗药丹。\n",this_object(),me);
	obj = present( "cold pill",this_object());
	if( obj ) obj->move( me );
}
void create()
{
	set_name("老者",({ "oldman" }));
	set("gender", "男性" );
	set("age",64);
	set("long","你看到的是一名神秘的老者，看起来似乎身怀决技。\n");
	set("combat_exp",1000000);

	set("kee",2000);
	set("max_kee",2000);
	set("force",3000);
	set("max_force",3000);
	set("force_factor",20);
	set_temp("apply/damage",60);
	set_temp("apply/armor",40);
	set_skill("unarmed",100);
	set_skill("snow-martial",120);
	map_skill("unarmed","snow-martial");
	set_skill("force",100);
	set_skill("snowforce",100);
	map_skill("force","snowforce");
	set_skill("dodge",100);
	set_skill("black-steps",120);
	map_skill("dodge","black-steps");
	setup();
	carry_object("/open/snow/obj/cold_pill");
}
void init()
{
	object me = this_player();
	if( !present( "cold pill" , me ) && !me->query_temp("no_fear_poison") )
		call_out("give_you",1,me);
}
