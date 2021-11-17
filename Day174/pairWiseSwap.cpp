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
    ListNode* swapPairs1(ListNode* head) {
        
        if(!head || !head->next)return head;
        ListNode* prev,*curr;
        
        curr = head->next->next;
        prev = head;
        
        head = head->next;
        head->next = prev;
        
        while(curr && curr->next)
        {
            prev->next = curr->next;
            prev = curr;
            ListNode* temp = curr->next->next;
            curr->next->next = curr;
            curr = temp;
        }
        prev->next = curr;
        
        return head;
    }
    
    //Recursive:
     ListNode* swapPairs(ListNode* head) {
        //In the recursive approach we're tackling nodes 2 at a time.
        //And we fix both the nodes.
        //And reinstate our loop invariable as current leftmost node
         
         //BaseCase:
         if(!head || !head->next)
                return head;
         
         ListNode* subResult = swapPairs(head->next->next);
         
         //fixing the case in point of 2 nodes
         ListNode* curr,*nxt;
         curr = head;
         nxt = head->next;
         
         //fixing the nodes
         curr->next = nxt->next;
         nxt->next = curr;
         curr->next = subResult;
         
         return nxt;
        
    }
};