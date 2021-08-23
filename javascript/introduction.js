// Variables

var intVar = 5;                           // Number
var decimalVar = 12.34                    // Floating piont
var booleanVar = true;                    // Boolean
var str = "This is a string";             // string
var str2 = 'This is also a string';       // string

// Constants
const max = 100;    

console.log(intVar);
console.log(decimalVar);
console.log(booleanVar);
console.log(str);
console.log(str2);
console.log(max);

// Operators

intVar = 10;
var sum = intVar + 6;
var hello = "Hello"
var greeting = hello + " world!";
var quotient = intVar / 3;
var remainder = intVar % 3;

console.log(sum);
console.log(hello);
console.log(greeting);
console.log(quotient);
console.log(remainder);

// Comparison
var finalExamGrade = 87;
var totalPoints = 912;
var passFinal = finalExamGrade > 60;
var passClass = totalPoints >= 900 && passFinal;
console.log(passClass);

// Arrays
var classes = ["CS101", "CS102", "CS201", "CSC210"];
console.log(classes);
classes = ["CSC110", "CSC205", "CSC230", "CSC240"];
console.log(classes[0]);
console.log(classes[1]);
console.log(classes[2]);
classes[3] = "CSC220";
console.log(classes);
console.log(classes.length);
classes.push("CSC310");
console.log(classes);
var taken = classes.pop();
console.log(taken);
console.log(classes);

// Control structures

if ("CSC310" == taken) {
    console.log("You have taken CSC310");
}
else {
    console.log("You have NOT taken CSC310");
}

var secret = 42;
var guess = 17;

if (guess == secret) {
    console.log("Correct guess");
}
else if (guess > secret) {
    console.log("Incorrect guess - too high!");
}
else {
    console.log("Incorrect guess - too low!");
}

guess = 42;
if (guess == secret) {
    console.log("Correct guess");
}
else if (guess > secret) {
    console.log("Incorrect guess - too high!");
}
else {
    console.log("Incorrect guess - too low!");
}

// Loops

for(var ii=0; ii<10;ii++) {
    console.log(ii)
}

for(var ii=20; ii>0;ii-=4) {
    console.log(ii)
}

var cities = ["Chandler", "Gilbert", "Mesa", "Phoenix", "Scottsdale"];
for (var ii=0; ii<cities.length; ii++) {
    console.log(cities[ii]);
}

x = 1;
var end = 5;
while (x <= end ) {
    console.log(x)
    x++;
}

// Functions
var visit = 0;
function visitCounter() {
    visit++;
}
console.log(visit);
visitCounter();
visitCounter();
visitCounter();
visitCounter();
visitCounter();
console.log(visit);

function jumpCounter(jump) {
    visit += jump;
}
console.log(visit);
jumpCounter(3);
jumpCounter(7);
jumpCounter(5);
console.log(visit);

function addNums(a,b){
    return a + b;
}
console.log(addNums(3,4));
console.log(addNums(10,6));
console.log(addNums(17,-2));
