// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


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
            fast = source->next;
            while (fast != NULL) {
                fast = fast->next;
                if (fast != NULL) {
                    slow = slow->next;
                    fast = fast->next;
                }
            }
            
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


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends