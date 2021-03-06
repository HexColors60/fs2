#include <ansi.h>
inherit SSERVER;

int update_condition(object me, int duration)
{
        int now_level,i;
        object *enemy;

        if(duration==0)
        {
          return 1;
        }
        me->apply_condition("level_up",1);
        if(!now_level=me->query_temp("level/now_level"))
          me->clear_condition("level_up");
  if(!me->query_temp("leveluping"))
  switch(now_level){
    case 1:
      if(!me->query_temp("leveluping"))
      message_vision(HIY"金色的斗气不断的在$N身边翻滚着!!\n"NOR,me);
      me->delete_busy();
      me->clear_condition("mogi");
      me->clear_condition();
      me->apply_condition("level_up",1);
      break;
    case 2:
      if(!me->query_temp("leveluping"))
      message_vision(HIC"蓝色的斗气不断的在$N身边翻滚着!!\n"NOR,me);
      me->delete_busy();
      me->clear_condition("mogi");
      me->clear_condition();
      me->apply_condition("level_up",1);
      break;
    case 3:
      if(!me->query_temp("leveluping"))
      message_vision(HIM"紫色的斗气不断的在$N身边翻滚着!!\n"NOR,me);
      me->delete_busy();
      me->clear_condition("mogi");
      me->clear_condition();
      me->apply_condition("level_up",1);
      break;
    case 4:
      if(!me->query_temp("leveluping"))
      message_vision(HBRED+HIW"红色和白色的斗气不断的在$N身边翻滚着!!\n"NOR,me);
      me->delete_busy();
      me->clear_condition("mogi");
      me->clear_condition();
      me->apply_condition("level_up",1);
      break;
    case 5:
      if(!me->query_temp("leveluping"))
      message_vision(HBRED+HIY"红色和金色的斗气不断的在$N身边翻滚着!!\n"NOR,me);
      me->delete_busy();
      me->clear_condition("mogi");
      me->clear_condition();
      me->apply_condition("level_up",1);
      break;
    case 6:
      if(!me->query_temp("leveluping"))
      message_vision(HBRED+HIC"红色和蓝色的斗气不断的在$N身边翻滚着!!\n"NOR,me);
      me->delete_busy();
      me->clear_condition("mogi");
      me->clear_condition();
      me->apply_condition("level_up",1);
      break;
    case 7:
      if(!me->query_temp("leveluping"))
      message_vision(HBRED+HIM"红色和紫色的斗气不断的在$N身边翻滚着!!\n"NOR,me);
      me->delete_busy();
      me->clear_condition("mogi");
      me->clear_condition();
      me->apply_condition("level_up",1);
      break;
    case 8:
      if(!me->query_temp("leveluping"))
      message_vision(HBCYN+HIW"蓝色和白色的斗气不断的在$N身边翻滚着!!\n"NOR,me);
      me->delete_busy();
      me->clear_condition("mogi");
      me->clear_condition();
      me->apply_condition("level_up",1);
      break;
    case 9:
      if(!me->query_temp("leveluping"))
      message_vision(HBCYN+HIY"蓝色和金色的斗气不断的在$N身边翻滚着!!\n"NOR,me);
      me->delete_busy();
      me->clear_condition("mogi");
      me->clear_condition();
      me->apply_condition("level_up",1);
      break;
    case 10:
      if(!me->query_temp("leveluping"))
      message_vision(HBCYN+HIM"蓝色和紫色的斗气不断的在$N身边翻滚着!!\n"NOR,me);
      me->delete_busy();
      me->clear_condition("mogi");
      me->clear_condition();
      me->apply_condition("level_up",1);
      break;
    default:
      return 1;
  }
  if(me->is_fighting()){
    enemy=me->query_enemy();
    for(i=0;i<sizeof(enemy);i++){
      if(enemy[i])
        if(500 > random(1000))
          enemy[i]->start_busy(1);
        else
          enemy[i]->start_busy(now_level);
    }
    message_vision(BLINK+HIY"$N身边的敌人受到$N身旁斗气的影响，行动受到了牵制!!\n"NOR,me);
  }
        return 1;
}
