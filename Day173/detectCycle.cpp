class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head)return false;
        ListNode* slow,*fast;
        slow = head;
        fast = head;
        
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                    return true;
        }
        return false;
    }
};