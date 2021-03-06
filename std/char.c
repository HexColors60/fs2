// char.c
 
#pragma save_binary
 
#include <action.h>
#include <ansi.h>
#include <command.h>
#include <dbase.h>
#include <move.h>
#include <name.h>
#include <skill.h>
#include <team.h>
 
#include <user.h>
 
inherit F_DBASE;
inherit F_ACTION;
inherit F_APPRENTICE;
inherit F_ATTACK;
inherit F_COMMAND;
inherit F_CONDITION;
inherit F_DAMAGE;
inherit F_FINANCE;
inherit F_MOVE;
inherit F_NAME;
inherit F_SKILL;
inherit F_MLIST;
inherit F_SPELL;
inherit F_FUNCTION;
inherit F_TEAM;
inherit F_PLACE;
 
// Use a tick with longer period than heart beat to save cpu's work
static int tick,bandage_tick;
void greeting(object ob);

void create()
{
        seteuid(0); // so LOGIN_D can export uid to us
}
 
// Use this function to identify if an object is a character.
int is_character() { return 1; }
 
// setup: used to configure attributes that aren't known by this_object()
// at create() time such as living_name (and so can't be done in create()).
void setup()
{
  seteuid(getuid(this_object()));
 
  set_heart_beat(1);
  tick = 10;
  bandage_tick = 10;
  enable_player();
 
  CHAR_D->setup_char( this_object() );
/*
  if( userp(this_object()) )
    call_out("check_robot", 400 + random(600));
*/
}

// by konn
void check_robot()
{
  int a, b, c, ans, nowtime;
  object me = this_object();
  string str;
 
  nowtime = (time() + 28800) % 86400;
  if( nowtime <= 28800 ) {
    call_out("check_robot", 1200 + random(1000));
    return ;
  }
//犯罪者不用查,因为会跳到冰判官那
  if(me->query("have_get_rest"))
    return ;

  if( wizardp(me)			||  /* 巫师不需要查 */
    me->is_fighting()			||  /* 战斗就让他打 */
    me->is_ghost()		        ||  /* 作鬼了就不用问 */
    me->query_temp("pk_fight")		||  /* pkla就让他打 */
    me->query_temp("unconcious")==1	||  /* 晕倒的不用查 */
    me->query_temp("netdead") 		||  /* 断线的也不用找 */
    in_edit(me)				||  /* 在编辑东西也不必 */
    in_input(me)			||  /* 读文章就让他专心读 */
    (query_idle(me)/60) >= 3 ) {	    /* 发呆中的就放他一马 */
      call_out("check_robot", 10);
      return ;
  }

  a = random(200) + 1;
  b = random(100) + 1;
  c = random(100) + 1;
  tell_object(me,
     HIW+"\n***************************************************************\n"+
     HIW+"\n\t\t\t系统要清查机器人, 请回答下面问题: \n\n"+
     HIW+"\n***************************************************************\n");

  switch( random(3) ) {
    case 0:
      str = sprintf("\t%s除以%s的余数等于多少?\n\n",
              chinese_number(a), chinese_number(b));
      tell_object(me, str);
      ans = a % b;
      me->set("robot/ans", ""+ ans);
      me->set("robot/quest", str);
      break;
    case 1:
      str = sprintf("\t%s除以%s的余数加上%s等于多少?\n\n",
              chinese_number(a), chinese_number(b), chinese_number(c));
      tell_object(me, str);
      ans = a % b;
      ans += c;
      me->set("robot/ans", ""+ ans);
      me->set("robot/quest", str);
      break;
    case 2:
      str = sprintf("\t%s除以%s的余数减掉%s等于多少?\n\n",
              chinese_number(a), chinese_number(b), chinese_number(c));
      tell_object(me, str);
      ans = a % b;
      ans -= c;
      me->set("robot/ans", ""+ ans);
      me->set("robot/quest", str);
      break;
  }

  me->set("robot/time", time() + 300);
  tell_object(me, "\t请用ans 作答.\n\n"+NOR);
  tell_object(me,
  HIW+"\n***************************************************************\n"NOR);

  call_out("check_robot", 600 + random(800) + random(800));
}

