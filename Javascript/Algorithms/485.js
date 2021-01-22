/**
 * @param {number[]} nums
 * @return {number}
 */
let findMaxConsecutiveOnes = nums => {
    let max = 0, count = 0;
    for (let i of nums){
        if (i){
            count++;
            if (count > max)
                max = count;
            continue;
        }
        count = 0;
    }
    return max;
};
