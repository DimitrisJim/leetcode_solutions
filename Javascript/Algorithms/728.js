/**
 * @param {number} left
 * @param {number} right
 * @return {number[]}
 */
let selfDividingNumbers = (left, right) => {
    const res = [];
    floor = Math.floor;
    pow = Math.pow;
    const right_ = right + 1;
    for(let num = left; num < right_; num++){
        // Count the number of digits in num
        let digits = 0;
        let temp = num;
        while (temp){
            temp = floor(temp / 10);
            digits++;
        }
    
        let div = pow(10, digits - 1);
        // Go through digits and see if they divide num.
        let count = 0, red = num;
        while (div) {
            let d = floor(red / div);
            red %= div;
            if ((d != 0) && !(num % d))
                count++;
            else
                break;
            div = floor(div / 10);
        }
        // Count == digits, all have divided num
        if (count == digits) {
            res.push(num);
        }       
    }
    return res; 
};
