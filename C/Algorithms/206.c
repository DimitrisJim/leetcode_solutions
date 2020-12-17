#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
  int val;
  struct ListNode *next;
};
typedef struct ListNode node;

struct ListNode *reverseList(struct ListNode *head) {
  struct ListNode *new_head = NULL, *tail, *tmp;
  while (head) {
    tmp = head;
    tail = new_head;
    head = head->next;
    new_head = tmp;
    new_head->next = tail;
  }
  return new_head;
}

node *reverse(node *head, node *tail) {
  if (!head)
    return tail;
  node *tmp = tail;
  tail = head;
  head = head->next;
  tail->next = tmp;
  return reverse(head, tail);
}

node *reverseList_recurse(node *head) { return reverse(head, NULL); }
