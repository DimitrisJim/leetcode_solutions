struct ListNode *swapPairs(struct ListNode *head) {
  if (!head || !(head->next))
    return head;

  // Track previous, current, next.
  struct ListNode *current = head, *previous = NULL, *next = current->next;
  head = next;
  while (next) {
    current->next = next->next;
    next->next = current;
    if (previous)
      previous->next = next;

    // reassign previous, next, current.
    previous = current;
    current = current->next;
    if (!current)
      break;
    next = current->next;
  }
  return head;
}