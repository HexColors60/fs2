#include <ansi.h>
#include <weapon.h>
#include <armor.h>
#include "/open/open.h"
#define SUB "/open/killer/obj/two"
inherit ITEM;
int help(object);
int level=0,armor_power=0,eq=1,now_def=0;
void create()
{
   seteuid(getuid());
   set_name("影武者",({ "nija fighter","nija","fighter" }) );
   set("weight",50);
   if( clonep() )
                set_default_object(__FILE__);
   else 
   {
     set("long",@LONG
     这是东瀛忍术超高禁术,所产生出来的忍者分身。据说早已失传，没想到又出现了。
     下列是你可以对他下的命令
     培养(feed)     格式 feed   <killer pill> ：使影武者成长
     命名(rename)   格式 rename <name>        ：为影武者改名
     资料(mob_data) 格式 mob_data             ：察看影武者等级与经验值
     护具(mob_eq)   格式 mob_eq <防具>        : 用于提高影武者的护身效果
     成长到一定程度，可以使用下列命令
     护身(helpme)   格式 helpme  <自己的名字> :可提高防御力
     背刺(mob_bak)  格式 mob_bak <敌人>       :一般时候，可以用于背刺敌人
     缠住(busy)     格式 busy    <敌人>       :战斗中冲出，妨碍敌人
     舍身(charge)   格式 charge               :耗损自身的等级，来回复你的精气神
     分身(sub)      格式 sub                  :把武影者变成你的分身
                                               可打cmds观看分身指令喔
     说话(mob_say)  格式 mob_say <msg>        :让影武者按照你的心意说话
LONG);
    set("unit","位");
    set("no_sell",1);
    set("no_drop",1);
    set("no_auc",1);
   }
   setup();
}

void init()
{
    if (this_player()->query("class") != "killer")
	return 0;
    if( this_player()==environment() )
    {
       add_action("feed_pet","feed");
       add_action("rename_pet","rename");
       add_action("mob_busy","busy");
       add_action("mob_charge","charge");
       add_action("mob_help","helpme");
       add_action("to_eq","mob_eq");
       add_action("to_say","mob_say"); 
       add_action("bit_pet","mob_bak");
       add_action("verify_pet","mob_data");
       add_action("do_sub","sub");
       add_action("help_sub","cmds");
    }
}
int help_sub()
{
  SUB->help_sub();   return 1;
}

int feed_pet(string arg)
{
   object obj,me=this_player();
   int expm;

   if(!arg)  return notify_fail("指令格式: feed <killer pill>\n");
   if(!(obj=present(arg,me)))
       return notify_fail("你身上没这样东西。\n");
   if(this_object()->query("helpme")==1)
       return notify_fail("他在保护你，那有心思吃药呀？\n");
   if(obj->query("id") != "killer pill")
       return notify_fail("你只能喂它杀手密药。\n");
   message_vision("$N喂了"+this_object()->name()+"一颗杀手密药。\n",me);
   if (!me->query("monkey_exp"))
   { 
      me->set("monkey_exp",1); 
      me->set("monkey_lv",1);
   }    
   expm=random(20);
   me->add("monkey_exp",expm);
   expm=me->query("monkey_exp");
   if (expm >= 100)  //升级
   {
    level =me->query("monkey_lv");
     level += 1;
     if (level > 100)
       level=100;
     me->set("monkey_lv",level);
     me->set("monkey_exp",1);
     expm=0;
   }
   obj->add_amount(-1);
   this_object()->set("lv",me->query("monkey_lv"));
   this_object()->set("exp",me->query("monkey_exp"));
   this_object()->set("bak_times",0);
   this_object()->set("busy_times",0);
   this_object()->set("mudsay",0);
   return 1;
}

int rename_pet(string arg)
{
   if(!arg) return notify_fail("你想把他改成什么名字呢?\n");
   arg = trans_color(arg);
   this_object()->set_name(arg + NOR,({ "nija fighter","nija","fighter" }) );
   write("你替你的影武者取了个名字叫"+this_object()->name()+"。\n");
   return 1;
}

