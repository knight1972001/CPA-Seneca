/* Add any JavaScript you need to this file. */

function startTime() {
    var today = new Date();
    var h = today.getHours();
    var m = today.getMinutes();
    var s = today.getSeconds();
    m = checkTime(m);
    s = checkTime(s);
    document.getElementById('txt').innerHTML = 'Time: ' + h + ':' + m + ':' + s;
    setTimeout(startTime, 500);
}

function checkTime(i) {
    if (i < 10) {
        i = '0' + i;
    }
    return i;
}

setTimeout(() => {
    document.querySelector('.overlay').style.display = 'none';
}, 2000);

//clock
var c = 0;
var min = 0;

function myCounter() {
    if (c < 60 && min === 0) {
        document.getElementById('demo').innerHTML = 'You accessed website: ' + ++c + 's';
    } else {
        if (c < 60) {
            document.getElementById('demo').innerHTML = 'You accessed website: ' + min + 'm' + ++c + 's';
        } else {
            c = 0;
            min++;
            document.getElementById('demo').innerHTML = 'You accessed website: ' + min + 'm' + ++c + 's';
        }
    }
}

function allEffect() {
    startTime();
    setInterval(myCounter, 1000);
    document.querySelector('#ShowMousse').onclick = ShowMouse;
    document.querySelector('#ShowTart').onclick = ShowTart;
    document.querySelector('#ShowCheese').onclick = ShowCheese;
    document.querySelector('#orderProblem').onclick = orderProblem;
}

function ShowMouse() {
    document.querySelector('.overlay').style.display = 'initial';
    setTimeout(() => {
        document.querySelector('.overlay').style.display = 'none';
    }, 2000);

    let mid = document.getElementById('mid');
    mid.innerHTML = '';
    for (let i = 1; i <= 26; i++) {
        let link = './images/mousse/image (' + i + ').jpg';
        let card = document.createElement('div');
        card.setAttribute('class', 'card');
        let form = document.createElement('form');
        form.setAttribute('action', 'https://formspree.io/xgenqdqp');
        form.setAttribute('method', 'POST');
        let img = document.createElement('img');
        img.setAttribute('id', 'product');
        img.setAttribute('src', link);
        img.setAttribute('style', 'width:200px; height: 300px; margin-top: 10px');
        form.appendChild(img);
        let h1 = document.createElement('h1');
        h1.setAttribute('class', 'cakeName');
        h1.innerText = mousseCake[i].name;
        form.appendChild(h1);

        let p1 = document.createElement('p');
        p1.setAttribute('class', 'price');
        p1.innerText = mousseCake[i].price;
        form.appendChild(p1);

        let p2 = document.createElement('p');
        p2.setAttribute('class', 'des');
        p2.innerText = mousseCake[i].description;
        form.appendChild(p2);

        let lable = document.createElement('lable');
        let textarea = document.createElement('textarea');
        textarea.setAttribute('style', 'display: none');
        textarea.setAttribute('name', 'message');
        textarea.innerText = link;
        lable.appendChild(textarea);
        form.appendChild(lable);
        let p = document.createElement('p');
        let button = document.createElement('button');
        button.setAttribute('type', 'submit');
        button.innerText = 'Add to cart';
        p.appendChild(button);
        form.appendChild(p);
        card.appendChild(form);
        mid.appendChild(card);
    }
}

function ShowTart() {
    document.querySelector('.overlay').style.display = 'initial';
    setTimeout(() => {
        document.querySelector('.overlay').style.display = 'none';
    }, 2000);

    let mid = document.getElementById('mid');
    mid.innerHTML = '';
    for (let i = 1; i <= 15; i++) {
        let link = './images/tart/image (' + i + ').jpg';
        let card = document.createElement('div');
        card.setAttribute('class', 'card');
        let form = document.createElement('form');
        form.setAttribute('action', 'https://formspree.io/xgenqdqp');
        form.setAttribute('method', 'POST');
        let img = document.createElement('img');
        img.setAttribute('id', 'product');
        img.setAttribute('src', link);
        img.setAttribute('style', 'width:200px; height: 300px; margin-top: 10px');
        form.appendChild(img);
        let h1 = document.createElement('h1');
        h1.setAttribute('class', 'cakeName');
        h1.innerText = tartCake[i].name;
        form.appendChild(h1);

        let p1 = document.createElement('p');
        p1.setAttribute('class', 'price');
        p1.innerText = tartCake[i].price;
        form.appendChild(p1);

        let p2 = document.createElement('p');
        p2.setAttribute('class', 'des');
        p2.innerText = tartCake[i].description;
        form.appendChild(p2);

        let lable1 = document.createElement('lable');
        let textarea = document.createElement('textarea');
        textarea.setAttribute('style', 'display: none');
        textarea.setAttribute('name', 'message');
        textarea.innerText = link;
        lable1.appendChild(textarea);
        form.appendChild(lable1);
        let p = document.createElement('p');
        let button = document.createElement('button');
        button.setAttribute('type', 'submit');
        button.innerText = 'Add to cart';
        p.appendChild(button);
        form.appendChild(p);
        card.appendChild(form);
        mid.appendChild(card);
    }
}

function ShowCheese() {
    document.querySelector('.overlay').style.display = 'initial';
    setTimeout(() => {
        document.querySelector('.overlay').style.display = 'none';
    }, 2000);

    let mid = document.getElementById('mid');
    mid.innerHTML = '';
    for (let i = 1; i <= 14; i++) {
        let link = './images/cheese/image (' + i + ').jpg';
        let card = document.createElement('div');
        card.setAttribute('class', 'card');
        let form = document.createElement('form');
        form.setAttribute('action', 'https://formspree.io/xgenqdqp');
        form.setAttribute('method', 'POST');
        let img = document.createElement('img');
        img.setAttribute('id', 'product');
        img.setAttribute('src', link);
        img.setAttribute('style', 'width:200px; height: 300px; margin-top: 10px');
        form.appendChild(img);
        let h1 = document.createElement('h1');
        h1.setAttribute('class', 'cakeName');
        h1.innerText = cheeseCake[i].name;
        form.appendChild(h1);

        let p1 = document.createElement('p');
        p1.setAttribute('class', 'price');
        p1.innerText = cheeseCake[i].price;
        form.appendChild(p1);

        let p2 = document.createElement('p');
        p2.setAttribute('class', 'des');
        p2.innerText = cheeseCake[i].description;
        form.appendChild(p2);

        let lable1 = document.createElement('lable');
        let textarea = document.createElement('textarea');
        textarea.setAttribute('style', 'display: none');
        textarea.setAttribute('name', 'message');
        textarea.innerText = link;
        lable1.appendChild(textarea);
        form.appendChild(lable1);
        let p = document.createElement('p');
        let button = document.createElement('button');
        button.setAttribute('type', 'submit');
        button.innerText = 'Add to cart';
        p.appendChild(button);
        form.appendChild(p);
        card.appendChild(form);
        mid.appendChild(card);
    }
}