use libbpf_rs::skel::{OpenSkel, SkelBuilder};
use anyhow::Result;

mod bpf {
    include!("bpf/cheat_scanner.bpf.rs");
}

fn main() -> Result<()> {
    let skel_builder = bpf::CheatScannerSkel::builder();
    let open_skel = skel_builder.open()?;
    let mut skel = open_skel.load()?;
    skel.attach()?;

    println!("[Cortex-AC] Loaded & protecting CoD/Apex");

    let mut ring = skel.maps().events();

    loop {
        if let Ok(sample) = ring.poll(std::time::Duration::from_millis(100)) {
            let pid = u32::from_le_bytes(sample[..4].try_into().unwrap());
            let cheat_type = u32::from_le_bytes(sample[4..8].try_into().unwrap());

            println!("CHEATER DETECTED | PID: {} | Type: {}", pid, cheat_type);
            unsafe {
                libc::kill(pid as i32, libc::SIGKILL);
            }
        }
    }
}
