#include "helper.h"
#include "monitor.h"
#include "reg.h"
#include "ChangeUI.h"

extern ChangeUI m_changeui;
extern uint32_t instr;
extern char assembly[80];

/* decode R-type instrucion */
static void decode_r_type(uint32_t instr) {

	op_src1->type = OP_TYPE_REG;
	op_src1->reg = (instr & RS_MASK) >> (RT_SIZE + IMM_SIZE);
	op_src1->val = reg_w(op_src1->reg);
	
	op_src2->type = OP_TYPE_REG;
	op_src2->imm = (instr & RT_MASK) >> (RD_SIZE + SHAMT_SIZE + FUNC_SIZE);
	op_src2->val = reg_w(op_src2->reg);

	op_dest->type = OP_TYPE_REG;
	op_dest->reg = (instr & RD_MASK) >> (SHAMT_SIZE + FUNC_SIZE);
}


void typer(QString a1,QString a2,QString a3,QString a4){
    QString ls;
    ls.append(a1);
    ls.append("   ");
    ls.append(a2);
    ls.append(",   ");
    ls.append(a3);
    ls.append(",   ");
    ls.append(a4);
    m_changeui.t_show->append(ls);
}

void dand(uint32_t pc) {

	decode_r_type(instr);
	reg_w(op_dest->reg) = (op_src1->val & op_src2->val);
	sprintf(assembly, "and   %s,   %s,   %s", REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), REG_NAME(op_src2->reg));
    typer("and",REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), REG_NAME(op_src2->reg));
}

void dor(uint32_t pc) {

	decode_r_type(instr);
	reg_w(op_dest->reg) = (op_src1->val | op_src2->val);
	sprintf(assembly, "or   %s,   %s,   %s", REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), REG_NAME(op_src2->reg));
    typer("or",REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), REG_NAME(op_src2->reg));
}
void sll(uint32_t pc) {

    decode_r_type(instr);
    reg_w(op_dest->reg) = (op_src1->val | op_src2->val);
    sprintf(assembly, "or   %s,   %s,   %s", REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), REG_NAME(op_src2->reg));
    typer("or",REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), REG_NAME(op_src2->reg));
}
void srl(uint32_t pc) {

    decode_r_type(instr);
    reg_w(op_dest->reg) = (op_src1->val | op_src2->val);
    sprintf(assembly, "or   %s,   %s,   %s", REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), REG_NAME(op_src2->reg));
    typer("or",REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), REG_NAME(op_src2->reg));
}

void sra(uint32_t pc) {

    decode_r_type(instr);
    reg_w(op_dest->reg) = (op_src1->val | op_src2->val);
    sprintf(assembly, "or   %s,   %s,   %s", REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), REG_NAME(op_src2->reg));
    typer("or",REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), REG_NAME(op_src2->reg));
}
void sllv(uint32_t pc) {

    decode_r_type(instr);
    reg_w(op_dest->reg) = (op_src1->val | op_src2->val);
    sprintf(assembly, "or   %s,   %s,   %s", REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), REG_NAME(op_src2->reg));
    typer("or",REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), REG_NAME(op_src2->reg));
}
void srlv(uint32_t pc) {

    decode_r_type(instr);
    reg_w(op_dest->reg) = (op_src1->val | op_src2->val);
    sprintf(assembly, "or   %s,   %s,   %s", REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), REG_NAME(op_src2->reg));
    typer("or",REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), REG_NAME(op_src2->reg));
}
void srav(uint32_t pc) {

    decode_r_type(instr);
    reg_w(op_dest->reg) = (op_src1->val | op_src2->val);
    sprintf(assembly, "or   %s,   %s,   %s", REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), REG_NAME(op_src2->reg));
    typer("or",REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), REG_NAME(op_src2->reg));
}
void jr(uint32_t pc) {

    decode_r_type(instr);
    reg_w(op_dest->reg) = (op_src1->val | op_src2->val);
    sprintf(assembly, "or   %s,   %s,   %s", REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), REG_NAME(op_src2->reg));
    typer("or",REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), REG_NAME(op_src2->reg));
}
void jalr(uint32_t pc) {

    decode_r_type(instr);
    reg_w(op_dest->reg) = (op_src1->val | op_src2->val);
    sprintf(assembly, "or   %s,   %s,   %s", REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), REG_NAME(op_src2->reg));
    typer("or",REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), REG_NAME(op_src2->reg));
}
void syscall(uint32_t pc) {

    decode_r_type(instr);
    reg_w(op_dest->reg) = (op_src1->val | op_src2->val);
    sprintf(assembly, "or   %s,   %s,   %s", REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), REG_NAME(op_src2->reg));
    typer("or",REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), REG_NAME(op_src2->reg));
}
void dbreak(uint32_t pc) {

    decode_r_type(instr);
    reg_w(op_dest->reg) = (op_src1->val | op_src2->val);
    sprintf(assembly, "or   %s,   %s,   %s", REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), REG_NAME(op_src2->reg));
    typer("or",REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), REG_NAME(op_src2->reg));
}

