let numberOfMatches = n => {
    const floor = Math.floor;
    let c = 0, r;
    while (n > 1){
        r = n % 2, n = floor(n / 2);
        c += n + r;
    }
    return c;
};
