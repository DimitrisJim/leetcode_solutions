/**
 * @param {number[]} queries
 * @param {number} m
 * @return {number[]}
 */
let processQueries = (queries, m) => {
    const P = [], res = [];
    for (let i = 1; i < m + 1; i++)
        P.push(i);
    
    queries.forEach(q => {
        let idx = P.indexOf(q);
        res.push(idx);
        P.splice(0, 0, P.splice(idx, 1)[0]);
    });
    return res;
};
