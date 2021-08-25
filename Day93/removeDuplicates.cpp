Node* removeDuplicates(Node *head)
{
   //using a pointer to iterate over linked list.
   struct Node* current = head;
    
    //traversing through the linked list.
    while (current->next != NULL)       
    {
        //if data at current node and next node are same, we store the node 
        //next to the next node of current node in link of current node.
        if (current->data == current->next->data)
           current->next = current->next->next;
           
        //else we just move the pointer to next node.
        else
           current = current->next; 
    }
    return head;
    
}