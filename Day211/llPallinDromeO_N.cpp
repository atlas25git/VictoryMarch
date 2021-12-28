class Solution{
  public:
    //Function to check whether the list is palindrome.
    Node* reverse_list(Node* head)
    {
        Node* prev = NULL;     
        Node* curr = head;   
        Node* next; 
        
        while(curr)
        {
            next = curr->next; 
            curr->next = prev;    
            prev = curr;         
            curr = next; 
        }
        return prev;
        
    }
    
    //Function to check whether two lists are identical.
    bool is_identical(Node* n1, Node* n2)
    {
        //iterating over both lists and returning 0 if data at any node
        //is not equal in both lists.
        for(  ; n1 && n2 ; n1=n1->next, n2=n2->next )
            if( n1->data != n2->data )
                return 0;
                
        //returning 1 if data at all nodes are equal.
        return 1;
    }
    
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        int size=0;
        Node* ptr;
        //finding number of nodes in the list.
        for( ptr=head ; ptr ; ptr=ptr->next )
            size++;
            
        
        if(size<2) return 1;
        
        //now, we split list into 2 halves. In case of odd number of elements, 
        //first half will have the middle element.
        //7
        //mid_pt = 3
        // 1,2,3,4, h2:5,6,7
        ptr = head;
        int mid_pt = (size-1)/2;
        
        //using a pointer to get to middle element to get the second half of list.
        while(mid_pt--)
            ptr = ptr->next;
            
        //ptr now holds address of last element of first half.
        
        //storing the elements of second half separately in head2.
        Node* head2 = ptr->next;
        ptr->next = NULL;     
        
        //we reverse the second half of list.
        head2 = reverse_list(head2);
        
        //we check whether both halves are identical (for odd number of elements
        //first half will have one extra element).
        bool ret = is_identical(head, head2);
        
        //we reverse back the second half of list and connect it to the first half.
        head2 = reverse_list(head2);
        ptr->next = head2;
        
        //returning 1 if list is palindrome else 0.
        return ret;
    }
};