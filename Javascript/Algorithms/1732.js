/**
 * @param {number[]} gain
 * @return {number}
 */
let largestAltitude = gain => {
    let max_height = 0, height_i = 0;
    for (let i of gain){
        height_i += i;
        if (height_i > max_height)
            max_height = height_i;
    }
    return max_height;
};
