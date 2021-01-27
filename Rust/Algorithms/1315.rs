e std::rc::Rc;
use std::cell::RefCell;

impl Solution {
    fn traverse_sum(node: Rc<RefCell<TreeNode>>, pval: i32) -> i32 {
        let n = Rc::try_unwrap(node).unwrap().into_inner();
        let (val, mut sum) = (n.val, 0);
        
        // Add left/right value to the sum if pval
        // is even and then add to sum whatever we
        // get back from recursing on those trees.
        if let Some(left) = n.left {
            if (pval & 1) == 0 {
                sum += left.borrow().val;
            }
            sum += Solution::traverse_sum(left, val);
        }
        if let Some(right) = n.right {
            if (pval & 1) == 0 {
                sum += right.borrow().val;
            }
            sum += Solution::traverse_sum(right, val);
        }
        sum
    }
    
    pub fn sum_even_grandparent(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let traverse_sum = Solution::traverse_sum;
        let r = Rc::try_unwrap(root.unwrap()).unwrap().into_inner();
        let val = r.val;
        
        // pval could be Option'ed, instead, recurse directly on
        // children of root so we don't need to to do that.
        match (r.left, r.right) {
            (Some(left), Some(right)) => {
                traverse_sum(left, val) + traverse_sum(right, val)
            }
            (None, Some(right)) => {
                traverse_sum(right, val)
            }
            (Some(left), None) => {
                traverse_sum(left, val)
            }
            (None, None) => {
                0
            }
        }
    }
}