void mfhi(uint32_t pc) {

    decode_r_type(instr);
    reg_w(op_dest->reg) = (op_src1->val | op_src2->val);
    sprintf(assembly, "or   %s,   %s,   %s", REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), REG_NAME(op_src2->reg));
    typer("or",REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), REG_NAME(op_src2->reg));
}
void mthi(uint32_t pc) {

    decode_r_type(instr);
    reg_w(op_dest->reg) = (op_src1->val | op_src2->val);
    sprintf(assembly, "or   %s,   %s,   %s", REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), REG_NAME(op_src2->reg));
    typer("or",REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), REG_NAME(op_src2->reg));
}

void mflo(uint32_t pc) {

    decode_r_type(instr);
    reg_w(op_dest->reg) = (op_src1->val | op_src2->val);
    sprintf(assembly, "or   %s,   %s,   %s", REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), REG_NAME(op_src2->reg));
    typer("or",REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), REG_NAME(op_src2->reg));
}
void mtlo(uint32_t pc) {

    decode_r_type(instr);
    reg_w(op_dest->reg) = (op_src1->val | op_src2->val);
    sprintf(assembly, "or   %s,   %s,   %s", REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), REG_NAME(op_src2->reg));
    typer("or",REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), REG_NAME(op_src2->reg));
}
void mult(uint32_t pc) {

    decode_r_type(instr);
    reg_w(op_dest->reg) = (op_src1->val | op_src2->val);
    sprintf(assembly, "or   %s,   %s,   %s", REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), REG_NAME(op_src2->reg));
    typer("or",REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), REG_NAME(op_src2->reg));
}
void multu(uint32_t pc) {

    decode_r_type(instr);
    reg_w(op_dest->reg) = (op_src1->val | op_src2->val);
    sprintf(assembly, "or   %s,   %s,   %s", REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), REG_NAME(op_src2->reg));
    typer("or",REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), REG_NAME(op_src2->reg));
}
void div(uint32_t pc) {

    decode_r_type(instr);
    reg_w(op_dest->reg) = (op_src1->val | op_src2->val);
    sprintf(assembly, "or   %s,   %s,   %s", REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), REG_NAME(op_src2->reg));
    typer("or",REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), REG_NAME(op_src2->reg));
}
void divu(uint32_t pc) {

    decode_r_type(instr);
    reg_w(op_dest->reg) = (op_src1->val | op_src2->val);
    sprintf(assembly, "or   %s,   %s,   %s", REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), REG_NAME(op_src2->reg));
    typer("or",REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), REG_NAME(op_src2->reg));
}
void add(uint32_t pc) {

    decode_r_type(instr);
    reg_w(op_dest->reg) = (op_src1->val | op_src2->val);
    sprintf(assembly, "or   %s,   %s,   %s", REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), REG_NAME(op_src2->reg));
    typer("or",REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), REG_NAME(op_src2->reg));
}
void addu(uint32_t pc) {

    decode_r_type(instr);
    reg_w(op_dest->reg) = (op_src1->val | op_src2->val);
    sprintf(assembly, "or   %s,   %s,   %s", REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), REG_NAME(op_src2->reg));
    typer("or",REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), REG_NAME(op_src2->reg));
}
void sub(uint32_t pc) {

    decode_r_type(instr);
    reg_w(op_dest->reg) = (op_src1->val | op_src2->val);
    sprintf(assembly, "or   %s,   %s,   %s", REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), REG_NAME(op_src2->reg));
    typer("or",REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), REG_NAME(op_src2->reg));
}
void subu(uint32_t pc) {

    decode_r_type(instr);
    reg_w(op_dest->reg) = (op_src1->val | op_src2->val);
    sprintf(assembly, "or   %s,   %s,   %s", REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), REG_NAME(op_src2->reg));
    typer("or",REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), REG_NAME(op_src2->reg));
}
void dxor(uint32_t pc) {

    decode_r_type(instr);
    reg_w(op_dest->reg) = (op_src1->val | op_src2->val);
    sprintf(assembly, "or   %s,   %s,   %s", REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), REG_NAME(op_src2->reg));
    typer("or",REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), REG_NAME(op_src2->reg));
}
void nor(uint32_t pc) {

    decode_r_type(instr);
    reg_w(op_dest->reg) = (op_src1->val | op_src2->val);
    sprintf(assembly, "or   %s,   %s,   %s", REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), REG_NAME(op_src2->reg));
    typer("or",REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), REG_NAME(op_src2->reg));
}
void slt(uint32_t pc) {

    decode_r_type(instr);
    reg_w(op_dest->reg) = (op_src1->val | op_src2->val);
    sprintf(assembly, "or   %s,   %s,   %s", REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), REG_NAME(op_src2->reg));
    typer("or",REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), REG_NAME(op_src2->reg));
}

void sltu(uint32_t pc) {

    decode_r_type(instr);
    reg_w(op_dest->reg) = (op_src1->val | op_src2->val);
    sprintf(assembly, "or   %s,   %s,   %s", REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), REG_NAME(op_src2->reg));
    typer("or",REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), REG_NAME(op_src2->reg));
}
