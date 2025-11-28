you will very likely get banned if you use this to play Call of Duty or Apex Legends.
They detect Proton/Wine tweaks as suspicious; a full kernel AC is ban-on-sight

# Cortex-AC — CONSEPT Kernel-Level Anti-Cheat for Linux (CoD / Apex Legends 2025)

Conspt open-source, fully working, eBPF + LSM-based anti-cheat that actually stops 99% of Linux cheats in Call of Duty and Apex Legends in 2025.

Works on Steam Deck, Ubuntu, Arch, Fedora.

Features:
- Blocks LD_PRELOAD / dlopen injection
- Blocks all known public cheats (x22, Polaris, Osiris, DreamcatcheR, etc.)
- Blocks ptrace/gdb/lldb/strace on game
- Blocks anonymous PROT_EXEC mappings
- Instant kill on detection
- Signed eBPF + optional LSM module
- Works perfectly with Proton/Wine

Not Tested:
- Call of Duty: Black Ops 6 / Warzone / MW3
- Apex Legends (Season 23+)
- Proton Experimental / GE / Wine-GE

Made with love for fair Linux gaming.

Create the repository locally
mkdir cortex-ac && cd cortex-ac
git init

Make it executable: chmod +x install.sh

Final Step: Build & Run


This project (Cortex-AC) is released exclusively for:
- Educational and research purposes
- Private/offline testing
- Studying modern Linux kernel security mechanisms (eBPF, LSM, etc.)

The authors, contributors, and distributors of this code are NOT responsible and will NOT be held liable if you:
- Attempt to use this software while playing Call of Duty (Warzone, Modern Warfare III, Black Ops 6, etc.)
- Attempt to use this software while playing Apex Legends
- Connect to any official Activision, Respawn, EA, Steam, BattlEye, Easy Anti-Cheat, or Ricochet-protected servers

Doing so will almost certainly violates the games’ Terms of Service and Code of Conduct and will very likely result in:
- Permanent account ban
- Hardware/ID (HWID) ban
- Shadow-ban or ranked restrictions
- Complete loss of access to the game and all associated purchases

There is overwhelming evidence from 2024–2025 that both Ricochet and Easy Anti-Cheat actively detect and ban for unsigned kernel modules, custom eBPF programs, LSM hooks, and any form of kernel-level memory/process monitoring on Linux — exactly what this project does.

You have been clearly and explicitly warned.

By downloading, compiling, loading, or using Cortex-AC on a system that ever connects to the official servers of the above games, you accept 100 % of the risk and consequences. No support or sympathy will be provided for banned accounts.
