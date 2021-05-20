// All you JavaScript code for assignment 4 should be in this file

window.onload = function() {

    createCountryList();
    document.querySelector("#menu_1").onclick = createCountryList;
    document.querySelector("#menu_21").onclick = softBy100;
    document.querySelector("#menu_22").onclick = createTable12;
    document.querySelector("#menu_31").onclick = createTableAmericas;
    document.querySelector("#menu_32").onclick = createTableAsia;
    document.querySelector("#menu_41").onclick = createCountryList;
    document.querySelector("#menu_42").onclick = createTableArabic;
}

//change subtitle function


function changeSubtitle(text) {
    document.querySelector("#subtitle").innerHTML = text;
}

//create table funtion
function createCountryList() {

    changeSubtitle("List of Countries and Dependencies");
    //reference to table
    var table = document.querySelector("#outputTable");

    // revove existing Body element
    var tblExistingBody = table.querySelector("tbody");
    if (tblExistingBody) table.removeChild(tblExistingBody);

    //create table body
    var tblBody = document.createElement("tbody");

    //create table rows
    for (var i = 0; i < countries.length; i++) {

        var row = document.createElement("tr");

        row.appendChild(getTdImage(countries[i].Code));
        row.appendChild(getTdElement(countries[i].Code));
        row.appendChild(getTdElement(countries[i].Name.English));
        row.appendChild(getTdElement(countries[i].Continent));
        row.appendChild(getTdElement(countries[i].AreaInKm2));
        row.appendChild(getTdElement(countries[i].Population));
        row.appendChild(getTdElement(countries[i].Capital));

        //append row
        tblBody.appendChild(row);
    }


    //append body
    table.appendChild(tblBody);

}


//create td element function
function getTdElement(text) {
    var cell = document.createElement("td");
    var cellText = document.createTextNode(text);
    cell.appendChild(cellText);
    return cell;
}

//create td element with image
function getTdImage(countryCode) {
    var cell = document.createElement("td");
    var img = document.createElement("img");
    img.src = "flags/" + countryCode + ".png";
    cell.appendChild(img);
    return cell;
}

//create table100 function
function softBy100() {
    changeSubtitle("List of Countries and Dependencies - Population greater than 100 million");
    //reference to table
    var table = document.querySelector("#outputTable");

    // revove existing Body element
    var tblExistBody = table.querySelector("tbody");
    if (tblExistBody) table.removeChild(tblExistBody);

    //create table body
    var tblBody = document.createElement("tbody");

    //create table rows
    for (var i = 0; i < countries.length; i++) {

        if (countries[i].Population > 100000000) {
            var row = document.createElement("tr");

            row.appendChild(getTdImage(countries[i].Code));
            row.appendChild(getTdElement(countries[i].Code));
            row.appendChild(getTdElement(countries[i].Name.English));
            row.appendChild(getTdElement(countries[i].Continent));
            row.appendChild(getTdElement(countries[i].AreaInKm2));
            row.appendChild(getTdElement(countries[i].Population));
            row.appendChild(getTdElement(countries[i].Capital));

            //append row
            tblBody.appendChild(row);
        }
    }
    //append body
    table.appendChild(tblBody);
}

//createTable12 function
function createTable12() {
    changeSubtitle("List of Countries and Dependencies - Population between 1 and 2 million");
    //reference to table
    var table = document.querySelector("#outputTable");

    // revove existing Body element
    var tblExistBody = table.querySelector("tbody");
    if (tblExistBody) table.removeChild(tblExistBody);

    //create table body
    var tblBody = document.createElement("tbody");

    //create table rows
    for (var i = 0; i < countries.length; i++) {

        if (countries[i].Population >= 1000000 && countries[i].Population <= 2000000) {
            var row = document.createElement("tr");

            row.appendChild(getTdImage(countries[i].Code));
            row.appendChild(getTdElement(countries[i].Code));
            row.appendChild(getTdElement(countries[i].Name.English));
            row.appendChild(getTdElement(countries[i].Continent));
            row.appendChild(getTdElement(countries[i].AreaInKm2));
            row.appendChild(getTdElement(countries[i].Population));
            row.appendChild(getTdElement(countries[i].Capital));

            //append row
            tblBody.appendChild(row);
        }
    }
    //append body
    table.appendChild(tblBody);
}

//createTableAmericas

function createTableAmericas() {

    changeSubtitle("List of Countries and Dependencies - Area greater than 1 million Km2, Americas");
    //reference to table
    var table = document.querySelector("#outputTable");

    // revove existing Body element
    var tblExistBody = table.querySelector("tbody");
    if (tblExistBody) table.removeChild(tblExistBody);

    //create table body
    var tblBody = document.createElement("tbody");

    //create table rows
    for (var i = 0; i < countries.length; i++) {

        if (countries[i].AreaInKm2 > 1000000 && countries[i].Continent == "Americas") {
            var row = document.createElement("tr");

            row.appendChild(getTdImage(countries[i].Code));
            row.appendChild(getTdElement(countries[i].Code));
            row.appendChild(getTdElement(countries[i].Name.English));
            row.appendChild(getTdElement(countries[i].Continent));
            row.appendChild(getTdElement(countries[i].AreaInKm2));
            row.appendChild(getTdElement(countries[i].Population));
            row.appendChild(getTdElement(countries[i].Capital));

            //append row
            tblBody.appendChild(row);
        }
    }
    //append body
    table.appendChild(tblBody);
}

//createTableAsia function

function createTableAsia() {
    changeSubtitle("List of Countries and Dependencies - All countries in Asia");
    //reference to table
    var table = document.querySelector("#outputTable");

    // revove existing Body element
    var tblExistBody = table.querySelector("tbody");
    if (tblExistBody) table.removeChild(tblExistBody);

    //create table body
    var tblBody = document.createElement("tbody");

    //create table rows
    for (var i = 0; i < countries.length; i++) {

        if (countries[i].Continent == "Asia") {
            var row = document.createElement("tr");

            row.appendChild(getTdImage(countries[i].Code));
            row.appendChild(getTdElement(countries[i].Code));
            row.appendChild(getTdElement(countries[i].Name.English));
            row.appendChild(getTdElement(countries[i].Continent));
            row.appendChild(getTdElement(countries[i].AreaInKm2));
            row.appendChild(getTdElement(countries[i].Population));
            row.appendChild(getTdElement(countries[i].Capital));

            //append row
            tblBody.appendChild(row);
        }
    }
    //append body
    table.appendChild(tblBody);
}

//createTableArabic function

function createTableArabic() {

    changeSubtitle("List of Countries and Dependencies – Country / Dep. Name in Arabic");
    //reference to table
    var table = document.querySelector("#outputTable");

    // revove existing Body element
    var tblExistBody = table.querySelector("tbody");
    if (tblExistBody) table.removeChild(tblExistBody);

    //create table body
    var tblBody = document.createElement("tbody");

    //create table rows
    for (var i = 0; i < countries.length; i++) {

        var row = document.createElement("tr");

        row.appendChild(getTdImage(countries[i].Code));
        row.appendChild(getTdElement(countries[i].Code));
        row.appendChild(getTdElement(countries[i].Name.Arabic));
        row.appendChild(getTdElement(countries[i].Continent));
        row.appendChild(getTdElement(countries[i].AreaInKm2));
        row.appendChild(getTdElement(countries[i].Population));
        row.appendChild(getTdElement(countries[i].Capital));

        //append row
        tblBody.appendChild(row);
    }


    //append body
    table.appendChild(tblBody);
}