int to_say(string arg)
{
   int pow,helpme,t_kee,buf;
   object ob,me,target;
   string str;

   me = this_player();
   ob = this_object();
   pow = ob->query("lv");
   if(ob->query("mudsay")!= 0)
      return notify_fail(ob->name()+"刚才说的快累死了，再给他药吧。\n");
   if( pow < 80 ) 
       return notify_fail(ob->name()+"还不够强大喔,再多喂他一些杀手密药吧。\n");
   if(!arg) return notify_fail("你想要他说什么呢？\n");
   
   message("mud",HIG+ob->name()+HIG+"说：‘"+arg+"’\n"NOR,users());
   ob->set("mudsay",1);
   return 1;
}

int mob_help(string arg)
{
   int pow,helpme,t_kee,buf;
   object ob,me,target;
   string str;
   me = this_player();
   ob = this_object();
   pow = ob->query("lv");
   helpme=ob->query("helpme");
	// 87.6.12加入
	//避免使用sub之后,影舞者的防御力变成零
   armor_power=me->query_temp("mob_def");

   if( !arg )
       return help(me);
   if (arg == "none")
   {
    ob->set("helpme",0);  //还要使自己的防御力下降
    me->add_temp("apply/armor",-now_def);
    return 1;
   }
   if (helpme == 1)
       return notify_fail(ob->name()+"已经在保护你了\n");
   target = present(arg, environment(me)); 
   if( target != me ) 
       return notify_fail(ob->name()+"去保护别人？真是伟大的情操\n");
   if( pow < 3 ) 
       return notify_fail(ob->name()+"还不够强大喔,再多喂他一些杀手密药吧。\n");
   buf=armor_power;  //取得武者的防御力
   if( buf > 600 )
   {
    message_vision(ob->name()+HIM+"化成一道金光，布满你的周围，形成超级防护层\n" 
NOR,target);
    me->add_temp("apply/armor",200);
    ob->set("helpme",1);
    now_def=200;
    return 1;
   }
   if( buf > 250 )
   {
    message_vision(ob->name()+HIM+"化成一道金光，全心的吸引敌人的注意\n" 
NOR,target);
    me->add_temp("apply/armor",80);
    ob->set("helpme",1);
    now_def=80;
    return 1;
   }
    if( buf > 200 )
    {
     message_vision(ob->name()+HIM+"拿起防具，全神地戒备着\n" NOR,target);
     me->add_temp("apply/armor",60);
     ob->set("helpme",1);
     now_def=60;
     return 1;
    }
    if( buf > 150 )
    {
     message_vision(ob->name()+HIM+"全神地戒备地看着四周\n" NOR,target);
     me->add_temp("apply/armor",40);
     ob->set("helpme",1);
     now_def=40;
     return 1;
    }
    if( buf > 100 )
    {
     message_vision(ob->name()+HIR+"戒备地看着四周\n" NOR,target);
     me->add_temp("apply/armor",30);
     ob->set("helpme",1);
     now_def=30;
     return 1;
    }
    if( buf > 50 )
    {
     message_vision(ob->name()+HIR+"轻松地看着四周\n" NOR,target);
     me->add_temp("apply/armor",20);
     ob->set("helpme",1);
     now_def=20;
    return 1;
    }
     message_vision(ob->name()+HIR+"能保护你吗？，你还是自己小心点吧\n" NOR,target);
     return 0;
}

