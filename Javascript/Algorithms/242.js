let isAnagram = (s, t) => {
    const make_counter = str => {
        let m = new Map;
        for (let c of str){
            let v = m.get(c);
            m.set(c, v? v + 1: 1);
        }
        return m;
    };
    // Don't check for size, we know, in this case
    // that they will be of equal size if counter_eq
    // is called.
    const counter_eq = (c1, c2) => {
        for (let k of c1.keys()){
            if (c1.get(k) != c2.get(k)) {
                return false;
            }
        }
        return true;
    }
    return s.length != t.length ? 
        false :     
        counter_eq(make_counter(s), make_counter(t));
};  
