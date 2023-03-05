use std::env;
use std::fs::File;
use std::io::Read;

fn main() -> std::io::Result<()> {
    let file = env::args().nth(1).unwrap_or(String::from("/dev/stdin"));
    let mut ifs = File::open(file)?;
    let mut buf = Vec::new();
    let read_size = ifs.read_to_end(&mut buf)?;
    println!("{read_size}");
    Ok(())
}
