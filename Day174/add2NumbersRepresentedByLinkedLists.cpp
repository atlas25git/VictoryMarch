class Solution
{
    public:
    
    Node* rec(Node*& head)
    {
        if(!head || !head->next)return head;
        Node* rem = head;
        Node* tail = head->next;
        
        Node* newH = rec(head->next);
        tail->next = rem;
        rem->next = NULL;
        
        return newH;
    }   
    
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        first = rec(first);
        second = rec(second);
        // Node* temp = second;
        // while(temp)cout<<temp->data<<" ",temp = temp->next;
        
        Node* dh = new Node(0);
        Node* f=first,*s=second,*curr=dh;
        int carry = 0;
        
        while(f || s)
        {
            int x = f?f->data:0;
            int y = s?s->data:0;
            int sum = x+y+carry;
            carry = sum/10;
            curr->next = new Node(sum%10);
            curr = curr->next;
            if(f)f=f->next;
            if(s)s=s->next;
        }
        
        if(carry)
            curr->next = new Node(carry);
            
        return rec(dh->next);
    }
};
