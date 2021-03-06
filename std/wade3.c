inherit ROOM;


// 要能存档的第一步：
inherit F_SAVE;

// 如不想存档，要加 static 在最前面
mapping data=([]);

void create()
{
 set("short","考题三");
 set("long","简单的电话簿，可以利用(add)来增加资料，
 如果你闲麻烦也可以直接用(ask)，当然也可以
 用(list)列出所有的资料。\n");

 // 第二步，可以不要，那第三步要改
 set("save_file", __DIR__);
 setup();
}

// 第三步，配合第二步，看一下就知道了
string query_save_file() { return query ("save_file"); }

void init()
{
 add_action("do_add","add");
 add_action("do_ask","ask");
 add_action("do_list","list");
}
int do_add(string str)
{
 string str1,str2;
 if(sscanf(str,"%s %s",str1,str2)!=2)
  return notify_fail("输入格式错误\n"); 
 printf("%s : %s\n",str1,str2); printf("%s 资料加入完毕\n",str1); 
 data += ([str1:str2]);
  // 存档第四步, 该存档时就下底下的命令
  this_object()->save();
 return 1;
}
int do_ask(string str1)
{
 if(!data[str1]) return notify_fail("你的通讯录中并无此人资料\n");
 printf("%s 的联络电话是 %s\n",str1,data[str1]);
 return 1;
}
int do_list()
{
 printf("通讯录资料\n");
 printf(" %O \n",data);
 printf("总共有 %d 笔资料\n",sizeof(data));
 return 1;
}
  
