int getNthFromLast(Node *head, int n)
{   
        if(!head)return -1;
       Node* temp = head;
       int s=0;
       while(temp)temp=temp->next,s++;
       
       n = s-n;
       if(n<0)return -1;
       while(n--)
       {
            head = head->next;    
       }
        
    return head->data;
}
