extern mod extra;
use extra::comm::DuplexStream;

fn plus_one(channel: &DuplexStream<int, int>) {
    let mut value: int;
    loop {
        value = channel.recv();
        channel.send(value + 1);
    }
}

fn main() {
    let (from_child, to_child) = DuplexStream();

    do spawn {
        plus_one(&to_child);
    };

    from_child.send(22);

    let twenty_three = from_child.recv();
    println(twenty_three.to_str());
}
