// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends
/*

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
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        if (k == 0) 
        return head;
        
        Node *walk = head;
        Node *prev;
        
        //this loop runs k times and walk pointer moves k nodes ahead 
        //and reaches new head node.
        while( k-- && walk!=NULL )
        {
            prev = walk;
            walk = walk->next;
        }
        //considering cases where k>=n so nothing needs to be done.
        if(!walk) return head; 
        
        //we store the walk pointer which gives the first node in newHead.
        Node* newHead = walk;
        
        //since prev points to the node placed before new head it is new tail
        //or the last node of new list so we store null in it's link part.
        prev->next = NULL;
        
        //we keep moving the walk pointer till we reach the last node of list.
        while( walk->next )
            walk = walk->next;
        
        //connecting last node of old list to old head.
        walk->next = head;
        
        //returning the new list.
        return newHead;
    }
};

    


// { Driver Code Starts.

void printList(Node *n)
{
    while (n != NULL)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, val, k;
        cin>>n;
        
        cin>> val;
        Node *head = new Node(val);
        Node *tail = head;
        
        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }
        
        cin>> k;
        
        Solution ob;
        head = ob.rotate(head,k);
        printList(head);
    }
    return 1;
}
  // } Driver Code Ends