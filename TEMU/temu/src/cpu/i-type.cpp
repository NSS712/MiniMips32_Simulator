#include "helper.h"
#include "monitor.h"
#include "reg.h"

extern ChangeUI m_changeui;
extern uint32_t instr;
extern char assembly[80];
/* decode I-type instrucion with unsigned immediate */
static void decode_imm_type(uint32_t instr) {

	op_src1->type = OP_TYPE_REG;
	op_src1->reg = (instr & RS_MASK) >> (RT_SIZE + IMM_SIZE);
	op_src1->val = reg_w(op_src1->reg);
	
	op_src2->type = OP_TYPE_IMM;
	op_src2->imm = instr & IMM_MASK;
	op_src2->val = op_src2->imm;

	op_dest->type = OP_TYPE_REG;
	op_dest->reg = (instr & RT_MASK) >> (IMM_SIZE);
}

void type(QString a1,QString a2,QString a3,unsigned int a4){
    QString ls;
    ls.append(a1);
    ls.append("   ");
    ls.append(a2);
    ls.append(",   ");
    ls.append(a3);
    ls.append(",   0x");
    ls.append(QString::number(a4,16));
    m_changeui.t_show->append(ls);
}

void lui(uint32_t pc) {

	decode_imm_type(instr);
	reg_w(op_dest->reg) = (op_src2->val << 16);
	sprintf(assembly, "lui   %s,   0x%04x", REG_NAME(op_dest->reg), op_src2->imm);
    QString ls;
    ls.append("lui   ");
    ls.append(REG_NAME(op_dest->reg));
    ls.append(",   0x");
    ls.append(QString::number(op_src2->imm,16));
    m_changeui.t_show->append(ls);
//    type("lui",REG_NAME(op_dest->reg), op_src2->imm);
}

void ori(uint32_t pc){

	decode_imm_type(instr);
	reg_w(op_dest->reg) = op_src1->val | op_src2->val;
	sprintf(assembly, "ori   %s,   %s,   0x%04x", REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), op_src2->imm);
    type("ori",REG_NAME(op_dest->reg), REG_NAME(op_src1->reg),op_src2->imm);
}

void xori(uint32_t pc) {

	decode_imm_type(instr);
	reg_w(op_dest->reg) = op_src1->val ^ op_src2->val;
	sprintf(assembly, "xori   %s,   %s,   0x%04x", REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), op_src2->imm);
    type("xori",REG_NAME(op_dest->reg), REG_NAME(op_src1->reg),op_src2->imm);
}

void addi(uint32_t pc) {

	decode_imm_type(instr);
	reg_w(op_dest->reg) = op_src1->val + op_src2->val;
	sprintf(assembly, "addi   %s,   %s,   0x%04x", REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), op_src2->imm);
    type("addi",REG_NAME(op_dest->reg), REG_NAME(op_src1->reg),op_src2->imm);
}

void beq(uint32_t pc) {

	decode_imm_type(instr);
	if(op_src1->val ==reg_w(op_dest->reg) ){
		pc+= 4+ ((op_src2->val)<<2);
	}
	
	sprintf(assembly, "beq   %s,   %s,   0x%04x", REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), op_src2->imm);
    type("beq",REG_NAME(op_dest->reg), REG_NAME(op_src1->reg),op_src2->imm);
}

void bne(uint32_t pc) {

	decode_imm_type(instr);
	if(op_src1->val !=reg_w(op_dest->reg) ){
		pc+= 4 +( (op_src2->val)<<2);
	}
	sprintf(assembly, "bne   %s,   %s,   0x%04x", REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), op_src2->imm);
    type("bne",REG_NAME(op_dest->reg), REG_NAME(op_src1->reg),op_src2->imm);
}

void addiu(uint32_t pc) {

	decode_imm_type(instr);
	reg_w(op_dest->reg) = op_src1->val + op_src2->val;
	sprintf(assembly, "addiu   %s,   %s,   0x%04x", REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), op_src2->imm);
    type("addiu",REG_NAME(op_dest->reg), REG_NAME(op_src1->reg),op_src2->imm);
}

void slti(uint32_t pc) {

	decode_imm_type(instr);
	reg_w(op_dest->reg) = op_src1->val << op_src2->val;
	sprintf(assembly, "slti   %s,   %s,   0x%04x", REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), op_src2->imm);
    type("slti",REG_NAME(op_dest->reg), REG_NAME(op_src1->reg),op_src2->imm);
}

void sltiu(uint32_t pc) {

	decode_imm_type(instr);
	reg_w(op_dest->reg) = op_src1->val << op_src2->val;
	sprintf(assembly, "xori   %s,   %s,   0x%04x", REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), op_src2->imm);
    type("sltiu",REG_NAME(op_dest->reg), REG_NAME(op_src1->reg),op_src2->imm);
}

