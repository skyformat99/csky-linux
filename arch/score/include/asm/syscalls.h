/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _ASM_SCORE_SYSCALLS_H
#define _ASM_SCORE_SYSCALLS_H

asmlinkage long score_rt_sigreturn(struct pt_regs *regs);

#include <asm-generic/syscalls.h>

#endif /* _ASM_SCORE_SYSCALLS_H */