inherit NPC;
void create()
{
        set_name("段正淳",({"duan zheng-chun","duan"}));
        set("gender","男性");
        set("age",45);
        set("class","scholar");
        set("str",40);
        set("long","帅气的中年人 ,留有小胡子 ,一付温文儒雅的样子 .\n");
        set("combat_exp",500000);
        set_skill("stabber",90);
        set_skill("force",70);
        set_skill("move",40);
        set("force",3000);
        set("max_force",3000);
        set("kee",2000);
        set("max_kee",2000);
          set_skill("literate",100);
        set_skill("parry",40);
        set_skill("dodge",40);
        set_skill("six-fingers",90);
        set_skill("linpo-steps",80);
        set_skill("sunforce",70);       
        map_skill("stabber","six-fingers");
        map_skill("dodge","linpo-steps");
        map_skill("move","linpo-steps");
        map_skill("parry","six-fingers");
        map_skill("force","sunforce");
        set("force_factor",10);
        set("functions/handwriting/level",50);
        set("chat_chance_combat",60);
        set("chat_msg_combat", ({
                (: perform_action("stabber.handwriting") :),
        }));
        set("chat_chance",10);
        set("chat_msg",({
                "段正淳到处看来看去 ,神色甚是扭捏.\n",
                "段正淳说道 : 喔喔喔 !好想要女人喔 ,春宫画也行啊 :~~\n"
                }));

        set("inquiry",([
        "庄静柔" : "你说小柔柔啊 ,哼 ,一个小姑娘 ,竟敢拒绝我 ,我一定要找机会 ,把她
脱个精光然后就 .....\n",
        "进入" : "不要 !啥事都好商量 ,就这不行 ,这可是我一亲小柔柔芳泽的大好良机 !\n",
        "想要女人吗" : "想 ,想 :P~~~~~\n",
        ]));
        setup();
        create_family("段家",8,"弟子");
        add_money("gold",10);
}

int accept_object(object me,object ob)
{
  if(ob->query("id")=="playboy")
       {
        command("smile "+me->query("id"));
        if(me->query("gender")=="男性")
        command("say 小兄弟 ,真是谢谢你啰 !");
        if(me->query("gender")=="女性")
        command("say 小姑娘 ,妳 .....妳怎么会有这种书 ,本王没收 !");
        me->set_temp("playboy",1);
        command("say 为了报答你 ,本王让你进去吧 !");
        tell_object(me,"快 !可以进去了 !\n");
        }
  return 1;
}

