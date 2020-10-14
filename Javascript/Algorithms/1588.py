/**
 * @param {number[]} arr
 * @return {number}
 */
var sumOddLengthSubarrays = function(arr) {    
    let get_mults = function(size) {
        let mults = [];
        // build list of odds and their occurences.
        const odds_a = [];
        const occurs_a = [];
        for(let i = 1; i <= size;){
           odds_a.push(i);
           occurs_a.push(1 + (size - i));
           i += 2;
        }
        // noice division.
        const mid = size % 2 ? Math.floor(size / 2) + 1 : Math.ceil(size / 2);

        // push first element
        mults.push(odds_a.length);
        const oolength = odds_a.length;
        for(let idx = 2; idx <= mid; idx++){
            let sum = 0;
            for (let j=0; j < oolength; j++){
                const odd = odds_a[j];
                const occurs = occurs_a[j];

                if ((idx < odd) && (occurs > idx)){
                    sum += idx;
                } else {
                    if (odd <= occurs){
                        sum += odd;
                    } else {
                        sum += occurs;
                    }
                }
            }
            mults.push(sum);
        }

        const l = mults.length
        if (size % 2){
           for(let i = l - 2; i > -1; i--)
               mults.push(mults[i]);
        }
        else {
            for(let i = l - 1; i > -1; i--)
                mults.push(mults[i]);
        }

        return mults;
    };

    // multiply elements with mults.
    let sum = 0;
    const length = arr.length;
    const mults = get_mults(length);
    for(let i = 0; i < length; i++)
        sum += arr[i] * mults[i];
    
    return sum;
};
