#include "helper.h"
#include "monitor.h"

extern char assembly[80];
extern ChangeUI m_changeui;

/* invalid opcode */
void inv(uint32_t pc) {

	uint32_t temp;
	temp = instr_fetch(pc, 4);

    uint8_t *p = (uint8_t *)&temp;
	printf("invalid opcode(pc = 0x%08x): %02x %02x %02x %02x ...\n\n", 
            pc, p[3], p[2], p[1], p[ 0]);

	printf("There are two cases which will trigger this unexpected exception:\n\
1. The instruction at pc = 0x%08x is not implemented.\n\
2. Something is implemented incorrectly.\n", pc);
	printf("Find this pc value(0x%08x) in the disassembling result to distinguish which case it is.\n\n", pc);

	assert(0);
}

/* stop temu */
void temu_trap(uint32_t pc){

	printf("\33[1;31mtemu: HIT GOOD TRAP\33[0m at $pc = 0x%08x\n\n", cpu.pc);
    QString ls="temu: HIT GOOD TRAP at $pc = 0x";
    ls.append(QString::number(cpu.pc,16));
    m_changeui.t_show->append(ls);

	temu_state = END;

}

