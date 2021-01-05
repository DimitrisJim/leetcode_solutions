let thousandSeparator = u => {
    const res = [],
          n = `${u}`,
          length = n.length;
    let count = 0;
    
    for (let i = length - 1; i >= 0; i--){
        if (count == 3){
            res.push('.');
            count = 1;
        } else {
            count++;
        }
        res.push(n[i]);
    }
    return res.reverse().join("");
};
