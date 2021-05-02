/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
  int carry = 0;
  struct ListNode *start = l1, *prev = NULL;

  // Sum numbers until both lists have values.
  while (l1 && l2) {
    int digit = carry + l1->val + l2->val;
    if (digit >= 10) {
      carry = 1;
      digit %= 10;
    } else
      carry = 0;
    l1->val = digit;
    prev = l1;
    l1 = l1->next;
    l2 = l2->next;
  }

  // One might still have values. Add them, keep reference to
  // final valid node in order to add carry if necessary.
  struct ListNode *final = NULL;
  if (l1) {
    while (l1) {
      int digit = carry + l1->val;
      if (digit >= 10) {
        carry = 1;
        digit %= 10;
      } else
        carry = 0;
      l1->val = digit;
      final = l1;
      l1 = l1->next;
    }
    if (carry == 1) {
      struct ListNode *end = malloc(sizeof(*end));
      end->val = carry;
      end->next = NULL;
      final->next = end;
    }
  } else if (l2) {
    prev->next = l2;
    while (l2) {
      int digit = carry + l2->val;
      if (digit >= 10) {
        carry = 1;
        digit %= 10;
      } else
        carry = 0;
      l2->val = digit;
      final = l2;
      l2 = l2->next;
    }
    if (carry == 1) {
      struct ListNode *end = malloc(sizeof(*end));
      end->val = carry;
      end->next = NULL;
      final->next = end;
    }
  } else {
    if (carry == 1) {
      struct ListNode *end = malloc(sizeof(struct ListNode));
      end->next = NULL;
      end->val = carry;
      prev->next = end;
    }
  }
  return start;
}