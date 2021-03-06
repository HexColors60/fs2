#include <ansi.h>
#include </open/open.h>
inherit NPC;
void do_wield();
string do_linpo();
void create()
{
        set_name("段誉",({"duan yu","duan","yu"}));
        set("title",HBMAG+HIC"六脉剑圣"NOR);
        set("long","他可是第一位将六脉神剑融会贯通的人,他的六脉神剑已达炉火纯青的
地步\n");
        set("gender","男性");
        set("combat_exp", 8000000);
        set("attitude","friendly");
        set("bellicosity",3000);
        set("family/family_name","段家");
        set("age",28);
        set("str", 44);
        set("cor", 44);
        set("cps", 45);
        set("per", 30);
        set("int", 42);
        set("food",1000);
        set("water",1000);
        set("force",100000);
        set("max_force",50000);
        set("kee",40000);
        set("max_kee",40000);
        set("gin",40000);
        set("max_gin",40000);
        set("sen",40000);
        set("max_sen",40000);
        set("chat_chance", 5);
        set("chat_msg", ({
        "段誉道: 唉!好不容易想出来的绝招，却找不到传人。\n",
        "段誉道: 自由自在的生活，真是太棒了。\n",
        }));
        set("inquiry", ([
        "凌波微步" : "那是我在琅环福地的神仙姊姊那学到的步法，在打不过别人，要逃跑的时候最有用了!!\n",
        "步法" : "你要学凌波微步???真的想学的话去找段云吧，我有把凌波微步的秘笈给他。\n",
        "精华" : (: do_linpo :),
        ]));
        set_skill("force",400);
        set_skill("unarmed",120);
        set_skill("sunforce",230);
        set_skill("linpo-steps",100);
        set_skill("six-fingers",125);
        set_skill("parry",100);
        set_skill("dodge",100);
        set_skill("move",100);
        set_skill("stabber",120);
        set_skill("literate",150);
        map_skill("force","sunforce");
        map_skill("dodge","linpo-steps");
        map_skill("move","linpo-steps");
        map_skill("parry","six-fingers");
        map_skill("unarmed","six-fingers");
        map_skill("stabber","six-fingers");
        set("force_factor",25);
        set("marks/six_sp",3);
        set("marks/six-fingers",3);
        set("marks/sun-finger",1);
        set("marks/linpo-steps",1);
        set("marks/handwriting",1);
        set_temp("apply/armor",300);
        set_temp("apply/stagger",50);
        set_temp("apply/defense",100);
        set_temp("apply/damage",120);
        set("mpower",3);
        set("six_spsp",1);
        set("env/quick_fan","YES");
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action("stabber.handwriting") :),
                (: exert_function("threeforce") :),
        }));
        set("functions/handwriting/level",150);
        set("functions/threeforce/level",100);

        setup();
        carry_object(PING_OBJ"neck0")->wear();
        carry_object(PING_OBJ"cloud_fan");
        add_money("gold",100);
}
void init()
{
    call_out("do_wield",1);
}
void do_wield()
{
    command("wield all");
}
string do_linpo()
{
    object ppl;

    ppl=this_player();

    if(ppl->query("family/family_name") != "段家")
      return "嗯?你怎可能到得了这边??";
    if(ppl->query("marks/ask_linpo")!=4)
      return "哈哈!易经精华之所在，可不是三言两语就可以说尽的。";
    if(ppl->query("int") > 33) ppl->set_temp("teach_time",2);
    else ppl->set_temp("teach_time",4);
    call_out("teach_step1",4,ppl);
    return HIY"原来你是要学逃跑的技巧阿，哈哈，没问题，我马上表演一次给你看，看清楚了喔!!"NOR;
}
int teach_step1(object ppl)
{
    if(!ppl) return 1;
    if(environment(this_object()) != environment(ppl)) return 1;
    message_vision(HIC"只见$N开始在$n"HIC"面前走来走去，$n"HIC"忽然眼睛一花，$N不见了!!\n"NOR,this_object(),ppl);
    call_out("teach_step2",2,ppl);
    return 1;
}
int teach_step2(object ppl)
{
    if(!ppl) return 1;
    if(environment(this_object()) != environment(ppl)) return 1;
    command("say 如何，看懂了吗???");
    call_out("teach_step3",2,ppl);
    return 1;
}
int teach_step3(object ppl)
{
    if(!ppl) return 1;
    if(environment(this_object()) != environment(ppl)) return 1;
    ppl->add_temp("teach_time",-1);
    if(ppl->query_temp("teach_time") > 0){
      ppl->do_command("shake");
      call_out("teach_step4",2,ppl);
      return 1;
    }
    else
    {
      ppl->do_command("nod");
      call_out("teach_step5",2,ppl);
      return 1;
    }
}
int teach_step4(object ppl)
{
    if(!ppl) return 1;
    if(environment(this_object()) != environment(ppl)) return 1;
    command("say 看不懂阿，没关系，我再做一次，看清楚啰!!");
    call_out("teach_step1",2,ppl);
    return 1;
}
int teach_step5(object ppl)
{
    if(!ppl) return 1;
    if(environment(this_object()) != environment(ppl)) return 1;
    message_vision(HIG"只见$N"HIG"开始在$n面前走来走去，$n忽然眼睛一花，$N"HIG"绕到了$n的背后!!\n",ppl,this_object());
    call_out("end_step",2,ppl);
    return 1;
}
int end_step(object ppl)
{
    if(!ppl) return 1;
    if(environment(this_object()) != environment(ppl)) return 1;
    command("haha");
    command("spank "+ppl->query("id"));
    command("say 干得好，以后几乎没人可以奈何得了你了!!");
    command("say 不过有两点要注意的!!");
    command("say 好汉不敌人多，所以千万不要一对多，到时候跑不掉，死的就是你了");
    command("say 跑进了死胡同，逃跑的路径少了，也就减少了你逃跑的机会");
    command("say 一定要注意这两点，知道吗?");
    ppl->set("marks/linpo-steps",1);
    ppl->delete("marks/ask_linpo");
    return 1;
}
void unconcious()
{
    message_vision("
$N忽然领悟"HIC"‘凌波微步’"NOR"的要旨所在，脚步作到"HIY"「动无常则，若危若安，进止难期，
若往若还”"NOR",霎时一片人影纷飞，让敌人头昏眼花\n",this_object());
    message_vision(HIC"$N趁着这个机会逃离开这里!!\n"NOR,this_object());
    destruct(this_object());
}
void die()
{
    message_vision("
$N心中默念，将"HIC"‘凌波微步’"NOR"的六十四卦步法，自「明夷”起始，经「贲”
 、「既济”、「家人”，走了一大圈而至「旡妄”，终于顺利摆\脱敌人的纠缠。\n"NOR,this_object());
    message_vision(HIC"$N趁着这个机会逃离开这里!!\n"NOR,this_object());
    destruct(this_object());
}
