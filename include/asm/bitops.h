#ifndef __ASM_CSKY_BITOPS_H
#define __ASM_CSKY_BITOPS_H

#include <linux/irqflags.h>
#include <linux/compiler.h>
#include <asm/barrier.h>

/*
 * asm-generic/bitops/ffs.h
 */
static inline int ffs(int x)
{
	if(!x) return 0;

	__asm__ __volatile__ (
			"brev %0\n\t"
			"ff1  %0\n\t"
			"addi %0, 1\n\t"
			: "=r"(x)
			: "0"(x));
	return x;
}

/*
 * asm-generic/bitops/__ffs.h
 */
static inline int __ffs(unsigned int x)
{
	__asm__ __volatile__ (
			"brev %0\n\t"
			"ff1  %0\n\t"
			: "=r"(x)
			: "0"(x));
	return x;
}

/*
 * asm-generic/bitops/fls.h
 */
static inline int fls(int x)
{
	__asm__ __volatile__(
			"ff1 %0\n\t"
			:"=r" (x)
			:"0" (x));

	return (32 - x);
}

/*
 * asm-generic/bitops/__fls.h
 */
static inline int __fls(int x)
{
	return fls(x) - 1;
}

#include <asm-generic/bitops/ffz.h>
#include <asm-generic/bitops/fls64.h>
#include <asm-generic/bitops/find.h>

#ifndef _LINUX_BITOPS_H
#error only <linux/bitops.h> can be included directly
#endif

#include <asm-generic/bitops/sched.h>
#include <asm-generic/bitops/hweight.h>
#include <asm-generic/bitops/lock.h>

#include <asm-generic/bitops/atomic.h>

/*
 * bug fix, why only could use atomic!!!!
 */
#include <asm-generic/bitops/non-atomic.h>
#define __clear_bit(nr,vaddr) clear_bit(nr,vaddr)

#include <asm-generic/bitops/le.h>
#include <asm-generic/bitops/ext2-atomic.h>
#endif /* __ASM_CSKY_BITOPS_H */

