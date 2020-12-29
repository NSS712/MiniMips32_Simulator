#include "ChangeUI.h"
#include "temu.h"

extern CPU_state cpu;
ChangeUI::ChangeUI()
{

}

void ChangeUI::update_ui()
{
    /*
     * 对m_q1设置参数就是对 ui->Q1进行属性设置。
     *
     */
    m_q1->setText("0x"+QString::number(cpu.gpr[0]._32,16));
    m_q2->setText("0x"+QString::number(cpu.gpr[1]._32,16));
    m_q3->setText("0x"+QString::number(cpu.gpr[2]._32,16));
    m_q4->setText("0x"+QString::number(cpu.gpr[3]._32,16));
    m_q5->setText("0x"+QString::number(cpu.gpr[4]._32,16));
    m_q6->setText("0x"+QString::number(cpu.gpr[5]._32,16));
    m_q7->setText("0x"+QString::number(cpu.gpr[6]._32,16));
    m_q8->setText("0x"+QString::number(cpu.gpr[7]._32,16));
    m_q9->setText("0x"+QString::number(cpu.gpr[8]._32,16));
    m_q10->setText("0x"+QString::number(cpu.gpr[9]._32,16));
    m_q11->setText("0x"+QString::number(cpu.gpr[10]._32,16));
    m_q12->setText("0x"+QString::number(cpu.gpr[11]._32,16));
    m_q13->setText("0x"+QString::number(cpu.gpr[12]._32,16));
    m_q14->setText("0x"+QString::number(cpu.gpr[13]._32,16));
    m_q15->setText("0x"+QString::number(cpu.gpr[14]._32,16));
    m_q16->setText("0x"+QString::number(cpu.gpr[15]._32,16));
    m_q17->setText("0x"+QString::number(cpu.gpr[16]._32,16));
    m_q18->setText("0x"+QString::number(cpu.gpr[17]._32,16));
    m_q19->setText("0x"+QString::number(cpu.gpr[18]._32,16));
    m_q20->setText("0x"+QString::number(cpu.gpr[19]._32,16));
    m_q21->setText("0x"+QString::number(cpu.gpr[20]._32,16));
    m_q22->setText("0x"+QString::number(cpu.gpr[21]._32,16));
    m_q23->setText("0x"+QString::number(cpu.gpr[22]._32,16));
    m_q24->setText("0x"+QString::number(cpu.gpr[23]._32,16));
    m_q25->setText("0x"+QString::number(cpu.gpr[24]._32,16));
    m_q26->setText("0x"+QString::number(cpu.gpr[25]._32,16));
    m_q27->setText("0x"+QString::number(cpu.gpr[26]._32,16));
    m_q28->setText("0x"+QString::number(cpu.gpr[27]._32,16));
    m_q29->setText("0x"+QString::number(cpu.gpr[28]._32,16));
    m_q30->setText("0x"+QString::number(cpu.gpr[29]._32,16));
    m_q31->setText("0x"+QString::number(cpu.gpr[30]._32,16));
    m_q32->setText("0x"+QString::number(cpu.gpr[31]._32,16));
    m_pc->setText("0x"+QString::number(cpu.pc,16));


//     m_q2->setText("this is q2!");
//    m_q3->setText("this is q3!");
}
