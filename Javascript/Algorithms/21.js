/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
let mergeTwoLists = (l1, l2) => {
    if (!l1 && !l2){
        return null;
    }
    let head = new ListNode(),
        ref = head;
    while (l1 && l2){
        if (l1.val <= l2.val){
            ref.val = l1.val, l1 = l1.next;
        }
        else {
            ref.val = l2.val, l2 = l2.next;
        }    
        ref.next = new ListNode();
        ref = ref.next;
    }
    let rem = l1? l1: l2;
    while (rem){
        ref.val = rem.val, rem = rem.next;
        if (rem){
            ref.next = new ListNode(), ref = ref.next;
        }
    }
    return head;
};
