class Solution {
public:
    ListNode* reverseList(ListNode* head) {
       if(!head || !head->next)return head;
        
        // ListNode* fHead = reverseList(head->next);
        // ListNode* fTail = head->next;
        // fTail->next = head;
        // head->next = NULL;
        // return fHead;
        
        ListNode* c=head,*n=0,*p=0;
        while(c)
        {
            n = c->next;
            c->next = p;
            p = c;
            c=n;
        }
        return p;
    }
};



class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        Node* curr=head,*next=NULL,*prev=NULL;
        while(curr)
        {
            next = curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    
};