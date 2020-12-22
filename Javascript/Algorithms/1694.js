let reformatNumber = function(number) {
    let counter = 0;
    for(let c of number){
        if (c != '-' && c != ' ') counter++;
    }
    
    // Find how many times to repeat and what will be left.
    let left = counter, repeat = 0;
    while (left > 4){
        left -= 3;
        repeat++;
    }

    // Add triplets, takes care of a number of edge cases:
    //  digits -> keep track of how many digits we've added so far (
    //            to know when to move to next group.)
    //  end    -> flag, re-use the while loop to also add left overs.
    //  lim    -> how many digits to we add? 3 or 2.
    //  repeat needs to be re-adjusted for the case where repeat == 0 
    //  and left == 4. We want to repeat twice even though repeat has 
    // initially been set to 0.
    let digits = 0,
        end = repeat > 0? 0: 1,
        lim = repeat > 0? 3 : (left == 4? 2: left),
        result = '';
    repeat = repeat > 0? repeat: (left == 4? 2: 0), i = 0;
    while (1) {
        // Skip '-' and ' '.
        while (number[i] && number[i] == '-' || number[i] == ' ') i++;

        // Add dash and, if we have leftovers, handle them, else break.
        if (digits == lim){
            result += '-';
            digits = 0;
            repeat--;
            if (repeat <= 0){
                if (end)
                    break;
                repeat = left == 4? 2: 1;
                lim = left == 4? 2: left;
                end = 1;
            }
        // Add digit.
        } else {
            result += number[i++];
            digits++;
        }
    }
    // Don't return superflous '-' added.
    return result.slice(0, -1);
};
