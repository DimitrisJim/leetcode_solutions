let sumEvenAfterQueries = (A, queries) => {
    const even = x => !(x & 1);
    const sum = (acc, x) => acc + x;
    let evenSum = A.filter(even).reduce(sum, 0), 
        idx = 0;
    
    // Go through queries.
    for(let [value, index] of queries) {
        const old_value = A[index],
              new_value = old_value + value;
        if (new_value % 2 == 0){
            // Add to evenSum:
            evenSum += new_value;
        }
        if (old_value % 2 == 0){
            // remove from evenSum:
            evenSum -= old_value;
        }
        A[index] = new_value;
        queries[idx++] = evenSum;
    };
    return queries;
};
