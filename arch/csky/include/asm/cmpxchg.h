#ifndef __ASM_CSKY_CMPXCHG_H
#define __ASM_CSKY_CMPXCHG_H

#ifdef CONFIG_CPU_HAS_LDSTEX
#include <linux/bug.h>
#include <asm/barrier.h>

#define __xchg(new, ptr, size)					\
({								\
	__typeof__(ptr) __ptr = (ptr);				\
	__typeof__(new) __new = (new);				\
	__typeof__(*(ptr)) __ret;				\
	unsigned long tmp;					\
	switch (size) {						\
	case 4:							\
		asm volatile (					\
		"1:	ldex.w		%0, (%3) \n"		\
		"	mov		%1, %2   \n"		\
		"	stex.w		%1, (%3) \n"		\
		"	bez		%1, 1b   \n"		\
			: "=&r" (__ret), "=&r" (tmp)		\
			: "r" (__new), "r"(__ptr)		\
			: "memory");				\
		break;						\
	default:						\
		BUILD_BUG();					\
	}							\
	__ret;							\
})

#define xchg(ptr, x)	(__xchg((x), (ptr), sizeof(*(ptr))))

#define __cmpxchg(ptr, old, new, size)				\
({								\
	__typeof__(ptr) __ptr = (ptr);				\
	__typeof__(new) __new = (new);				\
	__typeof__(new) __tmp;					\
	__typeof__(old) __old = (old);				\
	__typeof__(*(ptr)) __ret;				\
	switch (size) {						\
	case 4:							\
		asm volatile (					\
		"1:	ldex.w		%0, (%3) \n"		\
		"	cmpne		%0, %4   \n"		\
		"	bt		2f       \n"		\
		"	mov		%1, %2   \n"		\
		"	stex.w		%1, (%3) \n"		\
		"	bez		%1, 1b   \n"		\
		"2:				 \n"		\
			: "=&r" (__ret), "=&r" (__tmp)		\
			: "r" (__new), "r"(__ptr), "r"(__old)	\
			: "memory");				\
		break;						\
	default:						\
		BUILD_BUG();					\
	}							\
	__ret;							\
})

#define cmpxchg(ptr, o, n) \
	(__cmpxchg((ptr), (o), (n), sizeof(*(ptr))))
#else
#include <asm-generic/cmpxchg.h>
#endif

#endif /* __ASM_CSKY_CMPXCHG_H */
