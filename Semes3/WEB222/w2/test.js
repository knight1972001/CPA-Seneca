var candidatePhones1 = ["111-111-1111","2222222222","333-333-3333","4556","999-999-9999"];

var registeredPhones1 = [];

function verifyPhone(...number, ...arr)
{
    var phoneNum = /^\(?([0-9]{3})\)?[-. ]?([0-9]{3})[-. ]?([0-9]{4})$/;
  for (let i=0; i<number.length;i++)
  {
    if(number[i].value.match(phoneNum))
    {
        let a=0;
        arr[a]=number[i];
        a++;
    }
  }
  return a; //the number of matched phone format
}

verifyPhone(candidatePhones1[],registeredPhones1[]);
console.log(registeredPhones1);