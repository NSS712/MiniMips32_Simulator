
build/logic:     file format elf32-tradlittlemips
build/logic


Disassembly of section .text:

00000000 <main>:
   0:	3c011010 	lui	at,0x1010
   4:	34211010 	ori	at,at,0x1010
   8:	3c020101 	lui	v0,0x101
   c:	34421111 	ori	v0,v0,0x1111
  10:	00224024 	and	t0,at,v0
  14:	00224025 	or	t0,at,v0
  18:	2108ffff 	addi	t0,t0,-1
  1c:	3909003f 	xori	t1,t0,0x3f
  20:	20100003 	addi	s0,zero,3
  24:	22110002 	addi	s1,s0,2
  28:	4a000000 	c2	0x0

Disassembly of section .reginfo:

00000000 <.reginfo>:
   0:	00030306 	0x30306
	...
