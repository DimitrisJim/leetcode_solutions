let numSmallerByFrequency = (queries, words) => {
    // Count the frequencies of the smallest char in s.
    const frequency = s => {
        let count = 1, len = s.length;
        const arrS = Array.from(s).sort();
        for (let i = 1; i < len; i++){
            if (arrS[i-1] != arrS[i]){
                return count;
            }
            count++;
        }
        return count;
    };
    const sort_vals = (a, b) => a - b,
          // Needed container, information.
          cache = new Map,
          qlength = queries.length,
          wlength = words.length,
          // Sort word frequencies and iterate through queries.
          word_freqs = words.map(x => frequency(x)).sort((a, b) => a - b);
    
    // Go through queries and find how many words have larger frequency.
    for (let i = 0; i < qlength; i++){
        let freq = frequency(queries[i]);
        if (!cache.has(freq)){
            for(let k = 0; k < wlength; k++){
                if (freq < word_freqs[k]){
                    cache.set(freq, wlength - k);
                    break;
                }
            }
            // If no word has larger frequency, set to zero.
            if (!cache.has(freq)){
                cache.set(freq, 0);
            }
        }
        queries[i] = cache.get(freq);
    }
    return queries;
};
