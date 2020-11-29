/**
 * @param {number[]} target
 * @param {number} n
 * @return {string[]}
 */
let buildArray = (target, n) => {
    let ops = [],
        start = 0;
    target.forEach(i => {
        diff = i - start - 1;
        if (diff > 0){
            for(let i = 0; i < diff; i++){
                ops.push("Push");
                ops.push("Pop");
            }
        }
        ops.push("Push");
        start = i;
    })
    return ops;
};
