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
    pub fn get_decimal_value(head: Option<Box<ListNode>>) -> i32 {
        let mut node = head.expect("The unexpected");
        let mut sum: i32 = node.val;
        while node.next.is_some() {
            node = node.next.expect("The unexpected.");
            sum <<= 1;
            sum |= node.val;
        }
        sum
    }
}
