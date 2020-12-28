let maxPower = s => {
    let max_substring = 1,
        count = 1,
        current = s[0];
    const length = s.length;
    for (let i = 1; i < length; i++){
        let c = s[i];
        if (c == current){
            count++;
            if (count > max_substring){
                max_substring = count;
            }
        } else {
            count = 1;
            current = c
        }
    }
    return max_substring;
};
