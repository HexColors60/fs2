#include <room.h>

inherit ROOM;

void create ()
{
     set("short" ,"风雷帮帮派大厅");
     set("long", @LONG
这里是风雷帮的大厅，通常是帮派人员讨论的地方，同时这里也记录
着风雷帮帮众的点点滴滴。

LONG
     );
    
  set("light_up", 1);
  set("valid_startroom", 1);
  set("no_fight",1);

set("exits",([
"down":"/open/common/room/inn",
]));
     
     setup();

  call_other("/obj/board/clam_1", "?????");
}
void init()
{
add_action("list_array","list");
}
int list_array(string str)
{
int i,j=0;
int n;
object *glist;
glist=users();
n=sizeof(glist);
sort_array(glist,"list_skill",this_object());
message_vision("风雷帮能力排行榜\n",this_player());
message_vision("--------------\n",this_player());
 for(i=n-1;i>0;i--)
  {
    if(glist[i]->query("clam")=="风雷帮")
      {
        j++;
        message_vision("第"+chinese_number(j)+"名是"+    glist[i]->name()+"\n",this_player());
        
      }
   }
   
return 1;
}

int list_skill( object man1, object man2)
{
 int   i, j;
  
 i = man1->query("combat_exp",1);
 j = man2->query("combat_exp",1);
 if (i>j) return -1;
    else if (i<j) return 1;
     else return 0;
   }  
     
