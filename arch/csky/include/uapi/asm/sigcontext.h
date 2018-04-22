// SPDX-License-Identifier: GPL-2.0
// Copyright (C) 2018 Hangzhou C-SKY Microsystems co.,ltd.
#ifndef __ASM_CSKY_SIGCONTEXT_H
#define __ASM_CSKY_SIGCONTEXT_H

#include <asm/ptrace.h>

struct sigcontext {
	unsigned long	sc_mask;
	struct pt_regs	sc_pt_regs;
	struct user_fp	sc_user_fp;
};

#endif /* __ASM_CSKY_SIGCONTEXT_H */
