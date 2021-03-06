#include <ansi.h>
#include "/open/open.h"
inherit NPC;
string retitle();

void create()
{
object ob;
set_name("叶秀杀",({"master yar","yar","master"}));
set("long","他是名震江湖的一代杀手，黑牙联的头目。\n");
set("gender","男性");
set("title",HIW"～幻影～"NOR);
set("class","killer");
set("nickname","杀眼无情");
set("combat_exp",8000000);
set("attitude","heroism");
set("age",36);
set("str", 45);
set("cor", 34);
set("cps", 18);
set("per", 24);
set("int", 42);
set("kee",10000);
set("max_kee",10000);
set("gin",1600);
set("max_gin",1600);
set("atman",1200);
set("max_atman",1200);
set("mana",1000);
set("max_mana",1000);
set("force",100000);
set("max_force",100000);
set("quest/rain",1);
set_skill("cure",50);
set_skill("magic",20);
set_skill("literate",30);
set_skill("force",80);
set_skill("move",80);
set_skill("parry",60);
set_skill("dagger",90);
set_skill("dodge",100);

set_skill("throwing",120);
set_skill("blackforce",95);
set_skill("shade-steps",100);
set_skill("rain-throwing",100);
set_skill("shadow-kill",90);
map_skill("throwing","rain-throwing");
map_skill("dodge","shade-steps");
map_skill("force","blackforce");
set("bellicosity",1500);
set_temp("apply/armor",70);
set("force_factor",15);
set("chat_chance_combat",45);
set("chat_msg_combat",({
(:perform_action,"throwing.manakee":),
}));
setup();
create_family("黑牙联",2,"主席");
ob=carry_object("/open/killer/obj/hate_knife");
ob->set_amount(300);
ob->wield();
carry_object("/open/killer/weapon/k_cloth3.c")->wear();
carry_object("/open/killer/weapon/k_boot3.c")->wear();
carry_object("/open/killer/weapon/k_arm3.c")->wear();
carry_object("/open/killer/weapon/k_head3.c")->wear();
carry_object("/open/killer/obj/k_ring.c");
}

void init()
{
        add_action("do_join","join");
}

int accept_kill(object ob)
{
command("say 没想到居然有人敢来这撒野！！");
message_vision( this_object()->name()+"突然变脸，脸上出现杀气。\n",ob);
this_object()->set("bellicosity",8000);
command("cmd bellup");
command("wear bell_ring");
return 1;
}

void heart_beat()
{
        if( is_fighting() ){
                if( query("kee") < query("eff_kee") )
                        command("exert recover");
        }
        :: heart_beat();
}


int heal_up()
{
        if (!is_fighting() ) {
             message_vision (HIW"系统：战斗停止，$N回收中，。\n"NOR, this_object ());
             destruct(this_object());
             return 1;
        }
        return ::heal_up() + 1;
}
void unconcious ()
{
 object me=query_temp("last_damage_from");
if(!present("fight_card",me))
{
tell_object(me,"\n\n系统：由于你没携带晶片，所以无法记录战绩。\n");
destruct (this_object ());
}
else
if(!me->query("quest/start_game"))
{
tell_object(me,"\n\n系统：由于你没有正式登记，资料无法传输。\n");
destruct (this_object ());
}
else
if(me->query("quest/start_game")< 24)
       {
        message_vision(HIY"
恭喜"HIW+me->query("name")+HIY"挑战"HIG"‘"HIR"第二十三层试炼□塔"HIG"’"HIY"通过！！

"HIW"希望"+me->query("name")+"能不负众望，勇闯"HIG"‘"HIY"第二十四层试炼□塔"HIG"’"HIW"。
	"NOR,me);
	me->set("quest/start_game",24);
        destruct (this_object ());
       }
{
        :: unconcious();
	tell_object(me,HIW"系统：你已经通过测试，系统不做任何更改。\n"NOR);
	destruct(this_object());
}
}