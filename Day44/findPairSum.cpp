// { Driver Code Starts
// Initial Template for C++

// CPP program to find a pair with
// given sum using hashing
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

Node* insert(Node* root, int key) {
    if (root == NULL) return new Node(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}


bool findPair(Node* root, int sum);

// Driver code
int main() {

    int t;
    cin >> t;
    while (t--) {
        Node* root = NULL;
        int n, x;
        cin >> n;
        int val;
        for (int i = 0; i < n; i++) {
            cin >> val;
            root = insert(root, val);
        }
        cin >> x;
        if (findPair(root, x))
            cout << "1" << endl;
        else
            cout << "0" << endl;
    }

    return 0;
}// } Driver Code Ends



void check(Node* root,unordered_set<int>& s,int sum,int& mark)
{
        if(!root)return;
        //inorder traversal
        check(root->left,s,sum,mark);
        
        if(s.find(sum - root->data)!=s.end())
            {mark++;return;}
        else s.insert(root->data);
       
        check(root->right,s,sum,mark);
}

//Function to check if any pair exists in BST whose sum is equal to given value.
bool findPair(Node* root, int X) 
{
    //simp approach
    //maintain a set and look up for the pair
    //to be present just like in arrays using inorder
    //traversal
    unordered_set<int> s;
    int mark=0;
    check(root,s,X,mark);
    if(mark)
        return true;
    else 
        return false;
}



