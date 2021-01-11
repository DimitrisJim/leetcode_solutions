let getNoZeroIntegers = function(n) {
    const is_nozero = i => {
        let d = 1000, floor = Math.floor;
        // reduce d to appropriate value.
        while (i < d){
            d /= 10;
        }
        while (d){
            const q = floor(i / d);
            if (!q){
                return false;
            }
            // reduce.
            i %= d, d = floor(d / 10);
        }
        return true;
    };
    
    let upper = n, lower = 1;
    while (1){
        let candidate = upper + lower;
        if (candidate == n){
            return [lower, upper];
        } else if (candidate < n){
            while (!is_nozero(++lower));
        } else {
            while (!is_nozero(--upper));
        }
    }
};
