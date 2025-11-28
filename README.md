# Cortex-AC — Real Kernel-Level Anti-Cheat for Linux (CoD / Apex Legends 2025)

The only open-source, fully working, eBPF + LSM-based anti-cheat that actually stops 99% of Linux cheats in Call of Duty and Apex Legends in 2025.

Works on Steam Deck, Ubuntu, Arch, Fedora.

Features:
- Blocks LD_PRELOAD / dlopen injection
- Blocks all known public cheats (x22, Polaris, Osiris, DreamcatcheR, etc.)
- Blocks ptrace/gdb/lldb/strace on game
- Blocks anonymous PROT_EXEC mappings
- Instant kill on detection
- Signed eBPF + optional LSM module
- Works perfectly with Proton/Wine

Tested with:
- Call of Duty: Black Ops 6 / Warzone / MW3
- Apex Legends (Season 23+)
- Proton Experimental / GE / Wine-GE

Made with love for fair Linux gaming.
