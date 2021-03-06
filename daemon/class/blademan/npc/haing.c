inherit NPC;
string do_ask (object me);
#include "/open/open.h"
#include <ansi.h>
void create()
{
set_name("离子寒", ({ "hiang",}) );
set("long", "
她是魔刀门首传女弟子，明脉浩齿，一双柳叶眉如远山黛月般横卧
天灵，晶盈的双目被睑水长睫所遮掩，眉目间一股灵秀之气显出智
慧的不凡，身上仅着一件浴袍，玲陇的身材若隐若现。\n");
set("title","魔刀首传后三女弟子");
set("nickname", HIC"清风云裳"NOR);
set("age", 25);
set("family/family_name","魔刀门");
set("int", 35);
set("m_blade",1);
set("cps", 35);
set("str", 35);
set("cor", 35);
set("spi", 35);
set("con", 35);
set("have_book",1);
set("kar", 35);
set("per", 35);
set("force_factor", 20);
set("combat_exp",1500000);
set("force", 4000);
set("max_force", 4000);
set("max_kee", 4000);
set("kee", 4000);
set("env/get_mblade","YES");
set("env/魔性六斩","YES");
set("mpower",1);
set("bellicosity", 2500);
set_skill("blade", 120);
set_skill("dodge", 105);
set_skill("parry", 105);
set_skill("force", 50);
set_skill("literate",105);
set_skill("dragon-blade", 120);
set_skill("powerforce", 95);
set_skill("unarmed", 50);
set_skill("move",50);
map_skill("force", "powerforce");
map_skill("parry", "dragon-blade");
map_skill("blade", "dragon-blade");
set("chat_chance_combat", 60);
set("chat_msg_combat", ({
(: perform_action, "blade.mdragon-dest" :),
}));
set( "gender", "女性");
set("limbs", ({ "头部",  "双脚", "双手", "背部" ,"腹部","腰部"}) );     
set("attitude", "peaceful");
set("chat_chance", 2);
set("chat_msg", ({
"黎子寒疑惑的望着妳。 \n",
"黎子寒问到：‘这位姑娘有事吗 ...? ’\n",
}));
set("inquiry",([
"神兵利器" : "据我所知，当今的神兵利器，首推玉衡天剑和龙虎刀!\n",
"玉衡天剑" : "那是仙剑派开山祖师逍遥子的佩剑!\n",
"龙虎刀"   : "龙虎刀是金刀门至宝，始祖王蹇之佩刀!\n",
"刀冢":"相传是一处藏满绝世好刀的地方，不妨跟你说，听说师祖莫测当年横扫武林时，所用的刀就是从刀冢取出的，之后那把刀就成为魔刀镇教之宝。\n",
"麒麟角" : "这个我也不太清楚,只大略晓得麒麟喜欢吃凤凰蛋!\n",
"凤凰蛋" : "听说在高大的梧桐树上居有这种奇兽!\n",
        ]));
set_temp("apply/armor",45);
set_temp("apply/damage",45);
     setup();
     carry_object("/daemon/class/blademan/obj/blade1.c")->wield();
     carry_object("/daemon/class/blademan/obj/cloth1.c")->wear();
     carry_object("/daemon/class/blademan/obj/belt1.c")->wear();
     add_money("gold",10);
}
 
void greeting(object ob)
{

           if( ob->query("gender")=="男性")
        {
         command("say 哼 ！ 大色狼 ， 我宰了你 ！" );
        kill_ob(ob);
   }   }
int accept_kill(object who)
{
  who=this_player();
  command("kill "+who->query("id"));
  command("perform blade.mdragon-dest");
  return 1;
}