int to_eq(string arg)
{
  object ob,me;
  int armor;

  me=this_player();
  seteuid(getuid());
  if( !arg ) return help(me);
  if(!(ob = present(arg,me))) return notify_fail("你身上没这个东西！\n");
  if (ob->limit_ident(me)) 
    return notify_fail("唉呀！这物品似乎被某种封印封住了，所以影武者也不能装备\n\n"); 
  if (ob->query("skill_type")) 
      return notify_fail("拜托，我不是说不能给武器吗？\n\n"); 
  if (eq > 5)
      return notify_fail("拜托，你把他当猪吗？还是仓库呀？\n\n"); 

  if (ob->query("armor_type")) 
  {
    armor=ob->query("armor_prop/armor");
    switch(ob->query("armor_type"))
    {
      case(TYPE_CLOTH):	armor=armor*3;break;
      case(TYPE_SHIELD):armor=armor*4;break;
      case(TYPE_HEAD):
      case(TYPE_PANTS):	armor=armor*6;break;
      case(TYPE_NECK):
      case(TYPE_ARMBANDS):
      case(TYPE_WAIST):
      case(TYPE_WRISTS):
      case(TYPE_FINGER):
      case(TYPE_HANDS):
      case(TYPE_BOOTS):
      case(TYPE_LEGGINGS):
      case(TYPE_CAPE):	armor=armor*12;break;
    } 
    destruct(ob);
    eq+=1;
    armor_power=armor_power+armor;
	// 87.6.12加入
	//避免使用sub之后,影舞者的防御力变成零
    me->set_temp("mob_def",armor_power);
    write(this_object()->name()+HIG"将防具收下来！\n"NOR);
    return 1;                          //要防止防御力的累积
 }
  if (ob->query("食物")) 
    return notify_fail("不会吧？食物太多是不是？\n\n"); 
  if (ob->query("液体")) 
    return notify_fail("你想让他对敌人泼水呀？\n\n"); 
  if (ob->query("light_up"))
    return notify_fail("你看的到就够了啦！\n\n"); 
  return notify_fail("wa ley....你到底是给什么呀？\n\n"); 
} 
 
int mob_charge(string arg)
{
   int pow,bak_times,t_kee,buf;
   object ob,me,target;
   string str;

   me = this_player();
   ob = this_object();
   pow = ob->query("lv");
   if( pow < 50 ) 
     return notify_fail(ob->name()+"还不够强大喔,再多喂他一些杀手密药吧。\n");
   if( !arg )
   {
     write(ob->name()+HIG"收到命令后，知道他报效的时机来了。\n"NOR);
     write(ob->name()+HIG"闭上双眼，屏气凝神，使得原本黝黑的身体起了一阵光芒。\n"NOR);
     write(HIG"瞬间闪出一阵光芒，"+me->name()+"被光芒笼罩住\n"NOR);
     tell_object(me,"你感到你原本受损的身体，身心都完全回复了\n");
     me->set("gin",me->query("max_gin"));
     me->set("kee",me->query("max_kee"));
     me->set("sen",me->query("max_sen"));
     me->clear_condition();
     write(ob->name()+HIG"在光芒散去后，也消失的无影无踪。\n"NOR);
     ob->add("lv",-2);
     ob->set("exp",1);
     destruct(ob);
     me->add("monkey_lv",-2);
     me->set("monkey_exp",1);
     return 1;
   }    
   return notify_fail(ob->name()+"不会替别人舍身啦！。\n");
}
int bit_pet(string arg)
{
   int pow,bak_times,t_kee,buf;
   object ob,me,target;
   string str;
   me = this_player();
   ob = this_object();
   pow = ob->query("lv");
   bak_times=ob->query("bak_times");
   if( !arg )
       return notify_fail("你想叫"+ob->name()+"去背刺谁？\n");
   target = present(arg, environment(me)); 
    if(!target) return notify_fail("你找不到敌人!!\n");
   if( target->query("no_kill") ) 
       return notify_fail("这家伙你不能动就是不能动。\n");
   if( !wizardp(me) && environment(me)->query("no_fight") )
       return notify_fail("这里禁止战斗。\n");
   if( !target->is_character() || target->is_corpse() )
       return notify_fail("看清楚点,它并不是活物。\n");
   if( target == me ) 
       return notify_fail(ob->name()+"看起来并不想背刺你。\n");
   if( target->query_temp("bit")==1)
       return notify_fail("你以为敌人很笨会上二次当吗？\n");
   if( pow < 5 ) 
       return notify_fail(ob->name()+"还不够强大喔,再多喂他一些杀手密药吧。\n");
   if( bak_times > 2)
       return notify_fail(ob->name()+"很累了，再多喂他一些杀手密药吧。\n");
   if(this_object()->query("helpme")==1)
       return notify_fail("他在保护你，那有心思背刺呀？\n");

   message_vision(
   ""+ob->name()+"潜入房中的暗处，准备背刺$n。你摒息的看着它\n\n",me,target);
   buf=random(pow+15);
   if( buf > 15 )
   {
    if( buf > 30 )
    {
     message_vision(HIG"$N不够小心,被"+ob->name()+HIR+"背刺了！\n" NOR,target);
     t_kee=target->query("max_kee")/13;
     target->add("kee",-t_kee);
     target->set_temp("bit",1);
     ob->add("bak_times",1);
     return 1;
    }
    if( buf > 60 )
    {
     message_vision(HIG"$N毫无警觉,被"+ob->name()+HIR+"狠狠地背刺了！\n" NOR,target);
     t_kee=target->query("max_kee")/10;
     target->add("kee",-t_kee);
     target->set_temp("bit",1);
     ob->add("bak_times",1);
     return 1;
    }
    if( buf > 90 )
    {
     message_vision(HIG""+ob->name()+HIR+"狠狠地使出双重背刺！！$N受创很深！\n" NOR,target);
     t_kee=target->query("max_kee")/5;
     target->add("kee",-t_kee);
     target->set_temp("bit",1);
     ob->add("bak_times",1);
     return 1;
    }
    message_vision(HIG"$N一个不留意,被"+ob->name()+HIR+"背刺了！\n" NOR,target);
    t_kee=target->query("max_kee")/20;
    target->add("kee",-t_kee);
    target->set_temp("bit",1);
    ob->add("bak_times",1);
    return 1;
   }
   else
   {
    message_vision(HIC"$N急急忙忙往后跳开, 被"+ob->name()+HIC+"吓出了一深冷汗。\n" NOR,target);
    target->add("sen",-5);
    ob->add("bak_times",1);
    return 1;
   }
}

