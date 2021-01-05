let moveZeroes = nums => {
    const length = nums.length;
    let on_zero = 0, run = 0;
    
    while (1){
        while (nums[on_zero]){
            on_zero++;
            if (on_zero == length)
                return;
        }
        
        while (!nums[run] || run < on_zero){
            run++;
            if (run == length)
                return;
        }
        
        let tmp = nums[on_zero];
        nums[on_zero] = nums[run];
        nums[run] = tmp;
    }
};
