inherit NPC;
#include <ansi.h>
void create()
{
        set_name("死灵骨魔", ({ "death ghost king","death","ghost","king" }) );
        set("long",
        "他是死灵幽谷的玄冥之气所汇集而成的魔物，凭着己身强大的力量，把死灵界
掌握于手中，其‘玄冥神掌’更是让人不敢恭维。\n");
        set("gender","男姓");
        set("title",BLU"玄冥魔神"NOR);
        set("age", 100000);
        set("attitude", "aggressive");
        set("max_gin", 80000);
        set("max_kee", 80000);
	set("kee",1);
        set("max_sen", 80000);
        set("max_force", 2000000);
        set("force", 2000000);
        set("force_factor",50);
        set("str", 99);
        set("cor", 99);
        set("spi", 99);
        set("int", 99);
        set("bellicosity",10000);
        set_temp("apply/attack", 200);
        set_temp("apply/damage", 200);
        set("no_plan_follow",1);
        set_temp("no_die_soon",1);
        set_temp("apply/armor",  200);
        set_skill("move",150);
        set_skill("dodge",150);
        set_skill("parry",150);
        set_skill("force",500);
        set("combat_exp", 12000000);
        set_temp("kang-power",1);
        setup();
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

 if(mob->query("kee") < mob->query("max_kee") && random(100) < 20)
 {
    mob->receive_curing("kee",300);
    mob->receive_heal("kee",300);
 }
 if (!mob->is_fighting() || mob->is_fighting())
 {
 for (j=0 ; j < i ; j++)
 {
 if (!enemy[j]->is_fighting() && enemy[j]->is_character() && !enemy[j]->is_corpse() 
     && living(enemy[j]) && enemy[j]!="death ghost king") 
 mob->kill_ob(enemy[j]);
 }}
 if(random(10) > 3)
 {
    if (mob->is_fighting())
    {
        for (j=0 ; j < i ; j++)
        {
        if( enemy[j]->is_character() && !enemy[j]->is_corpse() && living(enemy[j])
            && enemy[j]->query("id")!="poison dragon")
        {
	message_vision( HIB
        "\n一股玄冥之气排山倒海而来，强大的气力压的$N喘不过气来！！\n"NOR,mob);
        COMBAT_D->report_status(enemy[j]);
        enemy[j]->add("kee",-1500);
        }}
 }
 }   
   set_heart_beat(1);
   ::heart_beat();
   
}
void die()
{
object me,ob,ob1;
me=query_temp("last_damage_from");
ob=new(__DIR__"test01");
ob1=new(__DIR__"test02");
tell_object(users(),HIW"
		～～"BLU"死灵幽谷传来一阵凄凉的哀嚎声"HIW"～～

"HIR"焚天魔王大怒：该死的"+me->query("name")+"～～竟然打败我的结拜好兄弟幽冥骨魔！！
	      看来我应该到人间界跟"+me->query("id")+"讨回这笔帐！！
	      
	      众魔将们听命～！！远征人间界的时间到了！！
	      
"HIW"独孤嵊大笑：哈哈～！！人间界即将大乱，看来我应该出塔助焚天魔王一臂之力！！
	    
	    各楼塔主得令！！火速出塔～～大闹人间界～～！！
"NOR);
ob->move("/open/common/room/inn");
ob1->move("/open/common/room/inn");
::die();
}
