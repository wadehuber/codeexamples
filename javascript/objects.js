var Person = {
    name: "Alice",
    age: 24,
    home: "Phoenix",
    birthday: function() {
        this.age++;
    }
}

console.log(Person);
Person.birthday();
console.log(Person);