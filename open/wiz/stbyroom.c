// 网聚奖品替身发放房间!!!
#include <room.h>
#include <ansi.h>
inherit ROOM;
string *user_id_2 = ({
"aspire","zero","amy","pnx","palla","trust","luner","gendor","catbaby","aanswer",
"chritina","madoka","jojowolf","sula","flamer","nakama","lancelin","lunn","libraa",
"hikki","zard","snowcraft","dunga","bloodblade","julio","leon","ddt","victor","kaze",
"lovesui","fee","evilshadow","wasain","guilty","apple","sillyboy","nicklin","aro",
"windows","cyberfight","pzp","copy","ansys","shian","women","namie","chan"
}),*user_id_4 = ({"puffy","smirk","sdgudam","cyr","leing","chan"});
void create ()
{
set ("short",HIC"网聚奖品‘替身’发放处"NOR);
set ("long","这次网聚共有将近七十位玩家参加!!!!
网聚的奖品单请打help fs_net及help fs_net2
此房间是用来发放网聚替身的房间!!
西边的房间是发放属性、技能、内力的房间!!!
东边是发放魔龙型防具的房间
指令如下：
          get_standby  <领取这次网聚的奖品>

");
  set("no_kill",1);
  set("no_fight",1);
  set("light_up",1);
  set("exits", ([
  "north" : "/open/wiz/fsroom",
  "east"  : "/open/wiz/meqroom.c",
  "west" : "/open/wiz/skill_room",
]));
  setup();
}

void init()
{
add_action("in_standby","get_standby");
}
int in_standby()
{
object me = this_player();
string name=me->query("id");
int i,j,number=sizeof(user_id_2),four=sizeof(user_id_4);
if(!me->query("fs_net3/standby"))
 {
   if(name=="lancelin")
    {
     write("恭喜你得到了三个替身!!!\n");
     me->add("standby",3);
     me->set("fs_net3/standby",1);
     log_file("net/standby", sprintf("%s(%s) 领取网聚替身奖品!!替身三个!!时间是%s!!\n"
     ,me->query("name"),me->query("id"),ctime(time()) ));
     return 1;
    }else if(name=="yukigirl")
    {
     write("恭喜你得到了五个替身!!!\n");
     me->add("standby",5);
     me->set("fs_net3/standby",1);
     log_file("net/standby", sprintf("%s(%s) 领取网聚替身奖品!!替身五个!!时间是%s!!\n"
     ,me->query("name"),me->query("id"),ctime(time()) ));
     return 1;
    }else if(name=="hgf")
    {
     write("恭喜你得到了十三个替身!!!\n");
     me->add("standby",13);
     me->set("fs_net3/standby",1);
     log_file("net/standby", sprintf("%s(%s) 领取网聚替身奖品!!替身十三个!!时间是%s!!\n"
     ,me->query("name"),me->query("id"),ctime(time()) ));
     return 1;
    }
   for (j=0; j<number; j++)
    if(user_id_2[j] == name)
     {
     write("恭喜你得到了二个替身!!!\n");
     me->add("standby",2);
     me->set("fs_net3/standby",1);
     log_file("net/standby", sprintf("%s(%s) 领取网聚替身奖品!!替身二个!!时间是%s!!\n"
     ,me->query("name"),me->query("id"),ctime(time()) ));
     return 1;
     }
   for(j=0;j<four;j++)
    if(user_id_4[j]==name)
     {
     write("恭喜你得到了四个替身!!!\n");
     me->add("standby",4);
     me->set("fs_net3/standby",1);
     log_file("net/standby", sprintf("%s(%s) 领取网聚替身奖品!!替身四个!!时间是%s!!\n"
     ,me->query("name"),me->query("id"),ctime(time()) ));
     return 1;
     }
    write("sorry!!你并不在名单上!!!\n");
    return 1;
 }
    write("你以经领了!!!\n");
    return 1;
}
