void removeLoop(Node* head)
    {
        Node *slow=head,*fast=head;
        
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow==fast)
            {   
                break;
            }
        }
        if(slow!=fast)return;
        
        if(slow == head){
            while(fast->next != slow)
                fast = fast->next;
            fast->next = NULL;
            return;
        }
        slow = head;
        while(slow->next != fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = NULL;
        // return;
    }