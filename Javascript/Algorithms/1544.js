let makeGood = s => {
    const res = [],
          abs = Math.abs;
    let end = s.length - 1,
        i = 0;
    
    while (i < end){
        let diff = abs(s[i].codePointAt() - s[i+1].codePointAt());
        if (diff == 32){
            i += 2;
            while (i <= end && res.length > 0){
                let diff = abs(s[i].codePointAt() - res.slice(-1)[0].codePointAt());
                if (diff == 32){
                    res.pop();
                    i++;
                } else {
                    break;
                }
            }
        } else {
            res.push(s[i]);
            i++;
        }
    }
    if (i == end){
        res.push(s[i]);
    }
    return res.join("");
};
