// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
   int data;
   Node* left;
   Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
   Node* temp = new Node;
   temp->data = val;
   temp->left = NULL;
   temp->right = NULL;

   return temp;
}




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
   Node* root = newNode(stoi(ip[0]));

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
           currNode->left = newNode(stoi(currVal));

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
           currNode->right = newNode(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}

int floor(Node* root, int key) ;



int main() 
{
   
   
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
       string s ,ch;
       getline(cin, s);
       Node* root = buildTree(s);
       getline(cin, s);
       int x = stoi(s);

       int ans = floor(root, x);
       cout << ans << "\n";
   }
   return 0;
} // } Driver Code Ends


//User function Template for C++


//Function to return the floor of given number in BST.
int floor(Node* root, int key) 
{ 
	if(!root)return -1;
	Node* res = NULL;
	
	while(!!root)
	{
	    if(root->data == key)
	    {
	        return root->data;
	    }
	    else if(root->data > key)
	        
	        {
	        //if the current root's data is gr8r than key
	        //essentially our data lies in left of ST
	        root = root->left;
	        }
	    else if(root->data < key)
	    {
	       //here the contingency lies that here could be some
	       //number gr8r than current data but smlr than key
	       //thus the more legitimate floor
	       //in res thus we maintian the oreder of these events
	       res= root;
	       root=root->right;
	    }
	    
	}
	//cout<<res->data;
	return !res?-1:res->data;
	

}
