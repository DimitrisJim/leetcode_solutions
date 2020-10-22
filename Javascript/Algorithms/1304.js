let sumZero = n => {
    let a = [];
    const bound = Math.floor(n/2) + 1;
    if(n & 1){
        a.push(0);
    }
    for(let i = 1; i < bound; i++){
        a.push(i);
        a.push(-i);
    }
    return a;
};
