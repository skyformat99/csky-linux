#include <linux/syscalls.h>

SYSCALL_DEFINE1(set_thread_area, unsigned long, addr)
{
	struct thread_info *ti = task_thread_info(current);

#if defined(CONFIG_CPU_CSKYV2)
	struct pt_regs *reg = current_pt_regs();
	reg->exregs[15] = (long)addr;
#endif
	ti->tp_value = addr;

	return 0;
}

SYSCALL_DEFINE6(mmap2,
	unsigned long, addr,
	unsigned long, len,
	unsigned long, prot,
	unsigned long, flags,
	unsigned long, fd,
	off_t, offset)
{
	if (unlikely(offset & (~PAGE_MASK >> 12)))
		return -EINVAL;
	return sys_mmap_pgoff(addr, len, prot, flags, fd,
		offset >> (PAGE_SHIFT - 12));
}

struct mmap_arg_struct {
	unsigned long addr;
	unsigned long len;
	unsigned long prot;
	unsigned long flags;
	unsigned long fd;
	unsigned long offset;
};

SYSCALL_DEFINE1(mmap,
	struct mmap_arg_struct *, arg)
{
	struct mmap_arg_struct a;

	if (copy_from_user(&a, arg, sizeof(a)))
		return -EINVAL;

	if (unlikely(a.offset & ~PAGE_MASK))
		return -EINVAL;

	return sys_mmap_pgoff(a.addr, a.len, a.prot, a.flags, a.fd, a.offset >> PAGE_SHIFT);
}

