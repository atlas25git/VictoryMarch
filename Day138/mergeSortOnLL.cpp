class Solution{
  public:
  
    //Function to split the list into two halves.
    void splitList(Node* source, Node*& frontRef, Node*& backRef) {
        
        //using two pointers to find the midpoint of list.
        struct Node* fast;
        struct Node* slow;
        if (source == NULL || source->next == NULL) {
            frontRef = source;
            backRef = NULL;
        } else {
            
            //first pointer, slow moves 1 node and second pointer, fast moves
            //2 nodes in one iteration.
            slow = source;
            fast = source;
            
            while(fast->next && fast->next->next)
            {
                slow = slow->next;
                fast = fast->next->next;
            }
            // 1 2 3 4 5 6
            // s s s 
            // f   f   f
            // while (fast != NULL) {
            //     fast = fast->next;
            //     if (fast != NULL) {
            //         slow = slow->next;
            //         fast = fast->next;
            //     }
            // }
            
            //slow is before the midpoint in the list, so we split the 
            //list in two halves from that point.
            frontRef = source;
            backRef = slow->next;
            //This step seperates the front ref mid way
            slow->next = NULL;
            
        }
    }
    
    //Function to merge two halves of list.
    Node* mergeList(struct Node* a, struct Node* b) {
        struct Node* result = NULL;
        
        //base cases when either of two halves is null.
        if (a == NULL)
            return (b);
        else if (b == NULL)
            return (a);
            
        //comparing data in both halves and storing the smaller in result and
        //recursively calling the mergeList function for next node in result.
        if (a->data <= b->data) {
            result = a;
            result->next = mergeList(a->next, b);
        } else {
            result = b;
            result->next = mergeList(a, b->next);
        }
        //returning the resultant list.
        return (result);
    }
    
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node *head) {
        
        struct Node* a;
        struct Node* b;
        
        if (head == NULL || head->next == NULL) 
        return head;
        
        //splitting the list into two halves.
        splitList(head, a, b);
        
        //calling the mergeSort function recursively for both parts separately.
        a = mergeSort(a);
        b = mergeSort(b);
        
        //calling the function to merge both halves.
        return mergeList(a, b);
    }

};
