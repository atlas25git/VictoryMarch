class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int cnt = 0;
        ListNode* curr = head;
        while(curr)cnt++,curr=curr->next;
        if(2*k-1 == cnt)return head;
        
        ListNode* kBegPrev = NULL,*kBeg = head,*kEndPrev = NULL,*kEnd = head;
        
        int begK = k-1;
        while(begK--)kBegPrev=kBeg,kBeg = kBeg->next;
        
        int endK = cnt-k;
        while(endK--)kEndPrev = kEnd,kEnd = kEnd->next;
        
        if(kBegPrev)kBegPrev->next = kEnd;
        if(kEndPrev)kEndPrev->next = kBeg;
        
        swap(kBeg->next,kEnd->next);
        
        //special cases when head node has been swapped
        if(k==1)
            //in this case kBeg contains the head that is swapped hence final head is in kEnd
            head = kEnd;
        if(k==cnt)
            //in this case kBeg contains the last node which will become the head after swap.
            head = kBeg;
        return head;
    }
};