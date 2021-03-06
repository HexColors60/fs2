
// master_jen.c

inherit NPC;


void create()
  {
set("class", "fighter");
        set_name("任我行", ({ "jen wu shin", "jen", "shin" }) );
        set("title","泷山派第六代二弟子");
        set("nickname", "陇山叛徒");
        set("gender", "男性");
        set("age", 65);
        set("attitude", "aggressive");
        set("long",
"任我行是任博文的弟弟，也就是任正晴的师叔，功夫不及任博文，但企图心极强，曾\n"
"意图以毒计毒杀任正晴以夺得掌门位，只可惜事迹败漏，被任博文秘密关在陇山武馆\n"
"的地下室达二十年，靠吃虫鼠维生，已濒临疯狂，见人便杀\n");

        set("str", 48);
        set("cps", 40);
        set("per", 34);
        set("int", 38);
        set("kar", 16);

       set("combat_exp",1000000);
       set("kee",2000);
       set("max_kee",2000);
        set("force"       , 2700);
        set("max_force"   , 2700);
        set("force_factor", 10);
        set("score"       , 200000);

//           set("chat_chance_combat", 80);

/*           set("chat_msg_combat", ({
                (: consider :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :)
          }) ); */


        set_skill("move",70);
        set_skill("unarmed", 60);
        set_skill("force", 60);
        set_skill("parry", 70);
	set_skill("dodge",80);
          set_skill("henma-steps",80);
        set_skill("lungshan",70);
        set_skill("haoforce",60);

        map_skill("force", "haoforce");
        map_skill("unarmed", "lungshan");
          map_skill("dodge", "henma-steps");

        set("chat_chance_combat",65);
        set("chat_msg_combat",({
//           (: exert_function, "enforceup" :),

            (: perform_action, "force.kang_kee"   :)
        }));



        setup();

        add_money("gold",10);
}

