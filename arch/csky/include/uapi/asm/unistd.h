#include <asm-generic/unistd.h>

#define __NR_set_thread_area	(__NR_arch_specific_syscall + 0)
__SYSCALL(__NR_set_thread_area, sys_set_thread_area)
#define __NR_ipc		(__NR_arch_specific_syscall + 1)
__SYSCALL(__NR_ipc, sys_ipc)
#define __NR_socketcall		(__NR_arch_specific_syscall + 2)
__SYSCALL(__NR_socketcall, sys_socketcall)
#define __NR_ugetrlimit		(__NR_arch_specific_syscall + 3)
__SYSCALL(__NR_ugetrlimit, sys_getrlimit)
#define __NR_cacheflush		(__NR_arch_specific_syscall + 4)
__SYSCALL(__NR_cacheflush, sys_cacheflush)
#define __NR_sysfs		(__NR_arch_specific_syscall + 5)
__SYSCALL(__NR_sysfs, sys_sysfs)

#define __NR_setgroups32	__NR_setgroups
#define __NR_getgid32		__NR_getgid
#define __NR_getgroups32	__NR_getgroups
#define __NR_setuid32		__NR_setuid
#define __NR_setgid32		__NR_setgid
#define __NR_getresgid32	__NR_getresgid
#define __NR_chown32		__NR_chown
#define __NR_setfsuid32		__NR_setfsuid
#define __NR_setfsgid32		__NR_setfsgid
#define __NR_lchown32		__NR_lchown
#define __NR_fchown32		__NR_fchown
#define __NR_geteuid32		__NR_geteuid
#define __NR_getegid32		__NR_getegid
#define __NR_getresuid32	__NR_getresuid
#define __NR_setresuid32	__NR_setresuid
#define __NR_setresgid32	__NR_setresgid
#define __NR_setreuid32		__NR_setreuid
#define __NR_setregid32		__NR_setregid
#define __NR__llseek		__NR_llseek
