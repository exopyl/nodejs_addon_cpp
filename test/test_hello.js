const addon = require('../build/Release/addon_animals.node');
const assert = require('assert');




describe('Hello Test', () => {
    it('should return Hello world', () => {
           strHello = addon.hello()
           assert.equal(strHello, "Hello World")
       });
   });



   describe('Hello Test', () => {
    it('should return Hello world', () => {
            const dog = new addon.Dog()
            str = dog.Speak()
            assert.equal(str, "wouaf");
       });
   });

