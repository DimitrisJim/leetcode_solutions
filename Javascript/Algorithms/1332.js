let removePalindromeSub = (s) => {
    const len = s.length,
          floor = Math.floor;
    if (len == 0){
        return 0;
    }
    let slice1 = s.slice(0, floor(len/2)),
        slice2 = Array(
            ...s.slice(floor(len/2) + (len % 2? 1: 0), len)
        ).reverse().join("")
    if (slice1 == slice2) {
        return 1;
    }
    return (new Set(s)).size;
};
