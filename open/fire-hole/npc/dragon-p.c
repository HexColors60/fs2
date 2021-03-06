//修正心跳问题与限制exp上限并增加1/100的机会使ppl中入灭 bye cyw at 91/04/02
inherit NPC;
inherit F_MASTER;
#include "/open/open.h"
#include <ansi.h>
void create()
{
        object ob;
        set_name("紫光火龙", ({ "poison dragon","dragon","poison" }) );
        set("long",
                "全身泛着紫光的火龙, 首护着火龙窟的结界交点。\n");
        set("race", "野兽");
        set("title",HIM"(毒气)"NOR);
        set("age", 49000);
        set("attitude", "aggressive");
        set("family/family_name","火龙窟");
        set("max_gin", 120000);
        set("max_kee", 120000);
        set("max_sen", 12000);
        set("max_force", 2000000);
        set("force", 2000000);
        set("force_factor",10);
        set("str", 99);
        set("cor", 99);
        set("spi", 99);
        set("int", 99);
        set("bellicosity",10000);
        set("limbs", ({ "头部", "身体", "前爪", "后爪", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        set_temp("apply/attack", 200);
        set_temp("apply/damage", 200);
        set("no_plan_follow",1);
        set_temp("no_die_soon",1);
        set_temp("apply/armor",  200);
        set_skill("move",150);
        set_skill("dodge",150);
        set_skill("parry",150);
        set_skill("force",500);
        set("combat_exp", 16000000);
        set_temp("kang-power",1);
        set_temp("def_fire",1);
        set_temp("todie",3);
        setup();
        ob=carry_object("/open/fire-hole/obj/p-pill.c");
        ob->set_amount(3);
}
void heart_beat()
{
 object env,mob,target,obj;
 mixed enemy;
 int i,hurt,j=0;
 mob = this_object();
 env = environment(mob);
 enemy = all_inventory( environment(mob) );
 i=sizeof(enemy);
 mob->clear_condition();
 if( query("kee") < 0)
 {mob->die();}
 if(mob->query("kee") < mob->query("max_kee") && mob->query("force") < 1000000)
 {
    mob->receive_curing("kee",500);
    mob->receive_heal("kee",500);
    mob->add("force",10000);
 }
// if (!mob->is_fighting() || mob->is_fighting())
// {
 for (j=0 ; j < i ; j++)
 {
 if (!enemy[j]->is_fighting() && enemy[j]->is_character() && !enemy[j]->is_corpse() 
     && living(enemy[j]) && enemy[j]->query("id")!="poison dragon" && userp(enemy[j]) && !wizardp(enemy[j]))
 mob->kill_ob(enemy[j]);
 }//}
 if(random(10) > 3)
 {
    enemy = all_inventory( environment(mob) );
    i=sizeof(enemy);
    target=enemy[random(i)];
    if (mob->is_fighting())
    {
        message_vision( HIM
        "\n紫光火龙从口中喷出一道紫色毒雾, 充满毒性的气体弥漫在四周!!\n"NOR,mob);
        for (j=0 ; j < i ; j++)
        {
        if(enemy[j]){	
        if( enemy[j]->is_character() && !enemy[j]->is_corpse() && living(enemy[j])
            && enemy[j]->query("id")!="poison dragon"
            && environment(this_object())==environment(enemy[j]))
        {
        hurt = 200+random(800);
        if (enemy[j]->query("class")=="fighter" && enemy[j]->query_temp("keeup")==1)
        hurt = hurt * 3;
        if (random(100)==13){
        tell_object (enemy[j],HIG"惨了!这好像是魔界奇毒‘入灭’!!\n"NOR);
        enemy[j]->apply_condition("mogi",5);}
        if (enemy[j]->query("class")!="poisoner")
        {  
        enemy[j]->apply_condition("ff_poison",15);
        enemy[j]->apply_condition("flower_poison",15);
        enemy[j]->apply_condition("snake_poison",15);
        enemy[j]->apply_condition("super_snake_poison",15);
        enemy[j]->apply_condition("dark_poison",15);
        enemy[j]->apply_condition("hart",15);
        enemy[j]->apply_condition("enforce_poison",15);
        enemy[j]->apply_condition("rose_poison",15);
        enemy[j]->set("five",100);
        enemy[j]->set("suck",100);}
        enemy[j]->add("kee",-hurt);
        COMBAT_D->report_status(enemy[j]);        
        }}}
 }
 }   
   set_heart_beat(1);
   ::heart_beat();
   
}
void die()
{
   int i,j=0;
   object *enemy,mob,me;
   me = this_player();
   mob = this_object();
   enemy = mob->query_enemy();
   i=sizeof(enemy);
        for (j=0 ; j < i ; j++)
        {
        if(enemy[j]){
        if(environment(this_object())==environment(enemy[j]) && userp(enemy[j])){
        enemy[j]->set_temp("ko_p",1);   
        if(enemy[j]->query("combat_exp") < 16000000){ 
        tell_object(enemy[j],HIY"\n由于你的努力, 终于打倒了紫光火龙, 你辛苦的代价换来了宝贵的经验!!\n"NOR);
        tell_object(enemy[j],HIC"你的战斗经验上升 7000 点, 潜在能力上升 1500 点!!\n"NOR);
        enemy[j]->add("combat_exp",7000);
        enemy[j]->add("potential",1500);  
        }}}}
   ::die();

}
