void addNode(Node *head, int pos, int data)
{
   Node* nN = new Node(data);
   if(!head)head = nN;
   Node* curr = head;
   while(pos-->0)curr=curr->next;
   
   nN->next = curr->next;
   if(curr->next)curr->next->prev = nN;
   curr->next = nN;
   nN->prev = curr;
   
   
}