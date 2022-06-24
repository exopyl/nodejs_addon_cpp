const addon = require('../build/Release/addon_animals.node');
const assert = require('assert');




describe('Hello Test', () => {
    it('should return Hello world', () => {
           strHello = addon.hello()
           assert.equal(strHello, "Hello World");
       });
   });

