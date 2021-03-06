// SPDX-License-Identifier: GPL-2.0
// Copyright (C) 2018 Hangzhou C-SKY Microsystems co.,ltd.
#include <linux/linkage.h>
#include <linux/init.h>
#include <asm/page.h>
#include <abi/regdef.h>

__HEAD
ENTRY(_start)
	/* set super user mode */
	lrw	a3, DEFAULT_PSR_VALUE
	mtcr    a3, psr
	psrset  ee

	/* set stack point */
	lrw     a3, init_thread_union + THREAD_SIZE
	mov	sp, a3

	jmpi	csky_start
END(_start)

#ifdef CONFIG_SMP
.align 10
ENTRY(_start_smp_secondary)
	/* Invalid I/Dcache BTB BHT */
	movi	a3, 7
	lsli	a3, 16
	addi	a3, (1<<4) | 3
	mtcr	a3, cr17

	tlbi.alls
	sync.is

	/* setup PAGEMASK */
	movi	a3, 0
	mtcr	a3, cr<6, 15>

	/* setup MEL0/MEL1 */
	grs	a0, _start_smp_pc
_start_smp_pc:
	bmaski  a1, 13
	andn    a0, a1
	movi    a1, 0x00000006
	movi    a2, 0x00001006
	or      a1, a0
	or      a2, a0
	mtcr	a1, cr<2, 15>
	mtcr	a2, cr<3, 15>

	/* setup MEH */
	mtcr	a0, cr<4, 15>

	/* write TLB */
	bgeni   a3, 28
	mtcr	a3, cr<8, 15>

	/* setup msa0 & msa1 */
	lrw	a3, PHYS_OFFSET | 0x8e
	mtcr	a3, cr<30, 15>
	lrw	a3, PHYS_OFFSET | 0x26
	mtcr	a3, cr<31, 15>

	/* enable MMU */
	movi	a3, 1
	mtcr    a3, cr18

	jmpi	_goto_mmu_on
_goto_mmu_on:
	movi	a3, 0xaa

	lrw	a3, DEFAULT_PSR_VALUE
	mtcr    a3, psr
	psrset  ee

	/* set stack point */
	lrw     a3, secondary_stack
	ld.w	a3, (a3, 0)
	mov	sp, a3

	jmpi	csky_start_secondary
END(_start_smp_secondary)
#endif
