// obj:/u/b/bss/bug_record
#include <ansi.h>
inherit ITEM;
inherit F_SAVE;
mapping *records;
private void get_title(string txt,mapping record);
void get_record_text(mapping mail, string str);
void receive_mail(mapping record);
void create()
{
  set_name(HIC"bug回报机"NOR, ({"bug record","record"}));
  set ("long", "
"HIY"
(1)要回报bug的玩家,请用本机器所提供的(record)功能,切勿将bug post
   在board上,否则巫师将以公布bug的罪名与以严惩,轻者废武功,重者
   purge
(2)若发现在record中有不是回报bug的文章,也将以增加巫师工作负担的罪
   名与以严惩,轻者ckill十次,重者purge
(3)在房间中的公布栏主要是给巫师将已处理或未处理的bug公布给玩家知
   道的,若有玩家乱post或是把它当成与巫师或玩家的聊天版,或者跟bug
   完全没关系的文章,post的玩家也将与以严惩,轻者罚款,重者sleep
(4)回报的bug一经确定属实之后,将会对该回报玩家与以奖励,切勿狮子大开
   口,要些geq,meq这类的好防具,或者是大幅的提升自己能力的要求,虽然
   会以玩家所希望的为主,但是巫师还是会以玩家所回报的bug大小,决定
   到底要给啥好处
有别的以后再补.................
"NOR);

  set("light_up", 1);
  set("no_fight", 1);
  set("no_get", 1);
  set("no_sac", 1);
  set("no_put", 1);
  set("no_give", 1);
  set("no_steal", 1);
  set ("save_file", "/data/bug_record");
  setup();
}

string query_save_file() {
  return query ("save_file");
}
void init()
{
  add_action("do_record","record");
  add_action("do_check","check");
  add_action("do_study","dostudy");
  add_action("do_del","dodel");
  restore();
}
int do_record()
{
        object user=this_player();
        mapping record;

        record = ([
                "from": this_player()->name(1) + "(" + this_player()->query("id") + ")",
                "title": "无题",
                "time": time(),
                "have_other_use?": "",
                "self_have_use?": "",
                "text": ""
        ]);
        write("请输入bug主题(如xxxx的bug，直接按enter会放弃record):");
        input_to((: get_title :),record);
        return 1;
}
private void get_title(string txt,mapping record)
{
        printf("txt=%s\n",txt);
        if(!txt || txt=="")
        {
                printf("txt=%s\n",txt);
                write("你放弃了record!!\n");
                return ;
        }
        record["title"] = txt;
        write("回报内容:\n");
        this_player()->edit( (: get_record_text, record :) );
}
void get_record_text(mapping record, string str)
{
        record["text"] = str;
        write("就你所知中，有其他的人知道或使用过这个bug吗?(y/n)[n]:");
        input_to("confirm_copy", record);
}

void confirm_copy(string yn, mapping record)
{
        if( yn[0]=='y' || yn[0]=='Y' )
                record["have_other_use?"]="yes";
        else
                record["have_other_use?"]="no";
        write ("请问你自己有用过这个bug吗(y/n) ? [n]");
        input_to ("confirm_other", record);
}
void confirm_other(string yn, mapping record)
{
        if ( yn[0]=='y' || yn[0]=='Y' )
                record["self_have_use?"]="yes";
        else
                record["self_have_use?"]="no";
        write("多谢你回报bug,有发现其他的bug,欢迎随时再来回报!!\n");
        receive_mail(record);
}
void receive_mail(mapping record)
{
        if( !pointerp(records) ) records = ({ record });
        else records += ({ record });
        save();
}
int do_check()
{
  int i;

  object user=this_player();
  if(!wizardp(user)) return 0;

  if( !pointerp(records) || !sizeof(records) ) {
    write("目前回报版没有任何的文章。\n");
    return 1;
  }

  write ("回报版目前共有 " + sizeof(records) + " 篇文章：\n");
  write ("### 标题=========================================================\n");
  for(i=0; i<sizeof(records); i++) {
    printf("%3d %s\n\t回报人：%s, %s(%d 字)\n",
      i+1,
      records[i]["title"],
      records[i]["from"],
      ctime (records[i]["time"]),
      strlen (records[i]["text"])
    );
  }
    write("\n");
    return 1;
}
int do_study(string arg)
{
        int num;
  object user=this_player();
  if(!wizardp(user)) return 0;

        if( !arg || !sscanf(arg, "%d", num) )
                return notify_fail("你要读哪一篇文章？\n");

        if( !pointerp(records) || num < 1 || num > sizeof(records) )
                return notify_fail("没有这个编号的文章。\n");

        num --;

        printf("标题：%s\n回 报 人：%s\n",
                records[num]["title"], records[num]["from"]);
        printf("have_other_use?:%s\n",records[num]["have_other_use?"]);
        printf("self_have_use?:%s\n\n",records[num]["self_have_use?"]);
        printf("内容:\n%s\n",records[num]["text"]);
        return 1;
}
int do_del(string arg)
{
        int num;
  object user=this_player();
  if(!wizardp(user)) return 0;

        if( !arg || !sscanf(arg, "%d", num) )
                return notify_fail("你要删除那一篇文章？\n");

        if( !pointerp(records) || num > sizeof(records) )
                return notify_fail("没有这个编号的文章。\n");

        num --;

        records = records[0..num-1] + records[num+1..sizeof(records)-1];
        save();
        write("Ok.\n");

        return 1;
}
