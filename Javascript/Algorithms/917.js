const letters = new Set("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ")

let reverseOnlyLetters = S => {
    let start = 0, end = S.length;
    let Sarr = Array.from(S);
    
    while (start < end){
        while (!letters.has(Sarr[start])){
            if (start == end){
                return Sarr.join("");
            }
            start++;
        }
        while (!letters.has(Sarr[end])){
            if (start == end){
                return Sarr.join("");
            }
            end--;
        }
        let tmp = Sarr[start];
        Sarr[start] = Sarr[end];
        Sarr[end] = tmp;
        start++, end--;
    }
    return Sarr.join("");
};
