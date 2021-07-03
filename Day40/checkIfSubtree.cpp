// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

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

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution
{
    vector<Node*> nodes;
    
  public:
    
    bool isSubTree(Node* T, Node* S) 
    {
        if(!S && !T)return true;
        if(!S || !T)return false;
        
        
        int dis = getDepth(S,-1);
        //cout<<"dis "<<dis<<" ";
        //stores all the nodes with depth equal to subtree
        getDepth(T,dis);
        //cout<<nodes.size()<<"s";
        for(Node* n: nodes)
            {   //cout<<"n "<<n<<" ";
                if(identical(n,S))
                    return true;
            }
        return false;
        
    }
    
    
    int getDepth(Node* r,int d)
    {
        if(!r)return -1;
        
        int depth = max(getDepth(r->left,d),getDepth(r->right,d))+1;
       
        if(depth == d)
            nodes.push_back(r);
        return depth;
    }
    
    bool identical(Node* a,Node* b)
    {
        if(!a && !b)return true;
        if(!a || !b || a->data != b->data)return false;
        return identical(a->left,b->left) && identical(a->right,b->right);
    }
    
    
    
};

// { Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string strT, strS;
        getline(cin, strT);
        Node *rootT = buildTree(strT);
        getline(cin, strS);
        Solution obj;
        Node *rootS = buildTree(strS);
        cout << obj.isSubTree(rootT, rootS) << "\n";

    }
    return 0;
}  // } Driver Code Ends