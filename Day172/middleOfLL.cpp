class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* n1 = head;
        ListNode* n2 = head;
        
        while(n2->next && n2->next->next){
            
            n1 = n1->next;
            n2 = n2->next->next;
        }
        if(n2->next)
            return n1->next;
        return n1;
    }
};