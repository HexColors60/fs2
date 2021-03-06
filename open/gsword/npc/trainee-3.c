inherit NPC;

void create()
{
	set_name("张应龙",({"in long","long"}));
	set("long","仙剑第五代大师兄 ,也是张乘风之长子 .\n");
	set("gender","男性");
	set("combat_exp",15507);
        set("attitude","heroism");
	set("age",23);
	set("title","仙剑派第五代大师兄");
	set("class","swordsman");
	set("force",500);
	set("max_force",500);
	set("family/master_name","张乘风");
	set("force_factor",5);
	set("str",30);
        set("cor", 30);
	set("per", 25);
	set("int", 30);
	set_skill("shasword",10);
	set_skill("sha-steps",3);
	map_skill("sword","shasword");
	map_skill("dodge","sha-steps");
	set("chat_chance",6);
	set("chat_msg",({
		"张应龙喃喃的说:小师妹之所以发生这种不幸的事，都是我一时贪玩造成的，
被师父责罚是理所当然的。\n",
          }));	
	set("cps",20);
	set("con", 30);
	set("spi", 15);
	set("kar", 30);
	set_skill("sword",60);
	set("inquiry",([
	"小师妹": "那天我带他到后山游玩，走着走着，看到奉命守在禁地入口
	的淡月师弟，我们也就上前聊了几句，不料一个不小心，竟让小师妹溜进
	了禁地，那禁地我们是决不能进入的，只好马上回报师父，师父大怒之下
	罚我在这私过一个月，至于小师妹现在的情形我也不太清楚。\n"
	]));
	set_skill("dodge",50);
	set_skill("parry",50);
	set_skill("move",40);
	set_skill("literate",40);
	set_skill("force",40);
	setup();
	carry_object("/obj/longsword.c")->wield();
	carry_object("/open/gsword/obj/robe_1")->wear();
	carry_object("/open/gsword/obj/ff_pill")->set_amount(1);
	create_family("仙剑派",5,"弟子");
}
