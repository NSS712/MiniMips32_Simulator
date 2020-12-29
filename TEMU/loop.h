#ifndef LOOP_H
#define LOOP_H

extern int cmd_w(char *args);
extern int cmd_c(char *args);
extern int cmd_q(char *args);
extern int cmd_si(char *args);
extern int cmd_help(char *args);
extern int cmd_info(char *args);
extern int cmd_p(char *args);
extern int cmd_mr(char *args);
extern int cmd_dw(char *args);

static struct
{
    char *name;
    char *description;
    int (*handler)(char *);
} cmd_table[] = {
    {"help", "Display informations about all supported commands", cmd_help},
    {"c", "Continue the execution of the program", cmd_c},
    {"q", "Exit TEMU", cmd_q},
    {"si", "单步执行", cmd_si},
    {"info", "打印寄存器和监视点状态", cmd_info},
    {"p", "表达式求值", cmd_p},
    {"x", "读取内存", cmd_mr},
    {"w", "监视点", cmd_w},
    {"d", "删除监视点", cmd_dw}
    /* TODO: Add more commands */

};
#endif // LOOP_H
