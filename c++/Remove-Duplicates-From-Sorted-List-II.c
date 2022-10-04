//Leetcode problem :- 82. Remove Duplicates from Sorted List II


struct ListNode* deleteDuplicates(struct ListNode* head){
    
    if(head == NULL || head->next==NULL)
        return head;
    
    struct ListNode *newHead, *prev;
    newHead=(struct ListNode*)malloc(sizeof(struct ListNode)*1);
    newHead->next=head;
    prev=newHead;
        
    while(head)
    {
        if(head->next && head->val == head->next->val)
        {
            while(head->next && head->val == head->next->val)
            {
                head=head->next;
            }
            prev->next = head->next;
            head= head->next;
        }
        else
        {
            prev=head;
            head=head->next;
        }
    }
    
    return newHead->next;
}
