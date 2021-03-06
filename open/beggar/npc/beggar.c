// beggar.c
// first written by grand 9/30/1995
// fixed by wade
// become guild master by Dico 07/10/1999

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("乞丐", ({ "beggar" }) );
        set("race", "人类");
        set("age", 23);
        set("long",@LONG
  一个浑身脏兮兮的乞丐，用乞求的眼光看着你。
你想起你是如此的杀孽罪重，不禁想帮他．．．．
你眼角的余光看到他身上有八个小布袋，这似乎有
什么重要的意义，但是你一时想不起来．．．
LONG);
        set("str", 24);
        set("cor", 26);
        set("gender","男性");
        set("class","beggar");
        set("combat_exp",1000000);
        set("attitude","heroism");
        set("max_force",3000);
        set("force",3000);
        set("max_kee",3000);
        set("kee",3000);
        set_skill("array",70);
        set_skill("move",60);
        set_skill("force",90);
        set_skill("dodge",60);
        set_skill("parry",70);
        set_skill("unarmed",120);
        set_skill("literate",30);

        set("chat_chance", 15);
        set("chat_msg", ({
                "乞丐用手拉了拉你袖子。\n",
                "乞丐抱住你的脚，想讨东西吃。\n",
                "乞丐对着你喃喃自语。\n" }) );
        set("inquiry", ([
        "thief" : "给我一些钱, 我就偷偷说与你听。",
        "袋子" : "老兄，眼力不错嘛。既然你看到了那我就告诉你吧。\n现在丐帮热烈招生中，想加入(JOIN)的话要赶快喔。",
        "小布袋" : "老兄，眼力不错嘛。既然你看到了那我就告诉你吧。\n现在丐帮热烈招生中，想加入(JOIN)的话要赶快喔。",
        "布袋" : "老兄，眼力不错嘛。既然你看到了那我就告诉你吧。\n现在丐帮热烈招生中，想加入(JOIN)的话要赶快喔。",
        ]));
        set("combat_exp",256);
        set_temp("apply/attack", 10);
        set_temp("apply/armor", 3);

        setup();
carry_object("/obj/cloth")->wear();
}

void reset()
{
  delete("accept_object");
}

// 用总次数故定对某些玩家不公, 会无法学到, 改成一人只给一次机会
// reset 的时候或者死掉重生的时候清掉重来, fixed by wade 12/13/1995
int accept_object(object who, object ob)
{
        int b, value;

        if (!query("accept_object/"+who->query("id"))) {
          b = who->query("bellicosity"); 
          if( (value=ob->value())  && b>0 ) {
                value = value/10;
                if (value < 1) value = 1;
                b = b - value;
                if (b < 0) b = 0;
                who->set("bellicosity", b); 
                add("accept_object/"+who->query("id"), 1);
                write("你觉得罪孽洗清了一些.\n");
          }
        }
        else
          say ("谢谢! 谢谢!\n");
        destruct(ob);
        return 1;
}

void init()
{
 add_action("do_join","join");
}

int do_join()
{
 if(this_player()->query("class"))
  return notify_fail("你已经加入其他公会了。\n");
 this_player()->set("class","beggar");
 message("system","\n你看见"+this_player()->name()+"把身上的衣服斯的破破烂烂的，\n"
 "把自己打扮的像一个乞丐一样，真不晓得他脑袋里在想什么。\n\n",users());
 return 1;
}
