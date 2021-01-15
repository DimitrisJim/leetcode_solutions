let findTarget = (root, k) => {
    const seen = new Set,
          q = [root];
    while (q.length > 0) {
        let {val, left, right} = q.pop();
        
        if (seen.has(k - val)){
            return true;
        } else {
            seen.add(val);
        }
        
        if (left){
            q.push(left);
        }
        if (right){
            q.push(right);
        }
    }
    return false;
};
