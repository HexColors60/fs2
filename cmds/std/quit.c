// quit.c

#include <ansi.h>
#include <command.h>

inherit F_DBASE;
inherit F_CLEAN_UP;
inherit F_SKILL;
object ob,ob2,*inb,horse, pal;
object *inv, link_ob, body_ob, mob, wiz ;
string *gift_key, *my_key, id, src, dst,pktitle;
int i,j,k,f1,f2,f3,f4,f5,f6,f7,f8,f9,f10;

mapping gift = ([
  "str":"膂力",
  "cor":"胆识",
  "int":"悟性",
  "spi":"灵性",
  "cps":"定力",
  "per":"容貌",
  "con":"根骨",
  "kar":"福缘",
]);

void create()
{
  seteuid(getuid());
  set("name", "离线指令");
  set("id", "quit");
  set_temp("channel_id", "连线精灵");
}

int main(object me, string arg)
{
  mapping my;
  object env;
  env = environment(me);
  ob=present("mdragon-eq",me);
  ob2=present("god-eq",me);
  f1=me->query("functions/white/level");
  f2=me->query("functions/nine/level");
  f3=me->query("functions/gen/level");
  f4=me->query("functions/ice/level");
  f5=me->query("functions/purple/level");
  f6=me->query("functions/black/level");
  f7=me->query("functions/bluesea/level");
  f8=me->query("functions/goldsun/level");
  f9=me->query("functions/blood/level");
  f10=me->query("functions/green/level");
  wiz=0;
  if( wizardp(me) && arg ) {
    if( wiz_level(me) < 4 )
      return notify_fail("你的职权无法强迫玩家离开。\n");
    wiz=me;
    if( !(me=find_player(arg)) )
      return notify_fail("没有这个玩家。\n");
/*
    if( wiz_level(wiz) < wiz_level(me) )
      return notify_fail("你无法强迫上级离开。\n");
*/
  }
  //若有设must_be_quit就一定会被quit,杀人凶手也不例外 by bss
  if(!me->query_temp("must_be_quit"))
  if( me->query("robot/ans") )
    return notify_fail( "你现在正被审问, 不得离线!\n" );

  if (me->query("pker")) {
    //chan设定pker三十分钟不能离线
    if(me->query("PKTIME") >= time()) //这样应该就不会有要wiz帮他消杀人凶手title的事by bss
      return notify_fail("你现在是杀人凶手，不能离线！\n");

    //表示超过三十分钟都没有事,就不是pker了 by chan
    else {
      me->set("pker",0);
      pktitle=me->query("PKNAME"); //将他的title回复
      me->set("title",pktitle);
      return notify_fail("你现在以经不是杀人凶手了,再打一次quit就可以离线了!\n");
    }
  }

  if (me->query_temp("multipk")) {
    if (!me->query_temp("must_be_quit")) {
      return notify_fail( "尚未缴交武林大会场地费, 无法离线。\n" );
    }
    else {
      "/open/mulitpk/room/room01.c"->valid_leave(me,"out");
    }
  }

  if (me->is_fighting())
    return notify_fail( "您正在战斗, 无法离线。\n");

  if (me->query_temp("抢劫中")) {
    me->delete("greeting_msg");
    me->set("id", me->query("old_id"));
    me->set("name", me->query("old_name"));
    me->set("nickname", me->query("old_nick"));
    me->set("title", me->query("old_title"));
    me->delete("old_id");
    me->delete("old_name");
    me->delete("old_nick");
    me->delete("old_title");
    env->delete("have_bandit");
  }
  if (me->query_temp("募捐中")){
    tell_object(me, HIW"你开始收起破碗公,离开这里。\n"NOR);
    me->delete("greeting_msg");
    me->set("id", me->query("old_id"));
    me->set("name", me->query("old_name"));
    me->set("nickname", me->query("old_nick"));
    me->set("title", me->query("old_title"));
    me->delete("old_id");
    me->delete("old_name");
    me->delete("old_nick");
    me->delete("old_title");
    me->delete_temp("募捐中");
    me->delete_temp("不准走");
  }

  if(me->query_temp("不准走")) return notify_fail("你现在不准走......!!\n");

  if(!wizardp(me)) {
    me->delete("env/隐身");
  }

  // 重新解后三 by swy
  if (!me->query("mblade-new")) {
    me->set("mblade-new",1);
  }

  // meq and godeq 泛滥所以要查一下 by swy
  if (ob && !me->query("qu-meq")) {
    me->set("qu-meq",1);
    me->delete("meq");
    me->delete("have_mdragon");
    log_file("mblade/meq",sprintf("(%s) 有 meq\n",me->query("id")));
  }

  if (ob2 && !me->query("qu-godeq")) {
    me->set("qu-godeq",1);
    log_file("mblade/godeq",sprintf("(%s) 有 godeq\n",me->query("id")));
  }

  // 发新的有 set 所以以下检查不用关 by swy
  if (!me->query("new-by-swy") && me->query("id")!="swy" ) {
    me->delete("clear-meq-godeq");
    me->delete("del-meq-godeq");
    inb = all_inventory(me);
    for (j=0; j<sizeof(inb); j++)
      if (inb[j]->query("id")=="mdragon-eq" || inb[j]->query("id")=="god-eq") {
        log_file ("mblade/clear-eq",
                  sprintf ("(%s)清除%s\n", me->query("id"),
                          inb[j]->query("name")));
        destruct(inb[j]);
     }
  }

  if (me->query_temp("have_horse",1)==1) {
    horse = find_living((string)me->query_temp("horse",1));
    if (horse && (horse->query_temp("my_boss",1)==me->query("id",1))) {
      destruct(horse);
    }
  }

  if (me->query("family/family_name")=="金刀门"&&me->query("id")!="swy") {
    me->do_command("enable dodge none");
    me->reset_action();
    me->do_command("enable move none");
    me->reset_action();
  }
  if (me->query("force_factor") > 10)
    me->set("force_factor",10);
  if (me->query("mana_factor") > 10)
    me->set("mana_factor",10);

  //设定离线时enforce 为 10 by chan
  if (me->query("powerup_flag")) {
    me->delete("powerup_flag");
    me->set("force_factor" ,10);
  }

  if (me->query_temp("upforce")==1) me->set("force_factor" ,10);
  gift_key = keys(gift);
  if (me->query_temp("spe") == 1)
    SEC_KEE_D(me->query("sec_kee"))->remove_it(me);

  for (i=0; i<sizeof(gift); i++) {
    if( me->query(gift_key[i])>35 ) {
      tell_object(me,"你的"+gift[gift_key[i]]+"过高，系统将它改为 35。\n");
      me->set(gift_key[i],35);
    }
  }

  // 把东西丢下来？
  if (!wizardp(me)) {
    inv = all_inventory(me);
    for (i=0; i<sizeof(inv); i++)
      if (!inv[i]->query_autoload() && inv[i]->query("name") != "布衣")
        DROP_CMD->do_drop(me, inv[i]);
  }

  if( sizeof(me->query_team()) > 0 ) {
    if(me->query_temp("leader"))
      me->query_temp("leader")->dismiss_team();
    write("你脱离了队伍了\n");
    me->dismiss_team();
  }

  // 这里是判断: 如果有人switch mob 的话, 则将link_ob 交回原
  // char身上。这里是使玩家档坏的最大原因, 现在已经改好了
  //                                       modified by Konn
  //
  if (body_ob = me->query_temp ("body_ob")) {
    link_ob = me->query_temp ("link_ob");
    me->delete_temp ("body_ob");
    exec (link_ob, me);
    exec (body_ob, link_ob);
    body_ob->setup();
    tell_object (me, "你的魂魄回到"+ body_ob->name() +"的身上。\n");
    write ("ok.\n");
    return 1;
  }

  if (wiz && wizardp(this_player(1))) {
    tell_object(me, wiz->name() + "(" + wiz->query("id") + ")强迫你离线。\n");
    message_vision("$N被$n瞪了一眼就离开游戏了。\n", me, wiz);
  }

  // by acky
  else {
    me->delete_temp("msg_buffer");
    write( "\n"+
    HIB"  ╓──╖╓──╖╓─╖╖╓╥─╖╓──╖╓──╖╓    ╖\n"+
    BLU"  ╟──╖╟──╢║  ║║  ║    ╟──╢╙──╖║    ║\n"+
    HIC"  ║      ║    ║║  ║║  ║    ║    ║      ║╙─╥╜\n"+
    CYN"  ╙      ╙    ╜╙  ╙╜  ╨    ╙    ╜╙──╜  ─╨  \n"+
    HIB"                                  ╓──╖╓──╮╓──╖╓──╖╓──╖\n"+
    BLU"                                  ╙──╖║    ║╟──╢║      ╟──╖\n"+
    HIC"                                        ║╟──╜║    ║║      ║      \n"+
    HIC"◆"+HIW"────────────────"+CYN"╙──╜╙      ╙    ╜╙──╜╙──╜"+HIW"─"+HIC"◆\n");
    write( CYN"\n由于你对真实世界的牵挂, 你将回到原来的世界。\n" +
           "希望你不要忘了自己的使命和你对这狂想空间伙伴们的承诺。\n"NOR );
    message_vision ("$N离开狂想空间了。\n", me);
  }

  log_file ("quit",
            sprintf("%s(%s)于 %s 离开游戏。\n他的上一个命令是 '%s'\n",
                    me->query("name"),
                    me->query("id"),
                    ctime(time()),
                    me->query_temp("last_input"))
  );

  // Modify By Spirits. 10.02.1995
  if (wiz_level(me) != 7) {
    CHANNEL_D->do_channel(this_object(), "sys",
      sprintf("%s(%s)离线。", me->query("name"), me->query("id")) );
  }
  me->set("last_on", time());

  if( pal=me->query_temp("pal") ) {
    pal->save();
    destruct(pal);
  }

  me->save();

  destruct(me);
  return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : quit <player>
指令说明 :
           当你(妳)想离开狂想的时候，可利用此一指令。
           离开之前，系统会自动储存您的进度。
           大巫师则可以强迫玩家离线。
HELP);
        return 1;
}
