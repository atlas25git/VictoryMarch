Node* insertInMiddle(Node* head, int x)
{
	Node* slow=head, *fast=head;
	if(!head)return new Node(x);
	
	while(fast->next && fast->next->next)slow=slow->next,fast=fast->next->next;
	
	Node* temp = slow->next;
	slow->next = new Node(x);
	slow->next->next = temp;
	
	return head;
}