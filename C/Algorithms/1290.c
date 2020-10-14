struct ListNode {
    struct ListNode* next;
    int val;
};

int getDecimalValue(struct ListNode* head){
    unsigned sum = head->val;
    struct ListNode* next = head->next;
    while (next != NULL){
        sum <<= 1;
        sum |= next->val;
        next = next->next;
    }
    return sum;
}

// Equivalent for loop.
int getDecimalValue2(struct ListNode* head){
    int sum;
    for(sum = head->val; head->next; sum <<= 1, head=head->next, sum |= head->val);
    return sum;
}
