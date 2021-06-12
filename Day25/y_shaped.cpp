// { Driver Code Starts
#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

/* Driver program to test above function*/
int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

int getSize(Node* head)
{
    // if(head==NULL)return 0;
    // else
    // return 1+ getSize(head->next);
    int c=0;
    while(head)
    {
        c++;
        head=head->next;
    }
    return c;
}

//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{   
    int h1=getSize(head1);
    int h2 =getSize(head2);
    //cout<<h1<<" "<<h2<<endl;
    
    if(h1<h2)
    {
        Node* temp=head1;
        head1=head2;
        head2=temp;
    }
     int k=abs(h1-h2);
    while(k--)
    {
        head1=head1->next;
        
    }
    //cout<<"adv"<<head1->data<<endl;
    //set<int> s;
    //cout<<"LL: ";
    while(head1->next != head2->next)
    {
        head2=head2->next;
        head1=head1->next;
    }
    return head1->next->data;
}

