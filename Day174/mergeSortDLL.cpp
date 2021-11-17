struct Node* merge(struct Node* first,struct Node *second)
{
    if(!first)return second;
    if(!second)return first;
    
    if(first->data < second->data)
    {
        first->next = merge(first->next,second);
        //coz the f->next will now contain a new node discerned from criteria
        first->next->prev = first;
        first->prev=NULL;
        return first;
    }
    else{
        second->next = merge(first,second->next);
        second->next->prev=second;
        second->prev = NULL;
        return second;
    }
}
struct Node* splitList(struct Node* head)
{
    struct Node* fast=head,*slow=head;
    while(fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    struct Node* temp=slow->next;
    slow->next=NULL;
    return temp;
}


//Function to sort the given doubly linked list using Merge Sort.
struct Node *sortDoubly(struct Node *head)
{
	if(!head || head->next==NULL)return head;
	
	struct Node* second = splitList(head);
	head = sortDoubly(head);
	second = sortDoubly(second);
	return merge(head,second);
}
