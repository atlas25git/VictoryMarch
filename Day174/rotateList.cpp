/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int cnt = 0;
        if(!head || !head->next || !k)return head;
        ListNode* curr = head;
        while(curr->next)curr = curr->next,cnt++;
        
        cnt++;
        k = k%cnt;
        // cout<<cnt<<" "<<k<<" "<<curr->val<<"\n";
        
        curr->next = head;
        int strt = cnt - k-1;
        curr = head;
        while(strt--)
            curr = curr->next;
        head = curr->next;
        curr->next = NULL;
        return head;
    }
};