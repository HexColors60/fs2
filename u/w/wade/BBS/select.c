// select.c
//
// 选择要看的版面
// select		如已经设定了，就显示出来
// select 版面		就是它了
// select cat		同 list cat, 列出所有版面
// wade@Fantasy.Space 12/16/1999
// 对于 BBS 系统的用法说明请见 help BBS

#include <BBS.h>

int help();

int main(object me, string s)
{
  string	board;		// 现在查看的版面
  object	BBS;
  mixed		boards;		// 表示所有版面

  if (!s || s == "") {	// 如已经设定了，就显示出来，否则提示一下
    if (!stringp (board = me->query("post/board"))) {	// 没设过。
      write ("抱歉，您还没设过任何想看的版面，请设先定之。\n");
      return 1;
    }
    write ("你设定的版面是："+board + "\n");
    return 1;
  }
  if (undefinedp (boards = get_dir (BBS_DIR))) {	// 连目录都错了？
    write ("这可能是 BBS 目录没设好的关系！\n");
    return 1;
  }
  if (s == "cat") {	// 列出所有版面，很简单啦！版面就是目录名称。
    printf ("目前的版面有：%O\n", boards);
    return 1;
  }
  if (member_array (s, boards) == -1) {	// 不存在这个版面！
    write ("哦！对不起，目前没有这个版面，如想查询，请用 select cat 命令。\n");
    return 1;
  }
  // 找到了！！！
  me->set ("post/board", s);	// 就是这么简单！
  write ("你选择 "+s+" 已设定好了。\n");

  return 1;
}

int help()
{
  write(@HELP
指令格式 : select [cat|版面]
意义 :
	此为 BBS 系统，命令有：
	使用者：list, select, post, read, renew
	巫　师：discard, mark, extract
指令说明：
	选择要看哪一个版面。
	select		<-- 如已设定，印出目前的设定，否则提示一下。
	select cat	<-- 列出所有版面
	select 版面	<-- 一看就知道了吧！
HELP
    );
    return 1;
}
