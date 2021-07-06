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


 // } Driver Code Ends



class Solution
{
    public:
    
    void fill(Node* root, vector<int>& res)
    {
        if(!root)return;
        fill(root->left,res);
        res.push_back(root->data);
        fill(root->right,res);
    }
    
    //Function to find the nodes that are common in both BST. 
    vector <int> findCommon(Node *root1, Node *root2)
    {
     vector<int> res1,res2;
     fill(root1,res1);
     fill(root2,res2);
    set<int> s;
    if(res1.size()<res2.size())swap(res1,res2);
    vector<int> res3;
    for(auto x: res2)
    {
        if(find(res1.begin(),res1.end(),x)!=res1.end())
            res3.push_back(x);
    }
    return res3;
    
     
    }
};




// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root1 = buildTree(s);

        getline(cin,s);
        Node* root2 = buildTree(s);
        Solution ob;
        vector <int> res = ob.findCommon(root1, root2);
        for (int i : res)
            cout << i << " ";
        cout<< endl;
    }

	return 1;
}  // } Driver Code Ends


//optimized:
class Solution
{
    public:
    //Function to find the nodes that are common in both BST. 
    vector <int> findCommon(Node *root1, Node *root2)
    {
        //creating two stacks for inorder traversals of both BST.
	    stack<Node *> stack1, s1, s2;
        vector <int> res; 
        
	    while (1)
	    {
	        //pushing the nodes of first BST in stack s1. 
		    if (root1)
		    {
			    s1.push(root1);
			    root1 = root1->left;
		    }
    		//pushing the nodes of second BST in stack s2.
		    else if (root2)
		    {
			    s2.push(root2);
			    root2 = root2->left;
		    }
		    //when both root1 and root2 become NULL
		    else if (!s1.empty() && !s2.empty())
		    {
    			root1 = s1.top();
			    root2 = s2.top();
    			
	    		//if data at current node in two BST's are same, we 
	    		//store it in output list.
		    	if (root1->data== root2->data)
			    {
				    res.push_back (root1->data);
				    //popping element from both stacks.
				    s1.pop();
    				s2.pop();
    				//moving to the inorder successor 
	    			root1 = root1->right;
		    		root2 = root2->right;
			    }
                //if data at current node of first BST is smaller than that of 
                //second BST then it's obvious that inorder successors of 
                //current node can have same value as that of second BST node. 
    			else if (root1->data< root2->data)
	    		{
		    	    //popping element from stack s1.
		    		s1.pop();
			    	root1 = root1->right;
				    
    				//root2 is set to NULL since we need new nodes of first BST. 
		    		root2 = NULL;
			    }
			    else if (root1->data> root2->data)
    			{
    			    //popping element from stack s1.
	    			s2.pop();
		    		root2 = root2->right;
		    		//root1 is set to NULL since we need new nodes of second BST.
			    	root1 = NULL;
    			}
	    	}
	    	else break;
	    } 
	    //returning the output list.
	    return res;
    }
};