int mob_busy(string arg)
{
   int pow,busy_times,t_kee,buf;
   object ob,me,target;
   string str;

   me = this_player();
   ob = this_object();
   pow = ob->query("lv");
   busy_times=ob->query("busy_times");

   if( !arg )
       return notify_fail("你想叫"+ob->name()+"去缠住谁？\n");
   target = present(arg, environment(me)); 
   if( target->query("no_kill") ) 
       return notify_fail("这家伙你不能动就是不能动。\n");
   if( !wizardp(me) && environment(me)->query("no_fight") )
       return notify_fail("这里禁止战斗。\n");
   if( target->is_busy() )
       return notify_fail("敌人已挨打中，你还要做什呀！\n");
   if( !target->is_character() || target->is_corpse() )
       return notify_fail("看清楚点,它并不是活物。\n");
   if( target == me ) 
       return notify_fail(ob->name()+"本来就缠着你，你还要他多腻你呀？。\n");
   if( pow < 30 ) 
       return notify_fail(ob->name()+"还不够强大喔,再多喂他一些杀手密药吧。\n");
   if( busy_times > 1)
       return notify_fail(ob->name()+HIG"很累了，再多喂他一些杀手密药吧。\n"NOR);
   if(this_object()->query("helpme")==1)
       return notify_fail("他在保护你，那有心思去缠住敌人呀？\n");

   if ( me->is_fighting(target) || me->is_killing(target) )
   {
   message_vision(ob->name()+"不顾生命危险，在战斗中冲了出去，想设法缠住$n。\n",target);
   buf=random(pow+20);
   if( buf > 90 )
   {
     message_vision(HIG"$N被"+ob->name()+HIR+"奋不顾身的打法，逼的根本没有办法对你进攻！\n" NOR,target);
     target->start_busy(2);
     t_kee=target->query("max_kee")/15;
     target->add("kee",-t_kee);
     ob->add("busy_times",1);
     return 1;
   }
   if( buf > 70 )
   {
     message_vision(HIG"$N被"+ob->name()+HIR+"的连续攻击缠住了\n" NOR,target);
     target->start_busy(2);
     t_kee=target->query("max_kee")/15;
     target->add("kee",-t_kee);
     ob->add("busy_times",1);
     return 1;
    }
    if( buf > 50 )
    {
     message_vision(HIG""+ob->name()+HIR+"连射数道飞刀，逼的$N有点手忙脚乱\n" NOR,target);
     target->start_busy(1);
     t_kee=target->query("max_kee")/20;
     target->add("kee",-t_kee);
     ob->add("busy_times",1);
     return 1;
    }
    if (buf > 20)
    {
     message_vision(HIG""+ob->name()+HIR+"冲了出去，令$N身形一顿\n" NOR,target);
     target->start_busy(1);
     ob->add("busy_times",1);
     return 1;
    }
    message_vision(HIG"$N被冲出来的"+ob->name()+HIR+"撞到了，但无伤大雅\n" NOR,target);
    t_kee=target->query("max_kee")/20;
    target->add("kee",-t_kee);
    ob->add("busy_times",1);
    return 1;
   }
   return notify_fail("神经病，不在战斗中，你缠心酸的呀！\n");
}

