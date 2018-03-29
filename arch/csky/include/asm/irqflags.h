// SPDX-License-Identifier: GPL-2.0
// Copyright (C) 2018 Hangzhou C-SKY Microsystems co.,ltd.
#ifndef __ASM_CSKY_IRQFLAGS_H
#define __ASM_CSKY_IRQFLAGS_H
#include <abi/reg_ops.h>

static inline unsigned long arch_local_irq_save(void)
{
	unsigned long flags;
	flags = mfcr("psr");
	asm volatile("psrclr ie\n");
	return flags;
}
#define arch_local_irq_save arch_local_irq_save

static inline void arch_local_irq_enable(void)
{
	asm volatile("psrset ee, ie\n");
}
#define arch_local_irq_enable arch_local_irq_enable

static inline void arch_local_irq_disable(void)
{
	asm volatile("psrclr ie\n");
}
#define arch_local_irq_disable arch_local_irq_disable

static inline unsigned long arch_local_save_flags(void)
{
	return mfcr("psr");
}
#define arch_local_save_flags arch_local_save_flags

static inline void arch_local_irq_restore(unsigned long flags)
{
	mtcr("psr", flags);
}
#define arch_local_irq_restore arch_local_irq_restore

static inline int arch_irqs_disabled_flags(unsigned long flags)
{
	return !(flags & (1<<6));
}
#define arch_irqs_disabled_flags arch_irqs_disabled_flags

#include <asm-generic/irqflags.h>

#endif /* __ASM_CSKY_IRQFLAGS_H */
