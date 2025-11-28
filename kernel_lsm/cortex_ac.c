#include <linux/module.h>
#include <linux/security.h>
#include <linux/binfmts.h>

static int cortex_ptrace_access_check(struct task_struct *child, unsigned int mode) {
    char comm[16];
    __builtin_memcpy(comm, child->comm, 16);

    if (strncmp(comm, "ModernWarfare", 13) == 0 ||
        strncmp(comm, "BlackOps6", 9) == 0 ||
        strncmp(comm, "r5apex.exe", 10) == 0) {
        return -EPERM;
    }
    return 0;
}

static struct security_hook_list cortex_hooks[] __lsm_ro_after_init = {
    LSM_HOOK_INIT(ptrace_access_check, cortex_ptrace_access_check),
};

static int __init cortex_init(void) {
    return security_add_hooks(cortex_hooks, ARRAY_SIZE(cortex_hooks), "cortex_ac");
}

module_init(cortex_init);
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Cortex Anti-Cheat LSM");
