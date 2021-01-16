#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2) {
  if (!l1 && !l2)
    return NULL;

  // New always points to beginning, ref goes through the
  // two linked lists.
  struct ListNode *new = malloc(sizeof(*new)), *ref, *rem;
  ref = new;
  while (l1 && l2) {
    if (l1->val <= l2->val) {
      ref->val = l1->val;
      l1 = l1->next;
    } else {
      ref->val = l2->val;
      l2 = l2->next;
    }
    ref->next = malloc(sizeof(*ref));
    ref = ref->next;
  }

  rem = l1 ? l1 : l2;
  while (rem) {
    ref->val = rem->val;
    rem = rem->next;
    if (rem) {
      ref->next = malloc(sizeof(*ref));
      ref = ref->next;
    }
  }
  // Remember to set final next value to NULL.
  ref->next = NULL;
  return new;
}
