// 段家 门人 made by onion
#include <ansi.h>
#include </open/open.h>
inherit NPC;
void create()
{
	set_name("凌落风",({"ling"}));
	set("long","凌落风是段云的第五个弟子, 脸无四两肉, 一副又懒又累的样子"+
	", 但他那一双眸子, 却显的炯炯有神、锐查秋毫。\n");
	set("gender","男性");
	set("class","scholar");
	set("combat_exp", 30000);
	set("attitude","heroism");
	set("age",40);
	set("inquiry", ([
	"thief" : "我们来京城并不是为这件事的, 抱歉了。",
	]));
	set("force",300);
	set("max_force",300);
	set("force_factor", 1);
	set_skill("force",40);
	set_skill("unarmed",50);
	set_skill("sunforce",40);
	set_skill("dodge",60);
	set_skill("linpo-steps",60);
	set_skill("six-fingers",66);
	map_skill("force","sunforce");
	map_skill("dodge","linpo-steps");
	map_skill("move","linpo-steps");
	map_skill("unarmed","six-fingers");
	setup();
	add_money("silver",1);
	create_family("段家",11,"弟子");
}

void die()                                                                 
{    
	object winner = query_temp("last_damage_from");
	int j;

        if(!winner)
	{
	::die();
	return ;
        }

	if ( winner->query_temp("bless")==1 )
	{
	j=random(6000);
	  if( j==7 || j==77 || j== 777 || j==1111 || j==55 || j==555 || j==1000 || j==4000 || j==3333 || j==5555 )
	  {      
	  new("/open/sky/obj8/winter_wind")->move(environment(winner));
	  message_vision(HIM"\n从凌落风的身上掉下了一件奇怪的东西!!\n"NOR,winner);
          write_file("/log/sky/winter_wind",sprintf("%s(%s) 让凌落风掉下了冬极风于 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}else{
	j=random(12000);
	  if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 ) 
	  {      
	  new("/open/sky/obj8/winter_wind")->move(environment(winner));
	  message_vision(HIM"\n从凌落风的身上掉下了一件奇怪的东西!!\n"NOR,winner);
          write_file("/log/sky/winter_wind",sprintf("%s(%s) 让凌落风掉下了冬极风于 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}
	::die();                                                           
}


