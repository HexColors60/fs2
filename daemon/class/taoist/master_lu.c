#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string magic1();
string magic2();
string magic3();
string adv_taoist();
//冰雪风暴之谜 by nike
string love_sky();
string why_sigh();
string butter_fly();
string ice_spell();

string do_area();
string do_array();
string do_howgo();
string ask_tesin();
string ask_tesin2();
string ask_god();
string ask_blood_king();
string do_mission();
string do_area1();

void create()
{
        set_name("陆清风",({"master lu","master","lu"}));
        set("long", 
"天道紫玄观的掌门，两鬓斑白，一对长眉垂颊。看来岁数应该
不少了，但脸上却依然神采奕奕，到十足像个三四十岁的中年
人。据说他不但精通"HIG"易经"NOR"，"HIG"老庄"NOR"，而且还擅于"HIG"星象"NOR"卜卦一类。\n"
);
       
        set("gender","男性");
        set("class","taoist");
        set("nickname",MAG"紫玄老道"NOR);
        set("combat_exp",3000000);
        set("attitude","friendly");
        set("age",88);
        set("title","天道派掌门人");
        set("str",20);
        set("cps",30);
        set("cor",25);
        set("per",25);
        set("int",35);
        set("con",25);
        set("spi",25);
        set("kar",40);
        set("max_s_kee",100);
        set("s_kee",100);
        set("sec_kee","tiger");
        set("max_kee",10000);
        set("kee",10000);
        set("max_sen",10000);
        set("sen",10000);
        set("max_gin",10000);
        set("gin",10000);
        set("force",5000);
        set("inquiry",([
        "有情天" : (:love_sky:),
        "叹气" : (:why_sigh:),
        "小蝶" : (:butter_fly:),
        "冰封秘咒" : (:ice_spell:),
        "星象" : (:do_area:),
        "云龙阵" : (:do_array:),
        "锁妖塔" : (:do_howgo:),
        "失落天书" : "当年众妖大闹人间的时失落的，现也不知流落何方。",
        "易经" : "你去集书房找你筑依师姊要一本来研读吧。",
        "老庄" : "集书房里藏有几册翻本，可以去找你筑依师姊要来读读。",
        "血魔" : (:ask_blood_king:),
        "神圣侠" : (:ask_god:),
        "逍遥子" : "逍遥子在大战中耗力甚大..故听仙师说..大战后已遭血魔余孽围勦..但我想这么凭其身手...应该不会如此容易就被击败...",
        "天门奇阵" : "我曾听师父说过,天门奇阵是当今武林中最神奇的一个阵法,据说是利用
几把神兵及几个功力深厚的人所设的..不过..我也只听过...不曾有幸见到.",
        "龙铁心" : (:ask_tesin:),
        "一面之缘" : (:ask_tesin2:),
                "使命" : (:do_mission:),
        "昆仑仙境" : (:do_area1:),
                "大剑师" : "这是世人对拥有超强实力并可自行制作武器之人的称号...
据我所知..目前似乎只有-龙铁心-拥有此封号.",
        "进阶术士" : (:adv_taoist:),
          ]));
        set("chat_chance",3);
        set("chat_msg", ({
                "陆清风缓缓的唸道：「有情天外...无情人...郎心已许...苦蝶魂”\n",
        }));
        set("max_force",5000);
        set("max_mana",3000);
        set("mana",3000);
        set("atman",3000);
        set("max_atman",3000);
        set("mana_factor",60);
        set_skill("literate",40);
        set_skill("cure",90);
        set_skill("taoism",90);
        map_skill("cure","taoism");
        set_skill("force",60);
        set_skill("gforce",100);
        map_skill("force","gforce");
        set_skill("dodge",80);
        set_skill("g-steps",100);
        map_skill("dodge","g-steps");
        set_skill("magic",100);
        set_skill("gmagic", 100);
        map_skill("magic", "gmagic");
        set_skill("whip",105);
        set_skill("gwhip",100);
        map_skill("whip","gwhip");  
        set_skill("parry",70);
        map_skill("parry","gwhip");
        set_skill("spells",120);
        set_skill("necromancy",100);
        map_skill("spells","necromancy");
        set_skill("move",80);
        map_skill("move","g-steps");
        set("spells/feeblebolt/level",90);
        set("spells/missible/level",100);
        set("spells/hardshell/level",90);
        set("spells/invocation/level",100);
        set("spells/stopmove/level",1);
        set("spells/lightfire/level",1);
        set("spells/flee/level",60);
        set("spells/manabody/level",1);
        set("force_factor",10);
        set("guild_master",1);
        set("chat_chance_combat",200);
        set("chat_msg_combat",({
         (: magic1 :),
         (: magic2 :),
         (: magic3 :),
        }));
        setup();
        create_family("天道派",2,"掌门人");
        carry_object("/open/tendo/obj/red_dragon_chain")->wield();
        carry_object("/open/tendo/obj/lucloth")->wear();
        carry_object("/open/tendo/obj/luboot")->wear();
        add_money("gold",20);
}

