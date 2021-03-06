//起死回生之术 by bss
#include <ansi.h>
inherit F_CLEAN_UP;
void move_obj(object corpse,object ppl);
void good_work(object me,object ppl,object corpse);
void bad_work(object ppl,object corpse,int stat);
void act(object me,object ppl,object corpse);

int main(object me, string arg)
{
    object ppl,corpse;
    string id,name;

    seteuid(getuid());
    if(me->query("class") != "doctor" && !wizardp(me))
      return 0;
    if(!wizardp(me)) return 0;
    if(me->query("doctor/save_die_time") > time())
      return notify_fail("在一天之中没有办法连救两个人!!\n");
    if(!arg) return notify_fail("你想要救活谁???\n");
    if(!corpse=present(arg,environment(me)))
      return notify_fail("没有你想要救的那个东西!!\n");
    if(me->query("force") < 2000)
      return notify_fail("你的内力不够!!!\n");
    if(me->is_fighting())
      return notify_fail("战斗中不能帮人复活!\n");
    id=corpse->query("victim_id");
    printf("id=%s\n",id);
    name=corpse->query("victim_name");
    if(!ppl=find_player(id)) //可能离线了，可能不是玩家
      return notify_fail(sprintf("%s(%s) 这个人已经没有救了!!!\n",name,id));
    if(ppl->query_temp("net_dead"))
      return notify_fail(sprintf("%s(%s) 这个人已经没有救了!!!\n",name,id));
    if(in_edit(ppl) || in_input(ppl))
        return notify_fail(sprintf("%s(%s) 这个人在救治的过程中受到阻碍!!!\n",name,id));
    if(corpse->query("no_save_die")) //尸体已经腐化了
      return notify_fail(sprintf("你没办法让尸体都腐化的人起死回生!!!\n",name,id));
    if(!ppl->query("ghost")) //已经出鬼门关了
      return notify_fail(sprintf("%s(%s) 这个人不用你救，已经出鬼门关了!!!\n",name,id));
    me->set("doctor/save_die_time",time()+86400);
    message_vision("
$N施展出银针门秘传绝技「圣手回春术”，将手搭在$n的头顶与气海，灌输自己的
真气，想要把$n从鬼门关救回来!!!\n",me,ppl);
    tell_object(ppl,"
你感到你的身体竟然开始散发着光芒，你觉得你好像快要复活了!!!\n");
    me->set_temp("save_die/limit",ppl->query("max_force")*8);
    me->set_temp("saving_die",1);
    me->set_temp("不准走",1);
    call_out("act",3,me,ppl,corpse);

    return 1;
}

void act(object me,object ppl,object corpse)
{
    int force_value;

    if(!me){//施救者离线，不存在，stat=1
      bad_work(ppl,corpse,1);
      return ;
    }
    if(!ppl){//被救者离线，不存在，stat=2
      bad_work(me,corpse,2);
      return ;
    }
    if(!corpse){//尸体不见了，stat=3
      bad_work(me,ppl,3);
      return;
    }
    if(!present(geteuid(me),environment(corpse))){//施救者离开了尸体，stat=4
      bad_work(me,ppl,4);
      return ;
    }
    if(!ppl->query("ghost")){ //已经出鬼门关了，stat=5
      bad_work(me,ppl,5);
      return ;
    }
    force_value=me->query("env/use_force");
    if(!force_value) force_value=1000;
    if(force_value < 1000) force_value=1000;
    me->add("force",-force_value);
    if(me->query("force")<1){//施救者的内力不够，stat=6
      bad_work(me,ppl,6);
      return ;
    }
    message_vision("$N将自身的内力不停的灌到$n的体内，试着接回$n体内已经断了的经脉!!\n",me,ppl);
    me->add_temp("save_die/point",force_value);
    if(me->query_temp("save_die/point") >= me->query_temp("save_die/limit")){
      good_work(me,ppl,corpse);
      return ;
    }
    call_out("act",3,me,ppl,corpse);
    return;
}
void bad_work(object ppl,object corpse,int stat)
{

    switch(stat){
      case 1:
        if(ppl){
          tell_object(ppl,"你身上的光芒渐渐的消失，看来你的复活失败了!!\n");
        }
        break;
      case 2:
        if(ppl){
          tell_object(ppl,"你想要救的人忽然吐出一大口鲜血，看来是救不活了!!!\n");
          ppl->delete_temp("save_die");
          ppl->delete_temp("saving_die");
          ppl->delete_temp("不准走");
        }
        break;
      case 3:
        tell_object(ppl,"你发现你想要救的人不见了???看来尸体被偷走了!!\n");
        tell_object(corpse,"你身上的光芒渐渐的消失，看来你的复活失败了!!\n");
        ppl->delete_temp("save_die");
        ppl->delete_temp("saving_die");
        ppl->delete_temp("不准走");
        break;
      case 4:
        tell_object(ppl,"你离开了你要救的人，看来他是不能活的了!!\n");
        tell_object(corpse,"你身上的光芒渐渐的消失，看来你的复活失败了!!\n");
        ppl->delete_temp("save_die");
        ppl->delete_temp("saving_die");
        ppl->delete_temp("不准走");
        break;
      case 5:
        tell_object(ppl,"你想要救的人忽然吐出一大口鲜血，看来是救不活了!!!\n");
        ppl->delete_temp("save_die");
        ppl->delete_temp("saving_die");
        ppl->delete_temp("不准走");
        break;
      case 6:
        message_vision("
$N因为顾着救人，耗光了身上所有的内力!!!
$N看起来摇摇欲坠，已经支持不下去了!!!\n",ppl);
        tell_object(corpse,"你身上的光芒渐渐的消失，看来你的复活失败了!!\n");
        ppl->delete_temp("save_die");
        ppl->delete_temp("saving_die");
        ppl->delete_temp("不准走");
        ppl->unconcious();
        break;
    }
    return ;
}

void good_work(object me,object ppl,object corpse)
{
    int exp = (int)ppl->query("combat_exp")/25;
    if(exp > 50000) exp = 50000;

    tell_object(ppl,"
你突然觉得一股强大的吸力出现在你身后，强大的吸力使你不由自主的向后飘飞!!!\n");
    ppl->remove_call_out("revive");
    ppl->relive();
    ppl->move(environment(me));
    ppl->reincarnate();
    move_obj(corpse,ppl);
    destruct(corpse);
    me->delete_temp("save_die");
    me->delete_temp("saving_die");
    me->delete_temp("不准走");
    me->add("combat_exp",exp);
    message_vision("$N终于把$n给救活了，不过也累出了满身大汗!!\n",me,ppl);
    log_file("SAVE_DIE",sprintf("(%s)把%s(%s)给救活了在 %s\n",
    me->query("id"),ppl->query("name"),ppl->query("id"),ctime(time())));
    message_vision("$N因此获得了"+exp+"点的经验值！",me);
    return ;
}

void move_obj(object corpse,object ppl)
{
    object *inv;
    int i;

    if(!corpse || !ppl) return ;
    inv=all_inventory(corpse);
    for(i=0;i<sizeof(inv);i++)
      inv[i]->move(ppl);

    return ;
}
