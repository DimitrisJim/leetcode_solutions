/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int inorder(struct TreeNode* root, int L, int R){
    int sum = 0, val = root->val;
    
    struct TreeNode *left = root->left, *right = root->right;
    if (left != NULL){
        sum += inorder(left, L, R);
    }
    if ((L<= val) && (val <= R)){
        sum += val;
    }
    if (right != NULL){
        sum += inorder(right, L, R);
    }    
    
    return sum;
}

int rangeSumBST(struct TreeNode* root, int L, int R){
    int root_value;
    // edge cases
    if (L == R)
        return L;
    if (root == NULL)
        return 0;
    
    // adjust root if needed. 
    root_value = root->val;
    while (!(L <= root_value) && (root_value <= R)){
        if (root_value < L){
            root = root->right;
        } else {
            root = root->left;
        }
        
        root_value = root->val;
    }
    
    // special cases after adjusting root.
    if (root_value == L){
        return root_value + inorder(root->right, L, R);
    }
    if (root_value == R){
        return root_value + inorder(root->left, L, R);
    }
    
    return inorder(root, L, R);
}


