let reformat = s => {
    let chars = [], nums = [];
    for (let c of s){
        (c.codePointAt() - 48) < 10? nums.push(c): chars.push(c);
    }
    
    let diff = nums.length - chars.length, res = [];
    if (diff == 0 || diff == 1){
        if (diff == 1){
            res.push(nums.pop());
        }
        chars.forEach(x => {
            res.push(x);
            res.push(nums.pop());
        });
    } else if (diff == -1){
        res.push(chars.pop());
        nums.forEach(x => {
            res.push(x);
            res.push(chars.pop());
        });
    } else {
        return "";
    }
    return res.join("");
};
