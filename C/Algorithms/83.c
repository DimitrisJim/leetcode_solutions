struct ListNode *deleteDuplicates(struct ListNode *head) {
  if (!head)
    return head;

  struct ListNode *original_head = head, *next = NULL;
  while (head->next) {
    next = head->next;
    if (head->val == next->val)
      head->next = next->next;
    else
      head = next;
  }
  return original_head;
}