void lw(uint32_t pc) {

	decode_imm_type(instr);
	reg_w(op_dest->reg) =  mem_read(op_src1->val+(op_src2->val<<2), 8);
    sprintf(assembly, "lw   %s,   0x%04x(%s)", REG_NAME(op_dest->reg), op_src2->imm, REG_NAME(op_src1->reg));

    QString ls;
    ls.append("lw");
    ls.append("   ");
    ls.append(REG_NAME(op_dest->reg));
    ls.append(",   0x");
    ls.append(QString::number(op_src2->imm,16));
    ls.append("(");
    ls.append(REG_NAME(op_src1->reg));
    ls.append(")");
    m_changeui.t_show->append(ls);

}
void sw(uint32_t pc) {

	decode_imm_type(instr);
	reg_w(op_dest->reg) = op_src1->val + op_src2->val;
	sprintf(assembly, "xori   %s,   %s,   0x%04x", REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), op_src2->imm);

    QString ls;
    ls.append("sw");
    ls.append("   ");
    ls.append(REG_NAME(op_dest->reg));
    ls.append(",   0x");
    ls.append(QString::number(op_src2->imm,16));
    ls.append("(");
    ls.append(REG_NAME(op_src1->reg));
    ls.append(")");
    m_changeui.t_show->append(ls);

}
void andi(uint32_t pc) {

	decode_imm_type(instr);
	reg_w(op_dest->reg) = op_src1->val & op_src2->val;
	sprintf(assembly, "xori   %s,   %s,   0x%04x", REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), op_src2->imm);
    type("andi",REG_NAME(op_dest->reg), REG_NAME(op_src1->reg),op_src2->imm);
}
void j(uint32_t pc) {

    decode_imm_type(instr);
    reg_w(op_dest->reg) = op_src1->val & op_src2->val;
    sprintf(assembly, "xori   %s,   %s,   0x%04x", REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), op_src2->imm);
    type("andi",REG_NAME(op_dest->reg), REG_NAME(op_src1->reg),op_src2->imm);
}
void jal(uint32_t pc) {

    decode_imm_type(instr);
    reg_w(op_dest->reg) = op_src1->val & op_src2->val;
    sprintf(assembly, "xori   %s,   %s,   0x%04x", REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), op_src2->imm);
    type("andi",REG_NAME(op_dest->reg), REG_NAME(op_src1->reg),op_src2->imm);
}
void lb(uint32_t pc) {

    decode_imm_type(instr);
    reg_w(op_dest->reg) = op_src1->val & op_src2->val;
    sprintf(assembly, "xori   %s,   %s,   0x%04x", REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), op_src2->imm);
    type("andi",REG_NAME(op_dest->reg), REG_NAME(op_src1->reg),op_src2->imm);
}
void lh(uint32_t pc) {

    decode_imm_type(instr);
    reg_w(op_dest->reg) = op_src1->val & op_src2->val;
    sprintf(assembly, "xori   %s,   %s,   0x%04x", REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), op_src2->imm);
    type("andi",REG_NAME(op_dest->reg), REG_NAME(op_src1->reg),op_src2->imm);
}
void lbu(uint32_t pc) {

    decode_imm_type(instr);
    reg_w(op_dest->reg) = op_src1->val & op_src2->val;
    sprintf(assembly, "xori   %s,   %s,   0x%04x", REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), op_src2->imm);
    type("andi",REG_NAME(op_dest->reg), REG_NAME(op_src1->reg),op_src2->imm);
}
void lhu(uint32_t pc) {

    decode_imm_type(instr);
    reg_w(op_dest->reg) = op_src1->val & op_src2->val;
    sprintf(assembly, "xori   %s,   %s,   0x%04x", REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), op_src2->imm);
    type("andi",REG_NAME(op_dest->reg), REG_NAME(op_src1->reg),op_src2->imm);
}
void sb(uint32_t pc) {

    decode_imm_type(instr);
    reg_w(op_dest->reg) = op_src1->val & op_src2->val;
    sprintf(assembly, "xori   %s,   %s,   0x%04x", REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), op_src2->imm);
    type("andi",REG_NAME(op_dest->reg), REG_NAME(op_src1->reg),op_src2->imm);
}
void sh(uint32_t pc) {

    decode_imm_type(instr);
    reg_w(op_dest->reg) = op_src1->val & op_src2->val;
    sprintf(assembly, "xori   %s,   %s,   0x%04x", REG_NAME(op_dest->reg), REG_NAME(op_src1->reg), op_src2->imm);
    type("andi",REG_NAME(op_dest->reg), REG_NAME(op_src1->reg),op_src2->imm);
}
