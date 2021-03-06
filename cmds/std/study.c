// study.c

#include <skill.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        object ob;
        mapping skill;
        int cost, intt, literate,repeat,i;
        string name;

        repeat=0;
        if( me->is_fighting() )
                return notify_fail("你无法在战斗中专心下来研读新知！\n");
        if(!arg)
                return notify_fail("你要读什么？\n");

        if(sscanf(arg,"%d %s",repeat,name)==2)
                arg=name;

        if(!repeat) repeat=1;

        if(!arg || !objectp(ob = present(arg, me)) )
                return notify_fail("你要读什么？\n");

        if( !mapp(skill = ob->query("skill")) )
          return notify_fail("这东西并不是武术秘籍, 你无法从它学到东西。\n");

        if( !(literate=me->query_skill("literate", 1)) )
                return notify_fail("你是个文盲，先学学读书识字(literate)吧。\n");

        if ( (int)me->query("combat_exp") < skill["exp_required"] )
          return notify_fail ("你的实战经验不足，再怎么读也没用。\n");

        if( !SKILL_D(skill["name"])->valid_learn(me) )
          return 0;
          //notify_fail("以你目前的能力，还没有办法学这个技能。\n");
// fix by Onion.
// skill 里的 valid_learn() 都有写 notify_fail(), 应以 skill 的叙述就好。
        if (ob->valid_learn(me)<0)
          return notify_fail ("据说你还不够格读此书哩!\n");

        cost = skill["difficulty"] - (intt=(int)me->query("int"));
        if (cost < 0) cost = 0;
        cost = -literate/10+skill["sen_cost"] + skill["sen_cost"]  * cost/20;
        if( cost < 0 ) cost = skill["sen_cost"];
        if(me->query("class")=="scholar")
                cost=cost*2/3;
        for(i=0;i<repeat;i++)
        {
        if( (int)me->query("sen") < cost ) {
                write("你现在过于疲倦，无法专心下来研读新知。\n");
                return 1;
        }

        if( me->query_skill(skill["name"], 1) > skill["max_skill"] )
          return notify_fail ("你发现上面所说的对你而言都太浅了。\n");

        me->receive_damage("sen", cost);

        if( !me->query_skill(skill["name"], 1) )
                me->set_skill(skill["name"], 1);
        else {
          // Modify By chun 95/10/27
          // 由literate的影响改为受int的影响
          // wade fix in 1/4/1996, 改为混合 literate 与 悟性 两者
          intt = intt/2;
          me->improve_skill(skill["name"], literate/10+random(intt)+5);
          if(me->query("class")=="scholar")
                me->improve_skill(skill["name"], literate/10+random(intt)+5);
        }

        message("vision", me->name() + "正专心地研读" + ob->name()
                + "。\n", environment(me), me);

        write("你研读有关" + to_chinese(skill["name"]) + "的技巧，似乎有点心得。\n");
        }
        return 1;
}

int help(object me)
{
   write( @HELP
指令格式 : study <物品名称>
指令说明 :
           这个指令使你可以从秘笈或其他物品自学某些技巧,
           但前提是: 你不能是个‘文盲’。
其他参考 :
           learn
HELP
   );
   return 1;
}
