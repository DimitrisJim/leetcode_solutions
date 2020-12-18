let breadth = (node, level, values, counts) => {
    if (!node){
        return;
    }
    let [left, right, val] = [node.left, node.right, node.val];
    let v = values[level];
    values[level] = v == undefined? val: v + val;
    let c = counts[level];
    counts[level] = c == undefined? 1: c+1;
    if (left){
        breadth(left, level+1, values, counts);
    }
    if (right){
        breadth(right, level+1, values, counts);
    }
}

let averageOfLevels = root => {
    const counts = [],
          values = [];
    const result = [];
    breadth(root, 0, values, counts);
    for (let i = 0; i < values.length; i++){
        if (counts[i] != 0){
            result.push(values[i] / counts[i]);
        }
    }
    return result;
};
