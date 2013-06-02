// create server
// and callback function
var http = require('http');
var fs = require('fs');

http.createServer(function(req, res) {
    var query = require('url').parse(req.url).query;
    console.log(query);
    file = require('querystring').parse(query).file;

    // content header
    res.writeHead(200, {'Content-Type': 'text/plain'});

    // increment global, write to client
    for (var i = 0; i < 100; i++) {
        res.write(i + '\n');
    }

    // open and read in the file contents
    var data = fs.readFileSync(file, 'utf8');
    res.write(data);
    res.end();
}).listen('/tmp/node-server-sock');
