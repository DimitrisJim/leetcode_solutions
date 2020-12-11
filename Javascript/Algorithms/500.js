// Only make sets of upper case chars.
let make_rows = () => {
    const rows = ["QWERTYUIOP", "ASDFGHJKL", "ZXCVBNM"];
    let s = new Set;
    for (let r of rows){
        s.add(new Set(r));
    }
    return s;
}

// Returns true if all elements of s1 belong
// in s2.
let issubset = (s1, s2) => {
    for(el of s1){
        if (!s2.has(el)){
            return false;
        }
    }
    return true;
}

var findWords = function(words) {
    const result = [],
          rows = make_rows();
    for (let w of words){
        let sw = new Set(w.toUpperCase());
        for (r of rows){
            if (issubset(sw, r)){
                result.push(w);
            }
        }
    }
    return result;
};
