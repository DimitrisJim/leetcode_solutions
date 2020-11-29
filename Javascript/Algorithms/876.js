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
var middleNode = function(head) {
    let mid = head,
        inc = false;
    while (head = head.next) {
        if (inc = !inc){
            mid = mid.next;
        }
    }
    return mid;
};
