const outer=(init)=>{
    let temp=init;
    const increment=()=>{
      return ++temp;
    }
    const decrement=()=>{
      return --temp;
    }
    const reset=()=>{
      temp=init;
      return temp;
    }

    const add=(param1)=>{
        return param1+temp;
    }
    const obj={
      incKey:increment,
      decKey:decrement,
      resetKey:reset,
      addKey:add
    }
    
    return obj;
  }

const obj1=outer(10)
let val=obj1.decKey();
let val2=obj1.addKey(23);
console.log(val2);

