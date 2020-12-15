use std::cell::RefCell;
use std::rc::Rc;

impl Solution {
    fn next_leaf(stack: &mut Vec<Rc<RefCell<TreeNode>>>) -> i32 {
        while stack.len() > 0 {
            // Unwrap completely, again. Don't need it around for much.
            let node = Rc::try_unwrap(stack.pop().unwrap())
                .ok()
                .unwrap()
                .into_inner();
            // return if we found leaf.
            if node.left.is_none() && node.right.is_none() {
                return node.val;
            }
            // Add children.
            if node.right.is_some() {
                stack.push(node.right.unwrap());
            }
            if node.left.is_some() {
                stack.push(node.left.unwrap());
            }
        }
        -1
    }

    pub fn leaf_similar(
        root1: Option<Rc<RefCell<TreeNode>>>,
        root2: Option<Rc<RefCell<TreeNode>>>,
    ) -> bool {
        // Shorten name, might also be sligtly more performant?
        let next_leaf = Solution::next_leaf;

        // Stack to keep nodes around, result.
        let mut stack1 = vec![root1.unwrap()];
        let mut stack2 = vec![root2.unwrap()];
        let mut result = false;

        // Continuous until we break.
        loop {
            let l1 = next_leaf(&mut stack1);
            let l2 = next_leaf(&mut stack2);
            if l1 != l2 {
                break;
            }
            if l1 == -1 && l2 == -1 {
                result = true;
                break;
            }
        }
        result
    }
}
