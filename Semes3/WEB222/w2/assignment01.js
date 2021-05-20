/*********************************************************************************
* WEB222 – Assignment 01
* I declare that this assignment is my own work in accordance with Seneca Academic Policy. No part of
* this assignment has been copied manually or electronically from any other source (including web sites)
* or distributed to other students.
*
* Name: LONG NGUYEN      Student ID: 155176183       Date: May 29th 2020
*
********************************************************************************/

/*****************************
* Task 1
*****************************/
console.log("");
console.log("||***************************||");
console.log("|| Task 1: In a comment line ||");
console.log("||***************************||");
console.log("");

/*  a) Infinity: The value Infinity (positive infinity) is greater than any other number. Ex: console.log(12/0);
    b) Undefined: Any property that has not been assigned a value, assumes the undefined value. Ex: var a;
    c) NaN: means "Not a Number data type". Ex: var x="12A3" */

/*****************************
* Task 2
*****************************/
console.log("");
console.log("||********************||");
console.log("|| Task 2: Conversion ||");
console.log("||********************||");
console.log("");

//Bin to Decimal
var bin=1010;
var dec=parseInt(bin,2);
console.log(bin+" Binary to Decimal: "+dec);
//Hex to Decimal
var hex="AF";
var dec=parseInt(hex,16);
console.log(hex+" Hex to Decimal: "+dec);
//Octal to Decimal 
var Octal=713;
var dec=parseInt(Octal,8);
console.log(Octal+" Octal to Decimal: "+dec);

/*****************************
* Task 3
*****************************/
console.log("");
console.log("||*********************************************||");
console.log("|| Task 3: Convert Cel-Fah/Fah-Cel Temperature ||");
console.log("||*********************************************||");
console.log("");

var celsiusTemp=0;
var fahTemp=0;
//Celsius to Fahrenheit
celsiusTemp=37;
fahTemp=celsiusTemp * 9/5 + 32;
console.log(celsiusTemp + "°C is " + fahTemp +"°F");
//fahrenheit to Celsius
fahTemp=98.6;
celsiusTemp=(fahTemp - 32) * 5/9;
console.log(fahTemp + "°F is " + celsiusTemp +"°C");

/*****************************
* Task 4
*****************************/
// a) Declaration approach.
console.log("");
console.log("||**********************************||");
console.log("|| Task 4: Larger or Largest Number ||");
console.log("||**********************************||");
console.log("");
function largerNum(a,b)
{
    if (a==b)
    {return a;}
    else{
        if (a>b)
            {return a;}
                 else{return b;}
         }

}
console.log("The larger number of 4 and 6 is "+largerNum(4,6));
// b) Expression approach.
var greaterNum = function(a,b){
    if (a==b)
    {return a;}
    else{
        if (a>b) {return a;}
        else return b;
    }
}
console.log("The greater Number of 2 and 9 is "+greaterNum(2,9));

/*****************************
* Task 5
*****************************/
console.log("");
console.log("||*******************||");
console.log("|| Task 5: Evaluator ||");
console.log("||*******************||");
console.log("");
//a) 
function Evaluator(...number){
    var total=0, count=0;
    var avg=0;
    var i=0;
    for (i=0; i < number.length; i++)
    {
        //console.log("a= "+number[i]);
        total += number[i];
        count++;
    }
    avg=total/count;
    var condition=(avg >= 25) ? "true" : "false";
    //console.log(avg);
    console.log("Average greater than or equal to 25: "+condition);
}
//b) 
Evaluator(30, 40, 50);
Evaluator(20,30,10);
Evaluator(19,20,11);

/*****************************
* Task 6
*****************************/
console.log("");
console.log("||************************||");
console.log("|| Task 6: Show Multiples ||");
console.log("||************************||");
console.log("");
// a)

function showMultiples(num, numMultiples)
{
    var i=0;
    for (i=1;i<=numMultiples;i++)
    {
        console.log(num+" x " + i + " = "+num*i);
    }
    console.log("");
}
// b)
showMultiples(5,4);
showMultiples(2,5);
showMultiples(7,7);

/*****************************
* Task 7
*****************************/
console.log("||*******************************||");
console.log("|| Task 7: Closure/Self Invoking ||");
console.log("||*******************************||");
console.log("");

function Increament()
{
    var x=100;
    return function () 
    {   
        return (x =x+100);
    };
}
var sum=Increament();
sum();
sum();
console.log(sum());


