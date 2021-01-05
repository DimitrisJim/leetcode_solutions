let findLUSlength = function(a, b) {
    const alen = a.length, blen = b.length;
    return a == b ? -1 : alen > blen? alen: blen; 
};
