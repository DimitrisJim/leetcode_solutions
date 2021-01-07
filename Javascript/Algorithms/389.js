let findTheDifference = (s, t) => {
    const length = s.length;
    let x = 0;
    for (let i = 0; i < length; i++){
        x ^= s[i].codePointAt() ^ t[i].codePointAt();
    }
    return String.fromCodePoint(x ^ t.slice(-1).codePointAt());
};
