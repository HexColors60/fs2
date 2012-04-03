#include <ansi.h>
#include "/open/open.h"
inherit NPC;
string answer_head()
 {
 int head;
 head=this_player()->query("snow-head",1);
return sprintf("你一共杀了%d个雪苍弟子。",head);
 }
int head=this_player()->query("snow-head",1);
void create()
{
        set_name("莫欢愁",({"older man","man"}));
        set("long","他是专门兑换雪苍人头的莫家总管。\n");
        set("gender","男性");
        set("title","莫家总管");
        set("combat_exp",100);
        set("attitude","friendly");
        set("age",60);
        set("str",40);
        set("cor", 24);
        set("cps", 18);
        set("per", 24);
        set("int", 42);
        set("force",40);
        set("inquiry",([
        "head":(: answer_head :)
        ]));
        set("list",([
        "雪莲丹": ([
                "local":"/open/gsword/obj/ff_pill",
                "head":2,
                "amount":500,
                "id":"force pill",
                ]),
        "灵芝仙丹": ([
                "local":"/open/gsword/obj/f_pill",
                "head":2,
                "amount":500,
                "id":"super pill",
                ]),
        "冰心露":([
                "local":"/daemon/class/doctor/medicine/curesick",
                "head":2,
                "amount": 500,
                "id":"ice heart pill",
                ]),
        "百花清心露":([
                "local":"/open/ping/obj/poison_pill",
                "head":2,
                "amount": 500,
                "id":"flower pill",
                ]),
        "日轮碎星破": ([
                "local":"/daemon/class/fighter/star",
                "head":30,
                "amount":30,
                "id":"destoryer",
                ]),
        "金刚指环": ([
                "local":"/open/snow/obj/figring",
                "head":35,
                "amount":35,
                "id":"figring",
                ]),
        "红宝石戒指":([
                "local":"/open/gsword/obj/ring-1",
                "head":20,
                "amount": 20,
                "id":"ruby_ring",
                ]),
        "冰雪神戒":([
                "local":"/open/ping/obj/ring-2",
                "head":20,
                "amount": 20,
                "id":"ice_ring",
                ]),
        "邪云神扇": ([
                "local":"/open/ping/obj/fan-1",
                "head":20,
                "amount":20,
                "id":"evil_fan",
                ]),
        "飘云扇": ([
                "local":"/open/ping/obj/cloud_fan",
                "head":35,
                "amount":35,
                "id":"cloud fan",
                ]),
        "厚背紫金刀":([
                "local":"/daemon/class/blademan/obj/gold-blade",
                "head":50,
                "amount": 50,
                "id":"gold blade",
                ]),
        "赏金":([
                "local":"/obj/money/gold",
                "head":1,
                "amount": 5000,
                "id":"gold",
                ]),
]));

        setup();
}

void init()
{
        add_action("do_list","list");
        add_action("do_want","want");
}
int do_list(object me)
{
        string *name;
        int i;
        me=this_player();
        name = keys(query("list"));
        tell_object(this_player(),"目前所能换到的奖品: \n\n");
        tell_object(this_player(),"  ｛ 奖品 ｝｛ 所须人头数 ｝\n\n");
        for(i=0;i<sizeof(name);i++)
tell_object(this_player(),sprintf("%10s%10d\n",name[i],query("list/"+name[i]+"/head")));
        return 1;
}

int do_want(string weapon)
{
        object ob;
        if(this_player()->query("snow-head")<5)
            {
        command("say 想要赏赐就多杀一点敌人呀！\n");
                return 1;
        }
        if(!query("list/"+weapon))
        {
                command("say 你想要什么赏赐？\n");
                return 1;
        }
        if(query("list/"+weapon+"/amount")<=0)
        {
                command("say 这样东西现在缺货。\n");
                return 1;
        }
if(this_player()->query("snow-head") < query("list/"+weapon+"/head"))
{
    command("say 等你人头够了再来换吧！\n");
      return 1;
  }
if(weapon=="雪莲丹"||weapon=="灵芝仙丹"||weapon=="冰心露")
{
        ob=new(query("list/"+weapon+"/local"));
        ob->add_amount(15);
        add("list/"+weapon+"/amount",-1);
this_player()->add("snow-head",-query("list/"+weapon+"/head"));
        ob->move(this_player());
        ob->set("no_drop",1);
        ob->set("no_give",1);
message_vision("$N拿给$n所要的"+ob->name()+"。\n",this_object(),this_player());
                return 1;
}
        ob=new(query("list/"+weapon+"/local"));
        ob->add_amount(1);
        add("list/"+weapon+"/amount",-1);
this_player()->add("snow-head",-query("list/"+weapon+"/head"));
        ob->move(this_player());
        ob->set("no_drop",1);
        ob->set("no_give",1);
message_vision("$N拿给$n所要的"+ob->name()+"。\n",this_object(),this_player());
                return 1;
}
