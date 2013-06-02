var net = require('net');

var client = new net.Socket();
client.setEncoding('utf8');

// connec to server
client.connect('8124', 'localhost', function() {
    console.log('connected to server');
    client.write('Who needs a browser to communicate?');
});

// prepare for input from the terminal
process.stdin.resume();

// when receive data, sent to server
process.stdin.on('data', function(data) {
    client.write(data);
});

// when recieve data back, print to console
client.on('data', function(data) {
    console.log(data);
});

// when server closed
client.on('close', function() {
    console.log('connection is closed');
});
