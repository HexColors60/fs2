// /adm/daemons/emoted.c
// ���������� es2 mudlib
// ��ӭ����������, �뱣������ͷ
// wade 1998/7/10

#pragma save_binary

#include <ansi.h>

inherit F_SAVE;

mapping emote;

//  emote mapping ���� emote ��������Ͽ⡣
//  ÿ�� emote �����õ�һЩ��������:
//
//  myself  - �� emote �����
//  target  - emote �Ķ���
//  others  - ���������������� emote �Ķ��������������
//
//  emote ��ʹ�� 'pattern' ��ȡ�����Ӧ�� emote ����
//  ������˵, �� "smile" ��ʹ�� daemon ��Ѱ emote mapping ��� "smile"
//  ���� "smile someone" ��ʹ�� daemon ��Ѱ emote mapping ��� "smile $"
//  ���� $ ��ζ��һ�� argument.
//
//  ��ʵ�ʵ� emote ѶϢ��, ���µı������������, �ó�������ѶϢ
//
//  $N    - emoter ������
//  $n    - emote ���������
//  $P    - emoter �ĳ�ν
//  $p    - emote ����ĳ�ν
//
//  Original by Annihilator@ESII (11/09/94)
//  fixed by wade (10/29/1995)
//  ������������Ĳ�����ʹ��

void create()
{
  seteuid(getuid());
  if( !restore() && !mapp(emote) )
    emote = ([]);
}

string query_save_file() { return DATA_DIR + "emoted"; }

// command_hook() of F_COMMAND call this as an alternate command processor.
int do_emote(object me, string verb, string arg, object *who,string channel)
{
  string str, my_gender, target_gender, msg_postfix, others, *e;
 // object target, *targets;  targets û�õ���
  object target;
  int   remote=0;

  if( !environment(me) ) return 0;

  if ( !mapp(emote) || undefinedp(emote[verb]) ) return 0;

  // Determine the pattern to be searched and the target.
  others = "";
  if ( stringp(arg) && arg != "" ) {
    if (sscanf (arg, "%s %s", arg, others) != 2) others = "";
    if (pointerp(who))
      target = find_living(arg);
    else
      target = present(arg, environment(me));
    if (!target && wizardp(me)) {
        remote = 1;
        target = find_player(arg);
    }
    if (!target || (target->query("env/����") && wiz_level(me) < wiz_level(target))) {
      others = arg+" "+others;
      msg_postfix = "";
    }
    else {
      target_gender = target->query("gender");
      if( target==me ) {
        msg_postfix = "_self";
        target = 0;
      } else msg_postfix = "_target";
    }
  } else msg_postfix = "";

  my_gender = me->query("gender");

  // �͸��Լ���
  if( stringp(str = emote[verb]["myself" + msg_postfix]) ) {
    str = replace_string(str, "$N", me->name());
    str = replace_string(str, "$P", gender_self(my_gender));
    str = replace_string(str, "$$", others);
    if( objectp(target) ) {
      str = replace_string(str, "$n", target->name());
      str = replace_string(str, "$p", gender_pronoun(target_gender));
    }
    if (remote) str = "*"+str;
    str=trans_color(str);
    if (pointerp(who))
      message("channel_emote",
        channel+str+NOR, me);
    else
      message("emote", HIY+str+NOR, me);
  }
  // �͸�����
  if( objectp(target) && stringp(str = emote[verb]["target"]) ) {
    str = replace_string(str, "$N", me->name()+"("+me->query("id")+")");
    str = replace_string(str, "$P", gender_pronoun(my_gender));
    str = replace_string(str, "$n", target->name());
    str = replace_string(str, "$p", gender_self(target_gender));
    str = replace_string(str, "$$", others);
    if (remote) str = "*"+str;
    str=trans_color(str);
    if (pointerp(who)) {
        message("channel_emote",
          channel+str+NOR, target );
    }
    else
      message("emote", HIY+str+NOR, target);
  }
  // �͸������˿�
  if( stringp(str = emote[verb]["others"+msg_postfix]) ) {
    str = replace_string(str, "$N", me->name()+"("+me->query("id")+")");
    str = replace_string(str, "$P", gender_pronoun(my_gender));
    str = replace_string(str, "$$", others);
    if( objectp(target) ) {
      str = replace_string(str, "$n", target->name());
      str = replace_string(str, "$p", gender_pronoun(target_gender));
    }
    if (remote) str = "*"+str;
    str=trans_color(str);
    if (pointerp(who)) {
        message("channel_emote", channel+str+NOR, who, ({me, target}));
    }
    else
      message("emote", HIY+str+NOR, environment(me), ({me, target}));
  }

// by ACKY
    if(target)
	if( arg && !userp(target) && userp(me) && verb != "nod" && random(100) < 50 ) {
		e = EMOTE_D->query_all_emote();
		EMOTE_D->do_emote( target, e[random(sizeof(e))], me->query("id") );
	}

  return 1;
}

int save_emotes()
{
  save();
  return 1;
}

int set_emote(string pattern, mapping def)
{
  emote[pattern] = def;
  save();
  return 1;
}

int delete_emote(string pattern)
{
  map_delete(emote, pattern);
  save();
  return 1;
}

mapping query_emote(string pattern)
{
  if( !undefinedp(emote[pattern]) ) return emote[pattern];
  else return ([]);
}

string *query_all_emote()
{
  return keys(emote);
}

mapping query_all_emotes()
{
  return emote;
}