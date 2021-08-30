// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};



struct Node* deleteNode(struct Node* root, int key);

// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}

void inorder(Node *root, vector<int> &v)
{
    if(root==NULL)
        return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int main() {
   
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
    string s; 
    getline(cin, s);
    Node* root1 = buildTree(s);
    getline(cin, s);
    int k = stoi(s);
    root1  = deleteNode(root1, k);
    vector<int> v;
    inorder(root1, v);
    for(auto i:v)
        cout << i << " ";
    cout << endl;
   }
   return 0;
}// } Driver Code Ends




//Function to delete a node from BST.
//Function to find the node with minimum element.
Node *minValueNode(Node *nod)
{
    Node *current = nod;
    while(current->left !=NULL)
        current = current->left;
    return current;
}

//Function to delete a node from BST.
Node* deleteNode(Node* root, int key)
{
    
    // base case
    if (root == NULL)
    return root;
    
    //if given value is less than data at current node, we call function 
    //recursively to delete in left subtree.
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    
    //else if given value is more than data at current node, we call function 
    //recursively to delete in right subtree.
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    
    //else we need to delete the current node. 
    else
    {
        //if node is with only one child or no child. 
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        
        //if node has two children, getting the inorder successor  
        //(smallest in the right subtree). 
        struct Node* temp = minValueNode(root->right);
        
        //copying the inorder successor's data to this node.
        root->data = temp->data;
        
        //deleting the inorder successor.
        root->right = deleteNode(root->right, temp->data);
    } 
    return root;
}
