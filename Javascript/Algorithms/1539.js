let findKthPositive = (arr, k) => {
    const length = arr.length;
    let start = 1;
    for (let i = 0; i < length; i++){
        let j = arr[i];
        if (start == j)
            start++;
        else {
            let step = j - start;
            if (step >= k)
                return start + k - 1;
            k -= step;
            start = j + 1;
        }
    }
    return start + k - 1;    
};
