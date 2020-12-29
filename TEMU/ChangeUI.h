#ifndef CHANGUI_H
#define CHANGUI_H

#include <QLabel>
#include <QTextEdit>

class ChangeUI
{
public:
    ChangeUI();
    void update_ui();

public:
    /*
     * 定义几个QLabel指针
     * 这个是将mainwindow中的控件指针赋值给他们的
     * 就是将 m_q1 = ui->Q1(在mainwindow中进行)
     *
     */
    QLabel*     m_q1;
    QLabel*     m_q2;
    QLabel*     m_q3;
    QLabel*     m_q4;
    QLabel*     m_q5;
    QLabel*     m_q6;
    QLabel*     m_q7;
    QLabel*     m_q8;
    QLabel*     m_q9;
    QLabel*     m_q10;
    QLabel*     m_q11;
    QLabel*     m_q12;
    QLabel*     m_q13;
    QLabel*     m_q14;
    QLabel*     m_q15;
    QLabel*     m_q16;
    QLabel*     m_q17;
    QLabel*     m_q18;
    QLabel*     m_q19;
    QLabel*     m_q20;
    QLabel*     m_q21;
    QLabel*     m_q22;
    QLabel*     m_q23;
    QLabel*     m_q24;
    QLabel*     m_q25;
    QLabel*     m_q26;
    QLabel*     m_q27;
    QLabel*     m_q28;
    QLabel*     m_q29;
    QLabel*     m_q30;
    QLabel*     m_q31;
    QLabel*     m_q32;
    QTextEdit*  t_show;
    QLabel*     m_pc;
};


#endif // CHANGUI_H
