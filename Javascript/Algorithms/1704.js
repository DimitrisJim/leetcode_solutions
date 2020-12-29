let halvesAreAlike = s => {
    let vowels = new Set("aAoOiIuUeE");
    const length = s.length,
          mid = Math.floor(length / 2);
    let count = 0;
    
    for (let i = 0; i < mid; i++){
        if (vowels.has(s[i])) {
            count++;
        }
    }
    for (let i = mid; i < length; i++){
        if (vowels.has(s[i])) {
            count--;
            if (count < 0){
                return false;
            }
        }
    }
    return count == 0;
};
