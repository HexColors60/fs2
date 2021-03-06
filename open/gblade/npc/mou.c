#include <ansi.h>
inherit NPC;
void create()
{
        set_name("独孤莫愁",({"degu mou","mou"}));
        set("long","此人是独孤嵊的弟子，和师父独孤嵊一心想平魔刀。\n");
        set("gender","男性");
        set("combat_exp",7000000);
        set("attitude","aggressive");
        set("age",50);
        set("class","fighter");
        set("family/family_name","雪苍派");
        set("quests/read_snow",2);
        set("title",HIC"武学之极"NOR);
        set("force",30000);
        set("max_gin",20000);
        set("max_sen",20000);
        set("max_kee",30000);
        set("bellicosity",5000);
        set("max_force",30000);
        set("force_factor",60);
        set("str",45);
        set("mpower",1);
        set("cor",45);
        set_skill("snow-martial", 120);
        set_skill("snowforce", 120);
        set_skill("snow-kee",120);
        set_skill("black-steps",120);
        set_skill("unarmed",120);
        set_skill("dodge",120);
        set_skill("parry",120);
        set_skill("force",120);
        map_skill("unarmed", "snow-martial");
        map_skill("parry","snow-kee");
        map_skill("force", "snowforce");
        map_skill("dodge", "black-steps");
        set_temp("apply/armor",100);
        set_temp("apply/damage",100);
        setup();
        carry_object("/open/snow/obj/figring")->wield();
        add_money("gold", 20);
}
void heart_beat()
{
object me,room,*target;
int i,j;
me=this_object();
room=environment(me);
target=me->query_enemy(room);
if(i=sizeof(target)) {
if(random(100) > 50)
{
if(random(9) >= 3)
{
message_vision(HIY"独孤莫愁运起‘雷爆掌’向你一击，顿时掌气已印在你的胸膛！\n"NOR,me);
for(j=0;j < i;j++) {
target[j]->add("kee",-800); }
   }
   else
   {
message_vision(HIC"独孤莫愁心感疲狈，运起‘独孤秘传法咒’一道蓝光从苍天发出，顿时精神百倍。\n"NOR,me);
    me->delete_busy();
    me->clear_condition();
if(random(9) >= 5) {
    me->receive_curing("kee",2000);
    me->receive_heal("kee",1000); }
   }
}
  }
  ::heart_beat();
  }

void die()
{
   object me;
   me=this_object()->query_temp("last_damage_from");
   if (me && userp(me))  {
   me->add("snow-head",50);
tell_room(environment(),sprintf("%s从独孤莫愁身上切下一颗人头。\n",me->name()));
   }
   ::die();
}
