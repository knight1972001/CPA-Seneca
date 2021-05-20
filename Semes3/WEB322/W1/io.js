const readline = require('readline');

var rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question("Enter your name: ", function(answer) {
    console.log('Hello ' + answer);
    rl.close();
})

console.log("Hello again");