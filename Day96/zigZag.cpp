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
	bool left = true;
	
	while (!currentlevel.empty())
	{
	    //storing the top element of currentlevel stack in temp and popping it.
		Node* temp = currentlevel.top();
		currentlevel.pop();
		res.push_back (temp->data);
		
			if (left)
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
			left = !left;
			swap(currentlevel, nextlevel);
		}
	}
	return res;
}
};