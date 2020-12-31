/**
 * @param {number[]} arr
 * @return {number}
 */
let findSpecialInteger = arr => {
    const length = arr.length;
    let threshold = Math.ceil(length * 0.25), count = 1;
    for (let i = 1; i < length; i++){
        if (arr[i-1] == arr[i]){
            count++;
            if (count > threshold)
                return arr[i];
        } else 
            count = 1;
    }
    return arr[0];
};
