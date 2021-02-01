    function all(){
        cakeButton();
        document.querySelector('#pizza').onclick = pizzaButton;
        document.querySelector('#cake').onclick = cakeButton;
    }

function pizzaButton(){
    document.querySelector('#pizza').style.color='white';
    document.querySelector('#pizza').style.backgroundColor = '#0b4652';
    document.querySelector('#cake').style.color='#0b4652';
    document.querySelector('#cake').style.backgroundColor = 'rgb(0,0,0,0)';
    var topContent = document.querySelector("#topContent");
    topContent.innerHTML='';
    for(let i=0;i<3;i++){
        let divTopCard=document.createElement("div");
        divTopCard.setAttribute("id","topCard");
        
        let img=document.createElement("img");
        img.setAttribute("src", pizza[i].img);
        let title=document.createElement("h2");
        title.textContent=pizza[i].title;
        let des=document.createElement("p");
        des.textContent=pizza[i].des;
        let button=document.createElement("button");
        button.textContent=pizza[i].price;
        
        divTopCard.appendChild(img);
        divTopCard.appendChild(title);
        divTopCard.appendChild(des)
        divTopCard.appendChild(button);

        topContent.appendChild(divTopCard);
    }
}

function cakeButton(){
    document.querySelector('#cake').style.color='white';
    document.querySelector('#cake').style.backgroundColor = '#0b4652';
    document.querySelector('#pizza').style.color='#0b4652';
    document.querySelector('#pizza').style.backgroundColor = 'rgb(0,0,0,0)';
    var topContent = document.querySelector("#topContent");
    topContent.innerHTML='';
    for(let i=0;i<3;i++){
        let divTopCard=document.createElement("div");
        divTopCard.setAttribute("id","topCard");
        
        let img=document.createElement("img");
        img.setAttribute("src", cake[i].img);
        let title=document.createElement("h2");
        title.textContent=cake[i].title;
        let des=document.createElement("p");
        des.textContent=cake[i].des;
        let button=document.createElement("button");
        button.textContent=cake[i].price;
        
        divTopCard.appendChild(img);
        divTopCard.appendChild(title);
        divTopCard.appendChild(des)
        divTopCard.appendChild(button);

        topContent.appendChild(divTopCard);
    }
}