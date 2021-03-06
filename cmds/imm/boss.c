// boss.c                                           
                                                    
#include <ansi.h>                                   
#define SYNTAX  "指令格式：boss [巫师姓名]\n"       
                                                    
inherit F_CLEAN_UP;                                 
                                                    
int main(object me, string arg)                     
{                                                   
        string name, str;                           
                                                    
        if( !arg ) name = me->query("id");          
                                                    
        else if( sscanf(arg, "%s", name)!=1 )       
                return notify_fail(SYNTAX);         
                                                    
        if ((str=SECURITY_D->get_boss(name)) == "") 
                write(name + " 还没有上司。\n");    
        else                                                   
                write(name + " 的顶头上司是 " + str + "。\n"); 
        return 1;                                              
}                                                              
                                                               
int help()                                                     
{                                                              
        write(SYNTAX + @TEXT                                   
                                                               
找出某位巫师的顶头上司。                                       
TEXT                                                           
        );                                                     
}                                                              

