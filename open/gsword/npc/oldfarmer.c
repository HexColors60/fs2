inherit NPC;

void create()
{
	set_name("鲁连",({"ru lian","ru","lian"}));
	set("long",@LONG
只知他是仙剑的成员之一 ,在仙剑派已有很长的一段时间由于他偶而会说些
仙剑的古事给大家听 ,所以门徒们都对他颇尊敬.
LONG);
	set("gender","男性");
	set("combat_exp",10000);
        set("attitude","heroism");
	set("age",23);
	set("title","仙剑派长者");
	set("class","swordsman");
	set("force",500);
	set("max_force",500);
	set("force_factor",5);
	set("str",30);
        set("cor", 30);
	set("per", 25);
	set("int", 30);
	set("chat_chance",6);
	set("chat_msg",({
        "老者道: 仙剑派创派已有一百余年 ,祖师爷--逍遥子--在创派后约五年\n
 的某场战役中 ,不幸受了严重的内伤 ,将掌门之位传给第二代掌门人后\n ,
 就此隐退江湖 ,云游四海。\n",
        "鲁连道: 祖师爷临走前特别吩咐我们不可接近禁地 ,原因他也没跟我们说\n
 清楚 ,我想大概只有掌门人知道吧。\n",
          }));	
	set("cps",20);
	set("con", 30);
	set("spi", 15);
	set("kar", 30);
	set_skill("sword",60);
	set("inquiry",([
        "古事": "我正在说咩 ,安静听啦...。\n",
        "禁地": "你们千万别去那里哦 ,后果不堪设想的 ,说不定仙剑派会就此毁在
        你手上。\n",
	]));
	set_skill("dodge",50);
	set_skill("parry",50);
	set_skill("move",40);
	set_skill("literate",40);
	set_skill("force",40);
	setup();
	carry_object("/obj/longsword.c")->wield();
	carry_object("/open/gsword/obj/robe_1")->wear();
	create_family("仙剑派",3,"弟子");
}

         
      
