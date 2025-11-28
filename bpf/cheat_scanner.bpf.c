#include "vmlinux.h"
#include <bpf/bpf_helpers.h>
#include <bpf/bpf_tracing.h>

struct event {
    u32 pid;
    u32 type;
};

struct {
    __uint(type, BPF_MAP_TYPE_RINGBUF);
    __uint(max_entries, 1 << 24);
} events SEC(".maps");

struct {
    __uint(type, BPF_MAP_TYPE_HASH);
    __type(key, u32);
    __type(value, u64);
    __uint(max_entries, 8192);
} protected_pids SEC(".maps");

static __always_inline bool is_protected(u32 pid) {
    u64 *val = bpf_map_lookup_elem(&protected_pids, &pid);
    return val != NULL;
}

SEC("tracepoint/syscalls/sys_enter_execve")
int handle_execve(struct trace_event_raw_sys_enter *ctx) {
    char comm[16];
    bpf_get_current_comm(&comm, sizeof(comm));

    if (__builtin_memcmp(comm, "ModernWarfare", 13) == 0 ||
        __builtin_memcmp(comm, "BlackOps6", 9) == 0 ||
        __builtin_memcmp(comm, "r5apex.exe", 10) == 0 ||
        __builtin_memcmp(comm, "Apex Legends", 12) == 0) {

        u32 pid = bpf_get_current_pid_tgid() >> 32;
        u64 val = 1;
        bpf_map_update_elem(&protected_pids, &pid, &val, BPF_ANY);
        bpf_printk("Cortex-AC: Protected game started PID %d", pid);
    }
    return 0;
}

SEC("kprobe/security_mmap_file")
int BPF_KPROBE(mmap_check, struct file *file, unsigned long prot, unsigned long flags) {
    u32 pid = bpf_get_current_pid_tgid() >> 32;
    if (!is_protected(pid)) return 0;

    if ((prot & PROT_EXEC) && !file && !(flags & MAP_DENYWRITE)) {
        struct event *e = bpf_ringbuf_reserve(&events, sizeof(*e), 0);
        if (e) {
            e->pid = pid;
            e->type = 1; // ANON_EXEC injection
            bpf_ringbuf_submit(e, 0);
        }
        return -EPERM;
    }

    return 0;
}

char LICENSE[] SEC("license") = "GPL";
