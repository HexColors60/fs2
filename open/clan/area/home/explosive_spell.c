// explosive_spell.c 阴阳爆裂符 by ACKY

inherit COMBINED_ITEM;
#include <ansi.h>
#include <combat.h>

int  do_stick( string arg );
void spell_msg( int phase , object me, object target );

int sticking;
object me;

void create()
{
	set_name( HIW""HBYEL"阴阳爆裂符"NOR, ({ "explosive spell", "spell" }) );
	set("long",@LONG
	一张又破又旧的纸, 上面有一些怪异的文字和图案, 
    恐怕只有鬼才看得懂, 似乎不值几文钱。

	或许可以贴(stick)看看, 不知会有什么效果。

LONG);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set( "base_weight", 1000 ); 
		set( "base_unit", "张");
		set( "value", 20000000 );
      		set( "unit", "叠" );
   		set( "no_sell", 1 );
   		set( "no_give", 1 );
   		set( "no_drop", 1 );
   		set( "no_sac" , 1 );
	}
	set_amount(1);
	setup();
}

void init()
{
	add_action( "do_stick", "stick" );
}

void heart_beat()
{
	int i, j, scale, armor;
	object *inv;
	inv = all_inventory( environment(me) );

	for( i= 0; i<sizeof(inv); i++ )
		if( userp(inv[i]) )
			if( (inv[i]->query("spell/explosive") + 
	                         me->query("spell/explosive") ) == 3 ) {
	me    ->set( "spell/explosive", 4 );
	inv[i]->set( "spell/explosive", 4 );
	message_vision( HIM"\n突然爆裂符起了感应, 从$N体内爆射出巨大的能量!\n"NOR ,inv[i] );
	message_vision( HIR"
 	                        ▁▎
                                 ▌▎
                                ▉  ▎                       ▎
                                 █  ▎                     ▁▎
                                ██  ▎                      █ 
       ▁▎                    █ █▌ ▎                   ███ 
        ▌ ▎               ██ ██▌                ▎ ██ █ 
       ▉ ▎               ██   ███              ▊███  █ 
     ██ ▊▌            ███    ████           ███  ████ 
     ██ █▌▊         █████  █████        ███    ████    ▎
    ██  ████    ██████  █████       █████    ████ ▎ 
  ███    ██    ██████    ██████  ███████    ████\n"NOR, me);
	message_vision( HIR"███    ████   █████    ██████     ███████    ████ 
 ███  █████ ██████    █████       ██████    ████ 
  ███  ████   ██████    ████     ██████      ████  
   ███    ███   █████    ███     ████████      ███  
     ███  ██████████    ███    ██████      █████ 
   ████    ███  ██████  ████ ██████    ████████ 
    ████      ███  ████  ████  █████    ███████ 
   ██████    ███  ███▍  ███ ████▌   ██████◤ 
       █████    ██████◣    ◥█████  █████◤ 
           ◥███◣      ◥██◤      ◥█◤◢█████◤                  
                ▔             ▔                 ▔▔▔\n"NOR, me );
	message_vision( HIY"\n$N体内的爆裂符受到感应, 形成坚固无比的防护力场!\n"NOR , me );

	for( j=0; j<sizeof(inv); j++ ) {
		if( !living(inv[j]) || inv[j]==me ) continue;
		armor = (int)inv[j]->query_temp("apply/armor");
		scale = (int)(armor/10);
		if( scale<2 ) scale=2 ;
		inv[j]->receive_damage( "kee", (int)(inv[j]->query("max_kee")/scale) );
		inv[j]->receive_wound ( "kee", (int)(inv[j]->query("max_kee")/scale) );
		tell_object( inv[j], HIR"\n你感到痛苦难耐，一股强大的能量让你的身体承受不住!\n"NOR);
		COMBAT_D->report_status( inv[j], 1 );                
	}
			}
	if( me->query( "spell/explosive" ) == 4 ) {
		set_heart_beat(0);
		me->delete( "spell/explosive" );
		destruct( this_object() );
	}	
}

int do_stick( string arg )
{
	object target;
	
	me = this_player();
	
    if(!arg) return notify_fail("你要贴在谁的身上??\n");
	if( sticking == 1 ) {
		write("此符咒已进入你体内, 无法除去。\n" );
		return 1;
	}
	
	if( arg == me->query("id") ) {
		write("想贴在自己身上? 不太好吧。\n" );
		return 1;
	}
	
	if( !(target = find_player(arg)) ) {
		write("目前线上无此玩家。\n" );
		return 1;
	}
	
	if( !target=present( arg, environment(me) ) || target == me )
		call_out( "spell_msg", 0, 3, me, me );
	else {
		if( target->query("combat_exp") > me->query("combat_exp")*2 ) {
			write( target->query("name")+"所散发出的神圣气息, 让你无法靠近。\n" );
			return 1;
		}
	        remove_call_out("spell_msg");
		call_out( "spell_msg", 0, 1, me, target );
	}
	
	return 1;
}

void spell_msg( int phase , object me, object target )
{
   	object spell = this_object();

	switch( phase ) {
	case 1:
		message_vision( "$N趁$n一不注意, 偷偷将符咒贴在$n身上。\n", me, target );
		spell->move(target);
		call_out( "spell_msg", 10, 2, me, target );
		break;
	case 2:
	   	message_vision( "$n渐渐地化入$N体内, 消失了。\n"NOR, target, spell );
		tell_object( target, HIY"
	                   ;;'      ,
	              ;,,,;;;;'     ;;
	           ,,;;;  ;'       ,;;,;;,
	               ;,;'     ,,;;;'  ;;
	              ,;;;;';;  '' ;;   ;;
	             ,;';;,;'     ;;'   ;;
	             ;' ;;,,,    ;;'   ,;;
	               ,;;'     ,;'    ;;'
	            ;;'';;    , '   ,;;;'
	                ;'  ,;;
	                  ,;'  '';,,
	                ,;;' ';,, ';;;,,
	              ,;;;   ;;;     ';;;,
	            ,;;;'      ,,,
	    ,,''           ,,;;';;         ,,''
	   ;;    ,;;       ' ,;'          ;;    ,;;
	    '';,;''           ';,          '';,;''
	     ,'                ''           ,'
	    ;'                             ;'\n"NOR);
		tell_object( target, HIY"	   ;;          "HIM"阴 阳 爆 裂 符"HIY"     ;;
	  ;;                             ;;
	  ';,,,,       "HIM"运 转 日 地 籙"HIY"    ';,,,,
	    '''';;,    "HIM"无 撼 焚 蚀 灭"HIY"      '''';;,
	    ,,''       "HIM"极 九 百 千 万"HIY"      ,,''
	   ;;    ,;;   "HIM"地 天 川 岳 生"HIY"     ;;    ,;;
	    '';,;''                        '';,;''
	     ,'                             ,'
	    ;'                             ;'
	   ;;                             ;;
	  ;;                             ;;
	  ';,,,,       "HIM"狂  想  天  神"HIY"    ';,,,,
	    '''';;,                        '''';;,
	   ,,     ;;  "HIM"急  急  如  律  令"HIY"  ,,     ;;
	    '''''''                        '''''''\n"NOR);
		target->set( "spell/explosive", random(2)+1 );
		sticking = 1;
		set_heart_beat(1);
		me = target;
		break;
	case 3:
		message_vision( "$N胡乱地将$n往自己身上贴。\n", me, spell );
		call_out( "spell_msg", 10, 2, me, me );
		break;
	}
}
