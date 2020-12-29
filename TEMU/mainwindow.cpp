#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "temu.h"
#include <stdlib.h>
#include "monitor.h"
#include "temu.h"
#include "reg.h"
#include "helper.h"
#include "memory.h"
#include "expr.h"
#include "watchpoint.h"
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <string.h>
#include <loop.h>
#include <QMessageBox>

#define NR_CMD (sizeof(cmd_table) / sizeof(cmd_table[0]))

extern CPU_state cpu;
ChangeUI m_changeui;
void cpu_exec(uint32_t);
void display_reg();
char *rl_gets();

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    printf("run mainwindow new\n");
//    m_changeUI = new ChangeUI();
    m_changeui.m_q1=ui->label;
    m_changeui.m_q2=ui->label_2;
    m_changeui.m_q3=ui->label_3;
    m_changeui.m_q4=ui->label_4;
    m_changeui.m_q5=ui->label_5;
    m_changeui.m_q6=ui->label_6;
    m_changeui.m_q7=ui->label_7;
    m_changeui.m_q8=ui->label_8;
    m_changeui.m_q9=ui->label_9;
    m_changeui.m_q10=ui->label_10;
    m_changeui.m_q11=ui->label_11;
    m_changeui.m_q12=ui->label_12;
    m_changeui.m_q13=ui->label_13;
    m_changeui.m_q14=ui->label_14;
    m_changeui.m_q15=ui->label_15;
    m_changeui.m_q16=ui->label_16;
    m_changeui.m_q17=ui->label_17;
    m_changeui.m_q18=ui->label_18;
    m_changeui.m_q19=ui->label_19;
    m_changeui.m_q20=ui->label_20;
    m_changeui.m_q21=ui->label_21;
    m_changeui.m_q22=ui->label_22;
    m_changeui.m_q23=ui->label_23;
    m_changeui.m_q24=ui->label_24;
    m_changeui.m_q25=ui->label_25;
    m_changeui.m_q26=ui->label_26;
    m_changeui.m_q27=ui->label_27;
    m_changeui.m_q28=ui->label_28;
    m_changeui.m_q29=ui->label_29;
    m_changeui.m_q30=ui->label_30;
    m_changeui.m_q31=ui->label_31;
    m_changeui.m_q32=ui->label_32;
    m_changeui.t_show=ui->textEdit;
    m_changeui.m_pc=ui->label_pc;
    m_changeui.update_ui();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mainloop(){
    init_wp_pool();
    while (1)
    {
        char *str = rl_gets();
        char *str_end = str + strlen(str);

        /* extract the first token as the command */
        char *cmd = strtok(str, " ");
        if (cmd == NULL)
        {
            continue;
        }

        /* treat the remaining string as the arguments,
         * which may need furth]
         * er parsing
         */
        char *args = cmd + strlen(cmd) + 1;
        if (args >= str_end)
        {
            args = NULL;
        }

        int i;
        for (i = 0; i < NR_CMD; i++)
        {
            if (strcmp(cmd, cmd_table[i].name) == 0)
            {
                if (cmd_table[i].handler(args) < 0)
                {
                    return;
                }
                break;
            }
        }

        if (i == NR_CMD)
        {
            printf("Unknown command '%s'\n", cmd);
        }
        break;
    }

}

void MainWindow::on_Btn_ni_clicked()
{
    cmd_si("1");
}

void MainWindow::on_btn_help_clicked()
{
     QMessageBox::critical(this, tr("help"),  tr("help - Display informations about all supported commands\nc - Continue the execution of the program\nq - Exit TEMU\nsi - 单步执行\ninfo - 打印寄存器和监视点状态\np - 表达式求值\nx - 读取内存\nw - 监视点\nd - 删除监视点"),QMessageBox::Save);
}

void MainWindow::on_btn_c_clicked()
{
    cpu_exec(-1);
}


void MainWindow::on_lineEdit_returnPressed()
{
    QString cin=ui->lineEdit->text();
//    char *str = cin;
//    std::string st = cin.toStdString();
//    const char* str = st.c_str();
//    QString temp=line->text();
    char *str=(char *)malloc(30);
    QByteArray ba=cin.toLatin1();
    strcpy(str,ba.data());

    char *str_end = str + strlen(str);

    /* extract the first token as the command */
    char *cmd = strtok(str, " ");
    if (cmd == NULL)
    {
        return;
    }

    /* treat the remaining string as the arguments,
     * which may need further parsing
     */
    char *args = cmd + strlen(cmd) + 1;
    if (args >= str_end)
    {
        args = NULL;
    }

    int i;
    for (i = 0; i < NR_CMD; i++)
    {
        if (strcmp(cmd, cmd_table[i].name) == 0)
        {
            if (cmd_table[i].handler(args) < 0)
            {
                return;
            }
            break;
        }
    }

    if (i == NR_CMD)
    {
        printf("Unknown command '%s'\n", cmd);
    }
    ui->lineEdit->setText(NULL);
}

void MainWindow::on_btn_w_clicked()
{
    WP *p = return_first();
    while (p != NULL)
    {
        Log("断点号%d, 表达式%s, 表达式的值%d\n", p->NO, p->expr, p->expr_val);
        QString ls=QString("断点号%1, 表达式%2, 表达式的值%3\n").arg(QString::number(p->NO)).arg(p->expr).arg(QString::number(p->expr_val));
        m_changeui.t_show->append(ls);
        p = p->next;
    }
}
