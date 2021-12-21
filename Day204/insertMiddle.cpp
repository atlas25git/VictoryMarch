Node* insertInMiddle(Node* head, int x)
{
	Node* slow=head,*fast = head;
	
	while(fast->next && fast->next->next)
	{
	    slow = slow->next;
	    fast = fast->next->next;
	}
	Node* nN = new Node(x);
	nN -> next = slow->next;
	
	slow->next = nN;
	
	return head;
}