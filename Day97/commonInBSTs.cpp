class Solution
{
    public:
    //Function to find the nodes that are common in both BST. 
    vector <int> findCommon(Node *root1, Node *root2)
    {
        stack<Node*> s0,s1,s2;
        vector<int> res;
        while(1)
        {
            if(root1)
                s1.push(root1),root1 = root1->left;
            else if(root2)
                s2.push(root2),root2=root2->left;
            else if(!s1.empty() && !s2.empty())
            {
                root1 = s1.top();
                root2 = s2.top();
                if(root1->data == root2->data)
                {
                    res.push_back(root1->data);
                    s1.pop(),s2.pop();
                    root1=root1->right;
                    root2=root2->right;
                }
                else if(root1->data < root2->data)
                {
                    s1.pop();
                    root1 = root1->right;
                    root2 = NULL;//will stop it from r2's nodes being inserted
                }
                else if(root1->data>root2->data)
                {
                    s2.pop();
                    root2=root2->right;
                    root1 = NULL;
                }
            }
            else break;
        }
        return res;
    }
};

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