// var message = {
//     writeMessage: function (msg){
//         localMessage=msg;
//     },
//     readMessage: function(){
//         console.log(localMessage + " from " + __filename);
//     }
// }

var message = require('./modules/message');

message.writeMessage("Hello World!");

message.readMessage();