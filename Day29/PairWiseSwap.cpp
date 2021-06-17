// { Driver Code Starts
//Initial Template for C++

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
//Function to swap elements pairwise.
struct Node* pairwise_swap(struct Node* head)
{   
    Node* h1=head; 
    while(head->next!=NULL && head->next->next!=NULL)
    {   
        int data = head->data;
        head->data = head->next->data;
        head->next->data = data;
        head = head->next->next;
    }
    if(head->next)
    {
         int data = head->data;
        head->data = head->next->data;
        head->next->data = data;
        head = head->next->next;
    }
    return h1;
}

// { Driver Code Starts.
void printList(struct Node* node) 
{ 
    while (node!=NULL) 
    { 
        printf("%d ", (node)->data); 
        node = (node)->next; 
    } 
}

int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n, l,firstdata;
        cin>>n;
        // taking first node of linked list
        cin>>firstdata;
        struct Node* head = new Node(firstdata);
        struct Node* tail = head;
        // taking remaining nodes of linked list
        for(int i = 1; i < n; i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        head =pairwise_swap(head);
        printList(head);
        cout << endl;
    }
}  // } Driver Code Ends