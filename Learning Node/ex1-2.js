// load http module
var http = require('http');
var fs = require('fs');

// create http server
http.createServer(function (req, res) {

    // open and read in helloworld.js
    fs.readFile('ex1-1.js', 'utf8', function(err, data) {

        // content header
        res.writeHead(200, {'content-type': 'text/plain'});
        if (err)
            res.write('Could not find or open the file for reading\n');
        else
            // if no error, write JS file to client
            res.write(data);
        res.end();
    });
}).listen(8124, function() { console.log('bound to port 8124');});

console.log('Server running on 8124');
