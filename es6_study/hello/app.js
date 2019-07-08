console.log("hello, world");

class Counter{
    constructor(){
       this.a = 5;
    };

    getA(){
        return this.a;
    };

    setA(a){
        this.a = a;
    };

    increment(){
        this.a++;
    };
}

const testClass = new Counter();

for( let i = 0; i < 10; i++)
{
    testClass.increment();
}

console.log(testClass.getA());
