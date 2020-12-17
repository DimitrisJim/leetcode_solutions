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
    pub fn reverse_list(
        mut head: Option<Box<ListNode>>,
    ) -> Option<Box<ListNode>> {
        let (mut new_head, mut tail, mut tmp) = (None, None, None);
        while head.is_some() {
            tmp = head.clone();
            tail = new_head;
            head = head.unwrap().next;
            new_head = Some(Box::new(ListNode {
                next: tail,
                val: tmp.unwrap().val,
            }));
        }
        new_head
    }
}
