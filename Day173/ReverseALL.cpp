class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        
        if(!head || !head->next)return head;
        
        ListNode* revHead,*tail,*rem;
        rem = head;
        tail = head->next;
        revHead = reverseList(head->next);
        
        //connecting the remaning part
        tail->next = rem;
        rem->next = NULL;
        return revHead;
    }
};