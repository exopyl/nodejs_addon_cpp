const addon = require('./build/Debug/addon_animals.node');
console.log('addon',addon);
//console.log('hello ', addon.hello());
//console.log('add ', addon.add(5, 10));

console.log(addon.hello());


const dog = new addon.Dog();
console.log(dog.Speak());

module.exports = addon;
