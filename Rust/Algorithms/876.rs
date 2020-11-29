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
    pub fn middle_node(mut head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut mid = head.clone();
        let mut inc = true;
        while head
            .clone()
            .expect("We receive a non-None head.")
            .next
            .is_some()
        {
            if inc {
                mid = mid.expect("Mid always points inside the Linked List.").next;
            }
            head = head
                .expect("Head has been vetted by while clause check.")
                .next;
            inc = !inc;
        }
        mid
    }
}
