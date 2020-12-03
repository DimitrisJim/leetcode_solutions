let countCharacters = (words, chars) => {
    // Make counts from the value
    const create_counter = value => {
        let m = new Map;
        for(let i of value) {
            let count = m.get(i);
            m.set(i, count? count + 1: 1);
        }
        return m;
    };
    
    // Helper structures.
    const ch_set = new Set(chars),
          ch_count = create_counter(chars),
          clen = chars.length;
 
    // Filters
    // all: All characters in str are contained in set.
    const all = (str, set) => {
        for (let c of str){
            if (!set.has(c)){
                return false;
            }
        }
        return true;
    }
 
    // can_build: can use chars of other to build me.
    const can_build = (me, other) => {
        let count = 0;
        for (let entry of me.entries()){
            let otherval = other.get(entry[0]);
            otherval = otherval? otherval: 0;
            if (otherval >= entry[1]){
                count++;
            }
        }
        return me.size == count;
    };
    // Use the filters:
    const is_smaller = w => w.length <= clen,
          is_contained = w => all(w, ch_set),
          is_buildable = w => can_build(create_counter(w), ch_count);
        
    // Count chars.
    const reducer = (acc, value) => acc + value.length
    return words.filter(is_smaller).filter(is_contained).filter(is_buildable).reduce(reducer, 0);
};
