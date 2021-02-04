let countBalls = function(lowLimit, highLimit) {
    // Initialize counter (list) with zeroes.
    const init_counter = n => {
        let slots = 18;
        if (n > 10000)
            slots = 45;
        else if (n > 1000)
            slots = 36;
        else
            slots = 27;
        return Array(slots).fill(0);
    };
    // Sum digits in n.
    const sum_digits = n => {
        const floor = Math.floor;
        let sum = 0;
        while (n) {
            sum += n % 10;
            n = floor(n / 10);
        }
        // 0-based indexing.
        return sum - 1;
    };
    // Add to array from a given base (multiple of ten).
    const add_from_base = (array, n, start, end) => {
        const base = sum_digits(n);
        for (let i = start; i < end; i++)
            array[base+i]++;
    };
    
    // Get counter:
    const arr = init_counter(highLimit),
          floor = Math.floor;
    // Get starting multiple of ten and remainder, similarly of end.
    let start_left = lowLimit % 10, start = floor(lowLimit / 10);
    let end_left = (highLimit + 1) % 10, end = floor((highLimit + 1) / 10);
    
    // If start equals end, we're on the same multiple of ten. Add values 
    // from [start_left, end_left)
    if (start == end)
        add_from_base(arr, start, start_left, end_left);
    // else, add [start_left, 10), [0, end_left) and then
    // go through (start + 1) * 10, (end - 1) * 10 by multiples
    // of ten.
    else {
        add_from_base(arr, start, start_left, 10);
        add_from_base(arr, end, 0, end_left);
        
        start = (start + 1) * 10;
        end = (end - 1) * 10;
        for (let i = start; i <= end; i += 10)
            add_from_base(arr, i, 0, 10);
    }
    // Return array maximum.
    return Math.max(...arr);
};
