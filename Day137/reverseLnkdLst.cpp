class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList1(struct Node *head)
    {   
        if(!head || !head->next)return head;
        
        //tail since it's the last element for the recusrive call made.
        Node* rest_tail = head->next;
        
        //will return head of reversed list
        Node* rest_head = reverseList(head->next);

        //fixing the head node
        rest_tail->next = head;
        
        head->next = NULL;
        
        return rest_head;
    }
    
    struct Node* reverseList(Node* head)
    {
      
        if(!head || !head->next)return head;
        
        Node* tail = head->next;
        Node* fhead = reverseList(head->next);
        //connecting tail to the remaining part
        tail->next = head;
        head->next=NULL;
        
        return fhead;    
    }
};