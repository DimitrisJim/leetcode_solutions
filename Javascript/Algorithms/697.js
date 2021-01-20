let findShortestSubArray = nums => {
    const make_counts = nums => {
        const counter = new Map;
        for (let i of nums){
            let val = counter.get(i)
            counter.set(i, val? val + 1: 1);
        }
        return counter;
    };
    
    // Go through nums from left and right looking for rightmost and leftmost 
    // occurences of the values in items. Result is minimum of the difference
    // rightmost - leftmost.
    const find_min = (items, nums, max_deg) => {
        const numslen = nums.length - 1;
        let min_length = numslen + 1;
        for (let i of items){
            let start = 0, end = numslen;
            while (start < end){
                let s = nums[start], e = nums[end];
                if (s != i)
                    start++;
                if (e != i)
                    end--;
                if (e == i && s == i){
                    let diff = end - start + 1;
                    if (diff == max_deg)
                        return diff;
                    if (diff < min_length)
                        min_length = diff;
                    break;
                }
            }
        }
        return min_length;
    };
    
    let max_degree = -1, items = [];
    const counter = make_counts(nums);
    // Find max degree and items that have it.
    for (let [k, v] of counter.entries()){
        if (v > max_degree){
            items = [k];
            max_degree = v;
        } else if (v == max_degree)
            items.push(k);
    }
    if (max_degree == 1)
        return 1;
    // Return min.
    return find_min(items, nums, max_degree);
};
