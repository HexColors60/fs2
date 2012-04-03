// 新增南蛮war 凌雪飞

#include <ansi.h>
string magic1();
string magic2();
string magic3();
//string magic4();
inherit NPC;
void create()
{
            set("guild_master",1);
            set_name("凌雪飞",({"fly dancer","fly","dancer"}) );
            set("long","她是月牙儿的师姐，擅长媚术，据说她已经领悟出夜梦天舞的终极杀\n招，当年因为心术不正而被逐出师门，但是她的修为似乎比月牙儿更\n高，以舞媚之术称霸南蛮数年无人能敌。\n");
            set("gender","女性");
            set("class","dancer");
            set("nickname",HIM"舞"HIW"之"HIG"传人"NOR);
            set("combat_exp",7000000);
            set("attitude","heroism");
            set("age",26);
            set("str", 99);
            set("cor", 99);
            set("int", 99);
            set("spi", 99);
            set("cps", 99);
            set("per", 99);
            set("con", 99);
            set("kar", 99);
            set("kee",150000);
            set("gin",40000);
            set("sen",40000);
            set("atman",40000);
            set("mana",40000);
            set("force",150000);
            set("max_kee",150000);
            set("max_gin",40000);
            set("max_sen",40000);
            set("max_mana",40000);
            set("max_atman",70000);
            set("max_force",200000);
            set_skill("parry",120);
            set_skill("unarmed",120);
            set_skill("move",120);
            set_skill("dodge",120);
            set_skill("magic",120);
            set_skill("spells",120);
            set_skill("force",250);
            set_skill("paull-steps",120);
            set_skill("dremagic",120);
            set_skill("dreamdance",120);
            set_skill("necromancy",120);
            set_skill("dreamforce",200);
            map_skill("unarmed","dreamdance");
            map_skill("parry","dreamdance");
            map_skill("dodge","paull-steps");
            map_skill("move","paull-steps");
            map_skill("force","dreamforce");
            map_skill("spells","necromancy");
            map_skill("magic","dremagic");
            set_temp("apply/armor",100);
			set_temp("ref_shield",1);
            set("/spells/reflection/level",100);
            set("/spells/fdragon/level",100);
            set("/spells/fireball/level",100);
            set("/spells/confuse/level",100);
            set("/spells/thunder/level",100);
            set("/spells/firedance/level",100);
            set("/spells/hellfire/level",100);
            set("/spells/dreamwings/level",100);
            set("/spells/dreamcure/level",100);
            set("/spells/meteor/level",100);
            set("get_dan_sp",1);
            set("allow_meteor",1);
            set("adv_dancer",1);
            set("allow_fdragon",1);
			set("random_move",200);
            set("allow_hellfire",1);
            set("force_factor",15);
            set_temp("roared", 1 );
            setup();
			set("chat_chance",100);
            set("chat_msg",({
            (: random_move :),
	        }));
            create_family("夜梦小筑",3,"凤凰传人");
            carry_object("/open/dancer/obj/linrboots.c")->wear();
            carry_object("/open/dancer/obj/maple_ribbon.c")->wield();
            carry_object("/open/dancer/obj/yuawaist.c")->wear();
            set("chat_chance_combat",60);
            set("chat_msg_combat",({
             (: magic1 :),
             (: magic2 :),
             (: magic3 :),
//             (: magic4 :),
            }));
}

int accept_kill(object who)
{
    who=this_player();
    command("con reflection");
    kill_ob(who);
message_vision(sprintf("\n\n"HIC"    "HIW"～　"HIM"忆红尘"HIW"，"HIG"血染霓裳"HIW"，"HIY"天地无痕各一方\n\n\n                          "HIC"无奈何"HIW"，"HIB"恨遗飞霜"HIW"，"HIR"孤独人间恨两行　"HIW"～\n\n\n        "HIR"╭═╮  ╭╗      "HIG"╠╦╦╦╦╯    "HIC"═╗╭══╮    "HIM"◆╭═╮╭═╮\n        "HIR"╠═╣╰═╝      "HIG"╰╬╬╬╬╯    "HIC"╰╯║╭╮║    "HIM"◆╠─╣╠─╣\n        "HIR"╰╦╯  ╭╗      "HIG"╰╬╩╩╩╯     "HIC"● ║║║║    "HIM"╗╠═╝╚═╣\n       "HIR" ╦╩╦╰═╯        "HIG"╠═╦╬╯     "HIC"╗ ║║║║    "HIM"║║ ╦╬╦ ║\n        "HIR"╰╦╯  ╭╗        "HIG"║●╬╬╯     "HIC"║ ║╰╯║    "HIM"║║ ╰︾╯ ║\n        "HIR"●║●╰═╯        "HIG"╯  ║║       "HIC"╯ ╰══╝  "HIM"╰╝║ ╭╬╮ ║\n\n\n"),this_player());
    who->start_busy(1);
    return 1;
}