int accept_object(object me, object obj)
{
        if( obj->query("name") == "失落天书" )
        {
          command("pat "+getuid(me));
          command("say 太好了, 是你从冥殿修罗的身上拿回来的吗？谢了。\n");
          if( me->query("family/family_name") == "天道派" )
          {
            command("say 既然你寻获天书有功, 我便将此天书上所记载的绝学传授与你吧。\n");
            write(me->query("name")+"照着陆清风所说的口诀随手演练一遍。\n\n"+
            "你觉得心中疑虑豁然贯通, 全身内力迅速流转一周天。\n\n"+
            "你学会了天书中所记载的绝学「天罡\战气”。\n\n");
            if( me->query("force") < me->query("max_force") )
            me->set("force",me->query("max_force"));
            me->set("marks/god-kee",1);
            me->set("title",HIY"天道"HIR"嫡传弟子"NOR);
          }
          destruct(obj);
        }
        else
          command("? "+getuid(me));
       if( obj->query("name") == HIR"焚天魔王的人头"NOR )
        {
          command("spank "+getuid(me));
          command("say 感谢少侠为武林除害。\n");
          if( me->query("family/family_name") == "天道派"&&(int)me->query("combat_exp")>=5000000 && !me->query("quest/tendo_hawk")&&me->query("quest/ask_tendo_hawk1")==1)
          {
            command("say 想我天道派与魔界征战数年，如今终于雨过天晴，得以太平。\n");
            command("say 就让为师送你去昆仑仙境拜见祖师爷吧。\n");
            me->move("/open/tendo/room/b1");
          }
          destruct(obj);
        }
        else
          command("? "+getuid(me));
              return 1;
}
string love_sky()
{
    object me = this_player();

        if(me->query("class")!="taoist")
                return "你不是本门弟子问这干什么？";
    if(me->query("combat_exp") < 5000000) return 0;
    if(!me->query_temp("icestorm/love_sky"))
    {
                command("sigh");
                me->set_temp("icestorm/lovestory",1);
                return "嗯...这...有情天...唉～～";
    }
}
string why_sigh()
{
        object me = this_player();
        
        if(me->query_temp("icestorm/lovestory")==1)
        {
                command("sob");
                command("say 这你有所不知啊...想当年小蝶情深义重...而我竟辜负了她...");
                me->set_temp("icestorm/lovestory",2);
                return "一切都是我对不起她啊...\n";
        }
}
string butter_fly()
{
        object me = this_player();
        
        if(me->query_temp("icestorm/lovestory")==2)
        {
                command("sigh");
                command("say 岁月催人老...没想到这段往事都已经过了六十多年了...");
                command("say 想当年小蝶和老夫从小青梅竹马，早已私定终生...");
                command("say 无奈家人的不赞成，令我们两人愤而决定一同出家，发誓十年之内决不婚娶...");
                command("say 于是我们约定好了十年后在长白山芙雪涯相见，一同还俗成亲...");
                command("say 但老夫却...却早已违背了誓言...偷偷的还俗与另一名女子完成婚约...");
                command("say 不知情的小蝶竟...竟痴痴的在芙雪涯等老夫...");
                command("say 等到老夫赫然想起之时，匆匆赶到芙雪涯却为时已晚...");
                command("say 小蝶竟为了等老夫而被她师父惩罚，给变成了一座雕像...");
                command("say 以老夫当时的修为，根本无法破解这残酷的「冰封秘咒”...");
                command("say 老夫从此便下定决心，一心向道，永不婚娶，并将芙雪涯改名为有情天...");
                command("say 虽然事隔多年，但直到今日，老夫还是没有勇气去面对小蝶...");
                command("sigh");
                me->set_temp("icestorm/lovestory",3);
                return "事情始末便是如此...";
        }
}
string ice_spell()
{
        object me = this_player();
        
        if(me->query_temp("icestorm/lovestory")==3)
        {
                command("say 这残酷的古术书早已消失在世界上...");
                return "但老夫当年赶到芙雪涯时，询问过一名猎狩，他说有见到一名老道姑上山而去，
却不知所谓何事，只知道其手上拿着一本破书";
        }
}
string do_mission()
{
  object who=this_player();
  if(who->query("class")!="taoist")
    return "你不是本门弟子问这干什么？";
  if(who->query("quest/ask_tendo_hawk")!=4)
    return "这不是妳该问的吧";
  who->set("quest/ask_tendo_hawk1",1);
  return HIY"当年魔王焚天祸害人间，先师便发誓要铲除焚天维护天下和平，如今\n            你取来焚天魔王的人头，为师便帮你解除‘异域空间’。"NOR;
}
string adv_taoist()
{
object me=this_player();
int i;
i=random(3);
                if(me->query("class")!="taoist")
                return "奇怪, 妳不是本派之人,问那么多干嘛...";
        if(me->query("adv_taoist"))
                return "你已经是了还问??";
        if(me->query("combat_exp") < 3000000 )
                return "你的经验还太浅薄了, 多加磨练后再来找我吧...";
        if(me->query("spells/feeblebolt/level")<100)
                return "你的苍冥之箭还不够强, 不够资格";
        if(me->query("spells/missible/level")<100)
                return "你的紫幽之箭还不够强, 不够资格";
                if(i==0){
                me->set("title",HIR"三道魂"HIW"˙"HIG"冥月"HIM"道使"NOR) ;
                                message("system",HIG"陆清风朗声说道:恭喜"HIY+this_player()->name()+HIM"成为"HIR"三道魂"HIW"˙"HIG"冥月"HIM"道使..\n"NOR,users());
                } 
                else if(i==1){
                me->set("title",HIR"三道魂"HIW"˙"HIR"焰日"HIM"道使"NOR) ;
                                message("system",HIG"陆清风朗声说道:恭喜"HIY+this_player()->name()+HIM"成为"HIR"三道魂"HIW"˙"HIR"焰日"HIM"道使..\n"NOR,users());
                }
                else{
                me->set("title",HIR"三道魂"HIW"˙"HIC"银星"HIM"道使"NOR) ;
                                message("system",HIG"陆清风朗声说道:恭喜"HIY+this_player()->name()+HIM"成为"HIR"三道魂"HIW"˙"HIC"银星"HIM"道使..\n"NOR,users());
                }
                me->set("adv_taoist",1);
        return "恭喜你,修为更上层楼并对于紫幽及苍冥之箭有更深的造诣!!";
}
void attempt_apprentice(object ob)
{
        object whip;
        if(this_player()->query("class")!="taoist")
        {
                command("say 你我志向不同，还是另寻名师吧。\n");
                return;
        }
        if(this_player()->query("kar") < 25)
        {
                command("say 你我有缘无份，还是另寻名师吧！\n");
                return;
        }
        command("hmm");
        command("recruit "+ob->query("id"));
        message("system",HIG"陆清风抚须笑道‘  乘天地之正，御六气之辩  ’

悠悠寰宇中，又多了一位仙风道骨的术士！！\n"NOR,users());
        
        command("say 本派首重修身养性，非不得已尽量不要与人交手。");
        write("\n");
        command("hmm");
        command("say 你可以先去找志清师叔买件修行用的道服。");
}
string do_area1()
{
  object who=this_player();
  if(who->query("class")!="taoist")  
     return "你不是本门弟子问这干什么？";
  return 
HIY"当年先师为了防止有人闯入昆仑仙境扰他清修，特别在入口之处布置\n            无上道法‘异域空间’，并吩咐若想前往昆仑仙境，必先完成天道派\n            宿世使命，方能获准进入仙境。"NOR;
}

string do_area()
{
  object who=this_player();
  if(who->query("class")!="taoist")
        return ("哎....星象之学浩瀚无穷，岂是三言两语就能说完的。");
  return (
"说到星象，这"HIW"云龙阵"CYN"就是为师当年以星象为据所排出的迷阵。"NOR"");
}

string ask_tesin()
{
if( this_player()->query("quests/shasword")==2)
{
return("大剑师龙铁心..我曾与他有一面之缘..但由于当时我年岁尚轻..因此无法向其请教!");

}
}
string ask_tesin2()
{
if( this_player()->query("quests/shasword")==3)
{
this_player()->set("quests/shasword",3);
return(" 我当时正经过魔域,正好龙铁心在铸剑.由于灵气逼人.我循气而行,因而有幸得见传说中的大剑师!");
 }
}
string ask_blood_king()
{
if (this_player()->query("quests/shasword")==2)
{
return ("百多年前.血魔扰乱武林..仙剑祖师消遥子带领当初极富盛名的刀神.儒侠三人出面勦魔.之后血魔就消声匿迹.但消遥子与神圣侠亦消失无踪了.");
}
}
string ask_god()
{
if (this_player()->query("quests/shasword")==2)
{
 this_player()->set("quests/shasword",4);
 return ("这神圣侠..据说是当初实力最强的三人了..");
}
}

string do_array()
{
  object who=this_player();
  if(who->query("class")!="taoist")  
    return ("你不是本门弟子问这干什么？");
    who->move("/open/center/room/inn");
  if(!who->query_temp("asked")) {
    who->set_temp("asked",1);
    return ("\n也好....你既然成为术士，也该知道这事。陆清风略有所思地说道,
在云龙阵旁有座"HIW"锁妖塔"CYN"。是当年魔界出口--魔眼洞崩毁众妖大闹人
间时，被祖师爷封印于那的。由于众妖危害甚巨，为师才特地布阵
于此加以保护，以防节外生枝坏了祖师爷五百年前的一番浴血苦战。"NOR"");
  }
  return (
"此阵杀恶不杀善，是专防妖魔侵入而设。
如杀气过高 阵中云龙会误以为妖魔来袭而攻击。

接着陆清风语带双关地说道 : 此阵更分为正逆两仪，由八卦衍
生而出，正行可到天道，逆行可致魔妖，切记切记。");
}

string do_howgo()
{
 object who=this_player();
  if(who->query("class")!="taoist")
        return (
"此事乃本门机密，"+RANK_D->query_respect(who)+"不必多问了。");
  return (
"这锁妖塔的妖怪厉害异常，就算是当年，祖师爷也费了九牛二虎之力才将其封住。
 其中有一只强力妖怪由镇塔明王守着!!");
}
int accept_fight (object who)
{
command("conj hardshell");
return 1;
}
int accept_kill(object who)
{
who=this_player();
kill_ob(who);
command("conj hardshell");
command("say 施主既执意如此,休怪贫道手下无情了!!");
return 1;
}

string magic1()
{
if(this_object()->query("kee")<=3000) {
          command("cast king invocation");
        }  
        return "\n";
}
string magic2()
{
if(random(2)<=1) 
command("cast missible");
else command("cast feeblebolt");
return "\n";
}
string magic3()
{
if(random(3)<=2)
command("cast stopmove");
return "\n";
}

void die()
{
        object cloth;
        int j;
        object winner = query_temp("last_damage_from");
        string name = winner->query("name");
        string class1 = winner->query("family/family_name");

        if(!winner)
        {
        ::die();
        return ;
        }

        new("/open/tendo/obj/lucloth")->move(winner);
        tell_object(users(),HIW"          
         陆清风"HIG"叹道:"HIC"天书"HIG"尚未找回,"HIR"冥殿修罗"HIG"未败,
                    哎,我竟会败给"+HIB+class1+HIG"弟子"+HIB+name+HIG+"之手,
                    我不干心阿!!\n\n
              "HBCYN"一道白光从昆仑山直升天际\n"NOR);

        if ( winner->query_temp("bless")==1 )
        {
        j=random(6000);
          if( j==7 || j==77 || j== 777 || j==1111 || j==55 || j==555 || j==1000 || j==4000 || j==3333 || j==5555 )
          {      
          new("/open/sky/obj3/light_feather")->move(environment(winner));
          message_vision(HIM"\n从陆清风的身上掉下了一件奇怪的东西!!\n"NOR,winner);
          write_file("/log/sky/light_feather",sprintf("%s(%s) 让陆清风掉下了光之明羽于 %s\n",
          winner->name(1),winner->query("id"),ctime(time())));
          }
        }else{
        j=random(12000);
          if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 ) 
          {      
          new("/open/sky/obj3/light_feather")->move(environment(winner));
          message_vision(HIM"\n从陆清风的身上掉下了一件奇怪的东西!!\n"NOR,winner);
          write_file("/log/sky/light_feather",sprintf("%s(%s) 让陆清风掉下了光之明羽于 %s\n",
          winner->name(1),winner->query("id"),ctime(time())));
          }
        }
::die();
}

