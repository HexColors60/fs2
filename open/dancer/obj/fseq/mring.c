// 网聚奖品by cgy(22/10/00)
#include <armor.h>
#include <ansi.h>
inherit FINGER;
object me=this_player();
int cor,kar,intt,spi,cps;
void create()
{
        set_name(HIG"狂想空间传说采玲"NOR,({"Fund_ring","ring"}) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit","件");
        set("value", 0);
        set("material","gem");
        set("long","一只传说的戒指，闪烁着奇异的光芒，好像拥有神奇功用。\n");
        set("no_auc",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_put",1);
        set("no_drop",1);
        set("no_get",1);
        }
        setup();
if(me->query("class")=="blademan")  this_object()->set("armor_prop/blade", 5);
if(me->query("class")=="fighter")   this_object()->set("armor_prop/unarmed",5);
if(me->query("class")=="swordsman") this_object()->set("armor_prop/sword",5);
if(me->query("class")=="scholar")   this_object()->set("armor_prop/stabber",5);
if(me->query("class")=="bandit")    this_object()->set("armor_prop/unarmed",5);
this_object()->set("armor_prop/move", 3);
this_object()->set("armor_prop/dodge", 5);
this_object()->set("armor_prop/parry", 5);
this_object()->set("armor_prop/force", 5);
this_object()->set("armor_prop/armor", 9);
}
void init()
{
     add_action("do_wear","wear");
     add_action("do_remove","remove");
}
int do_wear(string str)
{
     ::wear();
     if( query("equipped") )
     {
        kar = me->query("kar",1);
        cor = me->query("cor",1);
        cps = me->query("cps",1);
        spi = me->query("spi",1);
        intt = me->query("int",1);
message_vision(HIG"$N将狂想空间传说采玲戴上，狂想空间传说采玲唸起不死族回复咒文 撒拉 伊克 庵修姆。\n"NOR,me);
        set_heart_beat(1);
     }
}
int do_remove(string str)
{
   if(str=="Fund_ring" || str=="all" || str=="ring")
     if( query("equipped") )
     {
message_vision(YEL"$N脱下了狂想空间传说采玲，采玲用很奇怪的眼神瞄狂想空间传说采玲。\n"NOR,me);
        set_heart_beat(0);
     }
}

void heart_beat()
{
object *enemy;
int i;
  if( !objectp(me) )
        {
        set_heart_beat(0);
        return;
        }
  if( me->is_fighting()&&query("equipped")&&me->is_busy() )
  {
enemy=me->query_enemy();
i=random(sizeof(enemy));
if( enemy[i]->query("class")=="scholar" ) {
    kar = kar/2;
    intt = intt/2; }
if( random(cor+cps+spi) > 85-random(kar+intt) )  
    {
    me->delete_busy();
message_vision(HIW+"\n狂想空间传说采玲忽然发出阵耀眼的光芒，使$N冲开了身上被封之穴道。\n"+NOR,me);
    }
  }
  return;
}
