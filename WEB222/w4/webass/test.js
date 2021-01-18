function capitalize(a) {
  a = a.toLowerCase();
  var b = a.charAt(0).toUpperCase() + a.substring(1);
  return b;
}
var capitalize1 = capitalize('PATRICK'); // returns "Patrick"
var capitalize2 = capitalize('james'); // returns "James";

console.log(capitalize1 + ' ' + capitalize2);
