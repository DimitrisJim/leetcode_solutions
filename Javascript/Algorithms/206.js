/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
let reverseList = head => {
    let new_head = null,
        tail = null,
        tmp = null;
    while (head){
        tmp = head;
        tail = new_head;
        head = head.next;
        new_head = tmp;
        new_head.next = tail;
    }
    return new_head;
};
