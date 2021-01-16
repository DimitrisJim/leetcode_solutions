// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
//
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn merge_two_lists(
        mut l1: Option<Box<ListNode>>,
        mut l2: Option<Box<ListNode>>,
    ) -> Option<Box<ListNode>> {
        if l1.is_none() && l2.is_none() {
            return None;
        }
        // First, collect values into vector. (Do not want to go into hairy
        // issues with linked lists in Rust.)
        let mut values = Vec::new();
        loop {
            match (l1.clone(), l2.clone()) {
                // Use whichever is smaller.
                (Some(ln1), Some(ln2)) => {
                    let mut val = 0;
                    if ln1.val <= ln2.val {
                        values.push(ln1.val);
                        l1 = ln1.next;
                    } else {
                        values.push(ln2.val);
                        l2 = ln2.next;
                    }
                }
                // One is exhausted, use the other.
                (Some(ln1), None) => {
                    values.push(ln1.val);
                    l1 = ln1.next;
                }
                (None, Some(ln2)) => {
                    values.push(ln2.val);
                    l2 = ln2.next;
                }
                // Exhausted, break.
                (None, None) => {
                    break;
                }
            }
        }
        // Go through values and build result.
        let mut next = None;
        for val in values.into_iter().rev() {
            let node = Some(Box::new(ListNode { next, val }));
            next = node;
        }
        next
    }
}
