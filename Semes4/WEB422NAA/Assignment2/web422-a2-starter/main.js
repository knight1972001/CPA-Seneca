/*********************************************************************************
* WEB422 – Assignment 2
* I declare that this assignment is my own work in accordance with Seneca Academic Policy.
* No part of this assignment has been copied manually or electronically from any other source
* (including web sites) or distributed to other students.
*
* Name: Long Nguyen  Student ID: 155176183 Date: May 31th, 2021
* Heroku API Link: https://web422-assignment-lnguyen97.herokuapp.com/
*
********************************************************************************/

// -------------------
// variables
// -------------------
let restaurantData = [];
let currentRestaurant = {}
let page = 1;
const perPage = 5;
let map = null;
let testThis;
// -------------------
// lodash template functions
// -------------------
// - template code for displaying restaurant data in the <table>
let tableRows = _.template(`
    <% for(let i =0; i < data.length; i++) { %>
        <tr data-id= <%- data[i]._id %> >
            <td><%- data[i].name %></td>
            <td><%- data[i].cuisine%></td>
            <td><%- data[i].address.building %> <%- data[i].address.street %></td>
            <td><%- avg(data[i].grades) %></td>
        </tr>
    <% }  %>
`)

    
// - template code for displaying a selected restaurant's name and address 
let nameAddressUI = _.template(`    
    <h4><%- data.name %></h4>
    <p><%- data.building %> <%- data.street %></p>
    <p><%- data.borough %></p>
    <p><%- data.zipcode %></p>
`)

// - template code for displaying the ratings
let ratingsUI = _.template(`        
    <div class="panel panel-default">
    <% _.forEach(grades, function(grade){ %>
        <div class="panel-heading">Rating from <%- grade.date.substring(0,10) %> </div>
        <div class="panel-body">
            <p>Grade: <%- grade.grade %> </p>
            <p>Score: <%- grade.score %> </p>
        </div>
    <% }); %>
    </div>
`)

// -------------------
// other functions
// -------------------
// - calculates the average score of the restaurant
const avg = (grades) => {
    let total=0;
    for(let i=0;i<grades.length; i++){
        total+=grades[i].score;
    }
    let avg=total/grades.length;
    return avg.toFixed(2);
}

// - retrieves data from API and populates the <table> element rows
const loadRestaurantData = () => {
    fetch(`https://web422-assignment-lnguyen97.herokuapp.com/api/restaurants?page=${page}&perPage=${perPage}`).then((data)=>{
        return data.json();
    }).then((dataJson)=>{
        restaurantData=dataJson;
        $("#restaurant-table tbody").html(tableRows({data:restaurantData}));
        $("#curr-page").html(`Current page: ${page}`);
    }).catch((err)=>{
        console.log("Error: "+err);
    })
}

// -------------------
// This function will run when the HTML page finishes loading
// -------------------
$(document).ready(function() {    
    // write the code to:
    // - load restaurant data  
    loadRestaurantData();  
    // - implement the required event handlers     
    //      - clicking the NEXT button
    $("#btn-next").on("click",()=>{
        if(page==perPage){
            page=1;
        }else{
            page++;
        }
        loadRestaurantData();
    })
    //      - clicking the PREV button
    $("#btn-prev").on("click",()=>{
        if(page==1){
            page=perPage;
        }else{
            page--;
        }
        loadRestaurantData();
    });
    //      - clicking a row
    $("#restaurant-table tbody").on("click", "tr", function(){
        let clicked=$(this).attr("data-id");
        currentRestaurant=restaurantData.find(({_id})=>_id==clicked);

        if (map !== null) {
            map.remove()
        }
        
        map = new L.Map('leaflet', {
        center: [currentRestaurant.address.coord[1], currentRestaurant.address.coord[0]],
        zoom: 18,
        layers: [
        new L.TileLayer('https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png')
        ]
        });
        L.marker([currentRestaurant.address.coord[1], currentRestaurant.address.coord[0]]).addTo(map);

        let details={
            name: currentRestaurant.name,
            building: currentRestaurant.address.building,
            street: currentRestaurant.address.street,
            borough: currentRestaurant.borough,
            zipcode: currentRestaurant.address.zipcode
        }
        $("#restaurant-details").html(nameAddressUI({data:details}));
        $("#restaurant-details").css("background-color", "rgba(111, 255, 111, 0.164)");
        $("#ratings-container").html(ratingsUI({grades:currentRestaurant.grades}));
    })
})

