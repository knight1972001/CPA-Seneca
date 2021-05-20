// // function getAgeInYears(day) {
// //   let today = new Date();
// //   let age = today.getFullYear() - day.getFullYear();
// //   let month = today.getMonth() - day.getMonth();
// //   if (month < 0 || (month === 0 && today.getDate() < day.getDate())) {
// //     age--;
// //   }
// //   return age;
// // }

// // var day = '1995-02-04T07:34:45Z';
// // var birthday = new Date(day);
// // console.log('Dang CHay');
// // var today = new Date();
// // console.log(today);
// // var newday = birthday.getFullYear();
// // var nam = today.getFullYear();
// // console.log(nam);
// // console.log(newday);

// // var a = getAgeInYears(day);
// // console.log('tuoi la: ' + a);

// // function convertArr(ids) {
// //   var arr = [];
// //   console.log(ids.length);
// //   if (ids.length > 1) {
// //     for (var i = 0; i < ids.length; i++) {
// //       arr.push(ids[i]);
// //     }
// //   } else {
// //     arr.push(ids);
// //   }

// //   console.log(arr);
// //   return arr;
// // }

// // convertArr([2, 3, 5, 2]);
// // var arr = [];
// // var chuoi = 'day la chuoi';
// // arr.push(chuoi);
// // console.log(chuoi);
// // var tim = 'day';
// // var regex = new RegExp('^' + tim, 'i');
// // if (regex.test(chuoi)) {
// //   console.log('Khop');
// // } else {
// //   console.log('Kg khop');
// // }

// // var ketqua = arr.filter(arr => arr === tim);
// // console.log(ketqua);

// // var c = [
// //   [2, 8, 1, 5, 2, 6],
// //   [3, 54, 1, 5, 2]
// // ];
// // console.log(c);
// // c.slice(1, 3);
// // var d = [];
// // for (var i = 0; i < c.length; i++) {
// //   d = c[0].concat(c[i]);
// // }
// // console.log(d);
// var first = 'long';
// var last = 'nguyen';
// var email = ['knight1972001@gmail.com', 'email2ne'];
// var context =
//   'Dear ' +
//   first +
//   ' ' +
//   last +
//   ',\n\n' +
//   "Welcome to imaginary application!  We're so happy you joined, and wanted to take a moment to say hello. Our other users from City, Country will be glad to have you join them.\n\n" +
//   'Have a great day!\n\n' +
//   'Your Friends at the Imaginary Application Team';
// var user = {};
// var moi = Object.create(user);
// for (var i = 0; i < email.length; i++) {
//   moi[email[i]] = context;
// }
// console.log(moi);

// var x = -2.5;
// console.log(Math.round(x));
// console.log(Math.ceil(x));
// console.log(Math.floor(x));

var person4 = {};
person4.name = 'Muath';
person4.age = 25;
person4.age = 42;
person4.print = function() {
  console.log('My name is' + this.name + ", and I'm" + this.age + ' years old.');
};
person4.print();
