let findLucky = (arr) => {
    const Counter = new Map;
    
    arr.forEach(x => {
        let value = Counter.get(x);
        Counter.set(x, value? value + 1: 1);
    });
    let largest = -1
    for (let [k, v] of Counter.entries()){
        if (k == v && k > largest){
            largest = k;
        }
    }
    return largest;
};
