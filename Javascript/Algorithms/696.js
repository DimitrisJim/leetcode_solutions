let countBinarySubstrings = s => {
    // keep track of consequtive ones, zeros
    let c_ones = 0, c_zeros = 0, count = 0;
    let clear_on_next_zero = 0, clear_on_next_one = 0;
    for (let c of s){
        if (c == '0'){
            if (clear_on_next_zero) {
                clear_on_next_zero = 0;
                c_zeros = 0;
            }
            c_zeros++;
            // we have seen ones
            if (c_ones) {
                if (c_zeros <= c_ones) 
                    count++;
                clear_on_next_one = 1;
            }
        } else { 
            if (clear_on_next_one) {
                clear_on_next_one = 0;
                c_ones = 0;
            }
            c_ones++;
            // we have seen ones
            if (c_zeros) {
                if (c_ones <= c_zeros)
                    count++;
                clear_on_next_zero = 1;
            }
        }
    }
    return count;
};
