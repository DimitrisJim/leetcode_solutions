let getMinimumDifference = root => {
    // Nice, generator delegation works lovely. (seem slow, though).
    function *dfs(node){
        const [val, left, right] = [node.val, node.left, node.right];
        if (left)
            yield* dfs(left);
        yield val;
        if (right)
            yield* dfs(right);
    };
    
    // Collect generator values into array and find min.
    const res = Array(...dfs(root)),
          length = res.length;
    let min = res[1] - res[0];
    for(let i = 2; i < length; i++){
        let diff = res[i] - res[i-1];
        if (diff < min)
            min = diff;
    }
    return min;
};
