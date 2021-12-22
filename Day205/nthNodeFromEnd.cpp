//Function to find the data of nth node from the end of a linked list.
int getNthFromLast(Node *head, int n)
{
       int c = 0;
       Node* curr = head;
       while(curr)c++,curr=curr->next;
       if(c<n)return -1;
       
       int posStart = c - n;
       
       while(posStart-->0)
            head = head->next;
        return head->data;
}
