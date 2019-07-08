"use strict";

var _createClass = function () { function defineProperties(target, props) { for (var i = 0; i < props.length; i++) { var descriptor = props[i]; descriptor.enumerable = descriptor.enumerable || false; descriptor.configurable = true; if ("value" in descriptor) descriptor.writable = true; Object.defineProperty(target, descriptor.key, descriptor); } } return function (Constructor, protoProps, staticProps) { if (protoProps) defineProperties(Constructor.prototype, protoProps); if (staticProps) defineProperties(Constructor, staticProps); return Constructor; }; }();

function _classCallCheck(instance, Constructor) { if (!(instance instanceof Constructor)) { throw new TypeError("Cannot call a class as a function"); } }

console.log("hello, world");

var Counter = function () {
    function Counter() {
        _classCallCheck(this, Counter);

        this.a = 5;
    }

    _createClass(Counter, [{
        key: "getA",
        value: function getA() {
            return this.a;
        }
    }, {
        key: "setA",
        value: function setA(a) {
            this.a = a;
        }
    }, {
        key: "increment",
        value: function increment() {
            this.a++;
        }
    }]);

    return Counter;
}();

var testClass = new Counter();

for (var i = 0; i < 10; i++) {
    testClass.increment();
}

console.log(testClass.getA());
