let postorder = (root) => {
    if(!root){
        return [];
    }
    let [stack, seen, res] = [[root], new Set, []];
    while(stack.length){
        let node = stack.pop();
        if (seen.has(node)){
            res.push(node.val);
        } else {
            seen.add(node);
            if (node.children){
                stack.push(node)
                for (let c of node.children.reverse()){
                    stack.push(c);
                }
            } else {
                res.push(node.val);
            }
        }
    }
    return res;
};