int verify_pet(string str)
{
  int lv,expm,armor;
  object obj=this_object();

	// 87.6.12加入
	//避免使用sub之后,影舞者的防御力变成零
   armor_power=this_player()->query_temp("mob_def");

  lv =  (int)obj->query("lv");
  expm = (int)obj->query("exp");
  write(obj->name()+"      目前等级   :  "+lv+"\n\n");
  write(obj->name()+"      目前经验值 :  "+expm+"\n\n");
  write(obj->name()+"      目前防御力 :  "+armor_power+"\n\n");
  return 1;
}


//add by Leei
int do_sub(string str)
{
   int pow;
   object ob,me,sub;

   me = this_player();
   ob = this_object();
   pow = ob->query("lv");
   if( !pow || pow < 80 )
     return notify_fail(ob->name()+"不够强,再多喂他一些杀手密药吧。\n");
   if(this_object()->query("helpme")==1)
       return notify_fail("他在保护你，还想出分身，又不是妖怪\n");
   if ( me->query("force") < 100 )
     return notify_fail("你的内力不够。\n");
   if ( !me->is_fighting() )
     return notify_fail("在战斗中才能呼叫分身。\n");
   if ( me->query_temp("sub","USED") )
    return notify_fail("你得武影者没有归位，请离线后再进入。\n");
   if( !str )
   {
   message_vision(HIC"$N向$N的 "NOR"$n "HIC"求救,突然间$N的 "NOR"$n "HIC"变成人加入这场战斗。\n"NOR,me,ob);



    me->add("force",-100);
    sub=new("/open/killer/obj/two.c");
    sub->set("sub_id",""+me->query("id")+"");
    sub->set("old_name",""+ob->name()+"");
   if ( me->query_temp("pk_fight") ) {
    sub->set_temp("pk_fight",1);
   } else {   me->set_temp("sub","USED");    }
    sub->move( environment(me) );
    sub->invocation(me);
    destruct(ob);
   }
   return 1;
}


int query_autoload ()
{
  if(!this_player()) return 0;
  if (this_player()->query("quest/rain") == 1)
    return 1;
  return 0;
}  
int help(object me)
{
  write (@HELP
指令     : to_eq ,helpme
指令说明 :
       to_eq: 给与你的影武者防具，但是不能给武器，因为影武者的能力有限
              给他的防具，他并不是用来装备，而是拿来抵挡对手
              一位影武者可拿的防具，不可超过5项，防御力越高提升的效果越好
              当然，离线后他的防具也会消失,如果影武者的防御力低于50点的话,
           会因为自身难保,而不能保护你
      helpme: 让影武者专心的抵挡攻击，可在一般时候就使用护身，不需等战斗才用
              护身中的影武者无法进行背刺，缠住，培养，但是仍可以舍身。
 helpme none: 可以取消护身的效果。
HELP); 
  return 1;
}

