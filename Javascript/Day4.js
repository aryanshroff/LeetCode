arr=[1,2,3,4,5,6]

const fn= (n,i)=>{
    console.log(typeof i);
    return n+i;
}

var map = function(arr, fn) {
    const res=[];
    for (let i in arr){
        res.push(fn(arr[i],Number(i)));
    }
    return res;
};

res=map(arr, fn);
console.log(res);