// 背景效果

inherit NPC;

void create()
{
          set_name(" ",({"action"}));
          set("short","");
          set("chat_chance",5);
          set("chat_msg",({
          "你看到这里来来往往的游魂很多，但能往第二殿的却是少数。\n",
          "关卡守卫踹了踹一只穷苦的老鬼说：「没钱免谈！”\n",
          "关卡守卫抖了抖身上的金链子，脸上满是得意的笑容。\n"
	}) );
	setup();
}
