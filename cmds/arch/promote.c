// promote.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object ob;
        string old_status, new_status, my_id;
        int my_level, ob_level, level;

        if( !arg || sscanf(arg, "%s %s", arg, new_status)!=2 )
                return notify_fail("指令格式：promote <使用者> <等级>\n");

        if( (level=SECURITY_D->query_valid_level(new_status))==-1 )
                return notify_fail("没有这种等级。\n");

        ob = find_player(arg);
        if (!ob) {
          if (!ob = FINGER_D->acquire_login_ob(arg))
            return notify_fail ("没有这个玩家。\n");
        }

        my_level = wiz_level(me);

        old_status = SECURITY_D->get_status(arg);
        ob_level = wiz_level(arg);

        my_id = me->query("id");
           if (my_id == arg)
                   return notify_fail("你不可以更改自己的等级。\n");
           if( (my_level <= ob_level && wizhood(me) != "(manager)" ) )
                   return notify_fail("你不能更动他的职位。\n");
// 加上一限制  By Swy
        if(my_level<SECURITY_D->query_valid_level(new_status))
        return notify_fail("你不能更动成比自己高的职位。\n");
        seteuid(getuid());

        if( !(SECURITY_D->set_status(me, arg, new_status)) )
                return notify_fail("修改失败。\n");

        CHANNEL_D->do_channel( me, "sys",
          sprintf ("将%s(%s)的权限从%s改为%s。\n",
            ob->query("name"), arg, old_status, new_status));
        tell_object (ob, sprintf ("%s(%s)将你的等级变成%s\n",
                     me->name(), my_id, new_status));
       ob->save_autoload();
        ob->save();

        if( interactive(ob) ) {
          CHANNEL_D->do_channel( me, "sys", ob->short()+"离开这个世界了。\n");
          tell_object (ob, @LONG
    由于巫师涉及档案存取权限问题，也牵涉到很多其他系统上的
未知情况太多，无法一一解决，暂时先以强迫你离开的方式解决，
请你 quit 之后再进来，再度进来时，你的等级已经改变了，如果
你是第一次当巫师，请你用 help wiz_init  查看你该做的事情。
LONG);
        }
        destruct (ob);

        return 1;
}
