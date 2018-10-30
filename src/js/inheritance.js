console.log(`Understand Prototypical Inheritance well`);

var animalGroups = {
  MAMMAL: 1,
  REPTILE: 2,
  AMPHIBIAN: 3,
  INVERTEBRATE: 4
};

function Animal(name, type) {
  this.name = name;
  this.type = type;
}

var dog = new Animal("dog", animalGroups.MAMMAL);
var crocodile = new Animal("crocodile", animalGroups.REPTILE);

Animal.prototype.shout = function() {
  console.log(this.name + "is " + this.sound + "ing...");
};

function Dog(name, type) {
  Animal.call(this, name, type);
  this.sound = "bow";
}

Dog.prototype = Object.create(Animal.prototype);

var pet = new Dog("genmanShepard", animalGroups.MAMMAL);

pet.shout();

Dog.prototype.constructor = Dog;

console.log(pet.constructor);
console.log(Dog.prototype.constructor);
