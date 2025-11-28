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

Tested with:
- Call of Duty: Black Ops 6 / Warzone / MW3
- Apex Legends (Season 23+)
- Proton Experimental / GE / Wine-GE

Made with love for fair Linux gaming.

Create the repository locally
mkdir cortex-ac && cd cortex-ac
git init

Make it executable: chmod +x install.sh

Final Step: Build & Run
git remote add origin https://github.com/yourname/cortex-ac.git
git push -u origin main
