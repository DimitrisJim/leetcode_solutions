var addTwoNumbers = function(l1, l2) {
  let carry = 0, start = l1, prev = null;
  // both lists haven't been exhausted
  while (l1 && l2) {
    let digit = l1.val + l2.val + carry;
    if (digit >= 10) {
      carry = 1;
      digit %= 10;
    } else
      carry = 0;
    l1.val = digit;
    prev = l1;
    l1 = l1.next;
    l2 = l2.next;
  }
  // continue with the rest, keep reference to previous valid
  // node in order to add carry if it exists.
  let final = null;
  if (l1) {
    while (l1) {
      let digit = l1.val + carry;
      if (digit >= 10) {
        carry = 1;
        digit %= 10;
      } else
        carry = 0;
      l1.val = digit;
      final = l1;
      l1 = l1.next;
    }
    if (carry) final.next = new ListNode(1);
  } else if (l2) {
    prev.next = l2;
    while (l2) {
      let digit = l2.val + carry;
      if (digit >= 10) {
        carry = 1;
        digit %= 10;
      } else
        carry = 0;
      l2.val = digit;
      final = l2;
      l2 = l2.next;
    }
    if (carry) final.next = new ListNode(1);
  } else {
    if (carry) prev.next = new ListNode(1);
  }
  return start
};