// Definition for singly-linked list.
struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *middleNode(struct ListNode *head) {
  struct ListNode *mid = head;
  int inc = 0;
  while ((head = (*head).next)) {
    if ((inc = !inc))
      mid = (*mid).next;
  }
  return mid;
}
