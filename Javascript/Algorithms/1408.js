let stringMatching = words => {
    const sorter = (x, y) => x.length - y.length,
          res = [],
          length = words.length;
    
    words.sort(sorter);
    words.forEach((x, idx) => {
        for(let i = idx+1; i < length; i++){
            if (words[i].includes(x)){
                res.push(x);
                break;
            }
        }
    });
    return res;
};
