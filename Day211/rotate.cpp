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
        if(!head || !k)return head;
        int cnt = 0;
        ListNode* curr = head;
        while(curr)
            curr = curr->next,
            cnt++;
        if(cnt<=k)
            k%=cnt;
        
        if(!k)return head;
        
        curr = head;
        int posS = cnt - k;
        
        // cout<<cnt<<" "<<k<<" "<<posS<<"\n";
        curr = head;
        ListNode* prev = NULL;
        while(posS-->0)
        {
            prev =curr;
            curr = curr->next;
        }
        
        // cout<<curr->val<<" "<<prev->val<<" \n";
        
        prev->next = NULL;
        ListNode* nH = curr;
        
        while(curr->next)
        {
            curr = curr->next;
                
        }
        curr->next = head;
        return nH;
    }
};