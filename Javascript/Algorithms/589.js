var preorder = function(root) {
    if(!root){
        return [];
    }
    let [stack, res] = [[root], []];
    while (stack.length) {
        let node = stack.pop();
        if (node.children){
            for (c of node.children.reverse()){
                stack.push(c);
            }
        }
        res.push(node.val);
    }
    return res;
};
