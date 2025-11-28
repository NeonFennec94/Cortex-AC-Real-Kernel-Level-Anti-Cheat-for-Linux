#!/bin/bash
set -e

echo "Building Cortex-AC..."
make all

echo "Loading anti-cheat..."
sudo make load

echo ""
echo "Cortex-AC is now ACTIVE"
echo "All Call of Duty & Apex Legends processes are protected from cheats."
echo "Cheaters will be instantly killed."
