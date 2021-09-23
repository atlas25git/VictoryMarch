bool del2(Node* head)
{
    if(!head)return 1;
    
    // 1 1 2

    Node* prev,*curr;

    prev = head;
    curr = head;

    while(curr || curr->next)
    {   
        if(curr->data == curr->next->data)
        {
            curr = curr->next;
            if(prev->data == curr->data)
                {
                    prev->next = curr->next;

                }
            prev = curr;
        } 
        else
        {
        prev = prev->next;
        curr = curr->next;
        }
    } 

    return head;

}


a1 : 1,5,7,9,12
a2 : 2,3,8,10,11,-1//times 5