// made by ccat
// ����...���� group move...     ccat....9_12.96
// ���� chun ����,�ĳ�ֻ���� officer �����ı��� follow ��player.
//                                               ccat....9_15,96
// ��ǿһЩ�߼��ϵ��ж�, �������̫��� error ����дһ����ʽ
//                                              Arthur (10/9/1998)

#include <ansi.h>

inherit ITEM;
inherit F_GUILDCMDS;

void create()
{
        set_name("������", ({ "cloud fan","fan" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",@LONG
����һ�������л����Ƶ�����,ר���ṩ����Ǯ��ʹ��, ֻҪ��Ǯׯ��
�,��Ϳ�����������ڱ���½.(����: ����һ�� 500 coin,ֱ�Ӵ�Ǯׯ��.)

      ʹ�ø�ʽ: waveto <number>    ex: waveto 1,waveto 2
      �ֽ��ṩ�ĸ�����: 1. ��������   2. ��������   3. ƽ������
                        4. ������վ   5. ���ƴ�     6. ������Ϸ�����
                        7. <NONE>     8. <NONE>     9. <NONE>
                       10. ���ָ�

      �趨��ʽ: fanset <number>   ex: set 7,set 8 (ֻ�� 7,8,9)
      ���Զ���������λ�ô�����,��Ϊ�µĴ��͵�.

      ��ѯ��ʽ: fanshow           ex: fanshow
      ���Բ�ѯ��Ĵ��͵�����.

      Ⱥ���ƶ�: gmove <on|off>  ex: gmove on,gmove off
      Ⱥ�崫��ģʽ�����,��Ⱥ�崫��ģʽ ��,�� waveto �������������ı�
          ........<gmove�޹�Ա�����͸����ɵĸ߲�ʹ��>............
LONG
               );
                set("value", 1000);
        }
}

void init()
{
        if( environment() == this_player() ){
                add_action("do_fanset", "fanset");
                add_action("do_fanshow", "fanshow");
                add_action("do_waveto", "waveto");
                add_action("do_gmove", "gmove");
        }
}

int do_gmove(string arg)
{
        object me = this_player();
        int value=0; //������ɵĸ߽׼�����ʹ��rank
        if(me->query("clan"))
          if(me->query("clan/rank") < 4)
            value=1;
        if( me->query("class") == "officer"
          ||me->query("class") == "blademan"||value)
        {
                switch(arg)
                {
                        case "on":
                                me->set_temp("gmove",1);
                                write("Ⱥ���ƶ�ģʽ ����(on)!!!\n");
                                return 1;
                        case "off":
                                me->delete_temp("gmove");
                                write("Ⱥ���ƶ�ģʽ �ر�(off)!!!\n");
                                return 1;
                        default:
                                return notify_fail("Ⱥ���ƶ�: gmove <on|off>\n");
                }
        }
        return notify_fail("�������� ��Ա(officer)�͵���(blademan)���ɸ߲�(rank 3����)ʹ��.\n");
}

int do_fanset(string arg)
{
        object where, me = this_player();

        if(!me->query_temp("can_fanset")) return 0;
        if( (where = environment(me))->query("no_transmit") )
                return notify_fail("һ��ǿ��Ĵų��ӵص״���,����������趨,\n�ƺ�����Ĵ���Ը�˵ؿ��Դ���...\n");

        switch( arg ) {
                case "7" :
                case "8" :
                case "9" :
                        me->set_temp( "fan/" + arg, file_name(where) );
                        me->set_temp( "fan_s/" + arg, where->query("short") );
                        write("���趨����Ϊ����´��͵�.\n");
                        return 1;
                default :
                        return notify_fail("��ֻ���趨 7��8��9 ��\n");
        }
}

int do_fanshow(string arg)
{
        object me = this_player();

        write(  "���͵� 7 ��" + me->query_temp( "fan_s/7" ) +
              "\n���͵� 8 ��" + me->query_temp( "fan_s/8" ) +
              "\n���͵� 9 ��" + me->query_temp( "fan_s/9" ) + "\n" );
        return 1;
}

int do_waveto(string arg)
{
        string room="";
        object *count, me = this_player();
        int i;

        if( me->query_temp("unconcious") )
                return 0;
        if( me->is_fighting() )
                return notify_fail("ս�����޷�ʹ�û����ȡ�\n");
	if( CLAN_D->what_clan_area(me) != "NULL" )
		return notify_fail( "�޷��ڰ���������ʹ�á�\n" );
        if( me->query_temp("��׼��"))
                return notify_fail("ͻȻһ�������ӵص׷���,��ɢ�����������ƶ�,\n�ƺ�����Ĵ���Ը�˵ؿ��Դ���...\n");
        if( me->query_temp("������") )
                return notify_fail("�������޷�ʹ�û����ȡ�\n");
        if( environment(me)->query("no_transmit") )
                return notify_fail("ͻȻһ�������ӵص׷���,��ɢ�����������ƶ�,\n�ƺ�����Ĵ���Ը�˵ؿ��Դ���...\n");
        if( me->query("bank/coin") < 500 )
                return notify_fail(" ������˵: ��Ĵ���,�޷�֧������.\n");
       if( me->query_temp("invis"))
                return notify_fail(" ���ڲ����У��������Ҳ����㡣����\n");


        switch(arg)
        {
                case "1":
                        room="/open/capital/room/r70";         break;
                case "2":
                        room="/open/gsword/room/su3";          break;
                case "3":
                        room="/open/ping/room/road4";          break;
                case "4":
                        room="/open/trans/room/room4";          break;
                case "5":
                        room="/open/start/room/s5";            break;
                case "10":
                        room="/open/port/room/r3-1";           break;
                case "6":
                        room = me->query("startroom");         break;
                case "7":
                case "8":
                case "9":
                        if( !room = me->query_temp( "fan/"+ arg ) )
                                return notify_fail("��Ǹ, û������Ҫȥ�ĵط������ϡ�\n");
                        break;
                case "gs":
                        room = "/open/wiz/gs.c";               break;
                default:
                        return notify_fail("��Ǹ, û������Ҫȥ�ĵص㡣\n");
        }
        message_vision( HIB+"ֻ�����Ͻ���һ����¤����$N\n"+NOR ,me);

        if( me->query_temp("gmove") )
        {
                count = all_inventory( environment(me) );
                i = sizeof( count );

                if( !me->move(room) )
                        return notify_fail("Ŀ�ĵ��޷����\n");

                while(i--)
                {
                        if( count[i]->is_character() &&
                            !userp(count[i]) &&
                            !count[i]->is_fighting() &&
                        ( count[i]->query_temp("id") == me->query("id")
                        || count[i]->query_leader() == me ) )
                        count[i]->move(room);
                }

                message_vision(HIB+"һ��������,$N�����Ҵ������.\n"+NOR,me);
                me->add("bank/coin", -500);
                return 1;
        }

        if( room && !me->move(room) )
                return notify_fail("Ŀ�ĵ��޷����\n");

        message_vision(HIB+"һ��������,$N�������.\n"+NOR,me);
        me->add("bank/coin",-500);
        return 1;
}