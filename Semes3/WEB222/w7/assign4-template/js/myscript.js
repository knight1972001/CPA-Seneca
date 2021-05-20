// All you JavaScript code for assignment 4 should be in this file
window.onload = function() {
    menu();
    document.querySelector("#menu_1").onclick = byEnglish;
    document.querySelector("#menu_21").onclick = softBy100;
    document.querySelector("#menu_22").onclick = between1and2;
    document.querySelector("#menu_31").onclick = area1mil;
    document.querySelector("#menu_32").onclick = allAsia;
    document.querySelector("#menu_41").onclick = byEnglish;
    document.querySelector("#menu_42").onclick = byArabic;
    document.querySelector("#menu_43").onclick = byChinese;
    document.querySelector("#menu_44").onclick = byFranch;
    document.querySelector("#menu_45").onclick = byHindi;
    document.querySelector("#menu_46").onclick = byKorean;
    document.querySelector("#menu_47").onclick = byJapanese;
    document.querySelector("#menu_48").onclick = byRussian;
}

function allAsia() {
    let language = "English";
    let title = " - All countries in Asia";
    console.log(language);
    if (title !== null) {
        subtitle(title);
    }
    let table = document.querySelector("#outputTable");
    //check
    var tableBodycheck = table.querySelector("tbody");
    if (tableBodycheck) table.removeChild(tableBodycheck);

    let tableBody = document.createElement("tbody");

    for (var i = 0; i < countries.length; i++) {
        if (countries[i].Continent === "Asia") {
            let row = document.createElement("tr");

            row.appendChild(getImage(countries[i].Code));
            row.appendChild(getText(countries[i].Code)); {
                if (language === "English") {
                    row.appendChild(getText(countries[i].Name.English));
                }
                if (language === "Arabic") {
                    row.appendChild(getText(countries[i].Name.Arabic));
                }
                if (language === "Chinese") {
                    row.appendChild(getText(countries[i].Name.Chinese));
                }
                if (language === "Franch") {
                    row.appendChild(getText(countries[i].Name.Franch));
                }
                if (language === "Hindi") {
                    row.appendChild(getText(countries[i].Name.Hindi));
                }
                if (language === "Korean") {
                    row.appendChild(getText(countries[i].Name.Korean));
                }
                if (language === "Japanese") {
                    row.appendChild(getText(countries[i].Name.Japanese));
                }
                if (language === "Russian") {
                    row.appendChild(getText(countries[i].Name.Russian));
                }
            } // show by language
            row.appendChild(getText(countries[i].Continent));
            row.appendChild(getText(countries[i].AreaInKm2));
            row.appendChild(getText(countries[i].Population));
            row.appendChild(getText(countries[i].Capital));

            tableBody.appendChild(row);
        }
    }
    table.appendChild(tableBody);
}

function area1mil() {
    let language = "English";
    let num = "2";
    let title = " - Area greater than 1 million Km" + num.sup() + ", Americas";
    let a = document.querySelector("#subtitle")
    a.innerHTML = "List of Countries and Dependencies" + title

    let table = document.querySelector("#outputTable");
    //check
    var tableBodycheck = table.querySelector("tbody");
    if (tableBodycheck) table.removeChild(tableBodycheck);

    let tableBody = document.createElement("tbody");

    for (var i = 0; i < countries.length; i++) {
        if (countries[i].AreaInKm2 > 1000000 && countries[i].Continent == "Americas") {
            let row = document.createElement("tr");

            row.appendChild(getImage(countries[i].Code));
            row.appendChild(getText(countries[i].Code)); {
                if (language === "English") {
                    row.appendChild(getText(countries[i].Name.English));
                }
                if (language === "Arabic") {
                    row.appendChild(getText(countries[i].Name.Arabic));
                }
                if (language === "Chinese") {
                    row.appendChild(getText(countries[i].Name.Chinese));
                }
                if (language === "Franch") {
                    row.appendChild(getText(countries[i].Name.Franch));
                }
                if (language === "Hindi") {
                    row.appendChild(getText(countries[i].Name.Hindi));
                }
                if (language === "Korean") {
                    row.appendChild(getText(countries[i].Name.Korean));
                }
                if (language === "Japanese") {
                    row.appendChild(getText(countries[i].Name.Japanese));
                }
                if (language === "Russian") {
                    row.appendChild(getText(countries[i].Name.Russian));
                }
            } // show by language
            row.appendChild(getText(countries[i].Continent));
            row.appendChild(getText(countries[i].AreaInKm2));
            row.appendChild(getText(countries[i].Population));
            row.appendChild(getText(countries[i].Capital));

            tableBody.appendChild(row);
        }
    }
    table.appendChild(tableBody);
}

