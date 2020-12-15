let findOcurrences = (text, first, second) => {
    const words = text.split(' '),
          result = [],
          limit = words.length - 2;
    let start = 0;
    
    while (start < limit) {
        if (words[start] == first) {
            if (words[start+1] == second) {
                result.push(words[start + 2]);
                start += 2;
                continue;
            }
            start++;
            continue;
        }
        start++;
    }
    return result;
};
