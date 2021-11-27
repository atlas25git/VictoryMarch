// Function to return the floor of given number in BST.
int floor(Node* root, int key) 
{ 
	if(!root)return -1;
	Node* res = NULL;
	
	while(root)
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
	       //in res thus we maintian the order of these events
	       res= root;
	       root=root->right;
	    }
	    
	}
	//cout<<res->data;
	return !res?-1:res->data;
}