void heart_beat()
{
        int     wimpy_ratio;
        mapping my;
        object  me, ob,user, *obs;
        int     hurt, i;


  if ( !objectp(me=this_object()) )
   { set_heart_beat(0);
      return;
    }

//下面这行是用来检查玩家所在房间的目录用的 by bss
        user=this_object();
        "/adm/daemons/check_w_r_y"->main(user);

  if(user->query_temp("set_no_heart_beat"))
    set_heart_beat(0);
  if (userp(me=this_object())) {
    me->set_temp("cmd_cnt",0);
    // 照明系统
#ifdef WEATHER
    obs = all_inventory(me);
    for (i=0; i<sizeof(obs); i++)
      if (obs[i]->query("had_light") ) {
        obs[i]->add("light_up", -1);
        if ( !obs[i]->query("light_up")) {
          write ("从地上跳出一只蓝色小精灵，正在你惊讶之际.....\n"
                "蓝色小精灵抢走了你手上的"+obs[i]->short()+"后迅速逃逸。\n");

     if ( obs[i]->query("be_light")) {  //Add By leei to Light
     obs[i]->delete("be_light");
     obs[i]->delete("had_light");  
     obs[i]->delete("light_up");
     obs[i]->set("name",obs[i]->query("old_name") );
     obs[i]->delete("old_name");
     write ("被你发现了，马上从蓝色小精灵手中抢回你的"+obs[i]->short()+"。\n"); 
       }  else {         
     destruct(obs[i]);
          }                //End To Test        

         // destruct(obs[i]);   
        }
      }
#endif
 
#ifdef WEATHER
    // 冰苞系统
    if (environment(me) && environment(me)->query("outdoors")) {
      hurt = NATURE_D->query_reather_hurt();
      if (interactive(this_object()) && !query_temp("rain_cover"))
        receive_damage ("kee", hurt);
    }
#endif
  }
 
  if( !query_heart_beat(me) ) set_heart_beat(1);
        my = query_entire_dbase();
 
if( userp(me) && me->query("class")=="swordsman" ) {
if( !me->is_fighting() && me->query_temp("delay_fight")) {
me->delete_temp("delay_fight"); 
}
}
        // If we're dying or falling unconcious?
        if( my["kee"] < 0 || my["sen"] < 0 || my["gin"] < 0) {
                remove_all_enemy();
                if( !living(me) ) die();
                else unconcious();
                return;
        }
 
        // If we are dying bcz of mortal wounds?
        if( my["eff_kee"] < 0 || my["eff_sen"] < 0 || my["eff_gin"] < 0) {
                remove_all_enemy();
                die();
                return;
        }
 
        // Do attack if we are fighting.
        if ( is_busy() ) {
                continue_action();
                // We don't want heart beat be halt eventually, so return here.
                return;
        } else {
                // Is it time to flee?
                if( is_fighting()
                &&      intp(wimpy_ratio = (int)query("env/wimpy"))
                &&      wimpy_ratio > 0
                &&    ( my["kee"] * 100 / my["max_kee"] <= wimpy_ratio 
                        || my["gin"] < 15 || my["sen"] < 15 ) )
                        GO_CMD->do_flee(me);
                // Do attack or clean up enemy if we have fleed.
                attack();
		attack();
        }

        if( !userp(me) ) {
	  tick--; // 非玩家血液巡环快一倍
                me->chat();
                // chat() may do anything -- include destruct(me)
                if( !me ) return;
        }
 
 // 绷带与plaster系统...可互相配合 
	if( me->query_temp("medicine/bandaged") || me->query_temp("medicine/plaster_power") )
	if( bandage_tick-- <= 0 )
	{
	  me->receive_heal( (me->query_temp("medicine/type")?me->query_temp("medicine/type"):"kee"), me->query_temp("medicine/plaster_power")+me->query_temp("medicine/bandage_tick") );
	  me->receive_curing( (me->query_temp("medicine/type")?me->query_temp("medicine/type"):"kee"), me->query_temp("medicine/plaster_power")+me->query_temp("medicine/bandage_tick") );
	  if( me->query_temp("medicine/plaster_times") )
	    me->add_temp("medicine/plaster_times",-1);
	  if( !me->query_temp("medicine/plaster_times") && me->query_temp("medicine/plaster_power") )
	  {
	    me->set_temp("medicine/plaster_power",0);
	    write("你身上药膏的药效过了。\n");
	  }
	  else						bandage_tick=9;
	  if( me->query_temp("medicine/bandage_times") > 0 )
	    me->add_temp("medicine/bandage_times",-1);
	  if( me->query_temp("medicine/bandaged") && !me->query_temp("medicine/bandage_times") )
	  {
	    write("你身上的绷带已经被鲜血浸透了, 你顺手将它拆了下来。\n");
	    me->set_temp("medicine/bandaged",0);
	    obs = all_inventory(me);
	    for(i=0; i<sizeof(obs); i++)
	      if( obs[i]->query("cure_type")=="bandage" && obs[i]->query("equipped") )
		destruct(obs[i]);
	  }
	}

	
        // 每十个心跳做一次
        if( tick-- > 0  ) return;
        else tick = 10;

// 药性随时间减轻 
	if( me->query("status") >= 3 )
		me->add("status",-3);
// 出现 condition .. if have..
        update_condition();
 
        // If we are compeletely in peace, turn off heart beat.
        // heal_up() must be called prior to other two to make sure it is called
        // because the && operator is lazy :P
         if( !heal_up() && !is_fighting() && !interactive(me)) {
              if( environment() ) {
                      ob = first_inventory(environment());
                      while(ob && !interactive(ob))
                              ob = next_inventory(ob);
              }
              if( !ob ) set_heart_beat(0);
         }
 
        if(!me) return ;
        if( !interactive(me) ) return;
 
        // Make us a bit older. Only player's update_age is defined.
        // Note: update_age() is no need to be called every heart_beat, it
        //       remember how much time has passed since last call.
        me->update_age();
	me->save();
 
#ifdef IDLE_TIMEOUT
        if (wizardp(me)) {
          if(query_idle(me) > 10*IDLE_TIMEOUT)
                me->user_dump(DUMP_IDLE, IDLE_TIMEOUT);
        }
        else if(query_idle(me) > IDLE_TIMEOUT)
                me->user_dump(DUMP_IDLE, IDLE_TIMEOUT);
#endif
}
 
int visible(object ob)
{
        int lvl, invis;
 
        if (wizhood(this_player()) == "(manager)" || wizhood(this_player()) == "(admin)") return 1;
        lvl = wiz_level(this_object());
 
        if( lvl > wiz_level(ob) ) return 1;
        invis = ob->query("env/隐身");
        if( intp(invis) && (invis > lvl) ) return 0;
 
        if( ob->is_ghost() ) {
                if( is_ghost() ) return 1;
                if( query_temp("apply/astral_vision") ) return 1;
                return 0;
        }
        return 1;
}

void greeting(object ob)
{
  string        *msg;
  int           rnd;

  if( !ob || environment(ob)!=environment() )
    return;

  msg = query("greeting_msg");
  if (!msg || sizeof(msg) == 0)
    return;
  rnd = random(sizeof(msg));
  if( stringp(msg[rnd]) )
    say (msg[random(rnd)]);
  else if( functionp(msg[rnd]) )
    evaluate(msg[rnd]);
}

void init()
{
  object ob;

  ::init();
  if( interactive(ob = this_player()) && !is_fighting() ) {
    if( userp(this_object()) )
      greeting(ob);
    else {
      remove_call_out("greeting");
      call_out("greeting", 1, ob);
    }
  }
}
