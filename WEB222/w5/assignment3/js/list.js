// Data for the "HTML Lists" Page

var fruits = [ "Apples","Oranges","Pears","Grapes","Pineapples","Mangos" ];

window.onload = function()
{
    var list = document.querySelector("#fruit");

    var newList = "<ol>";

    for(var i = 0; i < fruits.length; i++)
    {
        newList += "<li>" + fruits[i] + "</li>";
    }

    newList += "</ol>";

    list.innerHTML = newList;


var directory = [
    {type: "file", name: "file1.txt"},
    {type: "file", name: "file2.txt"},
    {type: "directory", name: "HTML Files", files: [{type: "file", name: "file1.html"},{type: "file", name: "file2.html"}]},
    {type: "file", name: "file3.txt"},
    {type: "directory", name: "JavaScript Files", files: [{type: "file", name: "file1.js"},{type: "file", name: "file2.js"},{type: "file", name: "file3.js"}]}
];




    var folder=document.querySelector("#directory");

    var item= "<ul>";

    for (var i=0; i<directory.length; i++)
    {
        if(directory[i].type=="file")
        {
            item += "<li>" + directory[i].name + "</li>";
        }else{
            item+="<li>" + directory[i].name +"<ul>";
            for (var a=0; a<directory[i].files.length; a++)
            {
                item+="<li>"+directory[i].files[a].name +"</li>";
            }
            item+="</ul>" + "</li>";
        }
    }
    item += "</ul>";

    folder.innerHTML = item;
}

