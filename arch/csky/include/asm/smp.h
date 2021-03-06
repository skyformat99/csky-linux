#ifndef __ASM_CSKY_SMP_H
#define __ASM_CSKY_SMP_H

#include <linux/cpumask.h>
#include <linux/irqreturn.h>
#include <linux/threads.h>

#ifdef CONFIG_SMP

void __init setup_smp(void);

void __init setup_smp_ipi(void);

void __init enable_smp_ipi(void);

void arch_send_call_function_ipi_mask(struct cpumask *mask);

void arch_send_call_function_single_ipi(int cpu);

void __init set_send_ipi(void (*func)(const unsigned long *, unsigned long));

#define raw_smp_processor_id()	(current_thread_info()->cpu)

#endif /* CONFIG_SMP */

#endif /* __ASM_CSKY_SMP_H */
