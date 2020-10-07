/**
 * @param {number[]} candies
 * @param {number} extraCandies
 * @return {boolean[]}
 */
var kidsWithCandies = function(candies, extraCandies) {
    // Better reduce than apply, apply has max limit 
    // of num args a function can accept.
    let m = candies.reduce((a, b) => Math.max(a, b));
    return candies.map(el => (el + extraCandies >= m));
};
