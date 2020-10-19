/**
 * @param {number} num
 * @return {number}
 */
let maximum69Number = num => {
    const floor = Math.floor;
    // Find num of digits
    let digits = 0, temp = num;
    while (temp){
        temp = floor(temp / 10);
        digits += 1;
    }
    // Create our divisor
    let d = 1;
    while (--digits){
        d *= 10;
    } 
    d *= 9;
    // Divide until you can then return.
    let div = floor(num / d);
    temp = num % d;
    while (div == 1){
        d = floor(d / 10);
        div = floor(temp / d);
        temp %= d;
    }
    return num + floor(d / 3); 
};
