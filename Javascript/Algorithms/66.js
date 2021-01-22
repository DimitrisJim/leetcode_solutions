/**
 * @param {number[]} digits
 * @return {number[]}
 */
let plusOne = digits => {
    let i = digits.length - 1;
    while (i >= 0){
        if (digits[i] == 9){
            digits[i] = 0;
            i--;
        } else {
            digits[i]++;
            break;
        }
    }
    if (i == -1 && digits[0] == 0){
        digits.push(1);
        digits.reverse();
    }
    return digits;    
};
