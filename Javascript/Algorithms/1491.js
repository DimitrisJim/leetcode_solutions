/**
 * @param {number[]} salary
 * @return {number}
 */
var average = function(salary) {
    let count = salary.length - 2;
    const reducer = (accumulator, currentValue) => accumulator + currentValue;
    salary.sort((x, y) => x - y);
    return salary.slice(1, count + 1).reduce(reducer) / count;
};
