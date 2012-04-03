 // open/killer/ninja/find/9block2.c
 //此为有创意的迷宫，有兴趣的巫师可以抄去用
 //利用一间房间作出好像有数十间房间大小的感觉
#include </open/open.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "九宫迷阵");
  set ("long", @LONG
  
    四周都是相似的环境，每一个地方都是似曾相似
    看来你只能相信你手中的罗盘指示了，
    反正没犯下错误，就不会退回最初点
    
LONG);
 
  set("exits", ([ /* sizeof() == 1   */
      "north" : __DIR__"9block2.c", 
      "east" : __DIR__"9block2.c", 
      "west" : __DIR__"9block2.c", 
      "south" : __DIR__"9block2.c", 
      "northeast" : __DIR__"9block2.c", 
      "northwest" : __DIR__"9block2.c", 
      "southeast" : __DIR__"9block2.c", 
      "southwest" : __DIR__"9block2.c", 
        ]));
  set("no_transmit",2);
  setup();
}

void init()
{
   object me=this_player();
   if (me->query_temp("wrongway"))
   {
     me->move(__DIR__"9block");
     me->delete_temp("9block");
     return ;
   } 
   if(!me->query_temp("9block"))    
   { //代表目前还指示第一步骤
     me->set_temp("9block",1);
     me->set_temp("blockstep",1);
   } 
   if(!me->query_temp("9block"))    
   { //代表目前还指示第一步骤
     me->set_temp("9block",1);
     me->set_temp("blockstep",1);
   }
}

int valid_leave(object me, string dir)
{
   int i;
   
   i=me->query_temp("9block");
   switch(i)
   {
   	case 1:
   	  if (dir != "east")
   	  	me->set_temp("wrongway",1);
   	  else
   	  {//方向正确的话，先增加步数，再判断是否超过了
   	     me->add_temp("blockstep",1);
         if ((me->query_temp("blockstep") <= 2))
   	     	break;
   	     else //代表不小于2，也就是3
   	     { //代表方向正确，且步数已满，必须先切换方向
   	       me->set_temp("9block",2);
               me->set_temp("blockstep",1);
                break;
             } //因为方向切换了，所以下一次方向就错误
          }
        break;
        case 2:
   	  if (dir != "north")
   	  	me->set_temp("wrongway",1);
   	  else
   	  {//方向正确的话，先增加步数，再判断是否超过了
   	     me->add_temp("blockstep",1);
   	     //判断是否走够步数
         if ((me->query_temp("blockstep") <= 3))
   	     	break;
   	     else //代表不小于3，也就是4(第三步)
   	     { //代表方向正确，且步数已满，必须先切换方向
   	       me->set_temp("9block",3);
               me->set_temp("blockstep",1);
                break;
             } //因为方向切换了，所以下一次方向就错误
          }
        break;
        case 3:
   	  if (dir != "west")
   	  	me->set_temp("wrongway",1);
   	  else
   	  {
   	     //代表方向正确，且步数已满，必须先切换方向
   	     me->set_temp("9block",4);
             me->set_temp("blockstep",1);      
          }
        break;
        case 4:
   	  if (dir != "south")
   	  	me->set_temp("wrongway",1);
   	  else
   	  {//方向正确的话，先增加步数，再判断是否超过了
   	     me->add_temp("blockstep",1);
   	     //判断是否走够步数
         if ((me->query_temp("blockstep") <= 4))
   	     	break;
   	     else //代表不小于3，也就是4(第三步)
   	     { //代表方向正确，且步数已满，必须先切换方向
   	       me->set_temp("9block",5);
               me->set_temp("blockstep",1);
                break;
             } //因为方向切换了，所以下一次方向就错误
          }
        break;
        case 5:
   	  if (dir != "southeast")
   	  	me->set_temp("wrongway",1);
   	  else
   	  {//方向正确的话，先增加步数，再判断是否超过了
   	     me->add_temp("blockstep",1);
   	     //判断是否走够步数
         if ((me->query_temp("blockstep") <= 2))
   	     	break;
   	     else //代表不小于3，也就是4(第三步)
   	     { //代表方向正确，且步数已满，必须先切换方向
   	       me->set_temp("9block",6);
               me->set_temp("blockstep",1);
                break;
             } //因为方向切换了，所以下一次方向就错误
          }
        break;
        case 6:
      if (dir != "northeast")
   	  	me->set_temp("wrongway",1);
   	  else
   	  {//方向正确的话，先增加步数，再判断是否超过了
   	     me->add_temp("blockstep",1);
   	     //判断是否走够步数
         if ((me->query_temp("blockstep") <= 3))
   	     	break;
   	     else //代表不小于3，也就是4(第三步)
   	     { //代表方向正确，且步数已满，必须先切换方向
   	     
   	       //到这里已经到达目标......
   	       me->set_temp("firstpart",11);
   message_vision(HIY"忽然一道光芒出现，让$N眼睛睁不开来\n
			，行囊中似乎多了一点东西\n"NOR, me);
   	       new("/open/killer/ninja/find/greenring.c")->move(me);
   	       me->move("/open/killer/mon/ghost/room/ghost12.c");
   	       return 0;
               break;
             } //因为方向切换了，所以下一次方向就错误
          }
        break;
   
   }   
   return 1;
}
