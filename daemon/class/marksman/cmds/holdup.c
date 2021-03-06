// holdup.c
// By LinaSi-Inverse-( 1999 )
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object obj, ob;
        string Narrows, Nbow;

        me = this_player();

        if( !arg ) return notify_fail("[用法]: holdup <弓箭> with <弓>\n");
        if(sscanf(arg, "%s with %s",Narrows,Nbow) !=2 )
        return notify_fail("[用法]: holdup <弓箭> with <弓>\n");
        if( !obj = present(Narrows, me) )
        return notify_fail("你身上没有这种弓箭 ...。\n");
        if( me->query("family/family_name") != "射日派")
        return notify_fail("你不是射日派的人。\n");

        if( !ob = present(Nbow, me) )
        return notify_fail("你身上没有这把弓 ...。\n");
        if( obj->query("type")!="is_arrows")
        return notify_fail("看清楚点..那不是箭！\n");
        if( ob->query("skill_type") != "archery")
        return notify_fail("看清楚点..那不是弓！\n");

        if( obj->query("class") && obj->query("class") != me->query("class") )
        return notify_fail("这是属于"+to_chinese(obj->query("class"))+"职业专用的箭！！\n");
        if( obj->query("no_class") && me->query("class")
        &&  obj->query("no_class") == me->query("class") )
        return notify_fail("你的职业不能使用这类的箭！！\n");

        if( ob->query("arrow/id") != "none"
         && ob->query("arrow/name") != obj->query("name") )
        return notify_fail("弓上已经有其他种弓箭了。\n");

        message_vision("$N迅速地将"+obj->query("name")+"搭在"+ob->query("name")+"上。\n",me);

        if( ob->query("arrow/id")=="none" ) {
        ob->set("bow/attack",ob->query("weapon_prop/damage"));
        ob->set("weapon_prop/damage",
        obj->query("weapon_prop/damage")+ob->query("weapon_prop/damage"));
        }

        ob->set("arrow/id",obj->query("id"));
        ob->set("arrow/path",base_name(obj));
        ob->set("arrow/amount",obj->query_amount()+ob->query("arrow/amount"));
        ob->set("arrow/name",obj->query("name"));

        if( me->query_temp("weapon") == ob )
        me->set_temp("apply/damage",ob->query("weapon_prop/damage"));

        destruct(obj);
        return 1;
}
int help(object me)
{
  write(@HELP
[指令格式]：holdup <id>

[相关指令]：unhold, bcheck
HELP
    );
    return 1;
}

