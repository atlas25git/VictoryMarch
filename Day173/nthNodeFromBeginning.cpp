class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 0;
        ListNode* curr = head;
        while(curr)curr=curr->next,cnt++;
        if(cnt == n)return head->next;
        n = cnt - n -1;
        curr = head;
        while(n--){curr = curr->next;}
        // delete(curr->next);
        curr->next = curr->next->next;
        return head;
    }
};