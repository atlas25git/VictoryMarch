class Solution{
    public:
//Function to store the zig zag order traversal of tree in a list.
vector <int> zigZagTraversal(Node* root)
{
    vector <int> res;
    
    //if root is null, we return the list.
	if (!root)return res;
	
	//declaring two stacks to store the current and new level.
	stack<struct Node*> currentlevel;
	stack<struct Node*> nextlevel;
	
	//pushing the root in currentlevel stack.
	currentlevel.push(root);
	bool right = true;
	
	while (!currentlevel.empty())
	{
	    //storing the top element of currentlevel stack in temp and popping it.
		Node* temp = currentlevel.top();
		currentlevel.pop();
		res.push_back (temp->data);
		
			if (right)
			{
				if (temp->left)
					nextlevel.push(temp->left);
				if (temp->right)
					nextlevel.push(temp->right);
			}
			//to preserve the last access in stacks
			else 
			{
				if (temp->right)
					nextlevel.push(temp->right);
				if (temp->left)
					nextlevel.push(temp->left);
			}

		if (currentlevel.empty()) 
		{
			right = !right;
			swap(currentlevel, nextlevel);
		}
	}
	return res;
}
};

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	vector<int>res;
    	stack<Node*> cl;
    	stack<Node*> nl;
    	cl.push(root);
    	bool right = true;
    	while(!cl.empty())
    	{
    	    Node* cr = cl.top();
    	    cl.pop();
    	    res.push_back(cr->data);
    	    if(right)
    	    {
    	        if(cr->left)
    	            nl.push(cr->left);
    	        if(cr->right)
    	            nl.push(cr->right);
    	    }
    	    else
    	    {
    	        if(cr->right)
    	           nl.push(cr->right);
    	       if(cr->left)
    	            nl.push(cr->left);
    	    }
    	    
    	    if(cl.empty())
    	    {
    	        swap(cl,nl);
    	        right = !right;
    	    }
    	}
    	
    	return res;
    }
};
