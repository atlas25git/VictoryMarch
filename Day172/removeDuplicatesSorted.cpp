class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head,*prev = NULL;
        
        while(curr)
        {
            if(!prev)
                    prev = curr;
            else if(prev->val == curr->val)
            {
                prev->next = curr->next;
                
            }
            else
                prev = curr;
            curr = curr->next;
        }
        return head;
    }
};