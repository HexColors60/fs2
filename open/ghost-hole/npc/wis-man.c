#include <ansi.h>
inherit NPC;
string ask_use();
string ask_water();
void create ()
{
        set_name("老人",({"old man","man","old"}) );
        set("gender","男性");
        set("title",YEL"幽冥界"NOR);
        set("nickname",HIW"智慧之长"NOR);
        set("age",74);
        set("long","他从小身长在幽冥界内, 对于幽冥界的所有事情都十分了解, 如果对幽冥界有任何的疑问
, 都可以向他请教...\n");
        set("inquiry",([
        "幽冥界":"幽冥界大部分的事情都围绕在死灵骨魔与其两大驻守冥王",
        "死灵骨魔":"他是掌管着幽冥界的魔神, 对于他的行为, 我们幽冥界的魔物们早就
对他十分的不满了!!",
        "不满":"就算是魔物, 也希望有像人间一样好的待遇啊, 魔物们也是一种生物啊!!", 
        "行为":"除了残暴不仁之外, 我不知道该怎么形容他了..",
        "残暴不仁":"...我不想多做解释,你不会比一条猪还笨吧...",
        "待遇":"...我不想多做解释,你不会比一条猪还笨吧...",
        "生死蝶":"他是死灵骨魔最喜害的宠物, 听说在前几年不见了,不过...我知道他在
【死】冥王的手上!!",
        "死冥王":"她跟【生】冥王共同掌管冥界的【生】【死】大权!!",
        "冥王":"在两年前被死灵骨魔打败, 后归属于死灵骨魔的两大冥王, 现在为死灵骨魔
的左右手, 分别名为生冥王与死冥王!",
        "生冥王":"他跟【死】冥王共同掌管冥界的【生】【死】大权!!",
        "生命之水":(: ask_water :),
        "死蝶":"生死蝶死后, 就是了死蝶, 你可以拿生命之水让他复活",
        "使用":(: ask_use :),
        "use":(: ask_use :),
        ]));
        set("chat_chance",1);
        set("chat_msg",({
        "老人神情泰然的到处闲晃着, 仿佛在思考着所有幽冥界的事务...\n",
        "老人突然叹了一口气...\n",
        "老人神情古怪的说着一些你听不懂得话, 似乎十分严肃!!\n",
        "老人露出安详的微笑, 显得十分的轻松...\n",
        "老人激动的说着: 对于幽冥界有什么不懂得就来问我吧, 我早就想帮助人们
对付死灵骨魔了!!\n",
        "老人自言自语像是在提示着什么:生死蝶会带引你们找到通往死灵骨魔的所在
地的, 但是...!!\n",
        }));
        setup();
}
string ask_water()
{
object me=this_player();
object mob=this_object();
if(me->query_temp("ghost-hole/wis-man/know-living-water"))
return "我已经将生命之水给你了啊!!\n";
me->set_temp("ghost-hole/wis-man/do_ask_water",1);
return HIY"你有生命之水吗??那是用来让死蝶复活的必要物!!你知道如何使用(use)吗??"NOR;
}


string ask_use()
{
object me;
me=this_player();
if(!me->query_temp("ghost-hole/wis-man/do_ask_water"))
return "你在问什么啊??我听不懂....\n";
return "你先把生命之水给我看看!!\n";
}

int accept_object(object me,object ob)
{
object ob2;
me=this_player();
ob2=new("/data/autoload/mogi/sspill");
if(ob->query("id")!="living-water")
{
message_vision(HIY"老人以十分不屑的眼光看着$N给的"+ob->query("name")+", 接着举起右手, 招幻一个黑洞
, 把"+ob->query("name")+"给吸了进去!!\n"NOR,me);
return 1;
}
if(!me->query_temp("ghost-hole/wis-man/do_ask_water"))
{
message_vision(HIY"老人以十分不屑的眼光看着$N给的"+ob->query("name")+",
老人缓缓说道: 你拿这种东西给我做什么??
接着招唤一个黑洞, 把"+ob->query("name")+"给吸了进去!!\n"NOR,me);
return 1;
}
if(me->query_temp("ghost-hole/wis-man/know-living-water"))
{
message_vision(HIY"老人高兴的笑着:没想到$N会给我如此贵重的东西, 真是太感激$N了!!\n"NOR,me);
message_vision(HIY"老人随即转过身去, 从其背后的箱子里面拿出了一些药丸\n"NOR,me);
message_vision(HIR"老人给了$N一些红色药丸!!\n"NOR,me);
message_vision(HIY"老神笑着说:这些药丸很好用的, 就当作是你给我生命之水的谢礼吧!!\n"NOR,me);
ob2->set_amount(5);
ob2->move(me);
return 1;
}
message_vision(HIY"老人心满意足的笑着:原来生命之水是长的如此模样啊!!
		哈哈!!谢谢你了!!来..生命之水还给你, 
		你必需把这滴生命之水覆\盖\(cover butterfly)在死蝶身上, 这样死蝶
		就会复活了!!\n"NOR,me);
message_vision(HIW"老人把生命之水还给了$N \n"NOR,me);
me->set_temp("ghost-hole/wis-man/know-living-water",1);
ob->move(me);
return 1;
}
