/**
 * @param {number} n
 * @return {number}
 */
var subtractProductAndSum = function(n) {
    let p = 1;
    let s = 0;
    // thanks, js.
    floor = Math.floor; 
    while (n){
        let rem = n % 10;
        p *= rem;
        s += rem;
        n = floor(n/10);
    }
    return p - s;
};
