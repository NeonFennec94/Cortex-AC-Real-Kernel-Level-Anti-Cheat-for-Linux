#include "vmlinux.h"
#include <bpf/bpf_helpers.h>

struct {
    __uint(type, BPF_MAP_TYPE_HASH);
    __type(key, u32);
    __type(value, u64);
    __uint(max_entries, 8192);
} protected_pids SEC(".maps");

SEC("kprobe/ptrace_check")
int block_ptrace(struct pt_regs *ctx) {
    u64 id = bpf_get_current_pid_tgid();
    u32 pid = id >> 32;
    u32 tgid = id;

    if (pid == tgid) return 0; // same process

    u64 *protected = bpf_map_lookup_elem(&protected_pids, &tgid);
    if (protected) {
        bpf_printk("Cortex-AC: Blocked ptrace on protected game PID %d", tgid);
        return -EPERM;
    }
    return 0;
}

char LICENSE[] SEC("license") = "GPL";
