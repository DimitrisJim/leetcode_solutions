let titleToNumber = s => {
    const pow = Math.pow;
    let length = s.length - 1,
        col = 0;
    
    for(c of s){
        col += (c.codePointAt() - 64) * pow(26, length--);
    }
    return col;
};
