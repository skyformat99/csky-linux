// SPDX-License-Identifier: GPL-2.0
// Copyright (C) 2018 Hangzhou C-SKY Microsystems co.,ltd.
#ifndef __ASM_CSKY_TLB_H
#define __ASM_CSKY_TLB_H

#include <asm/cacheflush.h>
#include <abi/tlb.h>

#define tlb_end_vma(tlb, vma) \
	do { \
		if (!tlb->fullmm) \
			flush_tlb_range(vma, vma->vm_start, vma->vm_end); \
	}  while (0)

#define tlb_flush(tlb) flush_tlb_mm((tlb)->mm)

#include <asm-generic/tlb.h>

#endif /* __ASM_CSKY_TLB_H */
