let specialArray = (nums) => {
    const numsSize = nums.length;
    for (let i = 1; i < numsSize + 1; i++){
        let match = 0;
        for(let j = 0; j < numsSize; j++){
            let el = nums[j];
            if (el >= i){
                match++;
                if (match > i)
                    break;
                continue;
            }
            // break if num of elements left to see 
            if (match + (numsSize - j) < i)
                break;
        }
        if (match == i)
            return i;
    }
    return -1;
};
