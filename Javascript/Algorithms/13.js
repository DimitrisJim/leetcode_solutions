const special = new Set(["IV", "IX", "XL", "XC", "CD", "CM"]),
      rtoi = new Map([
          ['I', 1], ['V', 5], ['X', 10], ['L', 50], ['C', 100], ['D', 500], ['M', 1000]
      ]);

let romanToInt = s => {
    let i = 0, end = s.length - 1, n = 0;
    
    while (i < end){
        if (special.has(s.slice(i, i+2))){
            n = n - rtoi.get(s[i]) + rtoi.get(s[i+1]);
            i += 2;
            continue
        }
        n += rtoi.get(s[i]);
        i++;
    }
    
    return i == end + 1 ? n : n + rtoi.get(s[end]);
};
