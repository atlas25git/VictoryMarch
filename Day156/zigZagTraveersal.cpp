class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	vector<int>res;
    	stack<Node*> cl;
    	stack<Node*> nl;
    	cl.push(root);
    	bool nxtLvlRight = true;
    	while(!cl.empty())
    	{
    	    Node* cr = cl.top();
    	    cl.pop();
    	    res.push_back(cr->data);
    	    
    	    if(nxtLvlRight)
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
    	        nxtLvlRight = !nxtLvlRight;
    	    }
    	}
    	
    	return res;
    }
};