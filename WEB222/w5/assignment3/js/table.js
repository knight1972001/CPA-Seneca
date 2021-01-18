// Data for the "HTML Tables" Page

var users = [
    {first_name: "Kaitlin", last_name: "Burns", age: 23, email: "kburns99753@usermail.com"},
    {first_name: "Joshua", last_name: "Feir", age: 31, email: "josh319726@usermail.com"},
    {first_name: "Stephen", last_name: "Shaw", age: 28, email: "steve.shaw47628@usermail.com"},
    {first_name: "Timothy", last_name: "McAlpine", age: 37, email: "Timbo72469@usermail.com"},
    {first_name: "Sarah", last_name: "Connor", age: 19, email: "SarahC6320@usermail.com"}
];



window.onload = function()
{
    var userList=document.querySelector("#userList");
    var user="<table style=\"border:1px solid black\">";
    user+="<tr><th style=\"border:1px solid;\">First Name</th><th style=\"border:1px solid;\">Last Name</th><th style=\"border:1px solid;\">Age</th><th style=\"border:1px solid;\">Email</th></tr>";
    
    for(var i=0;i<users.length;i++)
    {
        user+="<tr>";
        user+="<td style=\"border:1px solid black\">"+ users[i].first_name +"</td>";
        user+="<td style=\"border:1px solid black\">"+users[i].last_name +"</td>";
        user+="<td style=\"border:1px solid black\">"+users[i].age +"</td>";
        user+="<td style=\"border:1px solid black\"><a href=\"mailto:" + users[i].email +"\">"+users[i].email +"<\/a><\/td>";
        user+="</tr>";
    }
    user+="</table>";

    userList.innerHTML = user;

}