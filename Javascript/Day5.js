var once = function(fn) {
    return function(...args){
     return fn.apply(this, args);   
    }
};

let fn = (a,b,c) => (a + b + c)
let onceFn = once(fn)

 let val=onceFn(1,2,3); // 6
 let val2=onceFn(4,5,6);
 console.log(val2);