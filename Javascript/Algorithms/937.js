let reorderLogFiles = logs => {
    if (logs.length < 2) 
        return logs;

    // Some arrows:
    const filter_digits = x => {
        let cp = x[1][0].codePointAt();
        // Between 0-9.
        return cp <= 57 && cp >= 48;
    };
    const filter_letters = x => {
        return !filter_digits(x);
    }
    // Sort the letters. We add the identifier to
    // the end of the string in order to use it 
    // as a tie-braker.
    const sorter = (x, y) => {
        let s1 = x.slice(1).join(" ") + x[0],
            s2 = y.slice(1).join(" ") + y[0];
        if (s1 < s2)
            return -1;
        else if (s1 > s2)
            return 1;
        return 0;
    };
    
    // Split logs into digit rows and letter rows.
    logs = logs.map(x => x.split(" "));
    let digits = logs.filter(filter_digits).map(x => x.join(" "));
    let letters = logs.filter(filter_letters);
    
    letters.sort(sorter);
    // Return letters and digits.
    return [
        ...letters.map(x => x.join(" ")),
        ...digits
    ];
};
