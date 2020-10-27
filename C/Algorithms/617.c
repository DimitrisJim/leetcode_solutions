#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2){
    // Handle initial edge cases.
    if (!t1 && !t2)
        return NULL;
    if (!t1)
        return t2;
    if (!t2)
        return t1;
    
    // Create root and set value.
    struct TreeNode *root = malloc(sizeof *root);
    root->val = t1->val + t2->val;
    
    // Pending: Queue implementation.   
    return NULL;
}
