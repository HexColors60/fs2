#include <ansi.h>
inherit NPC;
void do_special1();
void create()
{
        object ob,who;
        who=this_player();
        set_name("土方岁三", ({"npc08","hijikata doshizou","hijikata","doshizou"}));
        set("title", ""HIW"【新撰组副局长】"NOR"");
        set("long", "
土方岁三出身东京都，天然理心流，年幼时父母双亡，随兄嫂而住．后与近藤勇加入新选组，
帮助近藤勇取得局长之位，自己则位居副组长\n");
        set("age", 28);
        set("str", 50);
        set("cor", 50);
        set("int", 50);
        set("spi", 50);
        set("cps", 50);
        set("kar", 50);
        set("force", 100000);
        set("max_force", 5000);
        set("force_factor", 60);
        set("combat_exp", 10000000);
        set("max_kee",30000);
        set("kee",30000);
        set("max_gin",30000);
        set("gin",30000);
        set("max_sen",30000);
        set("sen",30000);
        set("race", "人类");
        set("gender", "男性");
        set_skill("dodge", 120);
        set_skill("move", 100);
        set_skill("parry", 100);
        set("bellicosity",10000);
        set("s_kee",400);
        set("quest/rain",1);
        set("quests/get_tiger",1);
        set("quest/memory",1);
        set("quest/head-kill",1);
        set("class","killer");
        set("max_s_kee",400);
        set("family/family_name","黑牙联");
        set("sec_kee","tiger");
        set_skill("force", 300);
        set_skill("fireforce",300);
        set_skill("dagger", 60);
        set_skill("shadow-kill", 30);
        set_skill("shade-steps", 120);
        set_skill("throwing", 120);
        set_skill("rain-throwing", 120);
        map_skill("throwing","rain-throwing");
        map_skill("dagger", "shadow-kill");
        map_skill("dodge", "nine-steps");
        map_skill("parry","wind-rain");
        map_skill("force","fireforce");
        set_temp("apply/damage", 300);
        set_temp("apply/armor", 300);
        set("functions/gold-fire/level",100);
        set("functions/manakee/level",200);
        set("quest/gold-fire",1);
        set("chat_chance_combat", 25);
        set("chat_msg_combat", ({
        (: do_special1 :),
        }));
        setup();
        carry_object("/u/u/unfinished/db");
        ob=carry_object("/u/u/unfinished/bomb.c");
        ob->set_amount(1000);
        ob->wield();
        carry_object("/open/killer/weapon/k_cloth3.c")->wear();
        carry_object("/open/killer/weapon/k_arm3.c")->wear();
        carry_object("/open/killer/weapon/k_head3.c")->wear();
        add_money("gold",25);
}

int accept_kill(object who)
{
who=this_player();
command("say 哼!!来吧!!\n");
command("wield dart");
command("cmd bellup");
command("perform fireforce.gold-fire");
command("charge "+who->query("id"));
command("split "+who->query("id"));
kill_ob(who);
    return 1;
}
int accept_fight(object who)
{
who=this_player();
command("say 新撰组成员战斗是不会手下留情的!!\n");
command("wield dart");
command("cmd bellup");
command("perform fireforce.gold-fire");
command("charge "+who->query("id"));
command("split "+who->query("id"));
kill_ob(who);
    return 1;
}

int do_cmd(string str)
{
 object who=this_player();
 object ob,anmy;
 ob=this_object();
 anmy=present( "anmy",environment(ob) );
 if(str=="askgod souji" || str=="askgod souji"){
write(HIY"土方岁三偷笑说：「对天神求神问卜，真笑死我了。”!!\n"
NOR);
command("wield dart");
command("cmd bellup");
command("perform fireforce.gold-fire");
command("charge "+who->query("id"));
command("split "+who->query("id"));
kill_ob(who);
 return 1;
                  }
}
void do_special1()
  {
    object *enemy,target;
    int i;

        enemy=this_object()->query_enemy();
        i=sizeof(enemy);
        target=enemy[random(i)];
        message_vision( HIG
        "土方岁三突然眼现杀气, 全身散发出惊人的杀气, 你当场被其杀气给震摄住!!\n"NOR,target);
        message_vision(
        "土方岁三放声大喝道:\n
        "+HIC"                   天  然  理  心  流\n
        "+HIR"                ***"+HIR"**"+HBCYN"水"NOR+HIR"**"+HBCYN"平"NOR+HIR"**"+HBCYN"刺"NOR+HIR"**"+HBCYN"法"NOR+HIR"**"+HIR"***"NOR+"\n\n",target);
        message_vision(HIC
        "土方岁三拔出"HIY"和泉守兼定"HIC"顿时刀光漫天, 全身被刀器所笼罩！！！\n"NOR,target);
        message_vision(HIW"\n土方岁三的"HIY"和泉守兼定"HIW"在$N胸口对穿而出, 给$N致命的一击！\n"NOR,target);
        target->receive_wound("kee",1000+random(500));
        COMBAT_D->report_status(target);
        COMBAT_D->report_status(target);
        target->start_busy(1);
  }
void heart_beat()
{
 object env,mob,*enemy,target;
 int i,j;
 mob = this_object();
 env = environment(mob);
if( query("kee") < 0)
mob->die();
 if( random(100) < 20)
 {
    enemy=mob->query_enemy();
    i=sizeof(enemy);
    target=enemy[random(i)];
    if( env == environment(target) )
    {
        message_vision( HIG
        "土方岁三突然眼现杀气, 全身散发出惊人的杀气, 你当场被其杀气给震摄住!!\n"NOR,target);
        message_vision(
        "土方岁三放声大喝道:\n
        "+HIW"                   独  门  禁  断  技\n
        "+HIB"                ***"+HIB"**"+HBCYN"壬"NOR+HIB"**"+HBCYN"生"NOR+HIB"**"+HBCYN"狼"NOR+HIB"**"+HBCYN"斩"NOR+HIB"**"+HIB"***"NOR+"\n\n",target);
        message_vision(HIC
        "土方岁三拔出"HIY"和泉守兼定"HIC"顿时刀光漫天, 全身被刀器所笼罩！！！\n"NOR,target);
        for(j=1;j<=10;j++)
        {
        message_vision(HIC"土方岁三快速挥斩"HIG"和泉守兼定"HIC", 如饿狼般朝着$N破绽猛劈！\n"NOR,target);
        target->receive_wound("kee",100+random(50));
        COMBAT_D->report_status(target);
        }
    }
 }
 
 if((mob->query("kee")<mob->query("max_kee")*0.5) && (random(100) < 20) )
 {
    tell_room(environment(), HIY+name()+"运起天然理心流疗法,为自己"
               +"疗伤.\n"+NOR);
    mob->receive_curing("kee",3000);
    mob->receive_heal("kee",1000);
 }

   
   set_heart_beat(1);
   ::heart_beat();
   
}

int heal_up()
{
        if (!is_fighting() ) {
             message_vision (HIW"系统：战斗停止，$N回收中，。\n"NOR, this_object ());
             destruct(this_object());
             return 1;
        }
        return ::heal_up() + 1;
}
void die ()
{
	object me=query_temp("last_damage_from");
	if(!present("fight_card",me))
	{
	tell_object(me,"\n\n系统：由于你没携带晶片，所以无法记录战绩。\n");
	destruct (this_object ());
	return ;
	}
	if(!me->query("quest/start_game"))
	{
	tell_object(me,"\n\n系统：由于你没有正式登记，资料无法传输。\n");
	destruct (this_object ());
	return ;
	}
	if(me->query("quest/start_game")< 9)
        {
        tell_object(users(),HIY"
	恭喜"HIW+me->query("name")+HIY"挑战"HIG"‘"HIR"第八层试炼□塔"HIG"’"HIY"通过！！
	
	"HIW"希望"+me->query("name")+"能不负众望，勇闯"HIG"‘"HIY"第九层试炼□塔"HIG"’"HIW"。
	"NOR);
	me->set("quest/start_game",9);
        destruct (this_object ());
	return ;
        }
	{
	tell_object(me,HIW"系统：你已经通过测试，系统不做任何更改。\n"NOR);
	destruct(this_object());
        :: die();
	}
}