const letters = new Set(
        "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
    ),
    // A multiset, basically.
    Counter = s => {
        const c = new Map;
        for (let el of s){
            let value = c.get(el);
            c.set(el, value? value + 1: 1);
        }
        return c;
    },
    // sets: A < B.
    is_subset = (A, B) => {
        for(let el of A){
            if (!B.has(el)){
                return false;
            }
        }
        return true;
    },
    // Multiset subset. Goes through all elements of c1
    // and checks to see if c2 has that value and, if so,
    // if the value is larger than that for c1. 
    counter_subset = (c1, c2) => {
        for (let [el, value] of c1){
            let value2 =  c2.get(el);
            if (value2){
                if (value > value2){
                    return false;
                }
            } else {
                return false;
            }
        }
        return true;
    },
    sort_len = (a, b) => a.length - b.length;

let shortestCompletingWord = (licensePlate, words) => {   
    // Build multiset, set for licensePlate.
    const ms_license = Counter(
        Array(...licensePlate).filter(x => letters.has(x)).map(x => x.toLowerCase())
    ),
    s_license = new Set(ms_license.keys());
    
    // Sort, start from smaller words.
    words.sort(sort_len);
    for (let w of words){
        // First compare subsets to filter out unwanted words.
        if (is_subset(s_license, new Set(w))) {
            // Then compare counters.
            if (counter_subset(ms_license, Counter(w))){
                return w;
            }
        }
    }
};
