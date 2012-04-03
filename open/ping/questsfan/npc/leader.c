inherit NPC;  //总镖头 by dhk 2000.4.22
#include <ansi.h>
#include </open/open.h>
string do_help();

void create()
{
    set_name("总镖头",({"mercenary leader","leader","mercenary"}) );
    set("title",""HIY"威武"NOR"镖局");
    set("gender", "男性");
    set("age",120);
    set("attitude", "peaceful");
    set("long", ""CYN"他是威武镖局总镖头，日前到北头山接恰一份红镖，谁\n"
                    +"知路经沼泽地，却不幸身陷泥沼，而无法自拔困在其中\n"
                    +"。他身陷于此正在等后好心的过路人伸出﹝援手﹞帮他\n"
                    +"一把。"NOR"\n");
    set("kee",2600);
    set("max_kee",2600);
    set("combat_exp",100000);
    set("class","blademan");
    set_skill("move",40);
    set_skill("force",80);
    set_skill("dodge",60);
    set_skill("parry",70);
    set_skill("blade",100);
    set_skill("gold-blade",90);
    set_skill("fly-steps",80);
    set_skill("sixforce",80);
    set_skill("fast-blade", 90);
    map_skill("blade","fast-blade");
    map_skill("parry","gold-blade");
    map_skill("dodge","fly-steps");
    map_skill("move","fly-steps");
    map_skill("force","sixforce");
    set_temp("apply/armor",100);
    set("force_factor",10);
    set("inquiry", ([
                     "援手"         : (: do_help :),
    ]));
    setup();
}
int accept_kill(object who)
{
  return 1;
}
int accept_fight(object who)
{
  return 1;
}
string do_help()
{
        object me=this_player();
        object room = environment(this_object());
//      if( me->query("family/family_name")=="段家") //&& me->query("marks/six_sp")<=2)
//      {
          me->set_temp("helpman",1);
          return("拜托！拜托！.......请你救救我﹝helpleader﹞");
//      }
//      else
//      {
//        command("sigh"+me->query("id"));
//        return("你不是段将军家的门人，我不放心!!");
//      }
}
void init()
{
  remove_call_out("greets");
  call_out("greets",1,this_player());
  add_action("do_nod","helpleader");
}
void greets(object me)
{
  command("help!");
}
int do_nod()
{
object me = this_player();
if(me->query_temp("helpman") != 1)
        return 0;
me->set_temp("helpman",2);
remove_call_out("greeting");
call_out("greeting",1,me);
 return 0;
}
int do_shake()
{
  object me = this_player();
  if(me->query_temp("helpman") != 1)
        return 0;
  me->delete_temp("helpman");
  remove_call_out("greeting2");
  call_out("greeting2",1,me);
  return 0;
}
void greeting(object me)
{
  object letter=new("/open/ping/questsfan/obj/letter.c");
  object ob = this_object();
if(me->query_temp("blade_ok")==0)
{
  command("smile");
  command("say 谢谢你的帮忙。请你把这封信交给威武镖局
副镖头，他会交你在下对您救命之恩的一点"HIR"心意。"NOR"");
  letter->move(me);
  me->set_temp("helpman",2);
    me->set_temp("blade_ok",1);
}
else
tell_room(environment(this_object()),"我已经好了谢谢!!!");
}
void greeting2(object me)
{
command("sigh");
tell_room(environment(this_object()),HIC"只见总镖头失望的大骂：现在的人真没同情心。\n"NOR);
}
