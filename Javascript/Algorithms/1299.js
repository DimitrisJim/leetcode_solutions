/**
 * @param {number[]} arr
 * @return {number[]}
 */
let replaceElements = arr => {
    const len = arr.length - 1;
    let max = arr[len];
    arr[len] = -1;
    for(let i = len - 1; i > -1; --i){
        let val = arr[i];
        arr[i] = max;
        max = val > max ? val : max;
    }
    return arr;  
};