void heart_beat()
{
 object env,mob,*enemy;
 int i,j,k;
 j=random(100);
 mob = this_object();
 if(!mob) return ;
 if(!environment(mob)) return ;
 env = environment(mob);
 if( j < 40 && is_fighting())
 {
message_vision( HIW"\n\n----- "HIY"媚 "HIW"＊ "HIG"影 "HIW"＊ "HIR"舞 "HIW"＊ "HIC"艳 "HIW"-----\n"HIM"$N"HIM"眼露媚光，随着夜色迷蒙翩翩起舞，朱唇娇艳，舞姿轻盈，此招正是\n"HIM"$N"HIM"倾国倾城，迷惑天下的妖媚之术，你受到媚术所迷惑，看的入迷三分\n不知不觉逐渐被媚术迷惑失神，攻防之值瞬间大降！\n\n"NOR, mob );
  for( k=0 ; k < i ; k++)
   {
   if( !enemy[k] ) continue;
    if( enemy[k]->is_character() && !enemy[k]->is_corpse() && living(enemy[k]) && enemy[k] != mob && !wizardp(enemy[k]) )
     {
      message_vision(HIR"妖媚之术如天仙下凡，看的你如痴如醉，目瞪口呆！！\n"NOR,enemy[k]);
      enemy[k]->receive_wound("kee",200);
      enemy[k]->apply_condition("power-down",enemy[k]->query_condition("power-down")+5);
/*        if(enemy[k]->query("class")=="fighter")
        {
        enemy[k]->set_temp("power-down",20);
        }else{
        enemy[k]->set_temp("power-down",10);
        }
*/      COMBAT_D->report_status(enemy[k]);
     }
   }
 }

    if( 40< j < 70 && is_fighting() )
        {
        enemy=mob->query_enemy();
        for(i=0;i<sizeof(enemy);i++){
        if(!enemy[i]) continue;
    if(environment(mob) == environment(enemy[i]))
        {
    message_vision( HIR"\n\n$N运起凤凰灵气，灵气灌顶游走全身，凤凰灵气配合梦玄法鉴，空气瞬间凝结成冰！\n\n                  "HIC"◎ "HBBLU+HIR"凤 "HIW"～ "HIR"凰 "HIW"～ "HIY"展 "HIW"～ "HIY"翅"NOR+HIC" ◎\n\n          "HIB"● "HIR"血 "HIW"、 "HIR"染 "HIW"、 "HIM"红 "HIW"、 "HIM"尘 "HIW"、 "HIG"舞 "HIW"、 "HIG"秋 "HIW"、 "HIG"风 "HIB"●\n\n\n"HIY"只见$N"HIY"身上散放出一股强大的气劲，灵气顿时浮现冲天而去，化成八道不同的灵光疾射\n"HIY"你胸前八大要穴，只见你"HIY"受灵气所限制，顿时全身内力不断流失，身体虚弱无力，无法使劲。\n\n"NOR, mob );
    enemy[i]->apply_condition("no_power_e",random(10)+5);
    enemy[i]->receive_damage("kee", 800 );
    enemy[i]->receive_damage("gin", 300 );
    enemy[i]->receive_damage("sen", 300 );
    COMBAT_D->report_status(enemy[i]);

    }
   }
  }

    if( 70 < j )
    {mob->delete_busy();
	if(mob -> query("kee") < mob->query("max_kee")*0.6)
	{
    message_vision( HIG"\n$N"HIG"使出梦玄法鉴治疗术，瞬间身上的伤口渐渐愈合。\n"NOR, mob);
    mob->clear_condition();
    mob->receive_heal("kee",700);
    mob->receive_curing("kee",700);
    mob->receive_heal("gin",500);
    mob->receive_curing("gin",500);
    mob->receive_heal("sen",500);
    mob->receive_curing("sen",500);
    }
    }

   set_heart_beat(1);
   ::heart_beat();

}

string magic1()
{
if(random(2)<1)
command("con firedance");
else command("con confuse");
return "\n";
}
string magic2()
{
if(random(2)<1)
command("con hellfire");
else command("con thunder");
return "\n";
}
string magic3()
{
if(random(3)<2)
command("con fdragon");
else command("con fireball");
return "\n";
}
/*string magic4()
{
if(random(2)<1)
command("con meteor");
else command("con fdragon");
return "\n";
}*/

void die()
{
    object winner = query_temp("last_damage_from");
    string name = winner->query("name");
    string class1 = winner->query("family/family_name");
    if(!winner)
    {
    ::die();
    return ;
    }
    tell_object(users(),HIW"\n\n\n    ～ "HIR"媚  舞  迷  离    "HIY"一 夕 成 名    "HIC"败 尽 多 少 英 雄 豪 杰\n\n                     "HIG"夜 梦 天 舞    "HIB"无 数 寒 霜    "HIM"成 就 一 代 云 舞 幻 姬 "HIW"～\n\n"HIR"没想到我一代舞之传人，竟然会败在"+HIG+class1+HIW"弟子"+HIY+name+HIR+"之手。\n难道这真的是上天的安排吗？我不甘心啊！！\n我的传人必会为我血洗天下的！！！\n\n\n"NOR);
      message_vision(HIY"\n"+winner->name()+"打死凌云飞得到四百点战功!!\n"NOR,winner);
      write_file("/log/get_warp",sprintf("%s(%s) 得到四百点战功于 %s\n",
          winner->name(1),winner->query("id"),ctime(time())));
          winner->add("war_score",400);
    ::die();
}
