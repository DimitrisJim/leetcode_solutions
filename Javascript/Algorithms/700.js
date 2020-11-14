let searchBST = (root, val) => {
    while (root){
        let rval = root.val;
        if (rval == val){
            return root;
        }
        root = val > rval ? root.right : root.left;
    }
    return null;
};
