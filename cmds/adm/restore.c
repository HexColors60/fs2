// 取回玩家的备份资料档.
// by wade (5/23/1996)
inherit F_CLEAN_UP;

int help();

int main(object me, string arg)
{
  string	src, dst, op, id;

  if (!arg) return help();
  if (sscanf (arg, "%s %s", op, id) != 2) {
    op = "-1";
    id = arg;
  }

  if (op == "-1") {
    dst = sprintf ("/data/login/%s/%s.o", id[0..0], id);
    src = sprintf ("/data/backup/login/%s/%s.o", id[0..0], id);
    if (!cp (src, dst))
      return notify_fail("无法取回 "+id+" 的资料档.\n");

    dst = sprintf ("/data/user/%s/%s.o", id[0..0], id);
    src = sprintf ("/data/backup/user/%s/%s.o", id[0..0], id);
    if (!cp (src, dst))
      return notify_fail("无法取回 "+id+" 的资料档.\n");
    write ("取回玩家资料 ok.\n");
  }
  else if (op == "-2") {
    dst = sprintf ("/data/login/%s/%s.o", id[0..0], id);
    src = sprintf ("/data/backup2/login/%s/%s.o", id[0..0], id);
    if (!cp (src, dst))
      return notify_fail("无法取回 "+id+" 的资料档.\n");

    dst = sprintf ("/data/user/%s/%s.o", id[0..0], id);
    src = sprintf ("/data/backup2/user/%s/%s.o", id[0..0], id);
    if (!cp (src, dst))
      return notify_fail("无法取回 "+id+" 的资料档.\n");
    write ("取回玩家资料 ok.\n");
  }
log_file("wiz/RESTORE",sprintf("%s restore %s on %s\n",
me->query("id"),id,ctime(time())));
  return 1;
}

int help()
{
	write(@HELP
指令格式： restore -1|-2 玩家 id		取回玩家的备份资料

save 会存档 + 第一份备份
  save -b 会存档 + 第一份备份 + 第二份备份
  普通状况下, 如死亡, 离开等等, 系统只会存档, 不会备份

  restore -1 是取回第一份备份
  restore -2 是取回第二份备份

  ps: 要让玩家先离开, 取回之后再进来.
HELP
	);
	return 1;
}
