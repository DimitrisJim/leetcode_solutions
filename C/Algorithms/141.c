bool hasCycle(struct ListNode *head) {
  if (!head || !head->next)
    return false;

  struct ListNode *start = head, *run = head->next->next;
  while (start && run) {
    if (start == run)
      return true;
    start = start->next;
    if (!run->next)
      return false;
    run = run->next->next;
  }
  return false;
}