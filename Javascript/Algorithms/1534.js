/**
 * @param {number[]} arr
 * @param {number} a
 * @param {number} b
 * @param {number} c
 * @return {number}
 */
var countGoodTriplets = function(arr, a, b, c) {
    let ai, aj, ak, count = 0;
    const len = arr.length;
    const abs = Math.abs;
    // Go through combinations.
    for(let i = 0; i < len; i++){
        ai = arr[i];
        for(let j = i+1; j < len; j++){
            aj = arr[j];
            // Bail early if first condition isn't met.
            if (a >= abs(ai - aj)){
                for (let k = j+1; k < len; k++){
                    ak = arr[k];
                    // check the rest of the conditions.
                    if ((b >= abs(aj - ak)) && (c >= abs(ai - ak))){
                        count += 1;
                    }
                }
            }
        }
    }
    return count;
};
