// by Avgirl 05/20/00
#include <ansi.h>
inherit F_CLEAN_UP;
int help(object me);
int ally(object me,string clan);
int cally(object me,string clan);
int remove_accept(object me,object target);
int main(object me, string arg)
{
string clan;
if(this_player()->query("clan/rank")>3)
                return notify_fail("你无权使用这个指令!!\n");
        if(!arg)
                return help(this_player());
        if(sscanf(arg,"-cancel %s",clan))
                return cally(this_player(),clan);
        if(sscanf(arg,"%s",clan))
                return ally(this_player(),clan);

        return 1;

}
int ally(object me,string clan)
{
string ally_s;
        string *ally,*allyy;
        object target;
object obj;
        int i;

        if(me->is_fighting() || me->is_ghost())
                return notify_fail("很抱歉,你现在的情况不能使用这个指令。\n");
        if( !CLAN_D->have_clan( clan ) )
                return notify_fail("无此帮派。\n");
// 判断有没有同盟...

        ally=CLAN_D->clan_query(me->query("clan/id"),"ally");
        for(i=0;i<sizeof(ally);i++){
                if(ally[i]==clan)
                                return notify_fail("你已经跟他同盟了呀!!\n");
        }
        if( !target = find_player(CLAN_D->clan_query(clan, "master")))
                return notify_fail("对方的帮主不在,你无法对他提出要求。\n");

        if(me->query_temp("ally/invite"))
                return notify_fail("你已经邀请了,等对方回应中。\n");
        else {
if(!me->query_temp("ally/accept")) {
// 开始邀请....
        this_player()->set_temp("ally/invite",clan);
        target->set_temp("ally/accept",me->query("clan/id"));

        tell_object(target,GRN""+CLAN_D->clan_query(me->query("clan/id"),"name")+"想要跟你结为盟帮。\n"+
        "如果同意的话请打 cally "+ target->query_temp("ally/accept")+"。\n"NOR);

        call_out("remove_accept",30,target,this_player());
        return 1;
        }
}
if(me->query_temp("ally/accept")!=clan)
                return notify_fail("有人正在邀请你同盟,如不同意请稍等。
\n");
        else {
remove_call_out("remove_accept");
target->delete("ally");
me->delete("ally");
// 答应了....

// 开始设定..~~~~
        ally=CLAN_D->clan_query(me->query("clan/id"),"ally");
if(!ally) ally=({});
        if( pointerp(ally)) {
                ally += ({ clan });}
CLAN_D->clan_set(me->query("clan/id"),"ally",ally);

ally=({});
        ally=CLAN_D->clan_query(clan,"ally");
 if(!ally) ally=({});
ally_s=me->query("clan/id");
        if( pointerp(ally)) {
 ally += ({ ally_s });}
CLAN_D->clan_set(clan,"ally",ally);
// 结束设定~~~
shout(
                HIY""+me->query("clan/name")+" 决定和 "
        +CLAN_D->clan_query(clan,"name")+" 同盟了,希望能创造更强盛的帮派!!!\n"NOR);
        return 1;
        }
}
int remove_accept(object target,object me)
{
target->map_delete("ally");

me->map_delete("ally");

        tell_object(target,HIR""+me->query("clan/name")+"已经放弃同盟了。\n"NOR);
        write(HIR""+target->query("clan/name") + "没有回应,您放弃同盟了。\n");
        return 1;
}

int cally(object me,string clan)
{
        string *ally,*allyy;
int tag;
        int i;

        if(me->is_fighting() || me->is_ghost())
                return notify_fail("很抱歉,你现在的情况不能使用这个指令。\n");
        if( !CLAN_D->have_clan( clan ) )
                return notify_fail("无此帮派。\n");
// 这边开使是删掉本身的ally....
        ally=CLAN_D->clan_query(me->query("clan/id"),"ally");
        for(i=0;i<sizeof(ally);i++){
if(ally[i]==clan) tag=1;
        }
if (!tag) return notify_fail("你们并没有跟这一帮同盟!!\n");
        if( pointerp(ally)) {
                ally -= ({ clan });}
        CLAN_D->clan_set(me->query("clan/id"),"ally",ally);


// 删掉对方的...
        ally=CLAN_D->clan_query(clan,"ally");
        if( pointerp(ally)) {
                  ally -= ({ me->query("clan/name") });}
CLAN_D->clan_set(clan,"ally",ally);

shout(
                HIY"从这一刻开始, "+me->query("clan/name")+" 决定取消和 "
        +CLAN_D->clan_query(clan,"name")+" 的同盟了!!!\n"NOR);

        return 1;
}


int help( object me )
{
        write("
        c_ally <帮派英文名称>：跟某帮同盟。
        c_ally -cancel <帮派英文名称>：跟某帮取消同盟。

                                        by avgirl 2000/05/20
");
        return 1;

}
