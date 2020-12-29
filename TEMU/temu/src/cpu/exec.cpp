#include "helper.h"
#include "all-instr.h"
#include "mainwindow.h"

typedef void (*op_fun)(uint32_t);
static void _2byte_esc(uint32_t pc);
void update_ui();
Operands ops_decoded;
uint32_t instr;

extern ChangeUI m_changeui;
/* TODO: Add more instructions!!! */

op_fun opcode_table [64] = {
/* 0x00 */	_2byte_esc, inv, j, jal,
/* 0x04 */	inv, beq, bne, inv,
/* 0x08 */	addi, addiu, slti, sltiu,
/* 0x0c */	andi, ori, xori, lui,
/* 0x10 */	lw, sw, temu_trap, inv,
/* 0x14 */	inv, inv, inv, inv,
/* 0x18 */	inv, inv, inv, inv,
/* 0x1c */	inv, inv, inv, inv,
/* 0x20 */	lb, lh, inv, lw,
/* 0x24 */	lbu, lhu, inv, inv,
/* 0x28 */	inv, inv, inv, inv,
/* 0x2c */	sb, sh, inv, sw,
/* 0x30 */	inv, inv, inv, inv,
/* 0x34 */	inv, inv, inv, inv,
/* 0x38 */	inv, inv, inv, inv,
/* 0x3c */	inv, inv, inv, inv
};

op_fun _2byte_opcode_table [64] = {
/* 0x00 */	sll, inv, srl, sra,
/* 0x04 */	sllv, inv, srlv, srav,
/* 0x08 */	jr, jalr, inv, inv,
/* 0x0c */	syscall, dbreak, inv, inv,
/* 0x10 */	mfhi, mthi, mflo, mtlo,
/* 0x14 */	inv, inv, inv, inv, 
/* 0x18 */	mult, multu, div, divu,
/* 0x1c */	inv, inv, inv, inv, 
/* 0x20 */	add, addu,sub, subu,
/* 0x24 */	dand, dor,dxor,nor,
/* 0x28 */	inv, inv, slt, sltu,
/* 0x2c */	inv, inv, inv, inv, 
/* 0x30 */	inv, inv, inv, inv, 
/* 0x34 */	inv, inv, inv, inv,
/* 0x38 */	inv, inv, inv, inv, 
/* 0x3c */	inv, inv, inv, inv
};

void exec(uint32_t pc){
	instr = instr_fetch(pc, 4);
	ops_decoded.opcode = instr >> 26;
	opcode_table[ ops_decoded.opcode ](pc);
    m_changeui.update_ui();
}

static void _2byte_esc(uint32_t pc) {
	ops_decoded.func = instr & FUNC_MASK;
	_2byte_opcode_table[ops_decoded.func](pc); 
}
