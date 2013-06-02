var http = require('http');

// The url we want, plus the path and options we need
var options = {
    host: 'localhost',
    port: 8124,
    path: '/?file=secondary',
    method: 'GET',
    agent: false
};

var processPublicTimeline = function(response) {
    // finished? ok, write the data to a file
    console.log('finished request');
};

for (var i = 0; i < 2000; i++) {
    // make the request, and then end it, to close the connection
    http.request(options, processPublicTimeline).on('error', function(error){ console.log(error);} ).end();
};
