var deleteDuplicates = function(head) {
  if (!head) return head;

  let original_head = head;
  while (head.next) {
    let next = head.next;
    if (head.val == next.val)
      head.next = next.next;
    else
      head = next;
  }
  return original_head;
};