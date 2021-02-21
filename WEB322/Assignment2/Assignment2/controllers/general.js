const express=require('express');
const router=express.Router();
const database = require('../models/database');


router.get("/", function(req, res){
    res.render("general/index",{
        hero: database.getHeroContent(), 
        cake: database.getAllCake(), 
        pizza: database.getAllPizza()
    });
});

//setup another route -> About route
router.get("/about", function(req, res){
    res.render("general/about");
});

router.get("/login_register", function(req, res){
    res.render("general/login_register");
});


module.exports=router;
