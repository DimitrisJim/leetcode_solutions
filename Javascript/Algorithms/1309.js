let freqAlphabets = s => {
    // i: indexes the string at current position we're evaluating
    let i = 0;
    const len = s.length;
    let res = [];
    while(i < (len - 2)){
        // Handle [char][char]# case
        if (s[i + 2] === '#'){
            let v = s[i + 1].codePointAt();
            if (s[i] === '1') {
                res.push(58 + v);
            } else {
                res.push(68 + v);             
            }
            i += 3;
        } 
        // Handle [char] case
        else {
            res.push(48 + s[i].codePointAt());
            i++;
        }
    }
    // Insert final elements.
    if ((len - i) == 2){
        res.push(48 + s[i].codePointAt());
        res.push(48 + s[i+1].codePointAt());
    } else if ((len - i) == 1){
        res.push(48 + s[i].codePointAt());    
    }
    const f = String.fromCodePoint
    return res.map(x => f(x)).join("");
};
