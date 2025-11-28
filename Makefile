all: bpf daemon lsm

bpf:
	clang -O2 -target bpf -g -c bpf/cheat_scanner.bpf.c -o bpf/cheat_scanner.bpf.o
	clang -O2 -target bpf -g -c bpf/ptrace_blocker.bpf.c -o bpf/ptrace_blocker.bpf.o

daemon:
	cd daemon && cargo build --release

lsm:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD)/kernel_lsm modules

clean:
	rm -f bpf/*.o
	cd daemon && cargo clean
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD)/kernel_lsm clean

load: all
	sudo bpftool prog load bpf/cheat_scanner.bpf.o /sys/fs/bpf/cheat_scanner
	sudo bpftool prog load bpf/ptrace_blocker.bpf.o /sys/fs/bpf/ptrace_blocker
	sudo insmod kernel_lsm/cortex_ac.ko

unload:
	sudo rm /sys/fs/bpf/cheat_scanner || true
	sudo rm /sys/fs/bpf/ptrace_blocker || true
	sudo rmmod cortex_ac || true