function between1and2() {
    let language = "English";
    let title = " - Population between 1 and 2 million";
    console.log(language);
    if (title !== null) {
        subtitle(title);
    }
    let table = document.querySelector("#outputTable");
    //check
    var tableBodycheck = table.querySelector("tbody");
    if (tableBodycheck) table.removeChild(tableBodycheck);

    let tableBody = document.createElement("tbody");

    for (var i = 0; i < countries.length; i++) {
        if (countries[i].Population >= 100000000 && countries[i].Population <= 200000000) {
            let row = document.createElement("tr");

            row.appendChild(getImage(countries[i].Code));
            row.appendChild(getText(countries[i].Code)); {
                if (language === "English") {
                    row.appendChild(getText(countries[i].Name.English));
                }
                if (language === "Arabic") {
                    row.appendChild(getText(countries[i].Name.Arabic));
                }
                if (language === "Chinese") {
                    row.appendChild(getText(countries[i].Name.Chinese));
                }
                if (language === "Franch") {
                    row.appendChild(getText(countries[i].Name.Franch));
                }
                if (language === "Hindi") {
                    row.appendChild(getText(countries[i].Name.Hindi));
                }
                if (language === "Korean") {
                    row.appendChild(getText(countries[i].Name.Korean));
                }
                if (language === "Japanese") {
                    row.appendChild(getText(countries[i].Name.Japanese));
                }
                if (language === "Russian") {
                    row.appendChild(getText(countries[i].Name.Russian));
                }
            } // show by language
            row.appendChild(getText(countries[i].Continent));
            row.appendChild(getText(countries[i].AreaInKm2));
            row.appendChild(getText(countries[i].Population));
            row.appendChild(getText(countries[i].Capital));

            tableBody.appendChild(row);
        }
    }
    table.appendChild(tableBody);
}

function byChinese() {
    createCountryList("Chinese", " - Country / Dep. Name in Chinese (中文)");
}

function byFranch() {
    createCountryList("Franch", " - Country / Dep. Name in Franch");
}

function byHindi() {
    createCountryList("Hindi", " - Country / Dep. Name in Hindi");
}

function byKorean() {
    createCountryList("Korean", " - Country / Dep. Name in Korean");
}

function byJapanese() {
    createCountryList("Japanese", " - Country / Dep. Name in Japanese");
}

function byRussian() {
    createCountryList("Russian", " - Country / Dep. Name in Russian");
}

function byArabic() {
    createCountryList("Arabic", " -  Country / Dep. Name in Arabic");
}

function byEnglish() {
    createCountryList("English", " - Country / Dep. Name in English");
}

function menu() {
    createCountryList("English", "");
}

function subtitle(title) {
    let a = document.querySelector("#subtitle")
    a.innerText = "List of Countries and Dependencies" + title
}

