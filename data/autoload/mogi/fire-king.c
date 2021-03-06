#include "/open/mogi/castle/npc/castle.h"
#include <ansi.h>
inherit NPC;
   
void create()
{
	set("long","
    焚天魔王, 魔界之统治者, 他全身火焰绕身, 火舌随着他的情绪不停的奔腾着。
仔细一看他竟可以御气凌空, 内功之深简直不可思议。另外练就旷世绝学「极火功”
, 极火掌一发动更是烈焰奔腾, 威不可挡。由极火功所化成的「极火金身”护身
气劲更能在四周形成坚硬火罩。
");
        set("gender","男性");
        set("nickname",HIR"赤狱混沅"NOR);
        set("title","魔界之王");
        set_name("焚天魔王",({"fire king","king"}));
        set("combat_exp",16000000);
        set("class","fighter");
        set("attitude","aggressive");
        set("score",90000000);
        set("bellicosity",1000000);
        set("age",10000);
        set("max_force",70000);
        set("force", 250000 ); 
        set("max_kee",70000);
        set("max_gin",70000);
        set("max_sen",70000);
        set("str", 35);
        set("cor", 35);
        set("cps", 35);
        set("int", 35);
        set("con", 35);
        set("kar", 35);
        set("force_factor",50);
        set_skill("dodge",200);
        set_skill("force",250);
        set("no_mount",1);
        set("no_plan_follow",1);
        set_skill("move",280);
        set_skill("parry",200);
        set_skill("mogi-steps",200);
        set_skill("firestrike",220);
        set_skill("unarmed",220);
        set_skill("literate",200);
        set_skill("fireforce",250);
        set_temp("apply/defense",60);
        set_temp("apply/armor",60);
        set_temp("apply/attack",30);
        set_temp("no_die_soon",1);
        map_skill("force","fireforce");
        map_skill("unarmed","firestrike");
        map_skill("dodge","mogi-steps");
        map_skill("move","mogi-steps");
        map_skill("parry","firestrike");
        set("functions/gold-fire/level",100);
        set("quest/gold-fire",1);
        set("quest/new_gold_fire",1);
        setup();
        carry_object("open/mogi/castle/obj/fire-king-head");
        carry_object("/data/autoload/mogi/fire-armor")->wear();
        carry_object("/data/autoload/mogi/fire-cloud-boots")->wear();
        carry_object("/data/autoload/mogi/fire-belt")->wear();
        carry_object("/data/autoload/mogi/daemon-cloak")->wear();
        carry_object("/data/autoload/mogi/fire-dragon")->wield();
        carry_object("/open/mogi/castle/obj/blood-water");   
        carry_object("/data/autoload/mogi/sspill")->set_amount(7);
        carry_object("/open/killer/headkill/obj/world_dag.c");
        add_money("gold",1000);
}

void init()
{
	::init();
	add_action( "block_cmd", "" );
	add_action( "do_cmd", "cmd" );
	add_action( "do_exert", "exert" );
	if( this_player()->query("combat_exp") < 2500000 )
		add_action( "do_kill", "kill" );
}

// 挡 do, 以免 cmd 判断失效 by ACKY
int block_cmd( string arg )
{
	if( (string)query_verb() == "do" ) {
		write( HIY"焚天魔王冷笑:「想耍下三烂的技俩?! 哼! 去死吧!”\n"NOR );
		if( is_fighting() )
			this_player()->start_busy(1);
		return 1;
	}
}

int do_cmd(string str){                 //ok by chan
 string arg;
 object who=this_player();
 object ob,king;
 ob=this_object();
 king=present( "king",environment(ob) );
 
	if( !str )
		return 0;

 if(str=="askgod king" || str=="askgod fire king"){
 write(HIY"焚天魔王冷笑：「在本魔王面前求神问卜!?先问问我还差不多。”去死吧!!\n"NOR);
 command("perform fireforce.gold-fire");
 king->kill_ob(who);
 return 1;
}
 if(str=="vet king" || str=="vet fire king"){
 write(HIY"焚天魔王怒斥道：「死庸医杵在这里干什么？！不如我送你一程吧！！”\n"NOR);
 command("perform fireforce.gold-fire");
 king->kill_ob(who);
 return 1;
}
 if(str=="bak king"){
 write(HIY"焚天魔王冷笑：想暗杀本魔王!!!也不打听谁是暗杀之王呀!!!去死吧!!\n"NOR);
 command("perform fireforce.gold-fire");
 king->kill_ob(who);
 return 1;
                  }

	if( sscanf( str, "%s %s", str, arg ) )
		if( str=="throw" ) {
			write( HIY"焚天魔王冷笑:「想干什么? 滚开!”\n"NOR );
			return 1;
		}
}

int do_kill( string str )
{
	object me = this_player();

	if( (str=="fire king"||str=="king") && me->query("combat_exp")<2500000 ) {
		write( HIY"焚天魔王冷冷地说:「你不够资格杀我!”\n"NOR );
		return 1;
	}
	return 0;
}

void greeting( object me )
{
	write( HIY"焚天魔王发出慑人心神声音:\n\t「来者何人～～”
\t「能来到这里, 真不简单! 江湖之上的人物, 算你一号!”
\t「不过若想找我比划, 你还差得太远!”
"NOR ); 
}

int accept_fight(object who)
{
	write( HIY"焚天魔王冷冷地说:「要命的话就快走吧!”\n"NOR );
	return 0;
}

int do_exert( string str )
{
	mixed	all;
	int	i;
	object	me;
	me	= this_player();
	all	= all_inventory(environment(me));

	if( str=="roar" ) {
		say(HIC"$N气凝丹田, 用力一吼企图以内力震伤焚天魔王。\n", me );
		say(HIC"焚天魔王冷笑说‘你这也叫吼? 让你们见识一下真正的"HIR"天魔狂吼"HIC"吧!\n");
		say(HIR"\n焚天魔王大吼一声, 刹那间天惊地摇, 魔界因此而震动! 周遭的生物刹那间非死即伤!\n");
		message_vision( HIR"结果所有人被这威力无比的天魔怒吼震伤, 哇一声吐出一大口鲜血!\n"NOR, me );
		for( i=0 ; i<sizeof(all); i++ )
			if( living(all[i]) && !wizardp(all[i]) && all[i]->query("id")!="fire king" ) {
				all[i]->add( "kee", -600 );
all[i]->delete_temp("hardshell");
				COMBAT_D->report_status( all[i], 1 );
			}
		return 1;
	}
	return 0;
}

int accept_kill( object who )
{
	write( HIY"焚天魔王从宝座上豁然站起!\n"NOR );
	command("say 鼠辈无礼! 嚐嚐我极火功的厉害吧!");
	if( !is_fighting() )
		command("perform fireforce.gold-fire");
	return 1;
}

void heart_beat()
{
 object *all;
	object	king;
	int	i, j, tmp , count;

	king	= this_object();
	all	= all_inventory(environment(king));
	count = random(100);
	j = random(3)+1;

//改变心跳出击方式，fire king本身能力已经暴猛了，运气不好心跳
//又一次全出，实在是太强了，就算再强的ppl也会一直被delay到死，
//连逃的机会也没有，所以更动形式，改成全时段出，每一次心跳会随
//机一种，若在数字边缘则不出，若真的运气不好一直出busy，那就运
//气太差了。

	for( i=0 ; i<sizeof(all); i++ )
		if( living(all[i]) && !wizardp(all[i]) && all[i]->query("id")!="fire king" && !is_fighting(all[i]) )
			kill_ob(all[i]);

	if( count < 10 && is_fighting() ) { // 主打 busy
		message_vision( HIR"\n焚天魔王大喝一声, 刹那间天惊地摇, 魔界因此而震动! 周遭的生物刹那间非死即碎!\n\n"NOR, king );
		message_vision( HIR"结果所有人被这威力无比的天魔怒吼震伤, 哇一声吐出一大口鲜血!\n"NOR, king );
		for( i=0 ; i<sizeof(all); i++ )
			if( living(all[i]) && !wizardp(all[i]) && all[i]->query("id")!="fire king" ) {
				all[i]->add( "gin", -100 );
all[i]->delete_temp("hardshell");
				all[i]->start_busy(j);//变的随机性质的，至少一回合，至多三回合。
				COMBAT_D->report_status( all[i], 1 );
			}
	}

	if( count > 10 && count < 25 && is_fighting() ) { // 主打 force
		message_vision( HIR"
	焚天魔王将全身业火暗运掌上, 掌上业火蕴藏着无限吸劲
	眨眼间, 焚天魔王叱喝回荡"HIW"‘魔道轮回 业火横行’"HIR"
	业火不断向四周吸引气劲!\n\n"NOR, king );
		message_vision( HIR"结果所有人八成内力全受业火吸引, 内劲狂泄!\n"NOR, king );
		for( i=0 ; i<sizeof(all) ; i++ )
			if( living(all[i]) && !wizardp(all[i]) && all[i]->query("id")!="fire king" ) {
				tmp = all[i]->query("force")/5*4;
				all[i]->add( "force", -tmp );
all[i]->delete_temp("hardshell");
				king->add( "force", tmp );
			}   
	}

	if( count > 25 && count < 50 && is_fighting() ) { // 主打神
		message_vision( HIR"
	焚天魔王全身火焰绕身, 突然将周身业火暗运掌上,
	眨眼间, 焚天魔王叱喝回荡"HIW"‘魔道横行 烈焰奔腾’"HIR"
	业火不断向你袭来!\n\n"NOR, king );
		for( i=0 ; i<sizeof(all) ; i++ )
			if( living(all[i]) && !wizardp(all[i]) && all[i]->query("id")!="fire king" )
				all[i]->receive_wound( "sen", 100+random(100) );
	}

	if( count > 50 && count < 80 && is_fighting() ) { // 主打mob
		message_vision( HIR"
	焚天魔王化身炼狱业火, 妖气在一瞬间变成沸腾血红魔风,
	凡被其吹拂之物尽挥成汽, 熔人口鼻令人窒息
	眨眼间, 焚天魔王叱喝回荡"HIW"‘赤狱混沅 魔道遮天’"HIR", 熔融魔气挟着蚀骨
	焚焰之风疯狂地侵袭着一切!\n\n"NOR, king );
		for( i=0 ; i<sizeof(all); i++ )
			if( living(all[i]) && !wizardp(all[i]) && !userp(all[i]) &&
			    !all[i]->query("master") && all[i]->query("id")!="fire king" )
				all[i]->die();
all[i]->delete_temp("hardshell");
	}

	if( count > 80 && is_fighting() ) { // 主打气
		message_vision( HIR"
	焚天魔王化身炼狱业火, 妖气在一瞬间变成沸腾血红魔风,
	凡被其吹拂之物尽挥成汽, 熔人口鼻令人窒息
	眨眼间, 焚天魔王叱喝回荡"HIW"‘赤狱混沅 魔道遮天’"HIR", 熔融魔气挟着蚀骨
	焚焰之风疯狂地侵袭着一切!\n\n"NOR, king );
		message_vision( HIR"结果被熔融极火卷到, 哀嚎连连中浑身青烟直冒, 伴随着阵阵焦肉味!\n"NOR, king );
		for( i=0 ; i<sizeof(all); i++ )
			if( living(all[i]) && !wizardp(all[i]) && all[i]->query("id")!="fire king" ) {
			all[i]->receive_wound( "kee", 500 );
all[i]->delete_temp("hardshell");
			COMBAT_D->report_status( all[i], 1 );
		}
	} 

	if( random(100) < 50 && is_fighting() && king->query("kee") > 0 )
	{
		message_vision( HIG"\n焚天魔王身冒出熊熊火焰, 伤口渐渐的愈合了!\n"NOR, king );
		king->delete_busy();
		king->clear_condition();
	    king->receive_curing("kee",5000);
	    king->receive_heal("kee",5000);
	    king->receive_curing("gin",5000);
	    king->receive_heal("gin",5000);
	    king->receive_curing("sen",5000);
	    king->receive_heal("sen",5000);

	}

	// by babe 计算刚好, 不要调整
	if( !is_fighting() ) {
		if( query("force") < query("max_force") ) // 1 -> 5.035
			command( "ex 200" );
		if( query("eff_kee") < query("max_kee") ) // 35 -> 40
			command( "10 exert heal" );
		if( query("gin") < query("eff_gin") ) // 125
			command( "exert regenerate" );
		if( query("kee") < query("eff_kee") ) // 125 -> 300
			command( "4 exert recover" );
		if( query("sen") < query("eff_sen") ) // 125
			command( "exert refresh" );
	}

	// enf 不减反增
	if( query("force_factor") < 40 )
	{
	king->set( "force_factor", 45 );
	}

    set_heart_beat(1);
	::heart_beat();
}

void die()
{
	int i,j;
	object *enemy;
  
   object winner = query_temp("last_damage_from");
   string name = winner->query("name");
   enemy = query_enemy();
  i=sizeof(enemy);
  
        tell_object(users(),HIW"
            
         焚天魔王仰天叹道：‘万年以来我的惊世神功无人能敌,
                             想不到今日败于"+HIY+
                             (winner->query("family/family_name")?winner->query("family/family_name"):"")+
                             HIC+name+HIW"       
                             之手, 真是后生可畏～叹啊～ ’

        "HIB"   魔界颳起狂风暴雨   一代魔界之王焚天魔王败了!             
"NOR);

 log_file("mogi/KILL_FIRE_KING", sprintf("%s(%s) 打败 焚天魔王 on %s\n"
,name,winner->query("id"), ctime(time()) ));

/*
	//by ACKY
	if( random(100) < 10 )
		environment(this_object())->war_start();
*/
	if( winner->query("clan/id") )
		CLAN_D->add_clanset( winner->query("clan/id"), "develop" , 10 );

   tell_object(winner,"
\n焚天魔王说：好吧...既然你已经赢了我了，我就把风青云
交给你了，反正这么多年来他也不肯吐漏连阳七诀剑法的奥秘。
不过他被我用独门手法点住了三元重穴，功力已经被封
现在我传你解穴手法(recover force)，你往北走可找到他。
\n");

   tell_object(winner,HIY"\n焚天魔王再用逼音成线的功夫告诉你：
真是后生可畏...这样我也没必要隐藏我的绝学了，现在我就传你
"HIR"极火金身心法"HIY"，极火真经就放在白虎室，慎习之！
\n"NOR);
   winner->set("quest/gold-fire",1);
   winner->set("quest/new_gold_fire",1);
   winner->set_temp("win_fireking",1);

   for(j=0;j<i;j++){
       if(enemy[j]->query("class")=="swordsman" && enemy[j]->query_temp("win_fireking")!=1)
       {
       enemy[j]->set_temp("win_fireking",1);
   tell_object(enemy[j],"焚天魔王说：好吧...既然你已经赢了我了，我就把风青云
交给你了，反正这么多年来他也不肯吐漏连阳七诀剑法的奥秘。
不过他被我用独门手法点住了三元重穴，功力已经被封
现在我传你解穴手法(recover force)，你往北走可找到他。
\n");
       }
                    }
//补充....................................
//武者解了话.会变成一代武尊....同时可以使用终极拳势...................by chan
 if(winner->query("class") == "fighter")
 if((winner->query("combat_exp") > 5000000) && !(winner->query("final/ko_king")))
 {
   winner->set("final/ko_king",1);
   winner->set("final/limit",1);
   tell_object(winner,HIR"你终于突破武学上极限!!悟出终极拳势!!成为武尊!!\n"NOR);
   winner->set("title","[1;33m玄天武尊 [0m");

   write("请打一下help 终极拳势,可以得知更多的讯息....!!!\n");
  }
//补充刀客解了能有制刀术 by swy
 if(winner->query("class") == "blademan")
if(winner->query("combat_exp")>5000000&&!winner->query("mk-blade")&&userp(winner))
 {
   winner->set("mk-blade",1);
tell_object(winner,HIY"\n焚天魔王再用逼音成线的功夫告诉你：
真是后生可畏...这样我也没必要隐藏我的绝学了，现在我就传你
"HIR"邪灵制刀术"HIY"，慎习之！\n"NOR);
if(winner->query("gender")=="男性") { winner->set("title",HIW"漩羽"HIY"刀皇"NOR); }
else { winner->set("title",HIB"刀魂"HIC"幽姬"NOR); }
   write("请打一下 help 邪灵制刀术，能知道更多讯息。\n");
  }

//Bellow Add By AceLan.......
        if( winner->query("family/family_name")=="儒门")
        {
                 tell_object(winner,HIW"你凭藉着高深的心法在不知不觉中领悟了焚天魔王极火功的精髓，
苦思了半饷之后突然顿悟到将极火功融入孔明兵法之道，遂大声狂欢道
"+HIR+"==========‘极火一出，万物具焚’==========\n"
NOR);
        } 

  :: die();
}                    
