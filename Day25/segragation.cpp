// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


 // } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(struct Node *head) {
    if (!head || !(head->next))
        return head;
  
    //creating three dummy nodes to point to beginning of three linked lists. 
    Node* zeroD = new Node(0); 
    Node* oneD = new Node(0); 
    Node* twoD = new Node(0); 
  
    //initializing current pointers for three lists. 
    Node* zero = zeroD, *one = oneD, *two = twoD; 
  
    //traversing over the list with a pointer. 
    Node* curr = head; 
    while (curr) { 
        
        //we check data at current node and store the node in it's respective
        //list and update the link part of that list.
        if (curr->data == 0) { 
            zero->next = curr; 
            zero = zero->next; 
            curr = curr->next; 
        }
        else if (curr->data == 1) { 
            one->next = curr; 
            one = one->next; 
            curr = curr->next; 
        } 
        else { 
            two->next = curr; 
            two = two->next; 
            curr = curr->next; 
        } 
    } 
  
    //attaching the three lists containing 0s,1s and 2s respectively.
    zero->next = (oneD->next) ? (oneD->next) : (twoD->next); 
    one->next = twoD->next; 
    two->next = NULL; 
  
    //updating the head of the list.
    head = zeroD->next; 
  
    //deleting dummy nodes.
    delete zeroD; 
    delete oneD; 
    delete twoD; 
  
    return head;
}

};


// { Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}  // } Driver Code Ends