function softBy100() {
    let language = "English";
    let title = " - Population greater than 100 million";
    console.log(language);
    if (title !== null) {
        subtitle(title);
    }
    let table = document.querySelector("#outputTable");
    //check
    var tableBodycheck = table.querySelector("tbody");
    if (tableBodycheck) table.removeChild(tableBodycheck);

    let tableBody = document.createElement("tbody");

    for (var i = 0; i < countries.length; i++) {
        if (countries[i].Population > 100000000) {
            let row = document.createElement("tr");

            row.appendChild(getImage(countries[i].Code));
            row.appendChild(getText(countries[i].Code)); {
                if (language === "English") {
                    row.appendChild(getText(countries[i].Name.English));
                }
                if (language === "Arabic") {
                    row.appendChild(getText(countries[i].Name.Arabic));
                }
                if (language === "Chinese") {
                    row.appendChild(getText(countries[i].Name.Chinese));
                }
                if (language === "Franch") {
                    row.appendChild(getText(countries[i].Name.Franch));
                }
                if (language === "Hindi") {
                    row.appendChild(getText(countries[i].Name.Hindi));
                }
                if (language === "Korean") {
                    row.appendChild(getText(countries[i].Name.Korean));
                }
                if (language === "Japanese") {
                    row.appendChild(getText(countries[i].Name.Japanese));
                }
                if (language === "Russian") {
                    row.appendChild(getText(countries[i].Name.Russian));
                }
            } // show by language
            row.appendChild(getText(countries[i].Continent));
            row.appendChild(getText(countries[i].AreaInKm2));
            row.appendChild(getText(countries[i].Population));
            row.appendChild(getText(countries[i].Capital));

            tableBody.appendChild(row);
        }
    }
    table.appendChild(tableBody);
}

function createCountryList(language, title) {
    console.log(language);
    if (title !== null) {
        subtitle(title);
    }
    let table = document.querySelector("#outputTable");
    var tableBodycheck = table.querySelector("tbody");
    if (tableBodycheck) table.removeChild(tableBodycheck);

    let tableBody = document.createElement("tbody");
    for (var i = 0; i < countries.length; i++) {
        let row = document.createElement("tr");

        row.appendChild(getImage(countries[i].Code));
        row.appendChild(getText(countries[i].Code)); {
            if (language === "English") {
                row.appendChild(getText(countries[i].Name.English));
            }
            if (language === "Arabic") {
                row.appendChild(getText(countries[i].Name.Arabic));
            }
            if (language === "Chinese") {
                row.appendChild(getText(countries[i].Name.Chinese));
            }
            if (language === "Franch") {
                row.appendChild(getText(countries[i].Name.Franch));
            }
            if (language === "Hindi") {
                row.appendChild(getText(countries[i].Name.Hindi));
            }
            if (language === "Korean") {
                row.appendChild(getText(countries[i].Name.Korean));
            }
            if (language === "Japanese") {
                row.appendChild(getText(countries[i].Name.Japanese));
            }
            if (language === "Russian") {
                row.appendChild(getText(countries[i].Name.Russian));
            }
        } // show by language
        row.appendChild(getText(countries[i].Continent));
        row.appendChild(getText(countries[i].AreaInKm2));
        row.appendChild(getText(countries[i].Population));
        row.appendChild(getText(countries[i].Capital));

        tableBody.appendChild(row);
    }
    table.appendChild(tableBody);
}

function getImage(code) { 
    var http = new XMLHttpRequest();
    let linkImg = "flags/" + code.toLowerCase() + ".png";
    // check the image exists or not
    http.open('HEAD', linkImg, false);                
    http.send();
    if (http.status == 200) {
        let th = document.createElement("th");
        let img = document.createElement("img");
        img.src = "flags/" + code.toLowerCase() + ".png";
        th.appendChild(img);
        return th;
    } else {
        let th = document.createElement("th");
        let img = document.createElement("img");
        img.src = "https://www.countryflags.io/" + code + "/flat/64.png";
        img.width = 29;
        img.height = 30;
        th.appendChild(img);
        return th;
    }

}

function getText(text) {
    let th = document.createElement("th");
    let thText = document.createTextNode(text);
    th.appendChild(thText);
    return th;
}