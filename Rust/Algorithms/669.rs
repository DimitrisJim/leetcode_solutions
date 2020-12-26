use std::cell::RefCell;
use std::rc::Rc;

impl Solution {
    fn trimmer(
        node: Option<Rc<RefCell<TreeNode>>>,
        parent: Option<Rc<RefCell<TreeNode>>>,
        low: i32,
        high: i32,
    ) {
        // leaf, done.
        if node.is_none() {
            return;
        }
        // Get copies of everything
        let trimmer = Solution::trimmer;
        let val = node.clone().unwrap().borrow().val;
        let left = node.clone().unwrap().borrow().left.clone();
        let right = node.clone().unwrap().borrow().right.clone();
        // If value of current node is smaller than low, keep right subtree
        // and recurse on it.
        if val < low {
            parent.clone().unwrap().borrow_mut().left = right.clone();
            trimmer(right, parent, low, high);
        // if larger than high, keep left subtree and recurse on it.
        } else if val > high {
            parent.clone().unwrap().borrow_mut().right = left.clone();
            trimmer(left, parent, low, high);
        // else, recurse on both.
        } else {
            trimmer(left, node.clone(), low, high);
            trimmer(right, node, low, high);
        }
    }

    pub fn trim_bst(
        root: Option<Rc<RefCell<TreeNode>>>,
        low: i32,
        high: i32,
    ) -> Option<Rc<RefCell<TreeNode>>> {
        if root.is_none() {
            return None;
        }
        // Establish new root, if needed.
        // Get value and compare.
        let val = root.clone().unwrap().borrow().val;
        if val < low {
            let right = Rc::try_unwrap(root.unwrap())
                .ok()
                .unwrap()
                .into_inner()
                .right;
            return Solution::trim_bst(right, low, high);
        } else if val > high {
            let left = Rc::try_unwrap(root.unwrap())
                .ok()
                .unwrap()
                .into_inner()
                .left;
            return Solution::trim_bst(left, low, high);
        // Found our root, start trimming children.
        } else {
            Solution::trimmer(root.clone(), None, low, high);
        }

        // Finally, return root.
        return root;
    }
}
