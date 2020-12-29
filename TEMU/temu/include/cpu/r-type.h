#ifndef __RTYPE_H__
#define __RTYPE_H__

//make_helper(and);
void dand(uint32_t pc);
void sll(uint32_t pc);
void srl(uint32_t pc);
void sra(uint32_t pc);
void sllv(uint32_t pc);
void srlv(uint32_t pc);
void srav(uint32_t pc);
void jr(uint32_t pc);
void jalr(uint32_t pc);
void syscall(uint32_t pc);
void dbreak(uint32_t pc);
void mfhi(uint32_t pc);
void mthi(uint32_t pc);
void mflo(uint32_t pc);
void mtlo(uint32_t pc);
void mult(uint32_t pc);
void multu(uint32_t pc);
void div(uint32_t pc);
void divu(uint32_t pc);
void add(uint32_t pc);
void addu(uint32_t pc);
void sub(uint32_t pc);
void subu(uint32_t pc);
void dor(uint32_t pc);
void dxor(uint32_t pc);
void nor(uint32_t pc);
void slt(uint32_t pc);
void sltu(uint32_t pc);

#endif
