/************************************************************************************
* WEB322 – Assignment 1 (Winter 2021)
* I declare that this assignment is my own work in accordance with Seneca Academic
* Policy. No part of this assignment has been copied manually or electronically from
* any other source (including web sites) or distributed to other students.
*
* Name:			LONG NGUYEN
* Student ID:	155176183
* Course:		WEB322NCC
*
************************************************************************************/

var express = require('express');
var path = require('path');
var app = express();


var HTTP_PORT = process.env.HTTP_PORT || 8080;

function onHttpStart(){
    console.log("Express http start on port " + HTTP_PORT);
}

//setup http server to listen on HTTP port
app.listen(HTTP_PORT, onHttpStart);

app.use(express.static("static"));
//setup route url path
app.get("/", function(req, res){
    res.sendFile(path.join(__dirname, "/views/index.html"));
});

//setup another route -> About route
app.get("/about", function(req, res){
    res.sendFile(path.join(__dirname, "/views/about.html"));
});

app.get("/menu", function(req, res){
    res.sendFile(path.join(__dirname, "/views/menu.html"));
});

app.get("/login_register", function(req, res){
    res.sendFile(path.join(__dirname, "/views/login_register.html"));
});

app.get("/redeem", function(req, res){
    res.sendFile(path.join(__dirname, "/views/redeem.html"));
});

app.use((req, res) =>{
    res.status(404).sendFile(path.join(__dirname, "/views/404.html"));;
});

app.use(function (err, req, res, next){
    console.error(err.stack)
    res.status(500).send("Something broke!");
});
