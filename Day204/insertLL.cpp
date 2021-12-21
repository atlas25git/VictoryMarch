class Solution{
  public:
    //Function to insert a node at the beginning of the linked list.
    Node *insertAtBegining(Node *head, int x) {
       Node* curr = new Node(x);
       if(!head)return curr;
       curr->next = head;
       head = curr;
       return head;
    }
    
    
    //Function to insert a node at the end of the linked list.
    Node *insertAtEnd(Node *head, int x)  {
       if(!head)return new Node(x);
       Node* curr = head;
       while(curr->next)curr=curr->next;
       curr->next = new Node(x);
       return head;
    }
};