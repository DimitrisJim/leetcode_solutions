/**
 * @param {number[]} arr
 * @return {boolean}
 */
let canMakeArithmeticProgression = arr => {
    arr.sort((a, b) => a-b);
    let step = arr[1] - arr[0],
        len = arr.length;
    for(let i = 2; i < len; i++){
        if (arr[i] != arr[i-1] + step)
            return false;
    }
    return true;  
};
