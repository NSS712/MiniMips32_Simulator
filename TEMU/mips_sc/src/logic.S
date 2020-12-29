#include "trap.h"
   .set noat
   .globl main
   .text
main:
   li $at, 0x10101010           #$at = 0x10101010
   li $v0, 0x01011111           #$v0 = 0x01011111
   and $t0, $at, $v0            #$t0 = 0x00001010
   or $t0, $at, $v0            #$t0 = 0x00001010
   addi $t0, $t0, 0xffff
   xori $t1,$t0,63
   addi $s0, $0, 3
   addi $s1, $s0, 2

   HIT_GOOD_TRAP		#stop temu
