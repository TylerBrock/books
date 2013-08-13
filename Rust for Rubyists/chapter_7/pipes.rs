//use core::pipes::{stream, Port, Chan};

fn main() {
    let (port, chan): (Port<int>, Chan<int>) = stream();

    do spawn {
        chan.send(10);
    }

    println(port.recv().to_str());
}
