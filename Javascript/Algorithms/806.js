let numberOfLines = (widths, s) => {
    const lcEng = "abcdefghijklmnopqrstuvwxyz",
          mapper = (el, idx) => [lcEng[idx], el];
    let lines = 0, line = 0;

    // Create mapping from characters to values
    const dwidths = new Map(widths.map(mapper));
    for (let c of s){
        let width = dwidths.get(c);
        line += width;
        if (line > 100) {
            lines += 1;
            line = width;
        }
    }
    return [lines + (line > 0 ? 1 : 0), line];
};
